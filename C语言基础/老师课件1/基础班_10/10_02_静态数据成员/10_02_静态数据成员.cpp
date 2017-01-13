// 10_02_静态数据成员.cpp : 定义控制台应用程序的入口点。
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
	static int m_nCount;    //在类体内说明静态数据
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
int CCounter::m_nCount = fun(); //在类体外定义静态数据
int a = fun();
