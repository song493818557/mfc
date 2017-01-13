// 04_虚函数表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CBase
{
public:
	virtual void Fun1()
	{
		printf("我是父类函数1");
	}
	virtual void Fun2()
	{
		printf("我是父类函数2");
	}
public:
	int a;
};
class CTest:public CBase
{
public:
	void Fun1()
	{
		printf("我是子类函数1");
	}
public:
	int b;
};
class CTest2 :public CBase
{
public:
	void Fun1()
	{
		printf("我是子类函数1");
	}
public:
	int b;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.a = 0x10;
	obj.b = 0x20;
	printf("%d\n", sizeof(CTest));
	printf("%d\n", &obj);  //假如有虚函数，你会发现对象比原来大了4个字节，因为多了一个虚表指针，虚表指针指向虚函数表，虚函数表中
	                       //存放着本对象的所有虚函数地址
	printf("%d\n", &obj.a);
	printf("%d\n", &obj.b);


	return 0;
}