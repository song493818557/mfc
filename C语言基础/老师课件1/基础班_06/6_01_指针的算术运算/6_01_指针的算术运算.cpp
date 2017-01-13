// 6_01_指针的算术运算.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
1.	只能进行加法和减法运算：+  -  ++  --  +=  -=
2.	两种形式：指针±整数  或者  指针 - 指针
3.	指针与整型值加减的结果是指针，表示使该指针移动 
( 整型值*存储单元的大小) 之后的内存地址。
存储单元的大小就是该指针所指向的数据类型所需的内存大小。
4.	指针与指针的减运算要求相减的两个指针属于同一类型，
其结果是整数，表示两个指针之间的数据的个数，并非两个地址的差值。

*/
int main()
{
	int nNumA = 0x11111111;
	int arr[10] = {1,2,3,4,5,6,7,8,9,10};
	int * p = arr;
	for (int i = 0; i < 10;i++)
	{
		printf("%d", *p);
		p++;
	}
	int nNumB = 0x22222222;

	int * pNumA = &arr[4];
	int * pNumB = &arr[9];

	int nResult = 0;
	//pNumA + pNumB;  //error
	nResult = pNumA - pNumB;
	//pNumA * pNumB;  //error
	//pNumA / pNumB;  //error

	pNumA = pNumA + 5;
	pNumA = pNumA - 5;

	pNumA = &nNumA;
	pNumB = &nNumB;
	nResult = pNumA - pNumB;

	char ch = 'h';
	char * pCh = &ch;
	//nResult = pNumA - pCh;   //error: 两个指针必须类型相同

    return 0;
}

