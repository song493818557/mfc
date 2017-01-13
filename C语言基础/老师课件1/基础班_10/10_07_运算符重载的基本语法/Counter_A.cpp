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
	//return m_nNum;   //转换构造
	return *this;      //拷贝构造
}

CCounter_A CCounter_A::operator++(int)
{
	//先保存原值
	CCounter_A temp(m_nNum);
	m_nNum += 1;

	//加完后,返回原值
	return temp;       //拷贝构造
}

int CCounter_A::operator+(CCounter_A & op2)
{
	return m_nNum + op2.m_nNum;
}

