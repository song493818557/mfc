// udpserver.cpp : 定义控制台应用程序的入口点。
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
	echorquest.icmpheader.checkSum = checksum((u_short *)&echorquest,sizeof(echorquest));//单独的算法
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

	//2.创建套接字
	int nErr = 0;
	SOCKET sock;
	sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); 
	HOSTENT * IpHost= gethostbyname(host);
	sockaddr_in dstIP = {0};
	dstIP.sin_family = AF_INET;
	dstIP.sin_addr.S_un.S_addr = *(u_long *)IpHost->h_addr;
	for (int i = 0; i < 4;i++){
		//发送ICMP 数据
		sendechoReQuest(sock,dstIP);

		GetTickCount();
		recvechoReQuest(sock, &sponse,&dstIP);
		printf("来自 %s的回复:字节32 时间=%dms," \
			inet_ntoa(dstIP.sin_addr), \
		GetTickCount()- 发送时间,

		);
	}
	//3. 定义服务器地址
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_port = htons(0x6767);
	service.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	//4, 绑定端口
	/********
	为服务器端口定义的监听socket指定一个地址及端口  这时客户端才知道在连接哪一个地址的哪个端口
	为此我们要调用bind()函数,该函数成功返回0 否则返回SOCKET_ERROR
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
	//1.指定需要使用的winsock规范的最高版本,并初始化winsock,装入winsock.dll
	WSADATA wsaDATA = { 0 };
	int nResult = 0;
	nResult = WSAStartup(MAKEWORD(2, 2), &wsaDATA);
	if (nResult == SOCKET_ERROR) return false;//也可以加上if (LOBYTE(wsd.wVersion) ||	HIBYTE(wsd.wHighVersion))判断是否加载到了指定的版本
	while (1)
	{
		char in = getchar();
		if (in == 'q') break;
	}
	
	WSACleanup();
	return 0;
}

