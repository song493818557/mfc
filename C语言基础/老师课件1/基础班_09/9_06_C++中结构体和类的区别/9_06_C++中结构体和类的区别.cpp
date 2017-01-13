// 9_06_C++中结构体和类的区别.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//C++结构体中默认访问权限为public(公开)的
struct SPoint3d
{
public:
	SPoint3d(float x, float y, float z) {};
	void print() {};
private:
	float m_x;
	float m_y;
	float m_z;
};

//类中默认访问权限为private(私有)的
class CPoint3d
{
public:   
	CPoint3d(float x, float y, float z) {};
	void print() {};
private:
	float m_x;
	float m_y;
	float m_z;
};

int main()
{
	SPoint3d stc_a(1, 2, 3);
	stc_a.print();

	CPoint3d obj_a(1, 2, 3);
	obj_a.print();
    return 0;
}

