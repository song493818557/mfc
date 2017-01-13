// 02_多态的实例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
//假如突然之间着火了，不同的人，他会有不同的救命方式

class CPeople
{
public:
	virtual void Zhaohuole()
	{
		
	}
};

class Yang :public CPeople
{
public:
	void Zhaohuole()
	{
		printf("Yang:我去打水\n");
	}
};

class Gong :public CPeople
{
public:
	void Zhaohuole()
	{
		printf("Gong:我去拿灭火器\n");
	}
};
class Qi :public CPeople
{
public:
	void Zhaohuole()
	{
		printf("Qi:不行了，要跳楼\n");
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	CPeople* p[10];
	
	Yang objYang;
	Gong objGong;
	Qi   objQi;
	p[0] = &objYang;
	p[1] = &objGong;
	p[2] = &objQi;
	bool bFire = false;
	//1...执行了很多代码
	bFire = true;
	//2...突然之间着火了
	if (bFire == true)
	{
	/*	objYang.Zhaohuole();
		objGong.Zhaohuole();
		objQi.Zhaohuole();*/
		for (int i = 0; i < 3; i++)
		{
			p[i]->Zhaohuole(); 
		}
	}


	return 0;
}

