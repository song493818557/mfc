// 09_����ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//int INT  �������
//typedef int INT; ��intһ������

//int(*FUN)(int); //����һ��ָ�������



//struct _HEHE{
//	int a;
//	int b;
//}stc1;       //����һ������ stc1


typedef struct _HEHE{
	int a;
	int b;
}HEHE; //��_HEHE���������һ������
HEHE g_hehe;

struct _HEHE g_hehe2;

typedef int(*FUN)(int);//�����������һ������

int Fun(int n,int m)
{
	printf("Hello %dPB\n",n);
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{


	int a;
	Fun(15);
	FUN p = Fun;

	p(16);
	return 0;
}

