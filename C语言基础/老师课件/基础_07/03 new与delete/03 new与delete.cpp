// 03 new与delete.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	int* p1 = (int *)malloc(sizeof(int) * 15);//原来的方式
	//malloc是一个函数

	int* p2 = new int[15];//新的方式
	int* p3 = new int(15);//也不报错，但是只申请了一个int型
	
	//new 是一个运算符

	free(p1);//原来的方式

	delete  []p2;//假如申请多个空间的话，需要加上[]
	delete  p3;//只申请了一个，释放的时候就不用加[]


		
	return 0;
}

