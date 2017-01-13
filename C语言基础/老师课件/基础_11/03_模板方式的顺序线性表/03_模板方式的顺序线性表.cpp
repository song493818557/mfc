// 03_模板方式的顺序线性表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"

class CTest
{
public:
	CTest() :m_a(10), m_b(20)
	{

	}
	friend std::ostream& operator<<(std::ostream& os, CTest);
private:
	int m_a;
	int m_b;
};
std::ostream& operator<<(std::ostream& os, CTest obj)
{
	os << obj.m_a << obj.m_b;
	return os;
}
int _tmain(int argc, _TCHAR* argv[])
{
	CMyList<int> obj;
	obj.Init(2);
	obj.InsertEle(0x10, 0);
	obj.InsertEle(0x20, 0);
	obj.InsertEle(0x30, 1);
	obj.InsertEle(0x30, 2);
	//obj.PrintAll();

	CMyList<CTest> obj2;
	obj2.Init(2);
	CTest hehe;
	CTest haha;

	obj2.InsertEle(hehe,0);
	obj2.InsertEle(hehe, 1);
	obj2.PrintAll();
	return 0;
}

