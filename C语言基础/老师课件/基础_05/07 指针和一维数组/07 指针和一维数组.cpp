// 07 ָ���һά����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int main(void)
{
	int a[5] = { 1, 2, 3, 4, 5 };
	int i;
	int* p;
	for (i = 0; i<5; i++)
	{
		printf("a[%d]=%d, *(a+%d)=%d\n", i, a[i], i, *(a + i));
		printf("&a[%d]=%p, a+%d=%p\n", i, &a[i], i, a + i);
	}
	for (p = a; p<a + 5; p++)
	{
		printf("address:%p, value:%d\n", p, *p);
	}
	return 0;
}
