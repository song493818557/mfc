// 11_07_������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB : public CClassA {
public:
	void fun_b() { cout << "fun_b:CClassB" << endl; }
};

int _tmain(int argc, _TCHAR* argv[]) {

	//��ͬ���͵Ķ���֮�䲻��ֱ�Ӹ�ֵ(������������)
	CClassA * pOpb = new CClassB;

	//������ ���κ�ʱ�򶼿����޷�Ĵ��游��Ĺ���
	CClassA objA, *pobjA;
	CClassB objB, *pobjB;
	pobjA = &objA;
	pobjA->fun_a();
	pobjA = &objB;     //������ ���κ�ʱ�򶼿����޷�Ĵ��游��Ĺ���
	pobjA->fun_a();
	//pobjA->fun_b();             // error! ���Ͳ�ƥ��
	((CClassB*)pobjA)->fun_b();   // right!
	pobjB = &objB; pobjB->fun_a();
	pobjB->fun_b();

	

	return 0;
}


