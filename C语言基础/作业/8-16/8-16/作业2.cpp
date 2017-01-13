// 8-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class Cshape{
public:
	virtual void Area(){}

	
};
class CRectangle:public Cshape{
public:
	CRectangle(float Clenght = 0) :m_length(Clenght){}
	virtual void Area(){
		cout << "正方形面积：" << m_length*m_length << endl;
	}
private:
	float m_length;
};
class CCircle :public Cshape{
public:
	CCircle(float Clenght = 0) :m_banjing(Clenght){}
	virtual void Area(){
		cout << "圆方形面积：" << 3.14*m_banjing*m_banjing << endl;
	}
private:
	float m_banjing;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Cshape* p[10] = {};

	//Cshape *p[10] = new Cshape[10];

	CCircle aa(3);
	Cshape *p1 = &aa;
	p1->Area();
	CRectangle ss(4);
	CCircle qq(3.4);
	CRectangle ww(3.2);
	CCircle ee(3.7);
	CRectangle rr(2.2);
	CCircle tt(3.4);
	CRectangle yy(3);
	CCircle uu(2.9);
	CRectangle ii(1.5);
	p[0] = &aa;
	p[2] = &qq;
	p[5] = &rr;
	p[6] = &tt;
	p[7] = &yy;
	p[8] = &uu;
	p[9] = &ii;
	for (int i = 0; i < 10;i++)
	{
		 p[i]->Area();
	}
	return 0;
}

