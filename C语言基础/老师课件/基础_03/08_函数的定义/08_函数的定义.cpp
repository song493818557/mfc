// 08_�����Ķ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//int Max(int a, int b);//���纯�������ڵ��ú���֮��Ļ���������ǰ���������

int Max(int a, int b)
{
	if (a>b)
	{
		return a;
	}
	else
	{
		return b;
	}
}

int Test(int num)
{
	int a;
	num = 200;
	Max(10, 20);
	return 50;
}
int _tmain(int argc, _TCHAR* argv[])
{

	int m = 0;
	Test(m); 
	printf("%d",m);
	return 0;
}

