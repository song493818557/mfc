// 3_02_�������ɨ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS

#include <winsock2.h>
#pragma comment(lib,"ws2_32.lib")
#include <iphlpapi.h>
#pragma comment(lib,"iphlpapi.lib")
#include <vector>
using std::vector;
bool checkActive(in_addr ip)
{
	ULONG dstMac[2] = { 0 };
	memset(dstMac,0xff,sizeof(dstMac));
	ULONG size = 6;
	HRESULT re = SendARP(ip.S_un.S_addr,0, dstMac,&size);
	if (re == NO_ERROR)
	{
		return true;
	}
	else {
		return false;
	}
}

DWORD WINAPI threadProc(LPVOID lpThreadParameter)
{
	in_addr ip;
	ip.S_un.S_addr = (ULONG)lpThreadParameter;

	if (checkActive(ip))
	{
		printf("���ִ������ : %s \n", inet_ntoa(ip));
	}
	return 0;
}

int main()
{
	 
	vector<in_addr> ipvect;//��һ��ר�ű���IP��VECTOR
	
	in_addr ip_start;
	in_addr ip_end; 
	ip_start .S_un.S_addr = inet_addr("192.168.1.1");
	ip_end.S_un.S_addr = inet_addr("192.168.1.255"); 
	//ѭ��̽������
	for (in_addr ip = ip_start;
		 ip.S_un.S_addr < ip_end.S_un.S_addr;
		 ip.S_un.S_un_b.s_b4++)
	{
		//�������߳�
		CreateThread(NULL,0, threadProc, (LPVOID)ip.S_un.S_addr,0,0);
			
	}
    getchar();
    return 0;
}

