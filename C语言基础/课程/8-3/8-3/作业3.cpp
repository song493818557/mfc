// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//思路：使用二进制提取个位数
uup:
	int c = 0;
	printf("请输入数字");
	scanf_s("%d", &c);  
	printf("%X\n",c);
	if (c % 7 == 0 && c%10 == 7){ 
		printf("是\n");
	}
	else
	{
		printf("否\n");
	}
	goto uup;
	return 0;

}
