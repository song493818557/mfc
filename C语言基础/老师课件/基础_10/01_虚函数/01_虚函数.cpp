// 01_�麯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class CClassA {
public:
	virtual void fun_a() { printf("fun_a:CClassA"); }
};
class CClassB : public CClassA {
public:
	virtual void fun_a() { printf("fun_a:CClassB"); }
};






int _tmain(int argc, _TCHAR* argv[]) {
	CClassA objA, *pobjA;
	CClassB objB;
	pobjA = &objA;
	pobjA->fun_a();

	pobjA = &objB;//��B����A�����ͣ������ܹ�ֱ�Ӹ�ֵ
	pobjA->fun_a();//������ָ��ָ����������ʱ�򣬵����麯����
	               //���õ���������麯��



	return 0;
}
