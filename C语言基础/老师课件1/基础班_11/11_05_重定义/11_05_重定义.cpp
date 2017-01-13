// 11_05_重定义.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA
{
public:
	void printf_A() { cout << "ClsA printf_A!\n" << endl; }
	void printf_B(int nNum) { cout << "ClsA printf_B!\n" << endl; }
};

class CClassB :public CClassA {
public:
	void printf_A(int nNum) { cout << "ClsB printf_A!\n" << endl; }
	void printf_B() { cout << "ClsB printf_B!\n" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CClassB objB;
	objB.printf_A(15);
	objB.printf_A();          //子类通过重定义,覆盖掉了父类的方法
	objB.CClassA::printf_A(); //必须通过类名来显式访问被重定义的方法

	objB.printf_B();
	objB.printf_B(15);
	return 0;
}

