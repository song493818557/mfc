#include "stdafx.h"
#include "Csocket.h"
using std::string; 
vector<Csocket*> Csocket::vecClientSock = {};
Cmysql*  Csocket::db = new Cmysql();
Csocket::Csocket()
{
	////db.LinkDataBase(
	//	"MYSQL",
	//	"debug",
	//	"root",
	//	"888888"); 
}
Csocket::Csocket(SOCKET sock,sockaddr_in addr)
{ 
	m_sock = sock;
	m_addr = addr;
	ZeroMemory(m_name,NAMELENGTH);
}

Csocket::~Csocket()
{
}

bool Csocket::RecvSocket()
{
	
	CreateThread(NULL, NULL, recvThread, (LPVOID)this, NULL, NULL);
	return true;
}

DWORD WINAPI Csocket::recvThread(_In_ LPVOID lpParameter)
{
	Csocket *pthis = (Csocket*)lpParameter;
	int retValue;
	MESSAGE message = {};
	while (true)
	{
		ZeroMemory(&message, sizeof(MESSAGE));
		retValue = recv(pthis->m_sock, (char*)&message, sizeof(message), 0);
		if (retValue == SOCKET_ERROR || retValue == 0)
		{
			if (pthis->m_name)
			{ 
				//删掉这个sock
				pthis->DeleteSock();
				//通知其他客户端有人下线了
				pthis->Leave();
			}
			//关不套接字
			closesocket(pthis->m_sock);
			delete pthis;
			return 0;
		}
		else{
			pthis->MyDispatchMessage(message);
		} 
	}
	return 0;
}

void Csocket::DeleteSock()
{
	for (DWORD i = 0; i < vecClientSock.size();i++)
	{
		if (vecClientSock[i] == this)
		{
			vecClientSock.erase(vecClientSock.begin() + i);
			break;
		}
	}
}
void Csocket::Leave()
{
	MESSAGE message;
	message.type = Anonymous;
	sprintf_s(message.buf, MESSAGEBUF, "%s下线了", m_name);
	message.len = strlen(message.buf);
	//下线通知所有客户端  自己已经从列表删除了
	SendSockMessage(message);
	printf("%s", message.buf);
}
void Csocket::SendSockMessage(MESSAGE &message, SOCKET sock /*= INVALID_SOCKET*/)
{
	//全部发
	if (sock == INVALID_SOCKET)
	{
		for (Csocket* &mysock : vecClientSock)
		{
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	else //除当前SOCK之外的发
	{
		for (Csocket* &mysock : vecClientSock)
		{
			if (mysock->m_sock == sock)
			{
				continue;
			}
			send(mysock->m_sock, (char *)&message, sizeof(MESSAGE), 0);
		}
	}
}
//分发消息
int Csocket::MyDispatchMessage(MESSAGE &message)
{
	//判断消息类型,分别处理
	MESSAGETYPE type = message.type; 
	switch (type)
	{
	case common:	//1 聊天消息属于普通消息
		SendSockMessage(message, m_sock);
		printf("%s\n", base.base64_decode(message.buf).c_str());
		break;
	case reg:		//2 注册姓名的消息，主要用于客户端给服务器发送
		Createnewuser(message); 
		break;
	case login:		//3 登录
		userlogin(message);
		break;
	case Anonymous:	//4 匿名聊天
		anonymous();
		break;
	case search:	//8 搜索
		searchuser(message);
		break;
	case addfriend:	//9	添加好友
		Addfriend(message);
		break;
	case alluser:	//11	添加好友
		Alluser(message);
		break;
	case vchat:		//10	私聊
		Vchat(message);
		break;
	case control:	//7 控制命令，服务器给客户端发
		anonymous();
		break;
	case file:		//5 发送文件的命令
		pushfile(message);
		break;
	case picture:	//6 发送图片的命令
		//anonymous();
		break;		
	default:		
		break;		
	}			   
	return 0;		
}					
//2 注册 
int Csocket::Createnewuser(MESSAGE &message)
{ 
	 
	_RESULT result; 
	string aa = base.base64_decode(message.buf);

	//string aa = "dassaa#dasdsa";
	int cc = aa.find_first_of("#");
	string name = aa.substr(0, cc);
	string pwd = aa.substr(cc + 1);
	char strLink[MAX_PATH] = { 0 };
	sprintf_s(strLink, MAX_PATH, "select * from  userdata where  uuser ='%s'",
		name.c_str());
	int temp = db->ExeSqlByRecordSet(result, strLink);
	if (temp == -1) goto retError;
	if (temp == 0)//昵称不存在 可以正常注册
	{
		sprintf_s(strLink, MAX_PATH, "INSERT into userdata(uuser,pwd) VALUES('%s','%s')",
			name.c_str(),
			pwd.c_str());
		temp = db->ExeSqlByRecordSet(result, strLink);
		if (temp == -1)
		{
			//sql语句执行失败
retError:
			strcpy_s(message.buf, MESSAGEBUF, "数据库异常 请联系管理员");
			message.type = reg;
			message.len = strlen(message.buf);
			//message.info.reginfo.nameLen = message.len;
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
		}
		else
		{
			//成功加入数据库,通知客户端和其他客户端
			anonymous(name);
			//给客户端回应个成功注册的信息
			MESSAGE message; 
			message.type = reg;
			sprintf_s(message.buf, MESSAGEBUF, "%s", "succeed!");  
			message.len = strlen(message.buf); 
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
		}
	}
	else
	{
		//已经存在相同用户名
		message.type = reg;
		memcpy_s(message.buf, MESSAGEBUF, "用户名已经存在!", strlen("用户名已经存在!"));
		message.len = strlen(message.buf);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	return temp;
}


int Csocket::userlogin(MESSAGE &message)
{
	_RESULT result;
	string aa =  base.base64_decode(message.buf);
	//string aa = "dassaa#dasdsa";
	
	int cc = aa.find_first_of("#");
	string name = aa.substr(0, cc);
	string pwd = aa.substr(cc + 1);
	char strLink[MAX_PATH] = { 0 };
	sprintf_s(strLink, MAX_PATH, "select * from  userdata where  uuser ='%s' and pwd = '%s'",
		name.c_str(),
		pwd.c_str());  
	int temp = db->ExeSqlByRecordSet(result, strLink);
	if (temp == -1){ 
		//sql语句执行失败
		strcpy_s(message.buf, MESSAGEBUF, "数据库异常 请联系管理员");
		message.type = reg;
		message.len = strlen(message.buf);
		//message.info.reginfo.nameLen = message.len;
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	if (temp == 1)//有对应的账号密码
	{ 
		//成功加入数据库,通知客户端和其他客户端
		anonymous(name.c_str());
		//给客户端回应个成功注册的信息
		MESSAGE message;
		message.type = reg;
		sprintf_s(message.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.buf);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0); 
	}
	else
	{
		//没有查询到正确的数据
		message.type = reg;
		sprintf_s(message.buf, MESSAGEBUF, "%s", "faild!");
		message.len = strlen(message.buf);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	return temp;
}
void Csocket::anonymous(string name)
{
	MESSAGE message;
	if (name == "123")
	{ 
		//给新上线的分配个昵称 
		sprintf_s(m_name, 20, "游客%d", m_addr.sin_port);
		//告诉该客户端自己的昵称 
		message.type = Anonymous;
		sprintf_s(message.buf, MESSAGEBUF, "%s", m_name); 
		message.len = strlen(m_name);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		sprintf_s(m_name, NAMELENGTH, "%s", name.c_str());
	}
	
	//通知其他人有新人上线了
	message.type = Anonymous;//普通消息  上面已经写过了 但是这样再写一次比较好分析
	sprintf_s(message.buf, sizeof(message.buf), "%s加入聊天室", m_name);
	message.len = strlen(message.buf);
	SendSockMessage(message);
	//加入客户端列表
	vecClientSock.push_back(this);
}

void Csocket::searchuser(MESSAGE &message)
{
	//模糊匹配数据数据
	//判断用户名 和当前在线的SOCK.m_name 是否一致  判断是否在线
	//返回数据
	char sql[MAX_PATH] = { 0 };
	sprintf_s(sql, MAX_PATH, "select uuser from userdata where uuser like '%s%s%s'", "%", message.buf, "%");
	_RESULT result;
	int temp = db->ExeSqlByRecordSet(result, sql);
	string Smessage = "123";
	if (temp == -1){
		Smessage = "系统错误";
	}
	else if (temp == 0)
	{  //没有数据 
		 Smessage = "没有找到哦";
	}
	else{
		 //找到了
		char aa[100] = { 0 };
		strcpy_s(aa, message.buf);
		sprintf_s(message.buf, MESSAGEBUF, "查询(%s)符合条件的有%d条记录", aa, result.vec_Data.size());
			message.len = strlen(message.buf);
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
			//发送头部消息
			Smessage = "";
			for (int i = 0; i < result.vec_Data.size();i++)
			{
				Smessage += result.vec_Data[i][0].c_str();
				Smessage += "\r\n";
			} 
	}
	message.len = strlen(Smessage.c_str());
	sprintf_s(message.buf, MESSAGEBUF, "%s", Smessage.c_str());
	send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
}

void Csocket::Addfriend(MESSAGE &message)
{
	//1 本地判断下是否符合要求 如 当前客户端是否登录了 没登录 就不能添加好友 (客户端自己判断)
	//2 查询flist表里面是否已经是好友了
	//3 插入数据 数据成功

	char sql[MAX_PATH] = { 0 };
	sprintf_s(sql, MAX_PATH, "select * from flist where uuser = '%s' and friend = '%s'", m_name, message.buf);
	_RESULT result;
	int temp = db->ExeSqlByRecordSet(result, sql);
	string Smessage = "123";
	if (temp == 0)
	{  //插入数据
		sprintf_s(sql, MAX_PATH, "insert into flist (uuser,friend) value ('%s','%s'),('%s','%s')", m_name, message.buf, message.buf, m_name);
		int temp = db->ExeSqlByRecordSet(result, sql); 
		temp == 0 ? sprintf_s(message.buf, MESSAGEBUF, "%s", "添加成功") : \
					sprintf_s(message.buf, MESSAGEBUF, "%s", "系统错误");
	}
	else{ 
		temp == -1 ? sprintf_s(message.buf, MESSAGEBUF, "%s", "系统错误") : \
					 sprintf_s(message.buf, MESSAGEBUF, "%s", "已经是好友了");
		} 
	message.len = strlen(message.buf); 
	send(m_sock, (char*)&message, sizeof(MESSAGE), 0);

}

void Csocket::Alluser(MESSAGE &message)
{
	string namea = "";
	for (Csocket* &mysock : vecClientSock)
	{
		namea += mysock->m_name;
		namea += "\r\n";
	}
	message.len = namea.length();
	message.type = search;
	sprintf_s(message.buf, MESSAGEBUF, "%s", namea.c_str());
	send(m_sock, (char*)&message, sizeof(MESSAGE), 0); 
}
string Csocket::Allsuser()
{
	string namea = "";
	for (Csocket* &mysock : vecClientSock)
	{
		namea += mysock->m_name;
		namea += "\r\n";
	}
	return namea;
}
void Csocket::Acmd()
{
	int i,j=1;
	while (j<2)
	{ 
		j = 1;
		while (j!=3)
		{
			i = 0;
			char user_name[50] = { 0 };
			printf("请输入要控制的用户名");
			scanf_s("%s", user_name, _countof(user_name));
			for (; i < vecClientSock.size(); i++)
			{
				if (strcmp(vecClientSock[i]->m_name, user_name) == 0)
				{
					j = 3;
					break;
				}
			}
			if (j == 3)
			{
				printf("请输入需要执行的指令");
			}
			else
			{
				printf("没有找到对应的sock");
			} 
		}
		char aa[MESSAGEBUF] = { 0 };
		MESSAGE message;
		scanf_s("%s", aa, _countof(message.buf));
		string aac;  
		message.type = control; 
		aac = vecClientSock[i]->base.base64_encode(aa, strlen(aa));
		sprintf_s(message.buf, MESSAGEBUF, "%s", aac.c_str()); 
		message.len = strlen(message.buf);
		send(vecClientSock[i]->m_sock, (char*)&message, sizeof(MESSAGE), 0);
		printf("命令发送成功! 继续按Y 返回菜单按N");
		char ch = 0;
		scanf_s("%s", &ch, 1);
		//控制跳出循环
		((ch == 'y') || (ch == 'Y')) ? j = 2 : j = 0;
		
	}
}

void Csocket::Defsql(string sql)
{
	_RESULT result;
	string temp="";
	int numb = db->ExeSqlByRecordSet(result, sql);
	if (numb == -1)
	{
		temp = "数据库错误";
	}
	else if(numb == 0)
	{
		temp = "无返回值";
	}
	else
	{
		for (int i = 0; i < result.vec_CloName.size(); i++)
		{
			printf("%-16s", result.vec_CloName[i].c_str());
			//temp += result.vec_CloName[i][0] + "\t\t\t";
		}
		//printf("\n");
		temp += "\r\n";
		for (int i = 0; i < result.vec_Data.size(); i++)
		{
			for (int j = 0; j < result.vec_Data[i].size(); j++)
			{
				//printf("\t%s", result.vec_Data[i][j]);
				temp += result.vec_Data[i][j] + "\t\t";
			}
			//printf("\n");
			temp += "\r\n";
		} 
	}
	printf("%s", temp.c_str());
}

//10 1V1 私聊vchat
void Csocket::Vchat(MESSAGE &message)
{
	string aa = message.buf;  
	int cc = aa.find_first_of(" ");
	string name = aa.substr(0, cc);
	string msgbuf =  aa.substr(cc + 1); 
	int i = 0;
	for (; i < vecClientSock.size(); i++)
	{
		if (strcmp(vecClientSock[i]->m_name, name.c_str()) == 0)
		{
			break;
		}
	} 
	message.type = vchat;
	sprintf_s(message.buf, MESSAGEBUF, "%s悄悄对你说:%s", m_name,msgbuf.c_str());
	message.len = strlen(message.buf);
	send(vecClientSock[i]->m_sock, (char*)&message, sizeof(MESSAGE), 0);
}

void Csocket::pushfile(MESSAGE &message)
{
	string aa = message.buf; 
	int cc = aa.find_first_of("#");
	string name = aa.substr(0, cc);
	string msgbuf = aa.substr(cc + 1);
	int i = 0;
	for (; i < vecClientSock.size(); i++)
	{
		if (strcmp(vecClientSock[i]->m_name, name.c_str()) == 0)
		{
			break;
		}
	}
	message.type = file; 
	sprintf_s(message.buf, MESSAGEBUF, "来自用户%s的文件#%s", m_name, msgbuf.c_str());
	message.len = strlen(message.buf);
	send(vecClientSock[i]->m_sock, (char*)&message, sizeof(MESSAGE), 0);
}

 


