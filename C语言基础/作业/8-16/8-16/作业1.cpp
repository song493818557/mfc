// 8-16.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "��ҵ1.h"
using std::cout;
using Hehe::g_num;
class CAnimal{
public:
	virtual void soud(){

	}


};
class Ccat :public CAnimal{
public:
	 void soud(){
		cout << "������\n";
	}


};
class CLeopard :public CAnimal{
public:
	 void soud(){
		cout << "����\n";
	}


};
int _tmain(int argc, _TCHAR* argv[])
{
	CAnimal *p[10];
	Ccat aa;
	CLeopard bb;
	p[0] = &aa;
	p[1] = &bb;
	p[0]->soud();
	p[1]->soud();
	return 0;
}

