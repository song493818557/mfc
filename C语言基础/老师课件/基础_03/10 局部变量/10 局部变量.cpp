// 10 局部变量.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int NumA = 10;

	if (5>3)
	{
		int NumA = 5;
		int NumB = 100;
		printf("%d", NumA);//使用的是小范围的NumA
	}
	printf("%d", NumA);//使用的是大范围的NumA
	//printf("%d", NumB);//无法使用离开了作用域的NumB
	return 0;
}

void Fun()
{
	//printf("%d", NumA);//错误的，局部变量只能在自己的函数的{}里使用
}