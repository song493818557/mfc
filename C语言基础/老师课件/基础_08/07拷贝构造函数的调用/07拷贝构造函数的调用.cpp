// 07拷贝构造函数的调用.cpp : 定义控制台应用程序的入口点。
//
// 06 拷贝构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

int g_Num = 0;
class CTest
{
public:
	CTest()
	{
		m_Num = g_Num;
		g_Num++;
		printf("我是构造%d\n", m_Num);

	}
	~CTest()
	{
		printf("我是析构%d\n", m_Num);
	}
	CTest(CTest & Other)
	{
		m_Num = g_Num;
		g_Num++;
		printf("我是拷贝构造函数%d\n", m_Num);
	}
private:
	int m_Num;
};

CTest Fun(CTest const &a)//假如你只想使用外部对象传入的值，而并非要修改
                         //就可以传引用参数，这样能够避免拷贝，提升程序效率
{
	return ;
}

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA;
	CTest objc(objA);
	CTest objB = Fun(objA);
	int a = 0;
	a++;
	a--;
	a++;
	a--;
	return 0;
}

