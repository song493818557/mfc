// 03_������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{ 
	int nYear = 0;
	printf("������һ�����:");
	scanf_s("%d", &nYear);
	nYear++;
	if (nYear%4==0)
	{
		if (nYear % 100 == 0)
		{
			if (nYear%400 == 0)
			{
				printf("������");
			}
			else
			{
				printf("��������");
			}
		}
		else
		{
			printf("������");
		}
	}
	else
	{
		printf("��������");
	}

	//����2��
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		printf("������");
	}
	else
	{
		printf("��������");
	}
	return 0;
}

