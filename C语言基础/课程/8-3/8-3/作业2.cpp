// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
uup:
	int c = 0;
	printf("������һ�����ж��Ƿ�Ϊ3");
	scanf_s("%d", &c);
	if (c % 3 == 0 && c != 0){
		printf("��\n");
	}
	else
	{
		printf("��\n");
	}
	goto uup;
	return 0;

}
