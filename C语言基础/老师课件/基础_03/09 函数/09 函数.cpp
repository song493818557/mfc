// 09 ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void shuchu()
{
	printf("hello15pb");
}

int panduan(int Num)
{
	if (Num%2 == 0)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	shuchu();
	int a = panduan(5);

	return 0;
}

