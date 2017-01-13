// 13_类和结构体的区别1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

struct CTest
{
	
	void fun()
	{
		printf("helloworld");
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.fun();
	return 0;
}

