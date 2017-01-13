// 基础_06.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Array[10];
	
	//数组名是数组的首地址，类型是一级指针

	//&Array数值还是首地址，类型数组指针

	int(*p)[10] = NULL;//数组指针
	int *p[10];        //指针数组
	int **p;           //二级指针
	void(*fun)(int, int);//函数指针，注意函数原型




	return 0;
}

