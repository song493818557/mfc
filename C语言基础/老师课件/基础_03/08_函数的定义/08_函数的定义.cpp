// 08_函数的定义.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//int Max(int a, int b);//假如函数定义在调用函数之后的话，可以在前面加声明。

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

