// 10_�̳л����¹���������������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class HEHE
{
public:
	HEHE()
	{
		printf("����HEHE�Ĺ���\n");
	}
	~HEHE()
	{
		printf("����HEHE������\n");
	}
};
class CBase1
{
public:
	CBase1()
	{
		printf("���Ǹ���1����\n");
		m_a = 100;
		m_b = 200;
	}
	~CBase1()
	{
		printf("���Ǹ���1����\n");
	}
	int m_a;
	int m_b;
private:

};
class CBase2
{
public:
	CBase2()
	{
		printf("���Ǹ���2����\n");
		m_a = 100;
		m_b = 200;
	}
	~CBase2()
	{
		printf("���Ǹ���2����\n");
		
	}
	int m_a;
	int m_b;
};
class CTest : public CBase1,public CBase2//����ͽ����̳У������ǹ��м̳�
{
public:
	CTest()
	{
		printf("�������๹��\n");
		m_c = 300;
	}
	~CTest()
	{
		printf("������������\n");
		m_c = 300;
	}
	int m_c;
private:
	HEHE obj;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	return 0;
}

