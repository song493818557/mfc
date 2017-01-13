// 02_define的缺点.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//Effective C++ 3rd的一个例子
#define MAX(a,b)  if(a>b ) {printf("%d",a);}else{ printf("%d",b);}

inline int Max(int a, int b)
{
	if (a>b)
	{ 
		printf("%d", a); 
	}
	else
	{
		printf("%d", b);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int nNumA = 5;
	int nNumB = 0;
	MAX(++nNumA, nNumB);      // nNumA被累加2次
	MAX(++nNumA, nNumB + 10); // nNumA被累加1次

	Max(++nNumA, nNumB);
	Max(++nNumA, nNumB + 10);
	return 0;
}
