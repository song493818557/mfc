// 04_�麯����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class CBase
{
public:
	virtual void Fun1()
	{
		printf("���Ǹ��ຯ��1");
	}
	virtual void Fun2()
	{
		printf("���Ǹ��ຯ��2");
	}
public:
	int a;
};
class CTest:public CBase
{
public:
	void Fun1()
	{
		printf("�������ຯ��1");
	}
public:
	int b;
};
class CTest2 :public CBase
{
public:
	void Fun1()
	{
		printf("�������ຯ��1");
	}
public:
	int b;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.a = 0x10;
	obj.b = 0x20;
	printf("%d\n", sizeof(CTest));
	printf("%d\n", &obj);  //�������麯������ᷢ�ֶ����ԭ������4���ֽڣ���Ϊ����һ�����ָ�룬���ָ��ָ���麯�����麯������
	                       //����ű�����������麯����ַ
	printf("%d\n", &obj.a);
	printf("%d\n", &obj.b);


	return 0;
}