// 05 goto.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int a = 0;
sign:
	a+=100000;
	printf("%d  ", a);
	if (a > 0)
	{
		goto sign;
	}


	return 0;
}

