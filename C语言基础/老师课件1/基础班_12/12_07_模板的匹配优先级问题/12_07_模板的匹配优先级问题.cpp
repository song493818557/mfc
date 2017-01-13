// 12_07_模板的匹配优先级问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdlib.h>
#include <iostream>
using std::cout;  using std::endl;

template <typename T1, typename T2>
T2  my_add(T1 NumA, T2 NumB) { return NumA + NumB; }
int my_add(int nNumA, int nNumB) { return nNumA + nNumB; }

int _tmain(int argc, _TCHAR* argv[]) {

	/*
	1.查找参数完全匹配的函数；
	2.查找函数模板，实例化产生一个匹配的模板函数；
	3.通过类型转换可产生参数匹配的函数。
	*/
	cout << my_add(1, 3.4) << endl;
	cout << my_add(1, 'A') << endl;
	cout << my_add(15, 87) << endl;
	system("pause");
	return 0;
}
