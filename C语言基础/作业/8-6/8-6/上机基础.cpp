// 8-6.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
#define LENTH 10
int _tmain(int argc, _TCHAR* argv[])
{
 
	int arr[LENTH] = {0};
	for (int i = 0; i < 10;i++){
		printf("���������������ֵ,��ǰ����Ϊ%d:\n",i);
		scanf_s("%d",&arr[i],100);
	}
	int * crr = arr;
	for (int i = 0; i < 10; i++){
		printf("%d:\n", crr[i]);
		//scanf_s("%d", arr[i], 100);
	}
	return 0;
}

