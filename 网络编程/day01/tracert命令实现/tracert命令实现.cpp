// tracert����ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h" 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <iphlpapi.h>
#pragma comment(lib,"iphlpapi.lib") 
CRITICAL_SECTION g_critical;  //�ٽ��������ƶ��̴߳�ӡ˳��
bool checkActive(in_addr ip){
	u_long dstMac[2] = { 0xff };
	u_long size = 6;
	//HRESULT
	DWORD re = SendARP(ip.S_un.S_addr, 0, dstMac, &size); 
	if (re == NO_ERROR && size == 6){
		EnterCriticalSection(&g_critical);  //�߳̽����ٽ����������̲߳����ٽ��룬���ƶ��߳��ڽ����ϵĴ�ӡ˳��
		printf("�������� : %-15s mac:", inet_ntoa(ip));
		byte *bphysAddr = (byte *)&dstMac;
		for (int i = 0; i < (int)size;i++)
		{
			if (i == (size - 1))
			{
				printf("%.2x\n",(int)bphysAddr[i]);
			}
			else
			{
				printf("%.2x-", (int)bphysAddr[i]);
			}
		}
		LeaveCriticalSection(&g_critical);  //�߳��뿪�ٽ����������߳��ܹ���������
	}   
	return 0;
}
DWORD WINAPI threadProc(LPVOID lpThreadParameter){
	in_addr ip;
	ip.S_un.S_addr = (u_long)lpThreadParameter;
	checkActive(ip);
	return 0;
} 
int _tmain(int argc, _TCHAR* argv[])
{ 
	in_addr ip_start, ip_stop;//������ʼIP
	ip_start.S_un.S_addr = inet_addr("192.168.1.1");
	ip_stop.S_un.S_addr = inet_addr("192.168.1.255");
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	//ѭ��̽������ 
	InitializeCriticalSection(&g_critical);
	for (in_addr ip = ip_start; ip.S_un.S_addr < ip_stop.S_un.S_addr;  ip.S_un.S_un_b.s_b4++)
	{
		CreateThread(NULL, 0, threadProc, (LPVOID)ip.S_un.S_addr, 0, 0);
		//threadProc((LPVOID)ip.S_un.S_addr); 
	}
	WSACleanup(); 
	getchar();
	return 0;
}

