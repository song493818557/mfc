// 09_�ض���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class CBase
{
public:
	void fun(int a)
	{
		printf("%d", a);
	}
public:
	int m_a;
	int m_b;
};

class CTest : public CBase//����ͽ����̳У������ǹ��м̳�
{
public:
public:
	void fun(char * szName)
	{
		printf("%s", szName);
	}
	char m_a;
private:
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.m_a = 100;

	obj.CBase::fun(10);//ֻҪ����͸����еĳ�Ա������ͬ���ˣ�
	                   //���������ʺ��������ʵľ����Լ��ġ�
	                   //����ĺ����ͱ��ض����ˣ���������ԭ������ģ�
	                   //��Ҫ��һ��������
	return 0;
}

