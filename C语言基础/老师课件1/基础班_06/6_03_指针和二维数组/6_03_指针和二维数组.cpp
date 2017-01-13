// 6_03_指针和二维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <typeinfo.h>

int main()
{
	int a[4][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{ 10, 11, 12 }
	};
	//数组名:可以隐式的转换为数组所存储类型的指针类型
	int(*p)[3] = a; //以前通过数组名使用数组 a[2][3];
	                //现在可以通过指针来使用数组
	//a = p;
	printf("%s \n", typeid(a).name());  //int[4][3]
	printf("%s \n", typeid(p).name());    //int(*)[3]   
	printf("%s \n", typeid(a + 0).name());	 //int(*)[3]
	printf("%s \n", typeid(a[0]).name());	 //int[3]
	printf("%s \n", typeid(&a[0]).name());	 //int(*)[3]
	printf("%s \n", typeid(&a).name());		 //int(*)[4][3]
	printf("%s \n", typeid(a[0][0]).name()); //int
	printf("%s \n", typeid(&a[0][0]).name());//int(*)

	int i, j;
	for (i = 0, j = 0; j < 3; j++)
	{
		printf("%d\t", *(*p + j));
	}
	putchar('\n');

	for (i = 1, j = 0; j < 3; j++)
	{
		printf("%d\t", *(p[i] + j));
	}
	putchar('\n');
	for (i = 2, j = 0; j < 3; j++)
	{
		printf("%d\t", (*(p + i))[j]);
	}
	putchar('\n');
	for (i = 3, j = 0; j < 3; j++)
	{
		printf("%d\t", *(&p[0][0] +i * 3 + j));
	}
	putchar('\n');

	return 0;
}

