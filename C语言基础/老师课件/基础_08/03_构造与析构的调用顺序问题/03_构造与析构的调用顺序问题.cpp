// 03_构造与析构的调用顺序问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


class CFadongji
{
public:
	CFadongji()
	{
		printf("jifadong\n");
	}
	~CFadongji()
	{
		printf("~jifadong\n");
	}
};
class CLunzi
{
public:
	CLunzi()
	{
		printf("lunzi\n");
	}
	~CLunzi()
	{
		printf("~lunzi\n");
	}
};

class CCar
{
public:
	CCar()
	{
		printf("qiche\n");
	}
	~CCar()
	{
		printf("~qiche\n");
	}
private:
	int m_NumA;
	CFadongji m_obj;
	CLunzi m_obj2;
};


int _tmain(int argc, _TCHAR* argv[])
{
	CCar obj;
	return 0;
}

