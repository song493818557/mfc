#pragma once
#include "Father.h"
class CChild_C:protected CFather
	                //文艺青年,将信将疑的继承父亲的属性
	                //(保护继承,有些属性(public)变为保护的,有些属性不变)
{
public:
	CChild_C();
	~CChild_C();

	void fun();
};

