// 10_继承环境下构造与析构的问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class HEHE
{
public:
	HEHE()
	{
		printf("我是HEHE的构造\n");
	}
	~HEHE()
	{
		printf("我是HEHE的析构\n");
	}
};
class CBase1
{
public:
	CBase1()
	{
		printf("我是父类1构造\n");
		m_a = 100;
		m_b = 200;
	}
	~CBase1()
	{
		printf("我是父类1析构\n");
	}
	int m_a;
	int m_b;
private:

};
class CBase2
{
public:
	CBase2()
	{
		printf("我是父类2构造\n");
		m_a = 100;
		m_b = 200;
	}
	~CBase2()
	{
		printf("我是父类2析构\n");
		
	}
	int m_a;
	int m_b;
};
class CTest : public CBase1,public CBase2//这个就叫做继承，并且是公有继承
{
public:
	CTest()
	{
		printf("我是子类构造\n");
		m_c = 300;
	}
	~CTest()
	{
		printf("我是子类析构\n");
		m_c = 300;
	}
	int m_c;
private:
	HEHE obj;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	return 0;
}

