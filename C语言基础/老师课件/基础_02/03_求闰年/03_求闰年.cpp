// 03_求闰年.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{ 
	int nYear = 0;
	printf("请输入一个年份:");
	scanf_s("%d", &nYear);
	nYear++;
	if (nYear%4==0)
	{
		if (nYear % 100 == 0)
		{
			if (nYear%400 == 0)
			{
				printf("是闰年");
			}
			else
			{
				printf("不是闰年");
			}
		}
		else
		{
			printf("是闰年");
		}
	}
	else
	{
		printf("不是闰年");
	}

	//方法2：
	if ((nYear % 4 == 0 && nYear % 100 != 0) || nYear % 400 == 0)
	{
		printf("是闰年");
	}
	else
	{
		printf("不是闰年");
	}
	return 0;
}

