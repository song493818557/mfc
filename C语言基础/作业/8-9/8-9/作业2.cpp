// 8-9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *myfile = NULL;
	char changge[30][20] = {"hello","wolrd","changge","changge","all","the","things","good","boy" };
	fopen_s(&myfile, "c:\\a\\file5.txt", "wb");
	fwrite(changge, sizeof(char) * 600, 1, myfile);
	fclose(myfile);
	myfile = NULL;

	fopen_s(&myfile, "c:\\a\\file4.txt", "rb");
	char changge1[30][20] = { 0 };
	fread(
		changge1, //写的起始地址
		sizeof(char) * 600, //一块的大小
		1,              //写入多少块
		myfile);
	for (int i = 0; i < 20;i++)
	{
		printf("%s",changge1[i]);
	}
	//printf("%s", changge1);
	//fclose(myfile);
	return 0;
}

