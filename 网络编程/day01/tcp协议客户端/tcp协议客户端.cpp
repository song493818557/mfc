// tcpЭ��ͻ���.cpp : �������̨Ӧ�ó������ڵ㡣
//  
#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
int _tmain(int argc, _TCHAR* argv[])
{
	//1.ָ����Ҫʹ�õ�winsock�淶����߰汾,����ʼ��winsock,װ��winsock.dll
	WSADATA wsaDATA = { 0 };
	int nResult = 0;
	nResult = WSAStartup(MAKEWORD(2, 2), &wsaDATA);
	if (nResult == SOCKET_ERROR) return false;//Ҳ���Լ���if (LOBYTE(wsd.wVersion) ||	HIBYTE(wsd.wHighVersion))�ж��Ƿ���ص���ָ���İ汾
	//2.�����׽���
	int nErr = 0;
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		return 0;
	}
	//3.��ip�Ͷ˿�
	sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0x6767);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	  
	//4.���ӷ������� 
	nErr = connect(sock, (sockaddr *)&addr, sizeof(sockaddr_in));
	if (SOCKET_ERROR == nErr)
	{
		printf("������δ����");
		goto over;
	}
	char buf[100] = "hello socket server, from client!";
	char buf2[100] = "xxxxxxxxxxxxxxxclient";
	while (true)
	{ 
		  nErr = send(sock, buf2, sizeof(buf2), 0);
		if (nErr != SOCKET_ERROR)
		{
			printf("�ͻ��˷���:%s\n", buf2);
		}
		/*nErr = recv(sock, buf, sizeof(buf), 0);
		if (nErr != SOCKET_ERROR)
		{
		printf("�ͻ��˽���:%s\n", buf);
		}*/
	}
over:
	//7.�ر��׽���
	closesocket(sock);
	//8.�ͷ���Դ
	WSACleanup();
	return 0;
}


