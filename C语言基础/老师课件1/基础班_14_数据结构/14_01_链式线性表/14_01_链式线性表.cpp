// 14_01_��ʽ���Ա�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyList.h"


int main()
{
	CMyList list;
	list.InsertList(44);
	list.InsertList(55);
	list.InsertList(66);
	list.InsertList(77);
	list.InsertList(88);

	list.InsertList(7878, 2);
	int nRe = 0;
	list.DeleteList(nRe, 2);
	list.DeleteList(nRe, 2);

    return 0;
}

