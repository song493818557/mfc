// 11_10_虚函数的工作原理.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

#include <iostream>
using namespace std;
/*
虚函数的工作原理：（拓展部分，不要求掌握）

编译器处理虚函数的方法：给每一个对象添加一个隐含的成员。
隐含成员中保存了一个指向函数地址数组的指针。
这个数组叫做 虚函数表（virtual function table）

1.假如一个类中有虚函数的话，
  对象的起始位就是虚函数表指针。虚表指针
2.基类   虚函数表中 存有所有虚函数的地址
3.派生类 包含有独立的虚函数表 （多继承有多个虚函数表，自己的虚函数加在第一个虚函数表的后面）
4.派生类 没有实现虚函数 ， 虚表内容将和父类的一样
5.派生类 如果实现了虚函数，那么虚表相应位置的虚函数地址
         会被修改为子类实现的那个虚函数地址。
6.通过以上机制，就实现了当使用父类指针指向子类对象的时候
  调用虚函数，会去对象的虚表中查找函数地址

  如果子类有实现，找到的地址就是子类的地址，调用的是子类的函数
  如果子类没有实现，找到的地址就是父类的地址，调用的是父类的函数
*/

class CBase
{
public:
	CBase() :m_nNum(0x11111111) {};
	virtual void fun1() { cout << "CBase::fun1  "; }
	virtual void fun2() { cout << "CBase::fun2  "; }
	virtual void fun3() { cout << "CBase::fun3  "; }

protected:
	int m_nNum;
};

class CBase2
{
public:
	CBase2() :m_nNum(0x22222222) {};
	virtual void fun1() { cout << "CBase2::fun1  "; }
	virtual void fun2() { cout << "CBase2::fun2  "; }
	virtual void fun3() { cout << "CBase2::fun3  "; }

protected:
	int m_nNum;
};

class CTest :public CBase, public CBase2
{
public:
	virtual void fun3() { cout << "CTest::fun3  "; }
	virtual void fun() { cout << "CTest::fun  "; }
};

//打印对象中的虚函数表(虚函数表地址，虚函数表中函数的地址，以及函数调用的结果)
static void showVirtualMethod(void * argPtr, int size)
{
	int * ptr = (int *)argPtr;   //对象的开始指针
	for (int i = 0; i<size / 4; ptr++, i++) //内存中每4个字节检测一下，是否是虚表指针
	{
		int * methodTable = (int *)(*ptr);  //取到内从中保存的地址
		if (!IsBadReadPtr(methodTable, 4))  //检查此地址是否是一个可读的地址
		{
			cout << "虚表地址: " << methodTable << endl; //此段内存中每四个字节就是一个函数地址

			FARPROC method = (FARPROC)*methodTable;
			for (; !IsBadCodePtr(method); methodTable++, method = (FARPROC)*methodTable) //每四个字节中的内容取出来，检查是否是代码段的地址
			{
				cout << "\t 虚函数地址: " << method << "\t";

				if (method && (*((int *)method)))
				{
					cout << "  函数调用结果：";
					method();
				}
				else {
					cout << "  非函数：" << endl;
					break;
				}
				cout << endl;
			}
		}

	}
}

int main()
{
	CTest test;
	test.fun();            cout << endl;
	test.CBase2::fun2();   cout << endl;
	test.fun3();           cout << endl;

	cout << "CTest类大小    " << sizeof(CTest) << endl;
	cout << "CTest类对象大小" << sizeof(test) << endl;
	showVirtualMethod(&test, sizeof(test));

	return 0;
}
