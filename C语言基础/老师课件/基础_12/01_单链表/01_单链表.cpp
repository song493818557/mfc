// 01_������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "LinkList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	CLinkList  objList;
	int nData;
	objList.InsertEle(0, 10);
	objList.InsertEle(0, 20);
	objList.InsertEle(0, 30);
	objList.InsertEle(1, 40);
	//30 40 20 10
	objList.printfAll();
	objList.DeleteEle(1, nData);
	return 0;
}

