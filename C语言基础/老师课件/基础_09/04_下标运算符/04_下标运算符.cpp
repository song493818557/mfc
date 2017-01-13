// 04_下标运算符.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CTest
{

public:
	//返回值应该是一个引用
	//
	int&  operator[](int a)
	{
		
		if (a<20)
		{
			return nArray[a];
		}
		Error = -1;
		return Error;
	}
	CTest()
	{
		for (int i = 0; i < 20; i++)
		{
			nArray[i] = i;
		}
	}
static int Error;
private:
	int nArray[20];
	
};
int CTest::Error = 0;

int _tmain(int argc, _TCHAR* argv[])
{
	int nArray[20] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	
	CTest obj;

	int a = obj[2];
	obj[2] = 10;
	return 0;
}

