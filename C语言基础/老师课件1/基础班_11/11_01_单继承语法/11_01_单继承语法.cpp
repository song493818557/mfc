// 11_01_���̳��﷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA
{
public:
	void print() {
		cout << m_nNumA << endl;
	}
	int m_nNumA;
};

class CClassB : public CClassA
{
public:
	int m_nNumB;
};

int main()
{
	CClassB claB;
	claB.m_nNumA = 10;
	claB.m_nNumB = 100;
	claB.print();
}


