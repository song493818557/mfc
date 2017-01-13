// 03_BiTree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "BiTree.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CBiTree obj;
	obj.InsertEle(50);
	obj.InsertEle(25);
	obj.InsertEle(75);
	obj.InsertEle(12);
	obj.InsertEle(37);
	obj.InsertEle(62);
	obj.InsertEle(88);
	//obj.Pre();
	obj.DeleteEle(50);
	obj.DeleteEle(75);
	return 0;
}

