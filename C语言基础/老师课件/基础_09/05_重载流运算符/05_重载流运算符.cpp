// 05_重载流运算符.cpp : 定义控制台应用程序的入口点。
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
//1 重载流运算符，必须是友元的方式，因为第一个参数不是本类对象，
//而是ostream或者istream.
//2 注意返回值需要是引用，用以支持连续的输入和输出
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

