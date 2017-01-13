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
				//ɾ�����sock
				pthis->DeleteSock();
				//֪ͨ�����ͻ�������������
				pthis->Leave();
			}
			//�ز��׽���
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
	sprintf_s(message.buf, MESSAGEBUF, "%s������", m_name);
	message.len = strlen(message.buf);
	//����֪ͨ���пͻ���  �Լ��Ѿ����б�ɾ����
	SendSockMessage(message);
	printf("%s", message.buf);
}
void Csocket::SendSockMessage(MESSAGE &message, SOCKET sock /*= INVALID_SOCKET*/)
{
	//ȫ����
	if (sock == INVALID_SOCKET)
	{
		for (Csocket* &mysock : vecClientSock)
		{
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	else //����ǰSOCK֮��ķ�
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
//�ַ���Ϣ
int Csocket::MyDispatchMessage(MESSAGE &message)
{
	//�ж���Ϣ����,�ֱ���
	MESSAGETYPE type = message.type; 
	switch (type)
	{
	case common:	//1 ������Ϣ������ͨ��Ϣ
		SendSockMessage(message, m_sock);
		printf("%s\n", base.base64_decode(message.buf).c_str());
		break;
	case reg:		//2 ע����������Ϣ����Ҫ���ڿͻ��˸�����������
		Createnewuser(message); 
		break;
	case login:		//3 ��¼
		userlogin(message);
		break;
	case Anonymous:	//4 ��������
		anonymous();
		break;
	case search:	//8 ����
		searchuser(message);
		break;
	case addfriend:	//9	��Ӻ���
		Addfriend(message);
		break;
	case alluser:	//11	��Ӻ���
		Alluser(message);
		break;
	case vchat:		//10	˽��
		Vchat(message);
		break;
	case control:	//7 ����������������ͻ��˷�
		anonymous();
		break;
	case file:		//5 �����ļ�������
		pushfile(message);
		break;
	case picture:	//6 ����ͼƬ������
		//anonymous();
		break;		
	default:		
		break;		
	}			   
	return 0;		
}					
//2 ע�� 
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
	if (temp == 0)//�ǳƲ����� ��������ע��
	{
		sprintf_s(strLink, MAX_PATH, "INSERT into userdata(uuser,pwd) VALUES('%s','%s')",
			name.c_str(),
			pwd.c_str());
		temp = db->ExeSqlByRecordSet(result, strLink);
		if (temp == -1)
		{
			//sql���ִ��ʧ��
retError:
			strcpy_s(message.buf, MESSAGEBUF, "���ݿ��쳣 ����ϵ����Ա");
			message.type = reg;
			message.len = strlen(message.buf);
			//message.info.reginfo.nameLen = message.len;
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
		}
		else
		{
			//�ɹ��������ݿ�,֪ͨ�ͻ��˺������ͻ���
			anonymous(name);
			//���ͻ��˻�Ӧ���ɹ�ע�����Ϣ
			MESSAGE message; 
			message.type = reg;
			sprintf_s(message.buf, MESSAGEBUF, "%s", "succeed!");  
			message.len = strlen(message.buf); 
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
		}
	}
	else
	{
		//�Ѿ�������ͬ�û���
		message.type = reg;
		memcpy_s(message.buf, MESSAGEBUF, "�û����Ѿ�����!", strlen("�û����Ѿ�����!"));
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
		//sql���ִ��ʧ��
		strcpy_s(message.buf, MESSAGEBUF, "���ݿ��쳣 ����ϵ����Ա");
		message.type = reg;
		message.len = strlen(message.buf);
		//message.info.reginfo.nameLen = message.len;
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	if (temp == 1)//�ж�Ӧ���˺�����
	{ 
		//�ɹ��������ݿ�,֪ͨ�ͻ��˺������ͻ���
		anonymous(name.c_str());
		//���ͻ��˻�Ӧ���ɹ�ע�����Ϣ
		MESSAGE message;
		message.type = reg;
		sprintf_s(message.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.buf);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0); 
	}
	else
	{
		//û�в�ѯ����ȷ������
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
		//�������ߵķ�����ǳ� 
		sprintf_s(m_name, 20, "�ο�%d", m_addr.sin_port);
		//���߸ÿͻ����Լ����ǳ� 
		message.type = Anonymous;
		sprintf_s(message.buf, MESSAGEBUF, "%s", m_name); 
		message.len = strlen(m_name);
		send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		sprintf_s(m_name, NAMELENGTH, "%s", name.c_str());
	}
	
	//֪ͨ������������������
	message.type = Anonymous;//��ͨ��Ϣ  �����Ѿ�д���� ����������дһ�αȽϺ÷���
	sprintf_s(message.buf, sizeof(message.buf), "%s����������", m_name);
	message.len = strlen(message.buf);
	SendSockMessage(message);
	//����ͻ����б�
	vecClientSock.push_back(this);
}

void Csocket::searchuser(MESSAGE &message)
{
	//ģ��ƥ����������
	//�ж��û��� �͵�ǰ���ߵ�SOCK.m_name �Ƿ�һ��  �ж��Ƿ�����
	//��������
	char sql[MAX_PATH] = { 0 };
	sprintf_s(sql, MAX_PATH, "select uuser from userdata where uuser like '%s%s%s'", "%", message.buf, "%");
	_RESULT result;
	int temp = db->ExeSqlByRecordSet(result, sql);
	string Smessage = "123";
	if (temp == -1){
		Smessage = "ϵͳ����";
	}
	else if (temp == 0)
	{  //û������ 
		 Smessage = "û���ҵ�Ŷ";
	}
	else{
		 //�ҵ���
		char aa[100] = { 0 };
		strcpy_s(aa, message.buf);
		sprintf_s(message.buf, MESSAGEBUF, "��ѯ(%s)������������%d����¼", aa, result.vec_Data.size());
			message.len = strlen(message.buf);
			send(m_sock, (char*)&message, sizeof(MESSAGE), 0);
			//����ͷ����Ϣ
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
	//1 �����ж����Ƿ����Ҫ�� �� ��ǰ�ͻ����Ƿ��¼�� û��¼ �Ͳ�����Ӻ��� (�ͻ����Լ��ж�)
	//2 ��ѯflist�������Ƿ��Ѿ��Ǻ�����
	//3 �������� ���ݳɹ�

	char sql[MAX_PATH] = { 0 };
	sprintf_s(sql, MAX_PATH, "select * from flist where uuser = '%s' and friend = '%s'", m_name, message.buf);
	_RESULT result;
	int temp = db->ExeSqlByRecordSet(result, sql);
	string Smessage = "123";
	if (temp == 0)
	{  //��������
		sprintf_s(sql, MAX_PATH, "insert into flist (uuser,friend) value ('%s','%s'),('%s','%s')", m_name, message.buf, message.buf, m_name);
		int temp = db->ExeSqlByRecordSet(result, sql); 
		temp == 0 ? sprintf_s(message.buf, MESSAGEBUF, "%s", "��ӳɹ�") : \
					sprintf_s(message.buf, MESSAGEBUF, "%s", "ϵͳ����");
	}
	else{ 
		temp == -1 ? sprintf_s(message.buf, MESSAGEBUF, "%s", "ϵͳ����") : \
					 sprintf_s(message.buf, MESSAGEBUF, "%s", "�Ѿ��Ǻ�����");
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
			printf("������Ҫ���Ƶ��û���");
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
				printf("��������Ҫִ�е�ָ��");
			}
			else
			{
				printf("û���ҵ���Ӧ��sock");
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
		printf("����ͳɹ�! ������Y ���ز˵���N");
		char ch = 0;
		scanf_s("%s", &ch, 1);
		//��������ѭ��
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
		temp = "���ݿ����";
	}
	else if(numb == 0)
	{
		temp = "�޷���ֵ";
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

//10 1V1 ˽��vchat
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
	sprintf_s(message.buf, MESSAGEBUF, "%s���Ķ���˵:%s", m_name,msgbuf.c_str());
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
	sprintf_s(message.buf, MESSAGEBUF, "�����û�%s���ļ�#%s", m_name, msgbuf.c_str());
	message.len = strlen(message.buf);
	send(vecClientSock[i]->m_sock, (char*)&message, sizeof(MESSAGE), 0);
}

 


