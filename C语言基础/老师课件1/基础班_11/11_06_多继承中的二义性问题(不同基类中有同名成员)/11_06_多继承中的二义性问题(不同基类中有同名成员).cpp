// 11_06_多继承中的二义性问题(不同基类中有同名成员).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB {
public:
	void fun_a() { cout << "fun_a:CClassB" << endl; }
	void fun_b() { cout << "fun_b:CClassB" << endl; }
};

class CClassC : public CClassA, public CClassB
{ /* 省略...... */
};
int _tmain(int argc, _TCHAR* argv[]) {
	CClassC obj;
	//obj.fun_a(); // 不明确
	obj.CClassA::fun_a();
	obj.CClassB::fun_a();
	return 0;
}

