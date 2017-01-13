// 10_06_友元成员函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CCounter;                //需要前置声明一下

class CShow{
public:
	void show1(CCounter obj);  //函数的实现必须在类实现的后面
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


