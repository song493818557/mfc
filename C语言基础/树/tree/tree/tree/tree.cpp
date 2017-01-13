// tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Ctree.h"

int _tmain(int argc, _TCHAR* argv[])
{

	Ctree tree;
	int nerror;
	tree.Insert(88, nerror);
	tree.Insert(75, nerror);
	tree.Insert(62, nerror);
	tree.Insert(50, nerror);
	tree.Insert(37, nerror);
	tree.Insert(25, nerror);
	tree.Insert(12, nerror);
	tree.Insert(76, nerror);
	tree.Insert(78, nerror);
	tree.Insert(94, nerror);
	tree.Insert(50, nerror);  
	tree.Insert(294, nerror);
	tree.Insert(150, nerror);
	tree.Insert(114, nerror);
	tree.Insert(142, nerror);
	tree.Insert(124, nerror);
	tree.Insert(66, nerror);
	tree.Insert(53, nerror);
	tree.Insert(119, nerror);
	tree.PreOrder();
	return 0;
}

