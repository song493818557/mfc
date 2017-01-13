// 10_07_运算符重载的基本语法.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Counter_A.h"
#include "Counter_B.h"
#include <iostream>
using namespace std;

int main()
{
	CCounter_A count,count2(88);

	int re1 = (++count).getNum();
	int re2 = (count++).getNum();

	int re3 = count + count2;
	count.operator+( count2);  // 成员函数 显式调用

	CCounter_B countB, countB2(88);

	re1 = (++countB).getNum();
	re2 = (countB++).getNum();

	re3 = countB + countB2;
	operator+(countB, countB2); //友元函数 显式调用

	//cout << count;
    return 0;
}

