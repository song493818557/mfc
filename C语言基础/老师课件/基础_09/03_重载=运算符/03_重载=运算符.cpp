// 03_����=�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CTest
{
public:
	CTest(int na = 0,int nb =0 ):
		m_a(na), m_b(nb)
	{
		p = new char[20];
	}
	//1 ����Ӧ�������ã�������������Ч��
	//2 ����ֵҲ���ã�ʹ���ܹ�����(a=b) =c�������
	//3 д��������أ�Ҳ���Լ��������Ҫ�����磺
	//  ��ֵ�����ֻ������������Ĳ�������ôҲ���÷���ֵ
	//  ���߲��漰�������(a=b) =c����ô����ֵҲ����������
	//4 ����д��ֵ��������ص�Ŀ�ĺ�д����������һ���ģ�����Ϊ��
	//  ����ǳ������
	CTest& operator=(CTest const &Other)//ϵͳĬ���ṩ�ĺ����һ��
	{
		m_a = Other.m_a;
		m_b = Other.m_b;
		//p = Other.p;�����ǳ����
		//if (p!=NULL)
		//{
		//	delete p;
		//}
		//p = new char[20];
		//memcpy(p, Other.p, 20);//�������������������
		return *this;
	}
private:
	int m_a;
	int m_b;
	char* p;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA(10,30);
	CTest objB(5,25);
	CTest objC(155, 25);


	objB = objA;


	return 0;
}

