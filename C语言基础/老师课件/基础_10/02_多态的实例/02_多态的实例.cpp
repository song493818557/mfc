// 02_��̬��ʵ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//����ͻȻ֮���Ż��ˣ���ͬ���ˣ������в�ͬ�ľ�����ʽ

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
		printf("Yang:��ȥ��ˮ\n");
	}
};

class Gong :public CPeople
{
public:
	void Zhaohuole()
	{
		printf("Gong:��ȥ�������\n");
	}
};
class Qi :public CPeople
{
public:
	void Zhaohuole()
	{
		printf("Qi:�����ˣ�Ҫ��¥\n");
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
	//1...ִ���˺ܶ����
	bFire = true;
	//2...ͻȻ֮���Ż���
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

