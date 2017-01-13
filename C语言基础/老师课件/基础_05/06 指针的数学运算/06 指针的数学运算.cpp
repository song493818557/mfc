// 06 指针的数学运算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Array[10] = { 0 };
	int *p1 = &Array[0];
	int *p2 = &Array[9];
	printf("%d %d %d", p1, p2, p2 - p1);
	return 0;
}

