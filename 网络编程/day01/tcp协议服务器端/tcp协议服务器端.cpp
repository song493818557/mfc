// tcp协议服务器端.cpp : 定义控制台应用程序的入口点。
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
	nResult= WSAStartup(MAKEWORD(2, 2), &wsaDATA);
	if (nResult == SOCKET_ERROR) return false;//也可以加上if (LOBYTE(wsd.wVersion) ||	HIBYTE(wsd.wHighVersion))判断是否加载到了指定的版本
	//2.创建套接字
	int nErr = 0;
	SOCKET sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); 
	if (sock == INVALID_SOCKET)
	{
		return 0;
	}
	//3.绑定ip和端口
	sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(0x6767);
	addr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");
	nErr=bind(sock, (sockaddr *)&addr, sizeof(sockaddr_in));
	if (SOCKET_ERROR == nErr)
	{
		printf("绑定IP地址失败");
		goto over;
	}
	//4. 监听
	nErr = listen(sock, SOMAXCONN);
	if (SOCKET_ERROR == nErr)
	{
		printf("监听失败");
		goto over;
	}
	sockaddr_in addrClient;
	addrClient.sin_family = AF_INET;
	//5.处理套接字连接	accept
	int nSize = sizeof(sockaddr_in); 
	SOCKET ClinentSocket = accept(sock, (sockaddr *)&addrClient, &nSize);//当前返回值代表着哪个主机连接上来的返回信息
	while (true)
	{
		nErr = recv(ClinentSocket, buf2, sizeof(buf2), 0);
		if (nErr != SOCKET_ERROR)
		{
			printf("服务器端接受到:%s\n", buf2);
		}
		/*nErr = send(sock, buf, sizeof(buf), 0);
		if (nErr != SOCKET_ERROR)
		{
			printf("服务器端发送%s\n", buf);
		} */
	} 
over:	
	//6.关闭套接字
	closesocket(sock);
	//7.释放资源
	WSACleanup();
	return 0;
}

