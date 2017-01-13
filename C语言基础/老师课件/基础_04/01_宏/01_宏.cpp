// 01_宏.cpp : 定义控制台应用程序的入口点。
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
//	printf("请输入一个半径:");
	//scanf_s("%lf", &banjing);
//	printf("这个圆形的周长为:%lf", L(banjing) );

//	printf("这个圆形的周长为:%lf", 2 * PI*banjing);
	int a = 9;
	printf("%d\n", L(a));
	printf("%d\n", L(a + 1)); 
	printf("%d\n", L2(a + 1));
	printf("%d\n", __LINE__);
	printf("%s\n", __FILE__);
	return 0;
}

