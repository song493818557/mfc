// 11_03_继承方式.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Father.h"
#include "Child_A.h"
#include "Child_B.h"
#include "Child_C.h"


int main()
{
	CFather  father;   //类体外只能访问公有属性
	father.m_Money;

	CChild_A child_A;  //公有继承 
	child_A.m_Money;

	CChild_B child_B;  //私有继承
	//child_B.m_Money;

	CChild_C child_C;  //包含继承
	//child_C.m_Money;

    return 0;
}

