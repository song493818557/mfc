// 08_C++������ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int  a = 0;
	short b = 100;
	a = b;
	b = (short)a;//���Զ�ת���ģ���ǿת��Ϊ����ʾ����

	int * p = NULL;
	p = (int *)a;//�����Զ�ת���ģ��������ǿת


	const int c = 0;
	
	//int  *  p2 = (int *)&c;
	//*p2 = 200;
	int  *  p2  = const_cast<int *>(&c);//ȥ����������

	int c = 100;
	short d = 0;

	d = static_cast<short>(c);


	int * p3 = NULL;
	p3 = reinterpret_cast<int*>(a);//


	return 0;
}

