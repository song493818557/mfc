// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//˼·��ʹ�ö�������ȡ��λ��
uup:
	int c = 0;
	printf("����������");
	scanf_s("%d", &c);  
	printf("%X\n",c);
	if (c % 7 == 0 && c%10 == 7){ 
		printf("��\n");
	}
	else
	{
		printf("��\n");
	}
	goto uup;
	return 0;

}
