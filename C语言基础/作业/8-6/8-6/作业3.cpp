// 8-6.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdio.h"
#include <stdlib.h>
void change(int array[],int n){
	int temp = 0;
	for (int i = 0; i <= n / 2; i++){
		array[i] = array[i] + array[n - i];
		array[n - i] = array[i] - array[n - i];
		array[i] = array[i] - array[n - i];
	}
	int aac = 0;
	return;
}
int _tmain(int argc, _TCHAR* argv[])
{
	
	int arc[25] = {2,3,4,5,56,6,67,7,7,3,2,1,1,13,4,5,6,7,8,9,10,11};
	int tmp = 0;
	tmp = _countof(arc)-1;
	change(arc, tmp);
	 
	printf("%d",arc);
	
	return 0;
}

