// 11_06_��̳��еĶ���������(��ͬ��������ͬ����Ա).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB {
public:
	void fun_a() { cout << "fun_a:CClassB" << endl; }
	void fun_b() { cout << "fun_b:CClassB" << endl; }
};

class CClassC : public CClassA, public CClassB
{ /* ʡ��...... */
};
int _tmain(int argc, _TCHAR* argv[]) {
	CClassC obj;
	//obj.fun_a(); // ����ȷ
	obj.CClassA::fun_a();
	obj.CClassB::fun_a();
	return 0;
}

