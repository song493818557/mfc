// 10_06_��Ԫ��Ա����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CCounter;                //��Ҫǰ������һ��

class CShow{
public:
	void show1(CCounter obj);  //������ʵ�ֱ�������ʵ�ֵĺ���
	void show2(CCounter obj);
};

class CCounter {
public:
	CCounter() {}
	CCounter(int nNum) { m_nCount = nNum; }
	void showcount() { cout << m_nCount << endl; }

private:
	friend void CShow::show1(CCounter obj);
	int m_nCount;
};

void CShow::show1(CCounter obj)
{
	cout << obj.m_nCount << endl;
}

void CShow::show2(CCounter obj)
{
	//cout << obj.m_nCount << endl; 
}
int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(16);
	CShow    objB;
	objA.showcount();
	objB.show1(objA);
	objB.show2(objA);
	return 0;
}


