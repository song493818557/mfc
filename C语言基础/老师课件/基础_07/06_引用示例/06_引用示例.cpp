// 06_����ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


void swap(int* p1, int *p2)
{
	int Temp = 0;
	Temp = *p1;
	*p1 = *p2;
	*p2 = Temp;
}
void swap(int& Num1, int& Num2)
{
	int Temp = 0;
	Temp = Num1;
	Num1 = 100;
	Num2 = Temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int Num1 = 0;
	int Num2 = 100;
	int &N = Num1; // �൱�ڸ�Num����һ������������N
	//int &M ;//����ģ����ñ����ʼ��

	N = Num2;//����һ����ʼ��֮�󣬾��޷��������������ˣ���ôд�Ļ�
	         //���ڸ�ֵ


	int a = 20;
	int b = 10;
	swap(&a, &b);

	swap(a, b);

	return 0;
}

