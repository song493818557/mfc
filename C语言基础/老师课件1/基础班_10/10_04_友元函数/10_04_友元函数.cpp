// 10_04_友元函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class CCounter
{
public:
	CCounter(int nNum)
	{
		m_nCount = nNum;
	}
	friend void showcount(CCounter &obj); //声明友元函数

private:
	int m_nCount;
};

void showcount(CCounter &obj)            //实现友元函数
{
	cout << obj.m_nCount << endl;        //函数体内能通过对象使用private,protect成员
}

int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(15);
	//objA.showcount(objA);   //友元函数不是成员函数,不能通过对象来调用

	showcount(objA);
	return 0;
}

