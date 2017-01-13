// 8-9.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//int allchange(char a[100], char b[100], int(*xall)(char a[100], char b[100])){
//
//	return(xall(a, b));
//}
void callall(char aa[100], char b[100], void(*xall)(char aa[100], char b[100])){

	return xall( aa,  b);
}
void X(char afrom[100],char ato[100]){
	FILE *myfile = NULL;
	fopen_s(&myfile, afrom, "rb");
	char changge1[600] = { 0 };
	fread(
		changge1, //写的起始地址
		sizeof(char) * 600, //一块的大小
		2,              //写入多少块
		myfile);
	fclose(myfile);
	//char changge[10] = { "hello", "wolrd", "changge", "changge", "all", "the", "things", "good", "boy" };
	myfile = NULL;
	fopen_s(&myfile, ato, "wb");
	//char changge[100] = {  };
	fwrite(changge1, sizeof(char) * 600, 1, myfile);
	fclose(myfile);
	myfile = NULL;
	fopen_s(&myfile, afrom, "w+b");
	char changge[100] = {};
	fwrite(changge, 0, 1, myfile);
	fclose(myfile);

}

void C(char afrom[100], char ato[100]){
	FILE *myfile = NULL;
	fopen_s(&myfile, afrom, "rb");
	char changge1[600] = { 0 };
	fread(
		changge1, //写的起始地址
		sizeof(char) * 600, //一块的大小
		1,              //写入多少块
		myfile);
	fclose(myfile);
	//char changge[10] = { "hello", "wolrd", "changge", "changge", "all", "the", "things", "good", "boy" };
	myfile = NULL;
	fopen_s(&myfile, ato, "wb");
	char changge[100] = { 0 };
	fwrite(changge1, sizeof(char) * 600, 1, myfile);
	fclose(myfile);
	myfile = NULL;

}
int _tmain(int argc, _TCHAR* argv[])
{
	
	/*char cc[100] = {};
	char *dd =0;
	dd = cc;
 	scanf_s("%s",  cc,100);*/
//	callall("c:\\a\\file5.txt", "c:\\a\\filexxx.txt", X);
	callall("c:\\a\\file5.txt", "c:\\a\\filexxx.txt", X);
	
	/*for (int i = 0; i < 20;i++)
	{
		printf("%s",changge1[i]);
	}*/
	//printf("%s", changge1);
	//fclose(myfile);
	return 0;
}

