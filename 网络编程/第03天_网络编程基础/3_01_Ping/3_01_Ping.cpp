// 3_01_Ping.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include "data.h"

void sendEchoReQuest(SOCKET sock, sockaddr_in dstIP)
{
	static int id = 1;
	static int seq = 1;

	ECHOREQUEST echoRequest = { 0 };

	echoRequest.time = GetTickCount();
	echoRequest.icmpHeader.type = 8;
	echoRequest.icmpHeader.code = 0;
	echoRequest.icmpHeader.id = id++;
	echoRequest.icmpHeader.seq = seq++;
	echoRequest.icmpHeader.checkSum =
		checksum((u_short *)&echoRequest, sizeof(echoRequest));

	int re = sendto(sock,
		(char *)&echoRequest,
		sizeof(echoRequest),
		0,
		(sockaddr *)&dstIP,
		sizeof(dstIP));

	if (re == SOCKET_ERROR)
	{
		printf(" sendto error");
	}
	return;
}

void recvEchoReQuest(SOCKET sock,
	ECHORESPONSE * sponse, sockaddr_in *dstIP)
{
	int size = sizeof(sockaddr);
	int re = recvfrom(sock, (char *)sponse, sizeof(ECHORESPONSE), 0,
		(sockaddr*)dstIP, &size);
	if (re == SOCKET_ERROR)
	{
		printf("recvfrom error");
	}
}

void Ping(char * host)
{
	SOCKET sock = socket(
		AF_INET, SOCK_RAW, IPPROTO_ICMP);

	HOSTENT * lpHost = gethostbyname(host);

	sockaddr_in dstIP = { 0 };
	dstIP.sin_family = AF_INET;
	dstIP.sin_addr.S_un.S_addr = *(u_long*)lpHost->h_addr;

	for (int i = 0; i < 4; i++)
	{
		//����ICMP����
		sendEchoReQuest(sock, dstIP);

		ECHORESPONSE sponse;
		recvEchoReQuest(sock, &sponse, &dstIP);


		printf("���� %s �Ļظ�: �ֽ�=32 ʱ��=%dms TTL=%d \n",
			inet_ntoa(dstIP.sin_addr),
			GetTickCount() - sponse.echoRequest.time,
			sponse.ipHeader.ttl
			);
	}
}
int main()
{
	//1.��ʼ��winsock����
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	while (true)
	{
		Ping("www.15pb.com");
		char in = getchar();
		if (in == 'q')
		{
			break;
		}
	}
	//2.�ͷŻ���
	WSACleanup();

	return 0;
}

