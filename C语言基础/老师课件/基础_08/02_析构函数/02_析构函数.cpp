// 02_析构函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int g_Num = 0;
class CTest
{
public:
	CTest()  {  // 构造函数
		m_num = g_Num;
		g_Num++;

		//printf("我是%d号构造",m_num);
		m_szName = new char[20];

	}
	~CTest() {  // 析构函数
		printf("我是%d号析构", m_num);
		delete[] m_szName;
	}
	void Shifang()
	{
		delete[]m_szName;
	}
protected:
	char *m_szName;
	int m_num;
};

CTest obj1;

int _tmain(int argc, _TCHAR* argv[])
{
	//CTest obj;//对象产生，会自动调用构造函数
	//obj.Shifang();
	//CTest * p = new CTest;

	//delete p;

	return 0;//局部对象即将自动销毁，会自动调用析构函数
}

