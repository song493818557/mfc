// 6_04_函数指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<stdio.h>
#include <process.h>
int max(int a, int b)
{
	return (a > b ? a : b);
}
int min(int a, int b)
{
	return (a < b ? a : b);
}
int sum(int a, int b)
{
	return a + b;
}

int test(int a, int b, int(*fun)(int, int))
{
	return 88 + (fun(a, b));
}
int main()
{
	//_beginthread(); //开启多线程时会使用函数指针传参数
	printf("max=%d\n", test(1, 2, max));
	printf("min=%d\n", test(3, 4, min));
	printf("sum=%d\n", test(5, 6, sum));
	return 0;
}

