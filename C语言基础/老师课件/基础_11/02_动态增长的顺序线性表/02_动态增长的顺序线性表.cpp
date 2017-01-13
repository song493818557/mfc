// 02_动态增长的顺序线性表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CMyList obj;
	obj.Init(2);
	obj.InsertEle(0x10, 0);
	obj.InsertEle(0x20, 0);
	obj.InsertEle(0x30, 1);
	obj.InsertEle(0x30, 2);
	return 0;
}

