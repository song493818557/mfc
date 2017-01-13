// day003 ping.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "data.h"
//发送ICMP协议
void sendtoEchorequest(SOCKET sock, sockaddr_in dstIP){
	static int id = 1;
	static int seq = 1;

	//设置icmp协议头
	ECHOREQUEST echorequest = { 0 };
	echorequest.time = GetTickCount();
	echorequest.icmpheader.i_id = id++;
	echorequest.icmpheader.i_seq = seq++;
	echorequest.icmpheader.i_type = 8;
	echorequest.icmpheader.i_code = 0;
	echorequest.icmpheader.i_checksum = checksum((u_short *)&echorequest, sizeof(echorequest));	
	//发送icmp协议
	int size = sizeof(sockaddr);
	int re = sendto(sock, (char *)&echorequest, sizeof(ECHOREQUEST), 0, (sockaddr *)&dstIP, sizeof(dstIP));
	if (re == SOCKET_ERROR) printf("sendto error");
	return;
}
//接受ICMP协议
void recvfromEchorequest(SOCKET sock, ECHORESPONSE * sponse, sockaddr_in  *dstIP){
	int size = sizeof(sockaddr);
	int re = recvfrom(sock, (char *)  sponse, sizeof(ECHORESPONSE), 0, (sockaddr  *)&dstIP, &size);
	if (re == SOCKET_ERROR) { printf("recvfrom error"); }
	return;

}
void Ping(char * host){
	SOCKET sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP); //开启原始套接字
	HOSTENT	*lphost = gethostbyname(host);	//获取本地的IP地址
	sockaddr_in dstIP = { 0 };
	dstIP.sin_family = AF_INET;
	dstIP.sin_addr.S_un.S_addr = *(u_long *)lphost->h_addr;//强转成IP地址
	for (int i=0; i < 4;i++)
	{
		//发送数据
		sendtoEchorequest(sock, dstIP);
		//接受数据
		ECHORESPONSE echoresponse = { 0 };
		recvfromEchorequest(sock, &echoresponse,&dstIP);
		int time = echoresponse.echorequest.time;
		//打印结果 来自 61.135.169.125 的回复: 字节=32 时间=28ms TTL=56
		printf("来自 %s 的回复: 字节=32 时间=%sms TTL=22");
		printf("来自 %s 的回复: 字节=32 时间=%sms TTL=22",
			inet_ntoa(dstIP.sin_addr),
			GetTickCount() - time);

	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	WSADATA wsadata;
	WSAStartup(MAKEWORD(2, 2), &wsadata);
	while (1)
	{
		Ping("www.15pb.com");
		char in = getchar();
		if (in == 'q')  break;
	}
	return 0;
}

