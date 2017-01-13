// day01.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
/*

*/
bool InitTCP(){
	//1 ��ʼ������   wsastartup 
	WSADATA wsd = { 0 };
	int nResult = WSAStartup(MAKEWORD(2, 2), &wsd);
	if (nResult == SOCKET_ERROR)
	{
		return FALSE;
	}
	if (LOBYTE(wsd.wVersion)||
		HIBYTE(wsd.wHighVersion)
		)
	{
		return 0;
	}

	//2 �����׽���   socket 
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_AH);//!!
	if (listenSock == INVALID_SOCKET){
		return 0;
	}
	//3 ���׽���	bind
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_port = htons(0x5566);
	serverAddr.sin_addr.S_un.S_addr= inet_addr("127.0.0.1");//127.0.0.1
	int re = bind(listenSock, (sockaddr *)&serverAddr, sizeof(serverAddr));
	if (re == SOCKET_ERROR)
	{
		printf("bind error");
		goto over;
	}
	//4  �����׽���	listen
	re = listen(listenSock,SOMAXCONN);
	if (re == SOMAXCONN)
	{
		printf("listen error");
		goto over;
	}
	//5 �����׽���	accept
	sockaddr_in clientAddr;
	int size = sizeof(clientAddr);
	SOCKET sToClientSock = accept(listenSock, (sockaddr*)&clientAddr, &size);
	if (sToClientSock == INVALID_SOCKET)
	{
		printf("accept error");
		goto over;
	}
	//6 �շ�����		send
	char buf[] = "hello socket client, from server!";
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
	closesocket(listenSock);
	//7 �ر��׽���	closesocket
	closesocket(listenSock);
	closesocket(sToClientSock); 
	//8 ���㻷��		wsacleanup
	WSACleanup();
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	return 0;
}

