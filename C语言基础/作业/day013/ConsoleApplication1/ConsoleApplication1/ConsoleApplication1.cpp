// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Clink.h"



int _tmain(int argc, _TCHAR* argv[])
{
	Clink mylist;
	mylist.Insertlink(3);
	mylist.Insertlink(4);
	mylist.Insertlink(55);
	mylist.Insertlink(6);
	mylist.Insertlink(77);
	mylist.Insertlink(8);
	mylist.Insertlink(9);
	mylist.Insertlink(22);
	mylist.Insertlink(33);
	mylist.Insertlink(66);
	TEAMINT bb;
	mylist.Deletelink(bb, 2);
	return 0;
}

