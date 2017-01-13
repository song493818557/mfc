#include "stdafx.h"
#include "Service.h"
#include "MySocket.h"


CService::CService()
{


}


CService::~CService()
{
	Clean();
}

// 初始化服务器
bool CService::Init()
{
	int retValue = SOCKET_ERROR;
	bool bRet = true;
	__try 
	{
		// 1.初始化套接字动态库
		WSADATA wsd;
		if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
		{
			__leave;
		}
		// 检查返回的库版本是否是2.2
		if (LOBYTE(wsd.wVersion) != 2 || HIBYTE(wsd.wHighVersion) != 2)
		{
			__leave;
		}
		// 2.创建套接字(服务器监听套接字)
		m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_ListenSock == INVALID_SOCKET)
		{
			__leave;
		}
		// 3.设置服务器地址
		SOCKADDR_IN servAddr = {};// 服务器地址
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons((short)1234);
		// 4.绑定套接字
		retValue = bind(m_ListenSock, (sockaddr*)&servAddr, sizeof(SOCKADDR_IN));
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
		// 5.监听套接字
		retValue = listen(m_ListenSock, SOMAXCONN);
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
	}
	__finally
	{
		if (retValue == SOCKET_ERROR || m_ListenSock == INVALID_SOCKET)
		{
			bRet = false;
			printf("服务器启动失败！\n");
			Clean();
		}
	}
	return bRet;
}

void CService::Clean()
{
	closesocket(m_ListenSock);
	WSACleanup();
}

// 等待客户端连接
bool CService::Accept()
{
	while (true)
	{
		sockaddr_in addrClient = {};
		int nAddrClientLenth = sizeof(sockaddr_in);
		SOCKET sClientSock;// 跟客户端相连的套接字
		sClientSock = accept(m_ListenSock, (sockaddr*)&addrClient, &nAddrClientLenth);
		if (sClientSock == INVALID_SOCKET)
		{
			printf("accept error!");
			Clean();
			return false;
		}
		CMySocket* clientSock = new CMySocket(sClientSock, addrClient);
		clientSock->RecvSocket();
	}
	return true;
}

