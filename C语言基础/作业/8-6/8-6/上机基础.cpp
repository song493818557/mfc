// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#define LENTH 10
int _tmain(int argc, _TCHAR* argv[])
{
 
	int arr[LENTH] = {0};
	for (int i = 0; i < 10;i++){
		printf("请依次输入数组的值,当前次数为%d:\n",i);
		scanf_s("%d",&arr[i],100);
	}
	int * crr = arr;
	for (int i = 0; i < 10; i++){
		printf("%d:\n", crr[i]);
		//scanf_s("%d", arr[i], 100);
	}
	return 0;
}

