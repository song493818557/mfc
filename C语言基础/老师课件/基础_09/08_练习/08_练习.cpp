// 08_��ϰ.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class CClassA {
public:
	void fun_a(int nNum) { cout << nNum << endl; }
	void fun_b()         { cout << "ClassA\n"; }
};
class CClassB :private CClassA {
public:
	void fun_c() {
		cout << "ClassB\n"; 
		fun_a(10);
	}
	//CClassA::fun_a;  //û�������仰��������˽�м̳У�
	                   //���������������ڵ����Ծͱ��˽�е��ˡ�
	//CClassA::fun_b;
};

int _tmain(int argc, _TCHAR* argv[]) {
	CClassB objB;
	objB.fun_a(15);
	objB.fun_b();
	objB.fun_c();
	return 0;
}


