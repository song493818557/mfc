#include "stdafx.h"
#include "Child_B.h"


CChild_B::CChild_B()
{
}


CChild_B::~CChild_B()
{
}

void CChild_B::fun()//2B青年,一律否定的继承父亲的属性
{					//(私有继承,继承下来的属性全部变为私有的,不再给孙子类继承)
	m_Money;        //继承了父亲的钱        公有属性 -> 私有属性
	m_Face;		    //继承了父亲的相貌      保护属性 -> 私有属性
	//m_WenHua;	    //继承不了父亲的知识    私有属性 -> XXXXXXX
}
