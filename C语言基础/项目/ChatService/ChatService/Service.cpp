#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Service.h"


CService::CService()
{


}


CService::~CService()
{
	Clean();
}

// ��ʼ��������
bool CService::Init()
{
	int retValue = SOCKET_ERROR;
	bool bRet = false;
	__try 
	{
		// 1.��ʼ���׽��ֶ�̬��
		WSADATA wsd;
		if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
		{
			__leave;
		}
		// ��鷵�صĿ�汾�Ƿ���2.2
		if (LOBYTE(wsd.wVersion) != 2 || HIBYTE(wsd.wHighVersion) != 2)
		{
			__leave;
		}
		// 2.�����׽���(�����������׽���)
		m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_ListenSock == INVALID_SOCKET)
		{
			__leave;
		}
		// 3.���÷�������ַ
		SOCKADDR_IN servAddr = {};// ��������ַ
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons((short)1234);
		// 4.���׽���
		retValue = bind(m_ListenSock, (sockaddr*)&servAddr, sizeof(SOCKADDR_IN));
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
		// 5.�����׽���
		retValue = listen(m_ListenSock, 1);
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
	}
	__finally
	{
		 bRet = true;
		if (retValue == SOCKET_ERROR || m_ListenSock == INVALID_SOCKET)
		{
			printf("����������ʧ�ܣ�\n");
			Clean();
		  bRet = false;
		} 
	}
	return bRet;
}

void CService::Clean()
{
	closesocket(m_ListenSock);
	WSACleanup();
}

// �ȴ��ͻ�������
bool CService::Accept()
{

	while (true)
	{
		//����˵�����
		
		sockaddr_in addrClient = {};
		int nAddrClientLenth = sizeof(sockaddr_in);
		SOCKET sClientSock;// ���ͻ����������׽���
		sClientSock = accept(m_ListenSock, (sockaddr*)&addrClient, &nAddrClientLenth);
		if (sClientSock == INVALID_SOCKET)
		{
			printf("accept error!");
			Clean();
			return false;
		}
		CMySocket clientSock;
		clientSock.RecvSocket(sClientSock, addrClient);
	}
	return true;
}

