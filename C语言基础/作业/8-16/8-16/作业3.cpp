// 8-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class CTeacher{
public:
	virtual void getgongzi(){}

	
};
class Cjiaoshou :public CTeacher{
public: 
	Cjiaoshou(int number = 10) :m_number(number){	}
	virtual void getgongzi(){ 
		cout << "当前教授的工资是：" << m_gongzi + (m_keshi*m_number);
	}
private:
	int  m_gongzi =5000;
	int  m_keshi = 50;
	int  m_number;
};
class Cfujs :public CTeacher{
public: 
	Cfujs(int number = 10) :m_number(number){	}
	virtual void getgongzi(){
		cout << "当前教授的工资是：" << m_gongzi + (m_keshi*m_number);
	}
private:
	int  m_gongzi = 3000;
	int  m_keshi = 30;
	int  m_number;
};
class Cjiangshi :public CTeacher{
public: 
	Cjiangshi(int number = 10) :m_number(number){	}
	virtual void getgongzi(){
		cout << "当前教授的工资是：" << m_gongzi + (m_keshi*m_number);
	}
private:
	int  m_gongzi = 2000;
	int  m_keshi = 20;
	int  m_number;
};
int _tmain(int argc, _TCHAR* argv[])
{
	CTeacher* p[10] = {};

	//Cshape *p[10] = new Cshape[10];

	Cjiaoshou aa(30);
	Cjiaoshou ss(40);
	Cjiaoshou qq(30);
	Cjiangshi ww(30);
	Cjiangshi ee(30);
	Cjiangshi rr(20);
	Cjiangshi tt(3.4);
	Cfujs yy(30);
	Cfujs uu(30);
	Cfujs ii(20);
	p[0] = &aa;
	p[2] = &qq;
	p[5] = &rr;
	p[6] = &tt;
	p[7] = &yy;
	p[8] = &uu;
	p[9] = &ii;
	for (int i = 0; i < 10;i++)
	{
		if (p[i])
		{
			p[i]->getgongzi();
		}
		
	}
	return 0;
}

