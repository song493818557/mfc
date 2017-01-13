// 07_多继承.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CBase1
{
public:
	void fun1()
	{
		printf("我是Base1");
	}
public:
	int m_a;
	int m_b;
};
class CBase2
{
public:
	void fun2()
	{
		printf("我是Base2");
	}
public:
	int m_c;
	int m_d;
};
class CTest : public CBase1,public CBase2//这个就叫做继承，并且是公有继承
{
public:
	int m_e;
private:
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.fun1();
	obj.fun2();
	return 0;
}

