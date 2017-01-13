// 1_02_TCP���ͻ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

/*
1. ��ʼ������		wsastartup
2. �����׽���        socket
// 3. ���׽���		bind
// 4. �����׽���		listen
// 5. �����׽�������	accept
3. ���ӷ�����        connect
4. X
5. X
6. ���ͽ�������		send/recv
7. �ر��׽���		closesocket
8. ������			wsacleanup
*/
int main()
{
	// 1. ��ʼ������		wsastartup
	WSADATA wsd = { 0 };
	int re = WSAStartup(MAKEWORD(2, 2), &wsd);
	if (re != 0) { return 0; }
	if (LOBYTE(wsd.wVersion) != 2 ||
		HIBYTE(wsd.wVersion) != 2)
	{
		return 0;
	}
	// 2. �����׽���     socket
	SOCKET sToServSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sToServSock == INVALID_SOCKET)
	{
		return 0;
	}
	// 3. ���׽���		bind	
	// 4. �����׽���		listen	
	// 5. �����׽�������	accept
	//3. ���ӷ�����      connect
	sockaddr_in servAddr = {0};
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(0x5566);
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.96");
	re = connect(sToServSock, (sockaddr *)&servAddr, sizeof(servAddr));
	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	// 6. ���ͽ�������	send/recv
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
	// 7. �ر��׽���		closesocket
	closesocket(sToServSock);
	// 8. ������		wsacleanup
	WSACleanup();

	return 0;
}

