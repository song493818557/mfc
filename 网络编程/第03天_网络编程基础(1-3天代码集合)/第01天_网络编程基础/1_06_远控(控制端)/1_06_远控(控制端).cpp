// 1_06_Զ��(���ƶ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include "stdafx.h"
/*
1. ��ʼ������
2. �����׽���
// ��bind
// ����listen
// ����accept
3. ���ӷ����� connect

4. ��������
5. ��������
6. �ر��׽���
7. ������

*/

#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <fstream>
using namespace std;

int main()
{
	//1. ��ʼ������
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (HIBYTE(wsd.wHighVersion) != 2 ||
		LOBYTE(wsd.wHighVersion) != 2)
	{
		goto Err;
	}
	//2. �����׽���
	SOCKET  sToServerSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sToServerSock == INVALID_SOCKET)
	{
		goto Err;
	}
	//// ��bind
	//// ����listen
	//// ����accept
	//3. ���ӷ����� connect
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons(short(1234));
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.97");//�ǵ��޸�Ϊ������IP
	int retVal = connect(sToServerSock, (sockaddr*)&servAddr, sizeof(sockaddr));
	if (retVal == SOCKET_ERROR)
	{
		goto Err;
	}

	//4. ��������
	char sendBuf[1024] = { 0 };
	while (true)
	{
		system("cls");
		printf("quit        �˳�\n");
		printf("shutdown    �ػ�\n");
		printf("noshutdown  ȡ���ػ�\n");
		printf("lookover    �鿴��Ļ\n");

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
			//��������
			static int id = 0;
			char fileName[100] = { 0 };
			sprintf_s(fileName, 100, "look_%d.jpg", id++);
			ofstream outFile(fileName, ios_base::binary);
			
			while (true)
			{
				char buf[1024] = { 0 };
				Sleep(10);						//��С��ʱ��ֹ���ݶ�д����ȫ
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

	//5. ��������
	//char recvBuf[1024] = { 0 };
	//retVal = recv(sToServerSock, recvBuf, 1024, 0);
	//if (retVal == SOCKET_ERROR)
	//{
	//	goto OVER;
	//}

Err:
	//6. �ر��׽���
	closesocket(sToServerSock);
	//7. ������
	WSACleanup();
	return 0;
}
