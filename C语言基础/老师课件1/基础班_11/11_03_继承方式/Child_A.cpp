#include "stdafx.h"
#include "Child_A.h"


CChild_A::CChild_A()
{
}


CChild_A::~CChild_A()
{
}

void CChild_A::fun()   //普通青年,全部原样的继承父亲的属性
{					   // (公有继承,继承下来的属性,保持原属性)
	m_Money;     //继承了父亲的钱        公有属性 -> 公有属性
	m_Face;      //继承了父亲的相貌      保护属性 -> 保护属性
	//m_WenHua;    //继承不了父亲的知识    私有属性 -> XXXXXXX
}
