// 10_02_��̬���ݳ�Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CCounter
{
public:
	void setcount(int i) { m_nCount = i; }
	void showcount() { cout << m_nCount << endl; }
private:
	static int m_nCount;    //��������˵����̬����
};


int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA, objB;
	objA.showcount();
	objB.showcount();
	objA.setcount(15);
	objA.showcount();
	objB.showcount();
	return 0;
}

int fun()
{
	return 10;
}
int CCounter::m_nCount = fun(); //�������ⶨ�徲̬����
int a = fun();
