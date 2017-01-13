// 1_04_UDP(客户端).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

/*
1. 初始化环境		wsastartup
2. 创建套接字        socket
//3. 绑定套接字		bind

// 4. 监听套接字		listen
// 5. 处理套接字连接		accept
6. 发送接收数据		sendto/recvfrom

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
	SOCKET sToClientSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sToClientSock == INVALID_SOCKET)
	{
		return 0;
	}
	// 3. 绑定套接字		bind	
	// 4. 监听套接字		listen	
	// 5. 处理套接字连接	accept

	// 6. 发送接收数据	sendto/recvfrom
	char buf[100] = "hello socket client,from client!";
	sockaddr_in clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(0x5566);
	clientAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.96");//127.0.0.1

	int size = sizeof(clientAddr);

	re = sendto(sToClientSock, buf, strlen(buf), 0,
		(sockaddr*)&clientAddr, sizeof(clientAddr));

	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	re = recvfrom(sToClientSock, buf, sizeof(buf), 0,
		(sockaddr*)&clientAddr, &size);
	if (re == INVALID_SOCKET)
	{
		goto over;
	}
over:
	// 7. 关闭套接字		closesocket
	closesocket(sToClientSock);
	// 8. 清理环境		wsacleanup
	WSACleanup();

	return 0;
}

