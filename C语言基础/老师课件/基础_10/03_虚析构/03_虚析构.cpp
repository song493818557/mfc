// 03_虚析构.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CBase
{
public:
	virtual ~CBase()
	{
		printf("我是父类析构函数");
	}
};

class CTest :public CBase
{
public:
	CTest()
	{
		Name = new char[20];
	}
	~CTest()
	{
		printf("我是子类析构函数");
		delete[]Name;
	}
private:
	char * Name;
};

int _tmain(int argc, _TCHAR* argv[])
{
	CBase *p = new CTest[2];


	//假如父类的析构函数不是虚函数，那么，就不会调用子类的析构
	//有可能造成资源泄露，
	delete []p;
	return 0;
}

