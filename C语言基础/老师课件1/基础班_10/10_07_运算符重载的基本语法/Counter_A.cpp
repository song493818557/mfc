#include "stdafx.h"
#include "Counter_A.h"

CCounter_A::CCounter_A(int num/*=0*/):m_nNum(num)
{
	m_nNum = num;
}

CCounter_A::~CCounter_A()
{
}

CCounter_A& CCounter_A::operator++()
{
	m_nNum += 1;
	//return m_nNum;   //ת������
	return *this;      //��������
}

CCounter_A CCounter_A::operator++(int)
{
	//�ȱ���ԭֵ
	CCounter_A temp(m_nNum);
	m_nNum += 1;

	//�����,����ԭֵ
	return temp;       //��������
}

int CCounter_A::operator+(CCounter_A & op2)
{
	return m_nNum + op2.m_nNum;
}

