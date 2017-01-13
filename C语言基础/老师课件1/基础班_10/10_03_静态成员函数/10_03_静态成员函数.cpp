// 10_03_静态成员函数.cpp : 定义控制台应用程序的入口点。
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
	static void showcount(CCounter obj)
	{
		cout << obj.m_nCount << endl;
		//m_nCount = 10;    //静态成员不能直接使用非静态数据成员
		m_nNum = 100;
	}
	
private:
	int m_nCount;
	static int m_nNum;
};
int CCounter::m_nNum = 0;

int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(15), objB(16);
	CCounter::showcount(objA);    //推荐使用类名来使用静态成员函数
	objB.showcount(objB);         //不推荐使用对象名.静态成员函数
	return 0;
}

