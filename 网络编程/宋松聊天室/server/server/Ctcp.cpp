#include "stdafx.h"
#include "Ctcp.h"


Ctcp::Ctcp()
{
}


Ctcp::~Ctcp()
{
	Clean();
}

bool Ctcp::Init()
{
	
	int retValue = SOCKET_ERROR;
	bool bRet = false;
	__try{
		//��ʼ���׽��ֶ�̬��
		WSADATA wsd;
		if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
		{
			__leave;
		}
		// ��ⷵ�ص��Ƿ���2.2�汾
		if (LOBYTE(wsd.wVersion) != 2 || HIBYTE(wsd.wHighVersion) != 2)
		{
			__leave;
		}
		//2.�����׽���(�����������׽���)
		m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_ListenSock == INVALID_SOCKET)
		{
			__leave;
		}
		//3. ���÷�������ַ
		sockaddr_in servAddr = {};//��������ַ
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons(1234);//htons((short)1234)
		//4. ���׽���
		retValue = bind(m_ListenSock, (sockaddr*)&servAddr, sizeof(sockaddr_in));
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
		//5.�����׽���
		retValue = listen(m_ListenSock, 1);
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
	}
	__finally{
		bRet = true;
		if (retValue == SOCKET_ERROR||m_ListenSock==INVALID_SOCKET)
		{
			printf("����������ʧ��!\n");
			Clean();
			bRet = false;
		} 
	}
	return bRet;
}

void Ctcp::Clean()
{
	closesocket(m_ListenSock);
	WSACleanup();
}
//�ȴ��ͻ�������
bool Ctcp::Accept()
{
	while (true)
	{
		//����˵�����
		sockaddr_in addrClient = {};
		int nAddrClientLenth = sizeof(sockaddr_in);
		SOCKET sClientSock;
		sClientSock = accept(m_ListenSock, (sockaddr*)&addrClient, &nAddrClientLenth);
		if (sClientSock == INVALID_SOCKET)
		{
			printf("accept error!");
			Clean();
			return false;
		}
		Csocket * clientSock = new Csocket(sClientSock,addrClient); 
		clientSock->RecvSocket();
	}
	return true;
}
