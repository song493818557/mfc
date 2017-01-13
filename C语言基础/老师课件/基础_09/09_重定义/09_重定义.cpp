// 09_重定义.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CBase
{
public:
	void fun(int a)
	{
		printf("%d", a);
	}
public:
	int m_a;
	int m_b;
};

class CTest : public CBase//这个就叫做继承，并且是公有继承
{
public:
public:
	void fun(char * szName)
	{
		printf("%s", szName);
	}
	char m_a;
private:
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.m_a = 100;

	obj.CBase::fun(10);//只要子类和父类中的成员函数名同名了，
	                   //子类对象访问函数，访问的就是自己的。
	                   //父类的函数就被重定义了，如果想访问原来父类的，
	                   //需要加一个作用域
	return 0;
}

