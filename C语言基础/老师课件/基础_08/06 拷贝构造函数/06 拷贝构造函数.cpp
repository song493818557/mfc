// 06 �������캯��.cpp : �������̨Ӧ�ó������ڵ㡣
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
		printf("���ǿ������캯��");
		this->m_a = Other.m_a;
		this->m_b = Other.m_b;

		//this->name = Other.name; //ǳ����
		this->name =new char[20];//���
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

