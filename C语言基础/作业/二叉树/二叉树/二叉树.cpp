// 二叉树.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Cbtree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Cbtree atree;
	//atree.Finsert_Elt(50);
	atree.Finsert_Elt(50);
	atree.Finsert_Elt(25);
	atree.Finsert_Elt(75);
	atree.Finsert_Elt(12);
	atree.Finsert_Elt(37);
	atree.Finsert_Elt(62);
	atree.Finsert_Elt(64);
	atree.Finsert_Elt(99);
	atree.Finsert_Elt(108);
	atree.Finsert_Elt(344);
	atree.Finsert_Elt(88);
	
	//前后序
	//atree.Pre();
	printf("\n ");
	atree.Premidell();
	atree.FDelete_Elt(75);
	atree.Pre();
	return 0;
}

