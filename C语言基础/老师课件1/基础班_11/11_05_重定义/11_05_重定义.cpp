// 11_05_�ض���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA
{
public:
	void printf_A() { cout << "ClsA printf_A!\n" << endl; }
	void printf_B(int nNum) { cout << "ClsA printf_B!\n" << endl; }
};

class CClassB :public CClassA {
public:
	void printf_A(int nNum) { cout << "ClsB printf_A!\n" << endl; }
	void printf_B() { cout << "ClsB printf_B!\n" << endl; }
};

int _tmain(int argc, _TCHAR* argv[])
{
	CClassB objB;
	objB.printf_A(15);
	objB.printf_A();          //����ͨ���ض���,���ǵ��˸���ķ���
	objB.CClassA::printf_A(); //����ͨ����������ʽ���ʱ��ض���ķ���

	objB.printf_B();
	objB.printf_B(15);
	return 0;
}

