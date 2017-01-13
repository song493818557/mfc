// 06 拷贝构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CTest
{
public:
	CTest(int a = 10,int b = 20)
		:m_a(a), m_b(b)
	{
		name = new char[20];
	}
	~CTest()
	{
		
		if (name == NULL)
		{
			delete[]name;
			name = NULL;
		}
	
	}
	CTest(CTest & Other)
	{
		printf("我是拷贝构造函数");
		this->m_a = Other.m_a;
		this->m_b = Other.m_b;

		//this->name = Other.name; //浅拷贝
		this->name =new char[20];//深拷贝
		memcpy(this->name, Other.name, 20);
	}
	void Print()
	{
		printf("a:%d b:%d", m_a, m_b);
	}
private:
	int m_a;
	int m_b;
	char * name;
};

CTest Fun(CTest a)
{
	a.Print();
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA;

	//CTest objB(objA);

	Fun(objA);

	return 0;
}

