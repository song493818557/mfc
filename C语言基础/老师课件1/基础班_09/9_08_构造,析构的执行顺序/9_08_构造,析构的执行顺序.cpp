// 9_08_����,������ִ��˳��.cpp : �������̨Ӧ�ó������ڵ㡣
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
	CStudent student; // ���ݳ�Ա��һ�������
	CTeacher teacher; // ���ݳ�Ա��һ������� 
};
int _tmain(int argc, _TCHAR* argv[]) {
	//CTutorpair obj;
	CTutorpair * pObj = new CTutorpair();
	delete pObj;
	cout << "Back in main.\n";
	return 0;
}

