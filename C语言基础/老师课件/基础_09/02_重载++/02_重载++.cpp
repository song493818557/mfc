// 02_重载++.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
enum MyEnum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};


class  CTest
{
public:
	CTest(int nX = 0,int nY = 0,int nDir = UP):
		m_x(nX), m_y(nY), m_nDir(nDir)
	{

	}
public:

	CTest operator++()//前置++
	{

		switch (m_nDir)
		{			
		case UP:
		{
			m_y--;
			break;
		}
			
		case DOWN:
		{
			m_y++;
			break;
		}
		case LEFT:
		{
			m_x--;
			break;
		}
		case RIGHT:
		{
			m_x++;
			break;
		}

		}
		/*CTest Temp(m_x, m_y, m_nDir);
		return Temp;*/

		return *this;//this就是本对象的地址，类型是CTest*
	}
	CTest operator++(int ) //后置++
	{
		CTest Temp(m_x, m_y, m_nDir);
		switch (m_nDir)
		{
		case UP:
		{
			m_y--;
			break;
		}

		case DOWN:
		{
			m_y++;
			break;
		}
		case LEFT:
		{
			m_x--;
			break;
		}
		case RIGHT:
		{
			m_x++;
			break;
		}

		}

		return Temp;
	}
private:
	int m_x;
	int m_y;
	int m_nDir;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest objA(1,1,UP);
	CTest objB;
	objB = objA++;

	objB = ++objA;

	int a = 0;
	int b = a++;
	b = ++a;
	return 0;
}

