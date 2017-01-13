#include "stdafx.h"
#include "Counter_B.h"

CCounter_B::CCounter_B(int num /*= 0*/)
{
	m_nNum = num;
}

CCounter_B::~CCounter_B()
{
}

CCounter_B& operator++(CCounter_B& op)
{
	op.m_nNum++;
	return op;
}
CCounter_B operator++(CCounter_B& op, int)
{
	CCounter_B temp(op.m_nNum);
	op.m_nNum += 1;
	return temp;
}
int operator+(CCounter_B & op1, CCounter_B & op2)
{
	return op1.m_nNum + op2.m_nNum;
}