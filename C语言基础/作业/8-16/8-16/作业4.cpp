// 8-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
template < typename T1, typename T2 > ;
T2 Fmax(T1 A, T2 B){
	//T1 BB = A > B ? A : B;
	return A > B ? A : B;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a = 5;
	char b = 'r';
	float c;
	float d = 8.8;
	char e[10] = "ddffks";
	c=Fmax(a, d);
	return 0;
}

