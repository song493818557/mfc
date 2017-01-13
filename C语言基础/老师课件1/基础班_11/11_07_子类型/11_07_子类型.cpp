// 11_07_子类型.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB : public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB" << endl; }
};

int _tmain(int argc, _TCHAR* argv[]) {

	//不同类型的对象之间不能直接赋值(除非是子类型)
	CClassA * pOpb = new CClassB;

	//子类型 在任何时候都可以无缝的代替父类的工作
	CClassA objA, *pobjA;
	CClassB objB, *pobjB;
	pobjA = &objA;
	pobjA->fun_a();
	pobjA = &objB;     //子类型 在任何时候都可以无缝的代替父类的工作
	pobjA->fun_a();
	//pobjA->fun_b();             // error! 类型不匹配
	((CClassB*)pobjA)->fun_b();   // right!
	pobjB = &objB; pobjB->fun_a();
	pobjB->fun_b();

	

	return 0;
}


