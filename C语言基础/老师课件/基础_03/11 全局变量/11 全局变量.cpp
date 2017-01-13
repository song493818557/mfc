// 11 全局变量.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

//extern int g_Num;//extern的作用就是，这个变量不在此文件中，去别的文件找一下
int g_Num;

void Fun(int a)
{
	printf("%d", g_Num);
	if (a%2 == 0)
	{
		g_Num = 1;
	}
	else
	{
		g_Num = 0;
	}

}

void fun()
{
	static int a = 10;//static 作用于局部变量的时候，它会使得变量值一直被保存住
	                  //即便退出了函数，下一次进入函数的时候，还是上一次离开函数
	                  //时候的值。
	printf("%d", a);
	a++;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//Fun(2);
	//int g_Num = 4;
	//printf("%d", g_Num);


	fun();
	fun();
	fun();
	return 0;
}

