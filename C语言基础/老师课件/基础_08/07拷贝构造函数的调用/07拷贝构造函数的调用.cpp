// 07�������캯���ĵ���.cpp : �������̨Ӧ�ó������ڵ㡣
//
// 06 �������캯��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int g_Num = 0;
class CTest
{
public:
	CTest()
	{
		m_Num = g_Num;
		g_Num++;
		printf("���ǹ���%d\n", m_Num);

	}
	~CTest()
	{
		printf("��������%d\n", m_Num);
	}
	CTest(CTest & Other)
	{
		m_Num = g_Num;
		g_Num++;
		printf("���ǿ������캯��%d\n", m_Num);
	}
private:
	int m_Num;
};

CTest Fun(CTest const &a)//������ֻ��ʹ���ⲿ�������ֵ��������Ҫ�޸�
                         //�Ϳ��Դ����ò����������ܹ����⿽������������Ч��
{
	return ;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA;
	CTest objc(objA);
	CTest objB = Fun(objA);
	int a = 0;
	a++;
	a--;
	a++;
	a--;
	return 0;
}

