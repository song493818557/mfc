// 9_09_带参数以及带初始化列表的构造函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CTemp
{
public:
	//CTemp() {}
	CTemp(int,int) {}
};

class CTest
{
public:
	CTest(int num)  //初始化列表,给数据成员提供了一个真正初始化的机会
		            //初始化列表的调用顺序,取决于数据成员的定义顺序
		:m_b(num),m_c(num), m_cTemp(num, 100)
	{
		m_a = num;
		//m_b = 100;
		//m_c = 100;
	}
private:
	int m_a;
	const int m_b;   //const 类型,只能初始化,不能赋值,所以放在初始化列表中
	int & m_c;       //引用  类型,只能初始化,不能赋值,所以放在初始化列表中
	CTemp m_cTemp;   //数据成员为类对象时,会隐式调用无参构造函数,如果该类没有无参构造函数,
	                 //则必须放在初始化列表中来显式调用其他有参构造函数
};


int main()
{
    return 0;
}

