// �ͻ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

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
	int re = 0;
	int nResult = WSAStartup(MAKEWORD(2, 2), &wsd);//ʹ��WINSOCK2.2��
	if (nResult == SOCKET_ERROR)//�ж��Ƿ���óɹ�
	{
		return FALSE;
	}
	if (LOBYTE(wsd.wVersion) ||
		HIBYTE(wsd.wHighVersion)
		)//�ж��Ƿ���õ���2.2�汾
	{
		return 0;
	}

	//2 �����׽���   socket 
	//AF_INET ���� TCP ��UDP
	//TCP : SOCK_STREAM ��ʽ ���IPPROTO_TCP
	//udp:SOCK_DGRAM ���ݱ� ���IPPROTO_UDP
	SOCKET sToservSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//!!
	if (sToservSock == INVALID_SOCKET){
		return 0;
	}
	//3 ���׽���	connect
	// ���׽���  
	//sin_family  AF_INET ���� TCP ��UDP
	//sin_port  ��Ҫ�任�Ķ˿� htons htons����ת��u_short��������TCP / IP�����ֽ�˳��(���)��
	//sin_addr.S_un.S_addr  inet_addr("127.0.0.1")
	sockaddr_in  servAddr = {0};
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(0x5566);
	servAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	
	re =connect(sToservSock, (sockaddr *)&servAddr, sizeof(servAddr));
	if (re == SOCKET_ERROR)
	{
		goto over;
	} 
	//4  �����׽���	listen
	
	//5 �����׽���	accept
	 
	//6 �շ�����		send
	char buf[] = "hello socket client, from server!";
	re = send(sToservSock, buf, strlen(buf), 0);
	if (re == SOCKET_ERROR)
	{
		goto over;
	}
	re = recv(sToservSock, buf, sizeof(buf), 0);
	if (re == INVALID_SOCKET)
	{
		goto over;
	}
over:
	closesocket(sToservSock);
	//7 �ر��׽���	closesocket
	closesocket(sToservSock);
	//8 ���㻷��		wsacleanup
	WSACleanup();
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}


