// 1_04_UDP(�ͻ���).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

/*
1. ��ʼ������		wsastartup
2. �����׽���        socket
//3. ���׽���		bind

// 4. �����׽���		listen
// 5. �����׽�������		accept
6. ���ͽ�������		sendto/recvfrom

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
	SOCKET sToClientSock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (sToClientSock == INVALID_SOCKET)
	{
		return 0;
	}
	// 3. ���׽���		bind	
	// 4. �����׽���		listen	
	// 5. �����׽�������	accept

	// 6. ���ͽ�������	sendto/recvfrom
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
	// 7. �ر��׽���		closesocket
	closesocket(sToClientSock);
	// 8. ������		wsacleanup
	WSACleanup();

	return 0;
}

