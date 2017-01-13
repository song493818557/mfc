// 递归示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
int n = 0;
void ZouLu(int 起点,int 终点)
{
	n++;
	if (终点 - 起点<0.1)
	{
		return;
	}
	else
	{
		ZouLu(起点, (起点 + (终点 - 起点) / 2));
		ZouLu((起点 + (终点 - 起点) / 2), 终点);
	}
	

}

int Clac(int n)
{
	if (n == 1)
	{
		return 1;
	}
	return n + Clac(n - 1);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int n = Clac(100);
	return 0;
}

