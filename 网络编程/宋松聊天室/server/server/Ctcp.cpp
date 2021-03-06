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
		//初始化套接字动态库
		WSADATA wsd;
		if (WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
		{
			__leave;
		}
		// 检测返回的是否是2.2版本
		if (LOBYTE(wsd.wVersion) != 2 || HIBYTE(wsd.wHighVersion) != 2)
		{
			__leave;
		}
		//2.创建套接字(服务器监听套接字)
		m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		if (m_ListenSock == INVALID_SOCKET)
		{
			__leave;
		}
		//3. 设置服务器地址
		sockaddr_in servAddr = {};//服务器地址
		servAddr.sin_family = AF_INET;
		servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
		servAddr.sin_port = htons(1234);//htons((short)1234)
		//4. 绑定套接字
		retValue = bind(m_ListenSock, (sockaddr*)&servAddr, sizeof(sockaddr_in));
		if (retValue == SOCKET_ERROR)
		{
			__leave;
		}
		//5.监听套接字
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
			printf("服务器启动失败!\n");
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
//等待客户端连接
bool Ctcp::Accept()
{
	while (true)
	{
		//进入菜单界面
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
