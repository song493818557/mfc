// 02_����++.cpp : �������̨Ӧ�ó������ڵ㡣
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

	CTest operator++()//ǰ��++
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

		return *this;//this���Ǳ�����ĵ�ַ��������CTest*
	}
	CTest operator++(int ) //����++
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

