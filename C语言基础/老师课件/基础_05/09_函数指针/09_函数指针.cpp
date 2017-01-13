// 09_函数指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//int INT  定义变量
//typedef int INT; 给int一个别名

//int(*FUN)(int); //定义一个指针变量。



//struct _HEHE{
//	int a;
//	int b;
//}stc1;       //定义一个变量 stc1


typedef struct _HEHE{
	int a;
	int b;
}HEHE; //给_HEHE这个类型起一个别名
HEHE g_hehe;

struct _HEHE g_hehe2;

typedef int(*FUN)(int);//给这个类型起一个名字

int Fun(int n,int m)
{
	printf("Hello %dPB\n",n);
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{


	int a;
	Fun(15);
	FUN p = Fun;

	p(16);
	return 0;
}

