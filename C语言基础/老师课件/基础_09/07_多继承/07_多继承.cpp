// 07_��̳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class CBase1
{
public:
	void fun1()
	{
		printf("����Base1");
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
		printf("����Base2");
	}
public:
	int m_c;
	int m_d;
};
class CTest : public CBase1,public CBase2//����ͽ����̳У������ǹ��м̳�
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

