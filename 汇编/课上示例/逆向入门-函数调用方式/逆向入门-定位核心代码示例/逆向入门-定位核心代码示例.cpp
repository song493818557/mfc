// ��������-��λ���Ĵ���ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <windows.h>


int _tmain(int argc, _TCHAR* argv[])
{
	printf("����������:");
	char buff[ 20 ];
	scanf_s("%s" , buff , 20);


	if(strcmp(buff , "hello15pb") == 0)
	{
		printf("������ȷ\n");
	}
	else
	{
		MessageBoxW(0 , L"�������" , L"��ʾ" , 0);
	}


	return 0;
}

