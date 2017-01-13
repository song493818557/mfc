// AVL_Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "AvlTree.h"


int _tmain(int argc, _TCHAR* argv[])
{

	CAvlTree obj;
	obj.InsertEleDiGui1(88);
	obj.InsertEleDiGui1(75);
	obj.InsertEleDiGui1(62);
	obj.InsertEleDiGui1(50);
	obj.InsertEleDiGui1(37);
	obj.InsertEleDiGui1(25);
	obj.InsertEleDiGui1(12);
	obj.InsertEleDiGui1(76);
	obj.InsertEleDiGui1(78);
	obj.InsertEleDiGui1(94);
	obj.InsertEleDiGui1(50);
	obj.InsertEleDiGui1(294);
	obj.InsertEleDiGui1(150);
	obj.InsertEleDiGui1(114);
	obj.InsertEleDiGui1(142);
	obj.InsertEleDiGui1(124);
	obj.InsertEleDiGui1(66);
	obj.InsertEleDiGui1(53);
	obj.InsertEleDiGui1(119);
	obj.PreOrder();
	return 0;
}

