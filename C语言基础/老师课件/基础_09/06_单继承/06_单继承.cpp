// 06_���̳�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CBase
{
public:
	int m_a;
	int m_b;
};

class CTest :  public CBase//����ͽ����̳У������ǹ��м̳�
{
public:
	int m_c;
private:
};



int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.m_a = 10;
	obj.m_b = 20;
	printf("%d", sizeof(CTest));
	return 0;
}

