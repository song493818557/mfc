// 07_类模板.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
template <typename T>
class CTest
{
public:
	void SetInfo(T obj)
	{
		m_Num1 = obj;
	}

	T m_Num1;
private:
};





int _tmain(int argc, _TCHAR* argv[])
{
	CTest<int>obj;
	printf("%d", sizeof(obj.m_Num1));

	CTest<char>obj2;
	printf("%d", sizeof(obj2.m_Num1));
	return 0;
}

