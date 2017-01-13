// 客户端.cpp : 定义控制台应用程序的入口点。
//

// day01.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
/*

*/
bool InitTCP(){
	//1 初始化环境   wsastartup 
	WSADATA wsd = { 0 };
	int re = 0;
	int nResult = WSAStartup(MAKEWORD(2, 2), &wsd);//使用WINSOCK2.2版
	if (nResult == SOCKET_ERROR)//判断是否调用成功
	{
		return FALSE;
	}
	if (LOBYTE(wsd.wVersion) ||
		HIBYTE(wsd.wHighVersion)
		)//判断是否调用的是2.2版本
	{
		return 0;
	}

	//2 创建套接字   socket 
	//AF_INET 包含 TCP 和UDP
	//TCP : SOCK_STREAM 流式 配合IPPROTO_TCP
	//udp:SOCK_DGRAM 数据报 配合IPPROTO_UDP
	SOCKET sToservSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);//!!
	if (sToservSock == INVALID_SOCKET){
		return 0;
	}
	//3 绑定套接字	connect
	// 绑定套接字  
	//sin_family  AF_INET 包含 TCP 和UDP
	//sin_port  需要变换的端口 htons htons函数转换u_short从主机到TCP / IP网络字节顺序(大端)。
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
	//4  监听套接字	listen
	
	//5 处理套接字	accept
	 
	//6 收发数据		send
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
	//7 关闭套接字	closesocket
	closesocket(sToservSock);
	//8 清零环境		wsacleanup
	WSACleanup();
	return 0;
}
int _tmain(int argc, _TCHAR* argv[])
{

	return 0;
}


