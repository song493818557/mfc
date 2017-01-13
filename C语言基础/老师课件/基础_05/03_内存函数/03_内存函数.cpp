// 03_内存函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>
int _tmain(int argc, _TCHAR* argv[])
{
	short *p =(short*) malloc(sizeof(short) * 10);//申明内存空间
	memset(
		p,//设置内存的起始地址
		0, //设置的值
		sizeof(short) * 10//大小
		);
	short *p2 = (short*)malloc(sizeof(short) * 10);
	memcpy(
		p2,//拷贝的目标地址
		p, //拷贝的源地址
		sizeof(short) * 10
		);



	return 0;
}

