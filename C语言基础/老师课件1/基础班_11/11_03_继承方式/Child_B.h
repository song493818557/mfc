#pragma once
#include "Father.h"
class CChild_B :private CFather //2B青年,一律否定的继承父亲的属性
{                               //(私有继承,继承下来的属性全部变为私有的,不再给孙子类继承)
public:
	CChild_B();
	~CChild_B();

	void fun();
};

