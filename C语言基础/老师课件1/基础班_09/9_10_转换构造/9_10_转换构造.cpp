// 9_10_ת������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CNumber
{
public:
	CNumber(){}
	explicit CNumber(int a):m_nNum(a) {} //explicit������˹��캯�������ת��
	CNumber(int a,int b) :m_nNum(a) {}
	~CNumber() {}
private:
	int m_nNum;
	//const int m_nNumB;
};

int main()
{
	//����ʹ��
	CNumber objA;
	CNumber objB();
	CNumber objC(67);
	CNumber objD(67,98);

	//objA = 99; //���������͵ı���ֱ�Ӹ�ֵ������ʱ,��������ʽת��
	           //C++�᳢���ñ���ȥƥ��CNumber���еĹ��캯��,
	           //���ƥ����,������һ����ʱ����,
	           //������ʱ��������������ֵ��objA.

	objA = (CNumber)100;  //���explicit��,��ֹ��ʽת��,��������ֹǿ��ת��
	objA = CNumber(100);

	objA = {100,220};
    return 0;
}

