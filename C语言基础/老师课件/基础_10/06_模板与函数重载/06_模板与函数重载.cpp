// 06_模板与函数重载.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


template <class T>
void swap(T &a, T &b)
{
	T Temp = a;
	a = b;
	b = Temp;
}
//函数模板也是可以构成重载的
template <class T>
void swap(T a)
{

}
//函数模板也不会影响普通函数的重载
void swap(int a, int b)
{
	int Temp = a;
	a = b;
	b = Temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int Num1 = 20;
	int Num2 = 10;
	swap(Num1,Num2);//假如普通函数与模板冲突，会优先调用普通函数
	return 0;
}

