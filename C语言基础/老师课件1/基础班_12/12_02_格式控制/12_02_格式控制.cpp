// 12_02_格式控制.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

int main()
{
	ofstream cfout("context.txt");

	double d1 = 3456.34545;
	double d2 = 56.345;

	//一。成员函数
	cfout.precision(4);
	cfout << d1 << endl;
	cfout.precision(10);
	cfout << d2 <<endl;

	//二。格式控制符，直接放到<<等操作符的后面
	cfout << setprecision(4)<<endl;
	cfout << d2 << endl;
    return 0;
}

