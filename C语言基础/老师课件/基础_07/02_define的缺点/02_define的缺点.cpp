// 02_define��ȱ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//Effective C++ 3rd��һ������
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
	MAX(++nNumA, nNumB);      // nNumA���ۼ�2��
	MAX(++nNumA, nNumB + 10); // nNumA���ۼ�1��

	Max(++nNumA, nNumB);
	Max(++nNumA, nNumB + 10);
	return 0;
}
