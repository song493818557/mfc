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
	char buf[] = "1_lbt4_0#128#005056C00008#0#0#0:1481051183:song:SONGSONG:4194592:20002:1edecf083209b4a3419aa4f35099a53614ead3a7097a7c8b7df801859822a0f67011d1713182c4f819f3693b0c54d52a56567bb3fcd097af4d096ee456fb65f39cba7f628977d28f3b79540112cfd72d834adad533627581e3ea3fe4c7fd3698e0e710bfe0944376051bfea5d2da9aa8b50e8f50fe6fda4490594bce27fefcdb:e9ed73106e6a7c65  ";//����444
//	char buf[] = "1_lbt4_0#128#005056C00008#0#0#0:1481051183:song:SONGSONG:4194592:20002:1edecf083209b4a3419aa4f35099a53614ead3a7097a7c8b7df801859822a0f67011d1713182c4f819f3693b0c54d52a56567bb3fcd097af4d096ee456fb65f39cba7f628977d28f3b79540112cfd72d834adad533627581e3ea3fe4c7fd3698e0e710bfe0944376051bfea5d2da9aa8b50e8f50fe6fda4490594bce27fefcdb:e9ed73106e6a7c65  ";
	sockaddr_in clientAddr;
	clientAddr.sin_family = AF_INET;
	clientAddr.sin_port = htons(2425);
	clientAddr.sin_addr.S_un.S_addr = inet_addr("192.168.32.128");//127.0.0.1

	int size = sizeof(clientAddr);

	re = sendto(sToClientSock, buf, strlen(buf), 0,
		(sockaddr*)&clientAddr, sizeof(clientAddr));

	if (re == SOCKET_ERROR)
	{
		goto over;
	}/*
	re = recvfrom(sToClientSock, buf, sizeof(buf), 0,
		(sockaddr*)&clientAddr, &size);
	if (re == INVALID_SOCKET)
	{
		goto over;
	}*/
over:
	// 7. �ر��׽���		closesocket
	closesocket(sToClientSock);
	// 8. ������		wsacleanup
	WSACleanup();

	return 0;
}

