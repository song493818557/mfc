// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
//小大
void change(int arrc[],int n ){

	 
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n-1; j++){
			if (arrc[j] > arrc[j + 1])
			{
				int temp = arrc[j];
				arrc[j] = arrc[j + 1];
				arrc[j + 1] = temp;
			}
		}

	}
	
	return;
}
//大小
void changea(int arrc[],int n ){

	 
	for (int i = 0; i <= n; i++){
		for (int j = 0; j <= n-1; j++){
			if (arrc[j] < arrc[j + 1])
			{
				int temp = arrc[j];
				arrc[j] = arrc[j + 1];
				arrc[j + 1] = temp;
			}
		}

	}
	
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int arc[25] = { 2, 23, 34, 15, 56, 66, 67, 77, 7, 3, 2, 19, 21, 13, 4, 5, 6, 7, 8, 9, 10, 11 };
	int tmp = 0;
	tmp = _countof(arc) - 1;
	changea(arc, tmp);
	system("pause");
	return 0;
}