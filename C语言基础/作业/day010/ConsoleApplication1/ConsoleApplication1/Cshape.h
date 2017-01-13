#pragma once
#include <iostream>
using namespace  std;

class Cshape
{
public:
	Cshape();
	virtual ~Cshape();
	virtual void Area() = 0;
	virtual void seta(int length = 2) = 0;
};
//正方形的面积=边长×边长
class CRectangle:public Cshape
{
public:
	CRectangle() :m_length(0){};
	virtual ~CRectangle(){};
	virtual void Area(){ cout << "正方形的面积" << m_length*m_length << endl; }
	virtual void seta(int length = 2){ m_length = length; }
private:
	int m_length;
};
//圆的面积=圆周率×半径×半径
class Circle :public Cshape
{
public:
	Circle() :m_pir(3.1314){};
	virtual ~Circle(){};
	virtual void Area(){ cout << "圆的面积" << m_pir*m_length*m_length << endl; }
	virtual void seta(int length = 2){ m_length = length; }
private:
	int m_length;
	int m_pir;
};