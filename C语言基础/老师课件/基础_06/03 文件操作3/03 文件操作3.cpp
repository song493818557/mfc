// 03 文件操作3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//写
	FILE * pFile = NULL;
	char buf[20] = { 0 };
	fopen_s(&pFile, "D:\\3.txt", "w");
	fprintf_s(pFile, "hello%dpb", 15);
	fclose(pFile);

	//读
	pFile = NULL;
	fopen_s(&pFile, "D:\\3.txt", "r");
	fscanf_s(pFile, "%s", buf, 20);
	fclose(pFile);

	return 0;
}

