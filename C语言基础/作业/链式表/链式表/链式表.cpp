// 链式表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Clinksa.h"
#include <process.h>

int _tmain(int argc, _TCHAR* argv[])
{
	Clinks aa;
	aa.Finsert(0,3);
	aa.Finsert(0, 4);
	aa.Finsert(0, 5);
	aa.Finsert(0, 7);
	aa.Finsert(1, 6); 
	aa.Finsert(0, 8);
	aa.Finsert(0, 9);
	aa.Finsert(0, 10);
	aa.Fprint();
	//int c = aa.Fdelete(1, c);
	//int d = aa.Fdelete(0, d);
	//int r = aa.Fdelete(5, r);
	//int e = aa.Fselect(8, e);
	aa.Fdeleteall();
	system("cls");
	aa.Fprint();
	return 0;
}

