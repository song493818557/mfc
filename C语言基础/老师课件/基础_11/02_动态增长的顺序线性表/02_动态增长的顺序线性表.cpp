// 02_��̬������˳�����Ա�.cpp : �������̨Ӧ�ó������ڵ㡣
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

