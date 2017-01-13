// 8-9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *myfile = NULL;
	char changge[100] = { 0 };
	fopen_s(&myfile, "c:\\a\\file3.txt", "wb");
	scanf_s("%s", &changge,100);
	fwrite(changge, sizeof(char) * 100, 1, myfile);
	fscanf_s(myfile, "%s", changge, 100);
	printf("%s", changge);
	fclose(myfile);
	myfile = NULL;

	fopen_s(&myfile, "c:\\a\\file3.txt", "rb");
	char changge1[100] = { 0 };
	fread(
		changge1, //写的起始地址
		sizeof(char) * 100, //一块的大小
		1,              //写入多少块
		myfile);
	printf("%s", changge1);
	fclose(myfile);
	return 0;
}

