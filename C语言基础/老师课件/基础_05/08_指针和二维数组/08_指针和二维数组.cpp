// 08_指针和二维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <stdio.h>
int main(void)
{
	int a[4][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{ 10, 11, 12 }
	};
	int(*p)[3] = a;
	

	int i, j;
	for (i = 0, j = 0; j < 12; j++)
	{
		printf("%d\t", *(*p + j));
		// *(*p + j)) 分解	*(a[0] + 0))
						//	*(a[0] + 1))
		                //	*(a[0] + 2))
	}
	//putchar('\n');
	//for (i = 1, j = 0; j < 3; j++)
	//{
	//	printf("%d\t", *(p[i] + j));
	//}
	//putchar('\n');
	//for (i = 2, j = 0; j < 3; j++)

	//	printf("%d\t", (*(p + i))[j]);
	//putchar('\n');
	//for (i = 3, j = 0; j < 3; j++)
	//{
	//	printf("%d\t", *(&p[0][0] + i * 3 + j));
	//}
	//putchar('\n');


//int(*p)[3] = a;
//01 00 00 00 * (*p + 0)//等于p[0][0]  *p 在这里默认等于该数组的首地址 这样可以每加一就可以到另外一个数组成员去   再进行解引用 不解引用定位的就是相对应的内存地址
//02 00 00 00 * (*p + 1)//等于p[0][1]
//03 00 00 00 * (*p + 2)//等于p[0][2]
//04 00 00 00 * (p[1] + 0)//定位到P[1]的内存地址 再进行相加 就可以到另外一个数组成员的内存地址
//05 00 00 00 * (p[1] + 1)
//06 00 00 00 * (p[1] + 2)
//07 00 00 00 (*(p + 2))[0] * (p + 2) 先定位到a[0]的内存地址  进行加法运算 再解引用 再进行a[0 + 2]的子成员进行运算 最终获得当前数组子成员的值
//08 00 00 00 (*(p + 2))[1]
//09 00 00 00 (*(p + 2))[2]
//0a 00 00 00 * (&p[0][0] + 3 * 3 + 0) &p[0][0] 定位到数组的首位 数组a[4][3] 的最后一组首位 再进行加法来输出a[4][0] 因为&p[0][0] + 3 * 3 + 0 这些都是地址的加法运算 需要加*（）解引用获得最终数据
//0b 00 00 00 * (&p[0][0] + 3 * 3 + 1)
//0c 00 00 00 * (&p[0][0] + 3 * 3 + 2)

return 0;
}

