// 01_��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#define  PI  3.1415926

//#define L(r)  2*PI*r

#define L(n)  (n+1)*n    


int L2(int n)
{
	return (n + 1)*n;
}
int _tmain(int argc, _TCHAR* argv[])
{
	double banjing = 0.0;
//	printf("������һ���뾶:");
	//scanf_s("%lf", &banjing);
//	printf("���Բ�ε��ܳ�Ϊ:%lf", L(banjing) );

//	printf("���Բ�ε��ܳ�Ϊ:%lf", 2 * PI*banjing);
	int a = 9;
	printf("%d\n", L(a));
	printf("%d\n", L(a + 1)); 
	printf("%d\n", L2(a + 1));
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);
	return 0;
}

