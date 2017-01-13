// 8-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;


class MyClass
{
public:
	static MyClass* fun1();
	static MyClass * p;
	~MyClass();
private:
	MyClass(){}
	

private:

};
MyClass * MyClass::p = nullptr;


MyClass* MyClass::fun1()
{
	if (p == nullptr)
	{
		p = new MyClass;
	}
	return p;
}


int fun()
{
	MyClass* pp = MyClass::fun1();

	MyClass* pp1 = MyClass::fun1();
	return 1;
}

int _tmain(int argc, _TCHAR* argv[])
{
	MyClass* pp = MyClass::fun1();
	MyClass* pp1 = MyClass::fun1();
	return 0;
}

