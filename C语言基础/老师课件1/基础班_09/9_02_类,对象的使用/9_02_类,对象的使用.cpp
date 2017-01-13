// 9_02_类,对象的使用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CPoint
{
public:
	CPoint()
	{
		m_x = 10;
		m_y = 20;
	}
	void print() {
		printf("%d ,%d ", m_x, m_y);
	}

	int m_x;
	int getY() const { return m_y; }
	void setY(int val) {
		if (val<0)  //增加一层过滤
		{
			return;
		}
		m_y = val; }
protected:  //保护属性和私有属性只有继承时才不一样
private:
	int m_y;
};
int main()
{
	//1.定义普通变量
	CPoint point;
	point.m_x = 50;   //公开数据直接访问
	point.setY(80);   //私有数据通过接口访问
	point.print();

	//2. 定义对象指针变量
	CPoint * pObj = new CPoint;
	//....一系列的操作
	delete pObj;

	pObj = nullptr;
	pObj = &point;
	pObj->m_x = 50;

	//3. 定义对象引用
	CPoint & obj = point;
	obj.m_x = 50;   //公开数据直接访问
	obj.setY(80);   //私有数据通过接口访问
	obj.print();

	//4. 定义对象数组
	CPoint objArr[10];
	objArr[0].m_x = 50;   //公开数据直接访问
	objArr[0].setY(80);   //私有数据通过接口访问
	objArr[0].print();

    return 0;
}

