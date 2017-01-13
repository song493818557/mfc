// 05_悬空指针问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <Windows.h>

typedef void(*P)();

int _tmain(int argc, _TCHAR* argv[])
{
	//int *p = (int*)malloc(sizeof(int));
	//free(p);
	//P = NULL;在释放了内存之后，最好及时赋值为NULL
	// …  do something
	//*p = 7;//使用了悬空指针

	int *p1;//没有被初始化的指针，叫做野指针

	return 0;
}

