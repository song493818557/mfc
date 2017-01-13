// 04 文件读写4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE * pFile = NULL;
	int buf[20] = { 1,2,3,4,5,6,7,8,9,10 };
	fopen_s(&pFile, "D:\\4.txt", "wb");
	fwrite(
		buf, //写的起始地址
		sizeof(int) * 10, //一块的大小
		1,              //写入多少块
		pFile);
	fclose(pFile);
	int buf2[20] = {};
	fopen_s(&pFile, "D:\\4.txt", "rb+");
	//先获取文件大小
	fseek(pFile, 0, SEEK_END); //移动到文件结尾
	int nSize = ftell(pFile);  //告知文件位置,因为文件位置处于结尾，
	                           //故而得到的是文件的大小，能为读取多少次
	                           //提供信息
	int nCount = (nSize / (sizeof(int) * 10)) + 1;
	while (nCount)
	{
	fread(
		buf2, //写的起始地址
		sizeof(int) * 10, //一块的大小
		1,              //写入多少块
		pFile);
	nCount--;
	}
	fclose(pFile);
	return 0;
}

