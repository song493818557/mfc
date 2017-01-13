// 05 函数的默认参数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int Add(int a, int b, int c = 0, int d = 0)
{
	return a + b + c + d;
}

int Add(int a,int b)
{
	return a + b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Add(1, 2);//当使用默认参数，与函数重载时，需要注意一下二义性的问题


	Add(1, 2,3);
	Add(1, 2, 3,4);
	return 0;
}

