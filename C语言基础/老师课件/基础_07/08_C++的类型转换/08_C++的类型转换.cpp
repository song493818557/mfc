// 08_C++的类型转换.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int  a = 0;
	short b = 100;
	a = b;
	b = (short)a;//能自动转换的，加强转是为起到提示作用

	int * p = NULL;
	p = (int *)a;//不能自动转换的，比需加上强转


	const int c = 0;
	
	//int  *  p2 = (int *)&c;
	//*p2 = 200;
	int  *  p2  = const_cast<int *>(&c);//去掉常量属性

	int c = 100;
	short d = 0;

	d = static_cast<short>(c);


	int * p3 = NULL;
	p3 = reinterpret_cast<int*>(a);//


	return 0;
}

