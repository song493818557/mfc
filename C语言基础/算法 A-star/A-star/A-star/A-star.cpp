// A-star.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "cstar.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Cstar aa(3,3,32,32);
	aa.Setmap();
	aa.Drawmap();
	aa.Getpath();
	aa.PrintPath();
	return 0;
}

