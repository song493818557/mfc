// 08_练习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class CClassA {
public:
	void fun_a(int nNum) { cout << nNum << endl; }
	void fun_b()         { cout << "ClassA\n"; }
};
class CClassB :private CClassA {
public:
	void fun_c() {
		cout << "ClassB\n"; 
		fun_a(10);
	}
	//CClassA::fun_a;  //没有这两句话，由于是私有继承，
	                   //这两个函数在类内的属性就变成私有的了。
	//CClassA::fun_b;
};

int _tmain(int argc, _TCHAR* argv[]) {
	CClassB objB;
	objB.fun_a(15);
	objB.fun_b();
	objB.fun_c();
	return 0;
}


