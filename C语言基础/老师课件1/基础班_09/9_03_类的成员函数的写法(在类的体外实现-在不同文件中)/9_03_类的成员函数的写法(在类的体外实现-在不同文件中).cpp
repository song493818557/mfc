// 9_03_类的成员函数的写法(在类的体外实现-在不同文件中).cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Date.h"

int main()
{
	CTdate date;
	date.set(10, 8, 2000);
	date.Isleapyear();

    return 0;
}

