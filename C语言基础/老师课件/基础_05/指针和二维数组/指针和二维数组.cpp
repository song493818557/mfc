// 指针和二维数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	
//
//	Array;   //整个数组的起始地址，类型是数组指针
//	Array[0];//第一排的起始地址，类型是一级指针，Array[0][0]才是int型
//	Array[1];//第二排的起始地址
//	Array[2];//第三排的起始地址
//
//	Array + 1;//往后加了16个字节
//	Array[0] + 1;//往后加了4个字节
////	printf("a:%d ,a[0]:%d a+1:%d  a[0]+1:%d", Array, Array[0],
//		Array + 1, Array[0] + 1;
//
//	
//	(*(Array + 1))[1];
//
//
//	if (&(*(Array + 1))[1] == &Array[1][1]){
//		printf("地址相同%d\n", &Array[1][1]);
//	}
//	else{
//		printf("地址不相同%d\n", &Array[1][1]);
//		printf("地址不相同%d\n", &(*(Array + 1))[1]);
//	}
//	//会变为1级指针类型
//
//	//*(Array + 0) 与Array[0] 与* (p + 0)与p[0]是等价的，都是第一排的首地址，
//	//类型都是一级指针类型。
//
//	//*(Array + 1) 与Array[1]是等价的
//	//*(Array + 2) 与Array[2]是等价的
//	*(Array + 1)[0]; Array[1][0]; *(p + 1)[0]; p[1][0];
//	*(*(Array + 1) + 0); *(Array[1] + 0); *(*(p + 1) + 0); *(p[1] + 0);
//	int(*p)[4] = Array;//数组指针的定义方式；
//	int Array[3][4];
//	int Array2[4] = { 0 };
//	int* p2 = Array2;
//	p = &Array2;//对一维名取地址，会变为一维数组指针类型，数值还是原来的数值，
//	            //并非真正的取出地址
//	p[1][0] = 10;
//
//	int(*p3)[4] = NULL;
//
	double* (*sp)[10] = {0};
	//double ** p = sp;
	//int ** p4 = &p3;

	return 0;
}

