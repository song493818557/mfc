// udpserver.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "data.h" 
VOID sendechoReQuest(SOCKET sock, SOCKADDR_IN dstIP){
	static int id = 1;
	static int seq = 1;
	echoRequest echorquest = {0};
	echorquest.time = GetTickCount();
	echorquest.icmpheader.type = 8;
	echorquest.icmpheader.code = 0;
	echorquest.icmpheader.id = id++;
	echorquest.icmpheader.seq = seq++;
	echorquest.icmpheader.checkSum = checksum((u_short *)&echorquest,sizeof(echorquest));//�������㷨
	int re = sendto(sock,
		(char *)&echorquest,
		sizeof(echorquest),
		0,
		(sockaddr *)&dstIP,
		sizeof(dstIP));
	if (re == SOCKET_ERROR){ 
		printf("sendto error");
	}
	return;
}


VOID recvechoReQuest(SOCKET sock, ECHORESPONSE * sponse, sockaddr_in *dstIP){
	int size = sizeof(sockaddr);
	int re = recvfrom(sock,
		(char *)&sponse,
		sizeof(sponse),
		0,
		(sockaddr *)&dstIP,
		&size);
	if (re == SOCKET_ERROR){
		printf("recvfrom error");
	}
	return;
}
void ping(char * host){

	//2.�����׽���
	int nErr = 0;
	SOCKET sock;
	sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
	HOSTENT * IpHost= gethostbyname(host);
	sockaddr_in dstIP = {0};
	dstIP.sin_family = AF_INET;
	dstIP.sin_addr.S_un.S_addr = *(u_long *)IpHost->h_addr;
	for (int i = 0; i < 4;i++){
		//����ICMP ����
		sendechoReQuest(sock,dstIP);

		GetTickCount();
		recvechoReQuest(sock, &sponse,&dstIP);
		printf("���� %s�Ļظ�:�ֽ�32 ʱ��=%dms," \
			inet_ntoa(dstIP.sin_addr), \
		GetTickCount()- ����ʱ��,

		);
	}
	//3. �����������ַ
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_port = htons(0x6767);
	service.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//4, �󶨶˿�
	/********
	Ϊ�������˿ڶ���ļ���socketָ��һ����ַ���˿�  ��ʱ�ͻ��˲�֪����������һ����ַ���ĸ��˿�
	Ϊ������Ҫ����bind()����,�ú����ɹ�����0 ���򷵻�SOCKET_ERROR
	********/
	nErr = bind(sock, (sockaddr *)&service, sizeof(service));
	if (nErr == SOCKET_ERROR)
	{
		goto CloseSock;
		return 0;
	}
	while (true)
	{
		char szRecvBuff[MAX_PATH] = { 0 };
		sockaddr_in stcClient;
		int nAddrLen = sizeof(sockaddr_in);
		nErr = recvfrom(sock, szRecvBuff, MAX_PATH, 0, (sockaddr*)&stcClient, &nAddrLen);
		if (nErr == INVALID_SOCKET)
		{
			goto CloseSock;
		}
		printf("%s\n", szRecvBuff);
	}
CloseSock:
	closesocket(sock);
}
int _tmain(int argc, _TCHAR* argv[])
{
	//1.ָ����Ҫʹ�õ�winsock�淶����߰汾,����ʼ��winsock,װ��winsock.dll
	WSADATA wsaDATA = { 0 };
	int nResult = 0;
	nResult = WSAStartup(MAKEWORD(2, 2), &wsaDATA);
	if (nResult == SOCKET_ERROR) return false;//Ҳ���Լ���if (LOBYTE(wsd.wVersion) ||	HIBYTE(wsd.wHighVersion))�ж��Ƿ���ص���ָ���İ汾
	while (1)
	{
		char in = getchar();
		if (in == 'q') break;
	}
	
	WSACleanup();
	return 0;
}

