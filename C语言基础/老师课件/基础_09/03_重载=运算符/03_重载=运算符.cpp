// 03_重载=运算符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CTest
{
public:
	CTest(int na = 0,int nb =0 ):
		m_a(na), m_b(nb)
	{
		p = new char[20];
	}
	//1 参数应该是引用，这样提升程序效率
	//2 返回值也引用，使得能够符合(a=b) =c这种情况
	//3 写运算符重载，也看自己程序的需要，比如：
	//  赋值运算符只会有两个对象的操作，那么也不用返回值
	//  或者不涉及特殊情况(a=b) =c，那么返回值也不必是引用
	//4 我们写赋值运算符重载的目的和写拷贝构造是一样的，都是为了
	//  避免浅拷贝。
	CTest& operator=(CTest const &Other)//系统默认提供的和这个一样
	{
		m_a = Other.m_a;
		m_b = Other.m_b;
		//p = Other.p;这个是浅拷贝
		//if (p!=NULL)
		//{
		//	delete p;
		//}
		//p = new char[20];
		//memcpy(p, Other.p, 20);//类似于这样，就是深拷贝
		return *this;
	}
private:
	int m_a;
	int m_b;
	char* p;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA(10,30);
	CTest objB(5,25);
	CTest objC(155, 25);


	objB = objA;


	return 0;
}

