// 9_06_C++�нṹ����������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//C++�ṹ����Ĭ�Ϸ���Ȩ��Ϊpublic(����)��
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

//����Ĭ�Ϸ���Ȩ��Ϊprivate(˽��)��
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

