// 11_08_��̬���� �� ��̬����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CClassA {
public:
	CClassA() {};
	CClassA(int a) {}
	virtual ~CClassA() {}
	virtual void fun_a() { cout << "fun_a:CClassA" << endl; }
};
class CClassB : public CClassA {
public:
	virtual ~CClassB() {}
	virtual void fun_a() { cout << "fun_a:CClassB" << endl; }
};

int _tmain(int argc, _TCHAR* argv[]) {
	CClassA objA, *pobjA;
	CClassB objB;

	CClassA objC(4); //������ͨ����̬������ɵ�.
					 //��̬����,�����ĵ��õ�ַ,�Ѿ��ڶ������ļ�����д����.
					 //�޲ι��캯��:E8 CD BF FF FF       call        CClassA::CClassA (0B113EDh) 
					 //�вι��캯��:E8 9A BF FF FF       call        CClassA::CClassA (0B113E8h)

	pobjA = &objA;
	pobjA->fun_a();   //��̬����,�����ĵ��õ�ַ,�����е�ʱ���ȷ��(virtual�麯��) 
	                  //FF D0                call        eax 
	pobjA = &objB;   
	pobjA->fun_a();   //��̬����,�����ĵ��õ�ַ,�����е�ʱ���ȷ��(virtual�麯��)
					  
	
	pobjA = new CClassB; // ֻ�и���������������Ϊ�麯��ʱ��
	delete pobjA;		 // �ͷŸ���ָ�룬���ܹ����õ����������������
					     // �Ӷ������ͷ������е���Դ��
					     // ���������������������ø����������ﵽ�����ͷ�
					     
					     //���������������������Ϊ�麯��
					     // ���ͷŸ���ָ��ʱ��ֱ�ӵ��ø������������ͽ�����
					     // �Ӷ������е���Դ�ò����ͷ�
	return 0;
}


