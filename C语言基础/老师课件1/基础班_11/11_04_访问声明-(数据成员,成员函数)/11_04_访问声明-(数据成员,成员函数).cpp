// 11_04_��������-(���ݳ�Ա,��Ա����).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	CClassA(int nNum) { m_nNumA = nNum; }
protected:
	int m_nNumA;
	void fun() {}
private:
	int m_nNumB;
};

class CClassB :private CClassA {
public:
	CClassB(int nNum) :CClassA(nNum) {
		// ......
	}
	void print() {
		fun();
		cout << m_nNumA << m_nNumB << endl;
	}
	CClassA::fun;
	CClassA::m_nNumA;
	//CClassA::m_nNumB;  //�����˽������,���಻�ܷ���
};
int _tmain(int argc, _TCHAR* argv[]) {
	CClassB objB(15);
	objB.print();
	objB.fun();
	objB.m_nNumA;
	//objB.m_nNumB;
	return 0;
}

