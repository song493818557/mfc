// 6_04_����ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//_beginthread(); //�������߳�ʱ��ʹ�ú���ָ�봫����
	printf("max=%d\n", test(1, 2, max));
	printf("min=%d\n", test(3, 4, min));
	printf("sum=%d\n", test(5, 6, sum));
	return 0;
}

