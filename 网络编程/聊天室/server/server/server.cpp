// server.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include "Cui.h" 
using std::cout;
using std::cin;
using std::string;
using std::endl;
//#include <WinSock2.h>
int _tmain(int argc, _TCHAR* argv[])
{
	Cmenu menu;
	menu.main_draw();
	menu.main_menu(1);
	Cui ui;
	 read_map();
	 draw_map();
	  
	/************************************************************************/
	/* 数据库连接测试*/
	/************************************************************************/
	Cmysql db;//创建DB对象
	db.LinkDataBase(
		"MYSQL",
		"game_info",
		"root",
		"888888"); //连接数据库

	_RESULT result;
	char strLink[MAX_PATH] = { 0 };

	db.ExeSqlByConnect(result, "select * from chat_ui");
	//ui.show();

	Cbase64 base;
	char  bb[] = "admin";
	string aa = base.base64_encode(bb, 5);
	aa = base.base64_decode(aa);
	printf("%s", aa.c_str());
	
	//cout << aa;


//	// 1. 初始化环境		wsastartup
//	WSADATA wsd = { 0 };
//	int re = WSAStartup(MAKEWORD(2, 2), &wsd);
//	if (re != 0) { return 0; }
//	if (LOBYTE(wsd.wVersion) != 2 ||
//		HIBYTE(wsd.wVersion) != 2)
//	{
//		return 0;
//	}
//	// 2. 创建套接字     socket
//	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
//	if (listenSock == INVALID_SOCKET)
//	{
//		return 0;
//	}
//	// 3. 绑定套接字		bind
//	sockaddr_in serverAddr;
//	serverAddr.sin_family = AF_INET;
//	serverAddr.sin_port = htons(0x5566);
//	serverAddr.sin_addr.S_un.S_addr = inet_addr("127.0.0.1");//127.0.0.1
//
//	re = bind(listenSock, (sockaddr *)&serverAddr, sizeof(serverAddr));
//	if (re == SOCKET_ERROR)
//	{
//		printf("bind error");
//		goto over;
//	}
//	// 4. 监听套接字		listen
//	re = listen(listenSock, SOMAXCONN);
//	if (re == SOCKET_ERROR)
//	{
//		printf("listen error");
//		goto over;
//	}
//	// 5. 处理套接字连接	accept
//	sockaddr_in clientAddr;
//	int size = sizeof(clientAddr);
//	SOCKET sToClientSock = accept(
//		listenSock, (sockaddr *)&clientAddr, &size);
//	if (sToClientSock == INVALID_SOCKET)
//	{
//		printf("listen error");
//		goto over;
//	}
//	// 6. 发送接收数据	send/recv
//	char buf[100] = "hello socket client,from server!";
//	re = send(sToClientSock, buf, strlen(buf), 0);
//	if (re == SOCKET_ERROR)
//	{
//		goto over;
//	}
//	re = recv(sToClientSock, buf, sizeof(buf), 0);
//	if (re == INVALID_SOCKET)
//	{
//		goto over;
//	}
//over:
//	// 7. 关闭套接字		closesocket
//	closesocket(listenSock);
//	closesocket(sToClientSock);
//	// 8. 清理环境		wsacleanup
//	WSACleanup();
	return 0;
}

