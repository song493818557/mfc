// 07_杨辉三角.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Array[10][10] = { 0 };
	//1 需要将最左边的一列都赋值为1，斜着的一列赋值为1
	for (int i = 0; i < 10; i++)
	{
		Array[i][0] = 1;
	}
	for (int i = 0; i < 10; i++)
	{
		Array[i][i] = 1;
	}
	//2 求出每一个元素的值
	for (int i = 2; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			Array[i][j] = Array[i - 1][j - 1] + Array[i - 1][j];
		}
	}
	//3 遍历输出
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j <= i; j++)
		{
			printf("%5d", Array[i][j]);
		}
		printf("\n");
	}
	return 0;
}

