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

	int c = 1;
uup:
	printf("%d\n", c);

	if (c < 100){
		c++;
		goto uup;
	}
	system("pause");
	return 0;

}