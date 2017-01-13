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
	//思路：使用二进制提取个位数

	//int c = 1;
	short int a,b;
	//char b;
uup:
	printf("请随意按键：");
	 
	scanf_s("%d %d", &a ,&b);
	//a = a + b;
	//b = a - b;
	//a = a - b;

	//a = a * b;
	//b = a / b;
	//a = a / b;

	a ^=  b;
	printf("\n %d %d", a, b);
	b ^= a ;
	printf("\n %d %d", a, b);
	a ^= b;
	printf("\n %d %d", a,b);
	////异或法可以完成对整型变量的交换，对于浮点型变量它无法完成交换。第二类方法更像是玩了一个文字游戏，此种方法采用了在代码中嵌入汇编代码的方法避免了临时变量的引入
	
	goto uup;
	
	return 0;

}
