// 05 ������Ĭ�ϲ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

int Add(int a, int b, int c = 0, int d = 0)
{
	return a + b + c + d;
}

int Add(int a,int b)
{
	return a + b;
}

int _tmain(int argc, _TCHAR* argv[])
{
	Add(1, 2);//��ʹ��Ĭ�ϲ������뺯������ʱ����Ҫע��һ�¶����Ե�����


	Add(1, 2,3);
	Add(1, 2, 3,4);
	return 0;
}

