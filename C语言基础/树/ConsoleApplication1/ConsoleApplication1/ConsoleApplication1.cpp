// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "avltree.h"


int _tmain(int argc, _TCHAR* argv[])
{
	Cavltree aa;
	aa.inserttree(88);
	aa.inserttree(75);
	aa.inserttree(62);
	aa.inserttree(50);
	aa.inserttree(37);
	aa.inserttree(25);
	aa.inserttree(12); 
	aa.inserttree(50);
	aa.inserttree(294);
	aa.inserttree(150);
	aa.inserttree(114);
	aa.inserttree(142);
	aa.inserttree(124);
	aa.inserttree(66);
	aa.inserttree(53);
	aa.inserttree(119);
//	aa.deletree(37);
	aa.Traverse();
	aa.deletree(124);
	aa.inserttree(124);
	aa.Traverse();
	return 0;
}

