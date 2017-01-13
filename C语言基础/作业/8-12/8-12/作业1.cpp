// 8-12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::endl;
using std::wcout;
using std::cout;
int _tmain(int argc, _TCHAR* argv[])
{
	
	wcout << "hello 15pb" << endl \
		<< 1 << endl\
		<< "hello 15pb" << endl \
		<< "hello 15pb" << endl \
		<<  22 << endl \
		<< 22 << endl \
		<<  22 << endl \
		<<  22.22 << endl \
		<< 22.2233 << endl;
	wcout << sizeof(bool) << endl \
		<< sizeof(char) << endl\
		<< sizeof(wchar_t) << endl \
		<< sizeof(short) << endl \
		<< sizeof(int) << endl \
		<< sizeof(long) << endl \
		<< sizeof(float) << endl \
		<< sizeof(double) << endl ;
	return 0;
}

