// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int arr[5] = { 2, 4, 6, 8, 10 };
	int *p = arr;
	printf("%d\n", *(arr + 0));
	printf("%d\n", *(arr + 1));
	printf("%d\n", *(arr + 2));
	printf("%d\n", *(arr + 3));
	printf("%d\n", *(arr + 4));
	printf("%d\n", *(arr));
	printf("%d\n", &arr);
	printf("%d\n", arr);
	return 0;


}