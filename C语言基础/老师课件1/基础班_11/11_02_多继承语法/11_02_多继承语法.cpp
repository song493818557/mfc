// 11_02_��̳��﷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA1
{
public:
	void print1() {
		cout << m_nNumA1 << endl;
	}
	int m_nNumA1;
};
class CClassA2
{
public:
	void print2() {
		cout << m_nNumA2 << endl;
	}
	int m_nNumA2;
};
class CClassB : public CClassA1,public CClassA2
{
public:
	int m_nNumB;
};

int main()
{
	CClassB claB;
	claB.m_nNumA1 = 10;
	claB.m_nNumA2 = 889;
	claB.m_nNumB = 100;
	claB.print1();
	claB.print2();
}

