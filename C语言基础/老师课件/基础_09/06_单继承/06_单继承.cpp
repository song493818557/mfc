// 06_单继承.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CBase
{
public:
	int m_a;
	int m_b;
};

class CTest :  public CBase//这个就叫做继承，并且是公有继承
{
public:
	int m_c;
private:
};



int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj;
	obj.m_a = 10;
	obj.m_b = 20;
	printf("%d", sizeof(CTest));
	return 0;
}

