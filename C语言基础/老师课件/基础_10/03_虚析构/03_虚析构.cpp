// 03_������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CBase
{
public:
	virtual ~CBase()
	{
		printf("���Ǹ�����������");
	}
};

class CTest :public CBase
{
public:
	CTest()
	{
		Name = new char[20];
	}
	~CTest()
	{
		printf("����������������");
		delete[]Name;
	}
private:
	char * Name;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBase *p = new CTest[2];


	//���縸����������������麯������ô���Ͳ���������������
	//�п��������Դй¶��
	delete []p;
	return 0;
}

