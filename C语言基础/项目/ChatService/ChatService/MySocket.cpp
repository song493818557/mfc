#include "stdafx.h"
#include "MySocket.h"

vector<CMySocket> CMySocket::vecClientSock = {};
CMySocket::CMySocket()
{
}


CMySocket::~CMySocket()
{
}


bool CMySocket::RecvSocket(SOCKET sock, sockaddr_in addr)
{
	// 给新上线的分配个昵称
	m_sock = sock;
	sprintf_s(m_name, 20, "昵称%d",addr.sin_port);
	// 告诉该客户端自己的昵称
	MESSAGE message;
	message.type = common;
	strcpy_s(message.buf, m_name);
	message.len = strlen(m_name);
	send(sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	// 通知其他人有新人上线了
	message.type = common;// 普通消息
	sprintf_s(message.buf, sizeof(message.buf), "%s加入聊天室", m_name);
	message.len = strlen(message.buf);
	SendSockMessage(message);
	// 加入客户端列表
	vecClientSock.push_back(*this);
	CreateThread(
		NULL, NULL, RecvThread, (LPVOID)m_sock, NULL, NULL);
	return true;
}

DWORD WINAPI CMySocket::RecvThread(_In_ LPVOID lpParameter)
{
	SOCKET sock = (SOCKET)lpParameter;
	INT retValue;
	MESSAGE message = {};
	while (true)
	{
		retValue = recv(sock, (CHAR*)&message, sizeof(message), 0);
		
		if (retValue == SOCKET_ERROR || retValue == 0)
		{
			// 删掉这个sock
			DeleteSock(sock);
			// 通知其他客户端有人下线了
			// ....
			closesocket(sock);
			return 0;

		}
		else
		{
			MyDispatchMessage(message, sock);
		}
		
	}
	return 0;
}



void CMySocket::DeleteSock(SOCKET sock)
{
	for (DWORD i = 0; i < vecClientSock.size();i++)
	{
		if (vecClientSock[i].m_sock == sock)
		{
			vecClientSock.erase(vecClientSock.begin() + i);
			break;
		}
		
	}
}


void CMySocket::SendSockMessage(MESSAGE &message, SOCKET sock)
{
	// 全部发
	if (sock == INVALID_SOCKET)
	{
		for (CMySocket &mysock : vecClientSock)
		{
			send(mysock.m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	// 除sock之外的发
	else
	{
		for (CMySocket &mysock : vecClientSock)
		{
			if (mysock.m_sock == sock)
			{
				continue;
			}
			send(mysock.m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	
}

// 分发消息
DWORD CMySocket::MyDispatchMessage(MESSAGE &message, SOCKET sock)
{
	// 判断消息类型,分别处理
	MESSAGETYPE type = message.type;
	switch (type)
	{
	case common:
		SendSockMessage(message,sock);
		printf("%s\n", message.buf);
		break;
	case reg:
		break;
	}

	return 0;
}



