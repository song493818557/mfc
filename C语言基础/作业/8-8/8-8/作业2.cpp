// 8-8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char *p[] = { "Hello", "15 pb", "change", "world" };



	for (int i = 0; i < 4; i++){
		printf("%s\n", *(p + i));

	}
	for (int i = 0; i < 4; i++){
		printf("%s\n", p[i]);

	}
	for (int i = 0; i < 4; i++){
		printf("%p\n", &p[i]);

	}
		
	return 0;
}

