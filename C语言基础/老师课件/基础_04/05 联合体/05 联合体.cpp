// 05 ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdlib.h>
union _TEMP
{
	char a;
	int  b;
}g_T;
int _tmain(int argc, _TCHAR* argv[])
{
	g_T.a = 66;
	g_T.b = 100;
	printf("%x:%d,%x:%d", &g_T.a, g_T.a, &g_T.b, g_T.b);
	system("pause");
	return 0;
}
