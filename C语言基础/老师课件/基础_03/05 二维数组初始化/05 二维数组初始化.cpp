// 05 二维数组初始化.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{

	int Array1[3][4] = { 1, 2, 3 ,  4, 5, 6 ,  7, 8, 9  };//整体初始化

	int Array2[3][4] = { {1,2,3}, {4,5,6}, {7,8,9} };//分行初始化

	int Array3[] = { 1, 2, 3, 4, 5, 6 };             //一维数组省略长度

	int Array4[][4] = { 1, 2, 3, 4, 5, 6, 7, 8 };    //二维数组只能省略行数

	printf("%d",Array4[1][1]);

	return 0;
}

