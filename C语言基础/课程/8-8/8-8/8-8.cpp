// 8-8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <crtdbg.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
typedef void(* signal(int signum, void(*handler)(int)))(int);
signal;
int _tmain(int argc, _TCHAR* argv[])
{
	char *str1 = "hello 15pb";
	//int temp = ;
	char *str2 = (char*)malloc(strlen(str1));
//	strcpy(str2,str1);//通过字符串拷贝 值不可用 需要使用 内存拷贝
	memset(
		str2,//设置内存的起始地址
		*str1, //设置的值
		sizeof(short) * 10//大小
		);
	memcpy(
		str1,//拷贝的目标地址
		str2, //拷贝的源地址 
		sizeof(short) * 10
		);
	printf("%d\n", str2);
	return 0;
}

