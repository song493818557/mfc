// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
#include<stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//思路：使用二进制提取个位数

	int c = 1;
	int a = 1;
	char b;
uup:
	//printf("%s\n", b);

	if (a < 6){
		c = a;

	iip:
		if (c != 0){
		//	b = "\t" + c;
			printf("%d  ",a);
			c--;
			goto iip;
		}
		a++;
		printf("\n");
		goto uup;
	}
	system("pause");
	return 0;

}
