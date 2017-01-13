// 8-5.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
void hello(int b){
	if (b % 2 == 0){
		char aaa =  'yes';
	 
	}
	else{
		char aaa = 'no';
		 
	}
	
}

int _tmain(int argc, _TCHAR* argv[])
{

	//int t = 0;
	//int aar[6][100] = { { 1, 2, 3, 4, 5, 6 }, { 2, 2, 3, 4, 5, 6 }, { 3, 2, 3, 4, 5, 6 }, { 4, 2, 3, 4, 5, 6 }, { 5, 2, 3, 4, 5, 6 }, { 6, 2, 3, 4, 5, 6 } };
	//int bar[6][100];
	//for (int i = 0; i < 6; i++)
	//{
	//	for (t = 0; t < 7; t++)
	//	{ 
	//		bar[i][t] = aar[i][t];
	//		 
	//	}

	int a = 0;
	char aaa = 1;
	printf("请输入一个数字");
	scanf_s("%d", &a);
	hello(a);
	printf("%d",aaa);
	system("pause");
	return 0;
}

