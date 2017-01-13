#include "stdafx.h"
#include "Child_C.h"


CChild_C::CChild_C()
{
}


CChild_C::~CChild_C()
{
}

void CChild_C::fun()//文艺青年,将信将疑的继承父亲的属性
{					//(保护继承,有些属性(public)变为保护的,有些属性不变)
	m_Money;        //继承了父亲的钱        公有属性 -> 保护属性
	m_Face;			//继承了父亲的相貌      保护属性 -> 保护属性
	//m_WenHua;		//继承不了父亲的知识    私有属性 -> XXXXXXX
}
