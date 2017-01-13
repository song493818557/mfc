#pragma once
#include "Father.h"

class CChild_A:public CFather  //普通青年,全部原样的继承父亲的属性
	                           // (公有继承,继承下来的属性,保持原属性)
	                   
{
public:
	CChild_A();
	~CChild_A();

	void fun();
};

