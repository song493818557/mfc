// 8-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <process.h>
#include <string.h>
#include "stdio.h"
#include <conio.h>
#include<stdlib.h>
int _tmain(int argc, _TCHAR* argv[])
{
	 

	short int x, y, numb = 0;
	int i = 0;
	int gg = 0;
	//char z;
	//char jz[18] = {9};
	scanf_s("%hd", &x);
	printf("DEC: %x\n", x);
gogoto:
	i++;
	if (i < 16){
		y = 0;
		y = ((x >> (15 - i)) & 1);
		numb += (y == 0) ? 0 : 1;
		//jz[i] = z;
		goto gogoto;
	}
	//jz[i] = 0;
	printf("该整数有%d个1\n", numb);
	//printf("完整二进制是%s", jz[i],17);
	system("pause");
	return 0;

}
