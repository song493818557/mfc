// 复习.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//1 什么是指针？
	//1.1 他是一个变量
	//1.2 它是用来存储地址的
	//2指针的定义方式
	//类型* 变量名;
	//int* a,b;//正常来说是这么写，不会产生错觉
	//int *a,b;
	//int * a;
	//3指针应该如何去存储地址
	//int a = 100;
	//int b = 200;
	//char c = 'c';
	//int* p = &a;
	//p = &b;
	//p = (int*)&c;
	//4 指针如何引用
	//int a = 100;
	//int b = 200;
	//char c = 'c';
	//
	//int* p = &a;
	//*p = 200;

	//p = &b;
	//*p = 400;

	//p = (int*)&c;//虽然通过强制转换将字符型的地址赋值
	//             //给了整型指针，但这么做是不安全的
	//*p = 0x123456;//修改到了变量c后面的空间，极为不安全
	//5 指针和数组的相似性
	//int Array[10] = {0,1,2,3,4};
	//int *q = Array;
	//q[0];
	//q[1];
	//q[2];//指针和数组都可以使用下标，方式是一样的。

	//int a = 0;
	//(&a)[1] = 10;//讲INT A下一个变量的值修改为10
	//6 结构体
	//6.1 定义
	struct 
	{
		int a;
		char b;
		int c[10];

	}  stcTest = { 100, 'A', {'a','b','c'} };
	
	struct MYSTRUCT 
	{
		int a;
		char b;
		char c[10];

	};
	MYSTRUCT hehe = { 0, 'A', "hello" };
	MYSTRUCT* p = NULL;
	//6.2 使用
	hehe.a;
	hehe.b;
	p = &hehe;
	int * p2 = &hehe.a;
	printf("%p\n", &hehe);
	printf("%p", &hehe.a);
	p->a = 10;
	//&hehe和 &hehe.a得到的值是一样的，但是他们的类型
	//不一样，正是因为类型不一样，
	//结构体指针能够访问到结构体中的所有成员
	//而int*的指针只能访问a;
	//p.a = 10;
	//7 枚举

	//enum ABC{
	//	a,b,c,d,e //相当于定义了5个常量
	//};

	//ABC Num = ;
	//枚举变量，可以限制此变量存储的值，从而
	//减少我们写程序出错的概率。



	return 0;
}

