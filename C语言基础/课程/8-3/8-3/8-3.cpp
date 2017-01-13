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
	short int a, b;
	//char b;
uup:
	
	//a = a + b;
	//b = a - b;
	//a = a - b;

	//a = a * b;
	//b = a / b;
	//a = a / b;

	//a ^=  b;
	//printf("\n %d %d", a, b);
	//b ^= a ;
	//printf("\n %d %d", a, b);
	//a ^= b;
	//printf("\n %d %d", a,b);
	////异或法可以完成对整型变量的交换，对于浮点型变量它无法完成交换。第二类方法更像是玩了一个文字游戏，此种方法采用了在代码中嵌入汇编代码的方法避免了临时变量的引入
	
	//问题一 为什么在进行数组链接的时候 接收的数组已经满了 
	//在局部变量里面已经溢出了 输出的时候还是正常输出？
	/*char sar[10] = { "123456" };
	char zar[] = { "asdfjgewqdffff" };
	//char zar[] = { 11, 12, 13, 4, 10, 24,0 };
	 a = strnlen_s(sar,100);
	 b = strnlen_s(zar, 100);
	 strcat_s(sar,100,zar);*/
	
	char jz[] = {"jkjkjkj","hjhjhkh","jhhjjhhh","hjhjhj"};
	
	printf("DEC: %s\n", jz);
	system("pause");
		return 0;

}
