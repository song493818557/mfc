// A-star.cpp : 定义控制台应用程序的入口点。
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

