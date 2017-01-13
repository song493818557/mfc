// 01_虚函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CClassA {
public:
	virtual void fun_a() { printf("fun_a:CClassA"); }
};
class CClassB : public CClassA {
public:
	virtual void fun_a() { printf("fun_a:CClassB"); }
};






int _tmain(int argc, _TCHAR* argv[]) {
	CClassA objA, *pobjA;
	CClassB objB;
	pobjA = &objA;
	pobjA->fun_a();

	pobjA = &objB;//类B是类A子类型，所以能够直接赋值
	pobjA->fun_a();//当父类指针指向子类对象的时候，调用虚函数，
	               //调用的是子类的虚函数



	return 0;
}
