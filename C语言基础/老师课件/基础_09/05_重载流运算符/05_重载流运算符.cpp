// 05_�����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using namespace std;

class CTest
{
public:
	CTest(int a, char* Name)
	{
		m_a = a;
		m_Name = Name;
	}
	friend ostream&  operator<<(ostream& os, CTest objA);
	friend istream&  operator>>(istream& is, CTest objA);
private:
	int m_a;
	char* m_Name;
};
//1 ���������������������Ԫ�ķ�ʽ����Ϊ��һ���������Ǳ������
//����ostream����istream.
//2 ע�ⷵ��ֵ��Ҫ�����ã�����֧����������������
ostream& operator<<(ostream& os, CTest objA)
{
	os << objA.m_a << objA.m_Name;
	return os;
}

istream& operator>>(istream& is, CTest objA)
{
	is >> objA.m_a >> objA.m_Name;
	return is;
}
int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj(20,"xiaoming");
	CTest objB(20, "xiaohong");
	cout << obj << objB;

	return 0;
}

