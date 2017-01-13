// 01_文件操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//FILE* pfile = fopen("D:\\1.txt", "r");//这个是非安全版的
	//打开文件
	FILE * pFile = NULL;
	fopen_s(&pFile, "D:\\1.txt", "w");
	//文件相关操作
	fputc('1', pFile);
	fputc('5', pFile);
	fputc('p', pFile);
	fputc('b', pFile);
	//关闭文件
	fclose(pFile);

	//打开文件
	pFile = NULL;
	fopen_s(&pFile, "D:\\1.txt", "r");

	//文件相关操作
	while (true)
	{
		char cCh = fgetc( pFile);
		if (feof(pFile))//结束是非0，没结束是0
		{
			break;
		}
		printf("%c", cCh);
	}
	//关闭文件
	fclose(pFile);



	return 0;
}

