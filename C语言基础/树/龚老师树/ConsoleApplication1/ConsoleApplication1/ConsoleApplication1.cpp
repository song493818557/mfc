// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Gtree.h" 


int _tmain(int argc, _TCHAR* argv[])
{
	CMyTree tt;
	tt.Insert(50);
	tt.Insert(25);
	tt.Insert(72);
	tt.Insert(12);
	tt.Insert(6);
	tt.Insert(16);
	tt.Insert(36);
	tt.Insert(30);
	tt.Insert(42);
	tt.Insert(78);
	tt.Delete(25);
	return 0;
}

