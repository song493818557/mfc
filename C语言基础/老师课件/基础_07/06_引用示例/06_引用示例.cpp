// 06_引用示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


void swap(int* p1, int *p2)
{
	int Temp = 0;
	Temp = *p1;
	*p1 = *p2;
	*p2 = Temp;
}
void swap(int& Num1, int& Num2)
{
	int Temp = 0;
	Temp = Num1;
	Num1 = 100;
	Num2 = Temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int Num1 = 0;
	int Num2 = 100;
	int &N = Num1; // 相当于给Num起了一个别名，叫做N
	//int &M ;//错误的，引用必须初始化

	N = Num2;//引用一经初始化之后，就无法引用其他变量了，这么写的话
	         //是在赋值


	int a = 20;
	int b = 10;
	swap(&a, &b);

	swap(a, b);

	return 0;
}

