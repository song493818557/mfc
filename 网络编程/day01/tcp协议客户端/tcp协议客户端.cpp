// tcp协议客户端.cpp : 定义控制台应用程序的入口点。
//  
#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")
int _tmain(int argc, _TCHAR* argv[])
{
	//1.指定需要使用的winsock规范的最高版本,并初始化winsock,装入winsock.dll
	WSADATA wsaDATA = { 0 };
	int nResult = 0;
	nResult = WSAStartup(MAKEWORD(2, 2), &wsaDATA);
	if (nResult == SOCKET_ERROR) return false;//也可以加上if (LOBYTE(wsd.wVersion) ||	HIBYTE(wsd.wHighVersion))判断是否加载到了指定的版本
	//2.创建套接字
	int nErr = 0;
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sock == INVALID_SOCKET)
	{
		return 0;
	}
	//3.绑定ip和端口
	sockaddr_in addr = {0};
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0x6767);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	  
	//4.连接服务器端 
	nErr = connect(sock, (sockaddr *)&addr, sizeof(sockaddr_in));
	if (SOCKET_ERROR == nErr)
	{
		printf("服务器未开启");
		goto over;
	}
	char buf[100] = "hello socket server, from client!";
	char buf2[100] = "xxxxxxxxxxxxxxxclient";
	while (true)
	{ 
		  nErr = send(sock, buf2, sizeof(buf2), 0);
		if (nErr != SOCKET_ERROR)
		{
			printf("客户端发送:%s\n", buf2);
		}
		/*nErr = recv(sock, buf, sizeof(buf), 0);
		if (nErr != SOCKET_ERROR)
		{
		printf("客户端接受:%s\n", buf);
		}*/
	}
over:
	//7.关闭套接字
	closesocket(sock);
	//8.释放资源
	WSACleanup();
	return 0;
}


