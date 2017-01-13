#include "stdafx.h"
#include "MySocket.h"

vector<CMySocket*> CMySocket::pvecClientSock = {};
CDataBaseCtrl* CMySocket::pDataBase = new CDataBaseCtrl;
CMySocket::CMySocket()
{
}


CMySocket::CMySocket(SOCKET sock, sockaddr_in addr)
{
	m_sock = sock;
	m_addr = addr;
	ZeroMemory(m_name, NAMELENGTH);
}

CMySocket::~CMySocket()
{
}


bool CMySocket::RecvSocket()
{	
	CreateThread(
		NULL, NULL, RecvThread, (LPVOID)this, NULL, NULL);
	return true;
}

DWORD WINAPI CMySocket::RecvThread(_In_ LPVOID lpParameter)
{
	CMySocket *pThis = (CMySocket*)lpParameter;
	INT retValue;
	MESSAGE message = {};
	while (true)
	{
		ZeroMemory(&message, sizeof(MESSAGE));
		retValue = recv(pThis->m_sock, (CHAR*)&message, sizeof(message), 0);
		
		if (retValue == SOCKET_ERROR || retValue == 0)
		{
			// 过滤掉还没登录就掉线的客户端
			if (pThis->m_name)
			{
				// 删掉这个sock
				pThis->DeleteSock();
				// 通知其他客户端有人下线了
				pThis->Leave();
			}
			// 关闭套接字
			closesocket(pThis->m_sock);
			// 删除该对象，因为是new出来的-->new的位置Service类的Accept函数
			delete pThis;
			return 0;

		}
		else
		{
			pThis->MyDispatchMessage(message);
		}
		
	}
	return 0;
}



void CMySocket::DeleteSock()
{
	for (DWORD i = 0; i < pvecClientSock.size();i++)
	{
		if (pvecClientSock[i] == this)
		{
			pvecClientSock.erase(pvecClientSock.begin() + i);
			break;
		}
		
	}
}


void CMySocket::Leave()
{
	MESSAGE message;
	message.type = common;
	sprintf_s(message.info.buf, MESSAGEBUF,"%s下线了",m_name);
	message.len = strlen(message.info.buf);
	// 下线通知所有客户端，自己已经从列表里删除了
	SendSockMessage(message);
	// 在服务器端输出一下
	printf("%s", message.info.buf);
}

void CMySocket::SendSockMessage(MESSAGE &message, SOCKET sock)
{
	// 全部发
	if (sock == INVALID_SOCKET)
	{
		for (CMySocket* &mysock : pvecClientSock)
		{
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	// 除sock之外的发
	else
	{
		for (CMySocket* &mysock : pvecClientSock)
		{
			if (mysock->m_sock == sock)
			{
				continue;
			}
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	
}

// 分发消息
INT CMySocket::MyDispatchMessage(MESSAGE &message)
{
	// 判断消息类型,分别处理
	MESSAGETYPE type = message.type;
	INT nRet = 0;
	switch (type)
	{
	case common:
		SendSockMessage(message,this->m_sock);
		printf("%s\n", message.info.buf);
		break;
	case reg:
		nRet = OnMessageReg(message);
		break;
	case Anonymous:// 匿名聊天
		OnMessageAnonymous();
		break;
	case login:
		OnMessageLogin(message);
		break;

	}
	return nRet;
}

void CMySocket::OnMessageAnonymous(CHAR* name)
{
	MESSAGE message;
	// 服务器分配昵称
	if (name == nullptr)
	{
		// 给新上线的分配个昵称
		sprintf_s(m_name, NAMELENGTH, "昵称%d", m_addr.sin_port);
		// 告诉该客户端自己的昵称
		message.type = common;
		strcpy_s(message.info.buf, MESSAGEBUF, m_name);
		message.len = strlen(m_name);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		sprintf_s(m_name, NAMELENGTH, "%s", name);
	}
	// 通知其他人有新人上线了
	message.type = common;// 普通消息
	sprintf_s(message.info.buf, sizeof(message.info.buf), "%s加入聊天室", m_name);
	message.len = strlen(message.info.buf);
	SendSockMessage(message);
	// 加入客户端列表
	pvecClientSock.push_back(this);
}

// -1表示失败
INT CMySocket::OnMessageReg(MESSAGE &message)
{
	// 要注册的姓名密码
	RESULT dataResult;
	CHAR name[NAMELENGTH] = {};
	CHAR password[MESSAGEBUF - NAMELENGTH] = {};
	DWORD dwNameLen = message.info.reginfo.nameLen;
	DWORD dwPassLen = message.len - 4 - dwNameLen;
	strncpy_s(name, message.info.reginfo.name, dwNameLen);
	strncpy_s(password, message.info.reginfo.name+ dwNameLen, dwPassLen);
	char sql[1024] = {};
	sprintf_s(sql, 1024, "SELECT * FROM user_data WHERE user_name = '%s'", name);
	INT nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	// nRet - 1说明语句执行失败，0说明没有查询到数据，其他有数据返回
	if (nRet == 0)
	{// 昵称不存在，可以正常创建
		sprintf_s(sql, 1024,
			"INSERT INTO user_data(user_name,user_password) VALUES('%s','%s')",
			name, password);
		nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	}
	if (nRet == -1)
	{
		// sql语句执行失败
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "数据库连接异常！");
		message.type = reg;
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		// 成功加入数据库，通知客户端和其他客户端
		OnMessageAnonymous(name);
		// 给客户端回应个成功注册的消息
		message.type = reg;
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	return nRet;
}

INT CMySocket::OnMessageLogin(MESSAGE &message)
{
	// 要登录的姓名密码
	RESULT dataResult;
	CHAR name[NAMELENGTH] = {};
	CHAR password[MESSAGEBUF - NAMELENGTH] = {};
	DWORD dwNameLen = message.info.reginfo.nameLen;
	DWORD dwPassLen = message.len - 4 - dwNameLen;
	strncpy_s(name, message.info.reginfo.name, dwNameLen);
	strncpy_s(password, message.info.reginfo.name + dwNameLen, dwPassLen);
	char sql[1024] = {};
	sprintf_s(sql, 1024, "SELECT * FROM user_data WHERE user_name = '%s' AND user_password = '%s' ", name,password);
	INT nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	if (nRet >0 )
	{
		// 成功登录
		OnMessageAnonymous(name);
		// 给客户端回应个成功的消息
		message.type = login;
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		// 失败
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "账户/密码错误！");
		message.type = login;
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	return 0;
}

