// A星.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "AStar.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CAStar obj;
	obj.SetInfo(5, 5, 30, 30);
	obj.SetMap();
	obj.PrintMap();
	obj.GetPath();
	obj.PrintPath();
	return 0;
}

