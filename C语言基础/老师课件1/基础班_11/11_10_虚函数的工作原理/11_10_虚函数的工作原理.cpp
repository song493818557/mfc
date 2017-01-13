// 11_10_�麯���Ĺ���ԭ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>

#include <iostream>
using namespace std;
/*
�麯���Ĺ���ԭ������չ���֣���Ҫ�����գ�

�����������麯���ķ�������ÿһ���������һ�������ĳ�Ա��
������Ա�б�����һ��ָ������ַ�����ָ�롣
���������� �麯����virtual function table��

1.����һ���������麯���Ļ���
  �������ʼλ�����麯����ָ�롣���ָ��
2.����   �麯������ ���������麯���ĵ�ַ
3.������ �����ж������麯���� ����̳��ж���麯�����Լ����麯�����ڵ�һ���麯����ĺ��棩
4.������ û��ʵ���麯�� �� ������ݽ��͸����һ��
5.������ ���ʵ�����麯������ô�����Ӧλ�õ��麯����ַ
         �ᱻ�޸�Ϊ����ʵ�ֵ��Ǹ��麯����ַ��
6.ͨ�����ϻ��ƣ���ʵ���˵�ʹ�ø���ָ��ָ����������ʱ��
  �����麯������ȥ���������в��Һ�����ַ

  ���������ʵ�֣��ҵ��ĵ�ַ��������ĵ�ַ�����õ�������ĺ���
  �������û��ʵ�֣��ҵ��ĵ�ַ���Ǹ���ĵ�ַ�����õ��Ǹ���ĺ���
*/

class CBase
{
public:
	CBase() :m_nNum(0x11111111) {};
	virtual void fun1() { cout << "CBase::fun1  "; }
	virtual void fun2() { cout << "CBase::fun2  "; }
	virtual void fun3() { cout << "CBase::fun3  "; }

protected:
	int m_nNum;
};

class CBase2
{
public:
	CBase2() :m_nNum(0x22222222) {};
	virtual void fun1() { cout << "CBase2::fun1  "; }
	virtual void fun2() { cout << "CBase2::fun2  "; }
	virtual void fun3() { cout << "CBase2::fun3  "; }

protected:
	int m_nNum;
};

class CTest :public CBase, public CBase2
{
public:
	virtual void fun3() { cout << "CTest::fun3  "; }
	virtual void fun() { cout << "CTest::fun  "; }
};

//��ӡ�����е��麯����(�麯�����ַ���麯�����к����ĵ�ַ���Լ��������õĽ��)
static void showVirtualMethod(void * argPtr, int size)
{
	int * ptr = (int *)argPtr;   //����Ŀ�ʼָ��
	for (int i = 0; i<size / 4; ptr++, i++) //�ڴ���ÿ4���ֽڼ��һ�£��Ƿ������ָ��
	{
		int * methodTable = (int *)(*ptr);  //ȡ���ڴ��б���ĵ�ַ
		if (!IsBadReadPtr(methodTable, 4))  //���˵�ַ�Ƿ���һ���ɶ��ĵ�ַ
		{
			cout << "����ַ: " << methodTable << endl; //�˶��ڴ���ÿ�ĸ��ֽھ���һ��������ַ

			FARPROC method = (FARPROC)*methodTable;
			for (; !IsBadCodePtr(method); methodTable++, method = (FARPROC)*methodTable) //ÿ�ĸ��ֽ��е�����ȡ����������Ƿ��Ǵ���εĵ�ַ
			{
				cout << "\t �麯����ַ: " << method << "\t";

				if (method && (*((int *)method)))
				{
					cout << "  �������ý����";
					method();
				}
				else {
					cout << "  �Ǻ�����" << endl;
					break;
				}
				cout << endl;
			}
		}

	}
}

int main()
{
	CTest test;
	test.fun();            cout << endl;
	test.CBase2::fun2();   cout << endl;
	test.fun3();           cout << endl;

	cout << "CTest���С    " << sizeof(CTest) << endl;
	cout << "CTest������С" << sizeof(test) << endl;
	showVirtualMethod(&test, sizeof(test));

	return 0;
}
