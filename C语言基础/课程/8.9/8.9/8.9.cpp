// 8.9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>


int _tmain(int argc, _TCHAR* argv[])
{
	//FILE* fope=fopen("c:\\File.txt","r");
	FILE * fope = NULL;
		int i = fopen_s(&fope, "c:\\a\\file.txt","w+");
		//文件相关操作
		fputc('xxx',fope);
		//关闭文件
		fclose(fope);
	return 0;
}

