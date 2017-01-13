// tracert命令实现.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h" 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <iphlpapi.h>
#pragma comment(lib,"iphlpapi.lib") 
CRITICAL_SECTION g_critical;  //临界区，控制多线程打印顺序
bool checkActive(in_addr ip){
	u_long dstMac[2] = { 0xff };
	u_long size = 6;
	//HRESULT
	DWORD re = SendARP(ip.S_un.S_addr, 0, dstMac, &size); 
	if (re == NO_ERROR && size == 6){
		EnterCriticalSection(&g_critical);  //线程进入临界区，其他线程不能再进入，控制多线程在界面上的打印顺序
		printf("发现主机 : %-15s mac:", inet_ntoa(ip));
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
		LeaveCriticalSection(&g_critical);  //线程离开临界区，其他线程能够继续进入
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
	in_addr ip_start, ip_stop;//设置起始IP
	ip_start.S_un.S_addr = inet_addr("192.168.1.1");
	ip_stop.S_un.S_addr = inet_addr("192.168.1.255");
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	//循环探测主机 
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

