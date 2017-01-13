// 1_06_远控(控制端).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include "stdafx.h"
/*
1. 初始化环境
2. 创建套接字
// 绑定bind
// 监听listen
// 处理accept
3. 连接服务器 connect

4. 发送数据
5. 接收数据
6. 关闭套接字
7. 清理环境

*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <fstream>
using namespace std;

int main()
{
	//1. 初始化环境
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (HIBYTE(wsd.wHighVersion) != 2 ||
		LOBYTE(wsd.wHighVersion) != 2)
	{
		goto Err;
	}
	//2. 创建套接字
	SOCKET  sToServerSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sToServerSock == INVALID_SOCKET)
	{
		goto Err;
	}
	//// 绑定bind
	//// 监听listen
	//// 处理accept
	//3. 连接服务器 connect
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(short(1234));
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.97");//记得修改为服务器IP
	int retVal = connect(sToServerSock, (sockaddr*)&servAddr, sizeof(sockaddr));
	if (retVal == SOCKET_ERROR)
	{
		goto Err;
	}

	//4. 发送数据
	char sendBuf[1024] = { 0 };
	while (true)
	{
		system("cls");
		printf("quit        退出\n");
		printf("shutdown    关机\n");
		printf("noshutdown  取消关机\n");
		printf("lookover    查看屏幕\n");

		scanf_s("%s", sendBuf, 1024);

		retVal = send(sToServerSock, sendBuf, strlen(sendBuf), 0);
		if (retVal == SOCKET_ERROR)
		{
			goto Err;
		}
		else if (!strcmp(sendBuf, "quit"))
		{
			break;
		}
		else if (!strcmp(sendBuf, "lookover"))
		{
			Sleep(300);
			//接收数据
			static int id = 0;
			char fileName[100] = { 0 };
			sprintf_s(fileName, 100, "look_%d.jpg", id++);
			ofstream outFile(fileName, ios_base::binary);
			
			while (true)
			{
				char buf[1024] = { 0 };
				Sleep(10);						//加小延时防止数据读写不完全
				retVal = recv(sToServerSock, buf, 1024, 0);
				if (retVal == SOCKET_ERROR)
				{
					outFile.close();
					break;
				}
				else if (retVal < 1024) {
					outFile.write(buf, retVal);
					outFile.close();
					break;
				}
				else
				{
					outFile.write(buf, retVal);
				}
			}

			int a = 3;
		}

	}

	//5. 接收数据
	//char recvBuf[1024] = { 0 };
	//retVal = recv(sToServerSock, recvBuf, 1024, 0);
	//if (retVal == SOCKET_ERROR)
	//{
	//	goto OVER;
	//}

Err:
	//6. 关闭套接字
	closesocket(sToServerSock);
	//7. 清理环境
	WSACleanup();
	return 0;
}
