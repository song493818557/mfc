// 06 十进制转换二进制.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int Num = 0;
	int Array[32];
	scanf_s("%d", &Num);
	int i = 0;
sign:

	Array[i] = Num % 2;
	Num = Num / 2;

	if (Num != 0)
	{
		i++;
		goto sign;
	}
sign2:
	printf("%d", Array[i]);
	i--;
	if (i>=0)
	{
		goto sign2;
	}
	return 0;
}

