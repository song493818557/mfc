// 04_函数重载的例子.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//函数重载说的是，同名函数，但是函数参数不同，调用的时候
//编译器会自动匹配合适的函数

//加上extern "C"，就是在以C的方式使用函数，不会进行名称粉碎，
//也就不支持函数重载
extern "C" int Add(int a, int b)
{
	printf("我是两个int型参数\n");
	return a + b;
}

extern "C" int Add(int a, char b)
{
	printf("我是一个int型参数，一个char型参数\n");
	return a + b;
}

//char Add(int a, int b)//返回值类型不同，不能构成重载
//{
//	printf("我是两个int型参数\n");
//	return a + b;
//}



int _tmain(int argc, _TCHAR* argv[])
{
	Add(1, 2);
	Add(1, 'A');
	return 0;
}

