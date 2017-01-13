// 9_08_构造,析构的执行顺序.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CStudent {
public:
	CStudent() { cout << "Constructing student.\n"; }
	~CStudent() { cout << "Destructing student.\n"; }
};

class CTeacher {
public:
	CTeacher() { cout << "Constructing teacher.\n"; }
	~CTeacher() { cout << "Destructing teacher.\n"; }
};

class CTutorpair {
public:
	CTutorpair() { cout << "Constructing tutorpair.\n"; }
	~CTutorpair() { cout << "Destructing tutorpair.\n"; }
protected:
	CStudent student; // 数据成员是一个类对象
	CTeacher teacher; // 数据成员是一个类对象 
};
int _tmain(int argc, _TCHAR* argv[]) {
	//CTutorpair obj;
	CTutorpair * pObj = new CTutorpair();
	delete pObj;
	cout << "Back in main.\n";
	return 0;
}

