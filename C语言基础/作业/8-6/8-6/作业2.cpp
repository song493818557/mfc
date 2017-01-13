// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	/* 非数组土方法
	int a = 0; int b = 0; int c = 0;
	int *aa, *bb , *cc;
	aa = &a;
	bb = &b;
	cc = &c;
	int maxa, maxb, maxc;
	printf("请依次输入数字:\n");
	scanf_s("%d",aa,100);
	printf("请依次输入数字:\n");
	scanf_s("%d", bb, 100);
	printf("请依次输入数字:\n");
	scanf_s("%d", cc, 100);
		if (*aa > *bb) { maxa = *aa; maxb = *bb; }
		else { maxa = *bb;  maxb = *aa;  }
		if (*cc > maxa) { maxa = *cc; maxb = *aa; maxc = *bb; }
		else{
		if (*cc > maxb){ maxb = *cc; maxc = *bb;}
		else{ maxc = *cc;   }
		}

		printf("%d %d %d", maxa,maxb,maxc);
		*/
	int a[3] = {0};
	int  *arr;
	arr = a;
	printf("请输入依次输入3个数字");
	int temp = 0;
	scanf_s("%d", &arr[0]);
	scanf_s("%d",  &arr[1]);
	scanf_s("%d", &arr[2]);
	for (int i = 0; i < 3;i++){
		for (int j = 0; j < 2; j++){
			if (arr[j] > arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}

	}
	return 0;
}

