// 08_��̬��Ա.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


class CTest
{
public:
	CTest()
	{
		Num++;
	}
	~CTest()
	{
		Num--;
	}
	void fun2()
	{

	}
	static void fun()  //���ᴫ��thisָ��
	{
		printf("helloworld");
		//b = 10;//�ھ�̬�����ڣ��޷����ʷǾ�̬��Ա��
		Num = 20;
	}
public:
	static int Num ;
	int b;
};
int CTest::Num = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA;
	//CTest objB;
	//CTest objC;
	//CTest objD;
	//CTest objE;
	objA.fun2();    //��ȷ��
	CTest::fun();   //��ȷ��
	//CTest::fun2();//����� ��̬�����뾲̬��Ա�����ö���Ϳ��Ե��ã�
	                //�������ڶ���
	                //�Ǿ�̬�ĳ�Ա�������Ա�����������ͨ��������ʹ�á�
	printf("%d\n", CTest::Num);//���Ǽȿ���ͨ����������һ����̬��Ա��
	//Ҳ����ͨ�����������ʾ�̬��Ա������һ�������������ͨ���������ʵģ�
	//��Ϊͨ��������ʣ����׺���ͨ�ĳ�Ա����Ū�졣
	//printf("D:%d\n", objD.Num);

	//printf("D:%d\n", objD.b);
	return 0;
}

