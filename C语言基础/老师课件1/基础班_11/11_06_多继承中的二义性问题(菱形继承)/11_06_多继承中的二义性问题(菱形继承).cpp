// 11_06_��̳��еĶ���������(���μ̳�).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB1 : virtual public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB1" << endl; }
};
class CClassB2 : virtual public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB2" << endl; }
};
class CClassC :  public CClassB1, public CClassB2 {
public:
	void fun_c() { cout << "fun_b:CClassC" << endl; }
};


int _tmain(int argc, _TCHAR* argv[]) {
	CClassC obj;
	//obj.fun_a();
	obj.CClassA::fun_a();
	obj.CClassB1::fun_a();
	obj.CClassB2::fun_a();

	obj.fun_a(); //��̳�(ֻ�ܽ��ͬһ����������Ķ���������)
	//obj.fun_b(); //��̳�(���ܽ����ͬ��������Ķ���������)  
	return 0;
}

