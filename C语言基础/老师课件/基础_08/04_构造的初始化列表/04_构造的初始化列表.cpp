// 04_构造的初始化列表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CHEHE
{
public:
	CHEHE(int a, int b)
	{

	}

};

class CTest
{
public:
	CTest(int a, int b=20, int c = 10) ://初始化表，
		m_a(a), m_b(b),//普通成员
		m_c(c),     //一般const类型的初始化，我们是写在初始化列表中的。
		m_d(c),     //引用类型的成员，也需要写在初始化列表中。
		objb(10,20) //没有无参构造的类对象，我们也需要在初始化列表中初始化
		Array(10,20,30) // 数组无法使用初始化列表
	{
		printf("我是有参数的构造");
		//对于类内的数组的初始化，就只能一个一个赋值了。
	}
	CTest():
		objb(11, 2), m_c(10), m_d(m_a)
	{
		printf("我是无参构造");
	}
private:
	int m_a;
	int m_b;
	//const int m_c = 10;这个语法，目前也是支持的了
	const int m_c;
	int & m_d;
	CHEHE objb;
	//int Array[20] = { 10, 20, 30 };
	int Array[20];
};

int _tmain(int argc, _TCHAR* argv[])
{
	CTest obj(10);


	return 0;
}

