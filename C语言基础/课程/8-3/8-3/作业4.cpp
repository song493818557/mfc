// 8-3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
int _tmain(int argc, _TCHAR* argv[])
{
	//˼·��ʹ�ö�������ȡ��λ��

	int c = 1;
uup:
	printf("%d\n", c);

	if (c < 100){
		c++;
		goto uup;
	}
	system("pause");
	return 0;

}