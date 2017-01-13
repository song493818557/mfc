// 06_遍历输出二维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Array[3][4] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12 };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d", Array[i][j]);
		}
		printf("\n");
	}

	/*for (int j = 0; j < 4; j++)
	{
		printf("%d", Array[1][j]);
	}
	for (int j = 0; j < 4; j++)
	{
		printf("%d", Array[2][j]);
	}*/
	return 0;
}

