// 1_01_TCP����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

/*
1. ��ʼ������		wsastartup
2. �����׽���        socket
3. ���׽���		bind
4. �����׽���		listen
5. �����׽�������		accept
6. ���ͽ�������		send/recv
7. �ر��׽���		closesocket
8. ������			wsacleanup
*/
int main()
{
	// 1. ��ʼ������		wsastartup
	WSADATA wsd = {0};
	int re = WSAStartup(MAKEWORD(2,2),&wsd);
	if (re != 0) { return 0; }
	if (LOBYTE(wsd.wVersion) != 2||
		HIBYTE(wsd.wVersion) != 2 )
	{
		return 0;
	}
	// 2. �����׽���     socket
	SOCKET listenSock = socket(AF_INET,SOCK_STREAM,IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)
	{
		return 0;
	}
	// 3. ���׽���		bind
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(0x5566);
	serverAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.96");//127.0.0.1

	re = bind(listenSock,(sockaddr *)&serverAddr, sizeof(serverAddr));
	if (re == SOCKET_ERROR)
	{
		printf("bind error");
		goto over;
	}
	// 4. �����׽���		listen
	re = listen(listenSock, SOMAXCONN);
	if (re == SOCKET_ERROR)
	{
		printf("listen error");
		goto over;
	}
	// 5. �����׽�������	accept
	sockaddr_in clientAddr;
	int size = sizeof(clientAddr);
	SOCKET sToClientSock = accept(
		listenSock, (sockaddr *)&clientAddr,&size);
	if (sToClientSock == INVALID_SOCKET)
	{
		printf("listen error");
		goto over;
	}
	// 6. ���ͽ�������	send/recv
	char buf[100] = "hello socket client,from server!";
	re = send(sToClientSock, buf, strlen(buf), 0);
	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	re = recv(sToClientSock, buf, sizeof(buf), 0);
	if (re == INVALID_SOCKET)
	{
		goto over;
	}
over:
	// 7. �ر��׽���		closesocket
	closesocket(listenSock);
	closesocket(sToClientSock);
	// 8. ������		wsacleanup
	WSACleanup();

    return 0;
}

