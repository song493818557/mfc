// 10_05_友元类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CCounter {
public:
	CCounter() {}
	CCounter(int nNum) { m_nCount = nNum; }
	void showcount() { cout << m_nCount << endl; }
private:
	int m_nCount;
	friend class CShow;
};


class CShow {
public:
	void show(CCounter obj) 
	{ 
		cout << obj.m_nCount << endl; 
	}
};
int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(16);
	CShow    objB;
	objA.showcount();
	objB.show(objA);
	return 0;
}


