// 06_ģ���뺯������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


template <class T>
void swap(T &a, T &b)
{
	T Temp = a;
	a = b;
	b = Temp;
}
//����ģ��Ҳ�ǿ��Թ������ص�
template <class T>
void swap(T a)
{

}
//����ģ��Ҳ����Ӱ����ͨ����������
void swap(int a, int b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int Num1 = 20;
	int Num2 = 10;
	swap(Num1,Num2);//������ͨ������ģ���ͻ�������ȵ�����ͨ����
	return 0;
}

