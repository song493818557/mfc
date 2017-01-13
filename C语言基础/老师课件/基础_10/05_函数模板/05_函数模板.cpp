// 05_函数模板.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

template <class T>
void swap(T &a,T &b)
{
	T Temp = a;
	a = b;
	b = Temp;
}
void swap(float& a, float& b) {
	
	float temp = a;
	a = b;
    b = temp;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int Num1 = 10;
	int Num2 = 20;
	char cCh1 = 'A';
	char cCh2 = 'B';
	swap(Num1, Num2);
	swap(cCh1, cCh2);
	return 0;
}

