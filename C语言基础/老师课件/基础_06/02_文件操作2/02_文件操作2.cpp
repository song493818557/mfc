// 02_文件操作2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char *buf  =(char*)malloc(20);
	char buf2[20] = {0};

	char * buf3 = NULL;

	FILE * pFile = NULL;
	//fopen_s(&pFile, "D:\\2.txt", "w");
	//fputs("hello 15pb", pFile);
	fopen_s(&pFile, "D:\\2.txt", "r");
	fgets(buf3, 10, pFile);

	fclose(pFile);
	return 0;
}

