// 11_06_多继承中的二义性问题(菱形继承).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB1 : virtual public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB1" << endl; }
};
class CClassB2 : virtual public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB2" << endl; }
};
class CClassC :  public CClassB1, public CClassB2 {
public:
	void fun_c() { cout << "fun_b:CClassC" << endl; }
};


int _tmain(int argc, _TCHAR* argv[]) {
	CClassC obj;
	//obj.fun_a();
	obj.CClassA::fun_a();
	obj.CClassB1::fun_a();
	obj.CClassB2::fun_a();

	obj.fun_a(); //虚继承(只能解决同一个基类引起的二义性问题)
	//obj.fun_b(); //虚继承(不能解决不同基类引起的二义性问题)  
	return 0;
}

