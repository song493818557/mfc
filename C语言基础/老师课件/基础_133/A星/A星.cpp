// A��.cpp : �������̨Ӧ�ó������ڵ㡣
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

