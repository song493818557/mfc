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
	// �������ߵķ�����ǳ�
	m_sock = sock;
	sprintf_s(m_name, 20, "�ǳ�%d",addr.sin_port);
	// ���߸ÿͻ����Լ����ǳ�
	MESSAGE message;
	message.type = common;
	strcpy_s(message.buf, m_name);
	message.len = strlen(m_name);
	send(sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	// ֪ͨ������������������
	message.type = common;// ��ͨ��Ϣ
	sprintf_s(message.buf, sizeof(message.buf), "%s����������", m_name);
	message.len = strlen(message.buf);
	SendSockMessage(message);
	// ����ͻ����б�
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
			// ɾ�����sock
			DeleteSock(sock);
			// ֪ͨ�����ͻ�������������
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
	// ȫ����
	if (sock == INVALID_SOCKET)
	{
		for (CMySocket &mysock : vecClientSock)
		{
			send(mysock.m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	// ��sock֮��ķ�
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

// �ַ���Ϣ
DWORD CMySocket::MyDispatchMessage(MESSAGE &message, SOCKET sock)
{
	// �ж���Ϣ����,�ֱ���
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



