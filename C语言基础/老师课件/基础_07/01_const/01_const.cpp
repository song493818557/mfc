// 01_const.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int a = 10;
	int Arrayp[a] = {1,2,3,4};
	int b = 0;
//	a = 100;  常量不能修改
	//第一种情况
	int const * p1 = NULL;
	 //p是变量，可以指向新的位置
	p1 = &b;
	//*p = 100;//错误的，不能通过*p修改指向的位置
	//第二种情况
	const int  *  p2 = NULL;
	//同上
	//第三种情况
	int  * const p3 = NULL;
	//p3 = &b;//错误的，p3是常量，不能指向新的位置
	*p3 = 100;//正确的
	return 0;
}

