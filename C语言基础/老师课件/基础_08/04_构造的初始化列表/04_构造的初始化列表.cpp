// 04_����ĳ�ʼ���б�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CHEHE
{
public:
	CHEHE(int a, int b)
	{

	}

};

class CTest
{
public:
	CTest(int a, int b=20, int c = 10) ://��ʼ����
		m_a(a), m_b(b),//��ͨ��Ա
		m_c(c),     //һ��const���͵ĳ�ʼ����������д�ڳ�ʼ���б��еġ�
		m_d(c),     //�������͵ĳ�Ա��Ҳ��Ҫд�ڳ�ʼ���б��С�
		objb(10,20) //û���޲ι�������������Ҳ��Ҫ�ڳ�ʼ���б��г�ʼ��
		Array(10,20,30) // �����޷�ʹ�ó�ʼ���б�
	{
		printf("�����в����Ĺ���");
		//�������ڵ�����ĳ�ʼ������ֻ��һ��һ����ֵ�ˡ�
	}
	CTest():
		objb(11, 2), m_c(10), m_d(m_a)
	{
		printf("�����޲ι���");
	}
private:
	int m_a;
	int m_b;
	//const int m_c = 10;����﷨��ĿǰҲ��֧�ֵ���
	const int m_c;
	int & m_d;
	CHEHE objb;
	//int Array[20] = { 10, 20, 30 };
	int Array[20];
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj(10);


	return 0;
}

