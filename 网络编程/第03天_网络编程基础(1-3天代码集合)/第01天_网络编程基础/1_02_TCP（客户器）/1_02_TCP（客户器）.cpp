// 1_02_TCP（客户器）.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

/*
1. 初始化环境		wsastartup
2. 创建套接字        socket
// 3. 绑定套接字		bind
// 4. 监听套接字		listen
// 5. 处理套接字连接	accept
3. 连接服务器        connect
4. X
5. X
6. 发送接收数据		send/recv
7. 关闭套接字		closesocket
8. 清理环境			wsacleanup
*/
int main()
{
	// 1. 初始化环境		wsastartup
	WSADATA wsd = { 0 };
	int re = WSAStartup(MAKEWORD(2, 2), &wsd);
	if (re != 0) { return 0; }
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		return 0;
	}
	// 2. 创建套接字     socket
	SOCKET sToServSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sToServSock == INVALID_SOCKET)
	{
		return 0;
	}
	// 3. 绑定套接字		bind	
	// 4. 监听套接字		listen	
	// 5. 处理套接字连接	accept
	//3. 连接服务器      connect
	sockaddr_in servAddr = {0};
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(0x5566);
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.96");
	re = connect(sToServSock, (sockaddr *)&servAddr, sizeof(servAddr));
	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	// 6. 发送接收数据	send/recv
	char buf[100] = "hello socket server,from client!";
	re = send(sToServSock, buf, strlen(buf), 0);
	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	re = recv(sToServSock, buf, sizeof(buf), 0);
	if (re == INVALID_SOCKET)
	{
		goto over;
	}
over:
	// 7. 关闭套接字		closesocket
	closesocket(sToServSock);
	// 8. 清理环境		wsacleanup
	WSACleanup();

	return 0;
}

