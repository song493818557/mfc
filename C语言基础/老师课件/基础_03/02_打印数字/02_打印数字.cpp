// 02_打印数字.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{


	for (int j = 1; j <=9; j++)
	{
		for (int i = 1; i <= j; i++)
		{
			printf("%d ", i);
		}
		printf("\n");
	}


	return 0;
}

