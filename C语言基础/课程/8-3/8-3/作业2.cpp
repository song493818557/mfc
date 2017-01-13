// 8-3.cpp : 定义控制台应用程序的入口点。
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
	printf("请输入一个数判断是否为3");
	scanf_s("%d", &c);
	if (c % 3 == 0 && c != 0){
		printf("是\n");
	}
	else
	{
		printf("否\n");
	}
	goto uup;
	return 0;

}
