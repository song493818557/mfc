// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>


int _tmain(int argc, _TCHAR* argv[])
{
	int a,b,c;
	scanf_s("%d", &a);
	if (a > 0)
	{
		b = a % 2;
		for (int i = b; i < a * 2; i += 2){
			if (i != 0)
			{
				printf("%3d  ", i);
			} 
		}
	}
	system("pause");
	return 0;
}

