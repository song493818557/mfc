// �ݹ�ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int n = 0;
void ZouLu(int ���,int �յ�)
{
	n++;
	if (�յ� - ���<0.1)
	{
		return;
	}
	else
	{
		ZouLu(���, (��� + (�յ� - ���) / 2));
		ZouLu((��� + (�յ� - ���) / 2), �յ�);
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

