// 9_01_面向对象的C语言.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CPoint3d
{
public:
	CPoint3d()
	{
		m_x = 10, m_y = 20, m_z = 30;
	}
	void Point3d_print()
	{
		printf("%f %f %f ", m_x, m_y, m_z);
	}
private:
	float m_x;
	float m_y;
	float m_z;
};
int main()
{
	CPoint3d point;
	point.Point3d_print();

    return 0;
}

