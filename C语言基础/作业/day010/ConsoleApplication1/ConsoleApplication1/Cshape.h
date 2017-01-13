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
//�����ε����=�߳����߳�
class CRectangle:public Cshape
{
public:
	CRectangle() :m_length(0){};
	virtual ~CRectangle(){};
	virtual void Area(){ cout << "�����ε����" << m_length*m_length << endl; }
	virtual void seta(int length = 2){ m_length = length; }
private:
	int m_length;
};
//Բ�����=Բ���ʡ��뾶���뾶
class Circle :public Cshape
{
public:
	Circle() :m_pir(3.1314){};
	virtual ~Circle(){};
	virtual void Area(){ cout << "Բ�����" << m_pir*m_length*m_length << endl; }
	virtual void seta(int length = 2){ m_length = length; }
private:
	int m_length;
	int m_pir;
};