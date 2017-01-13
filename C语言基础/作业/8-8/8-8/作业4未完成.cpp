// 8-8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>

struct _bookinfo
{
	char book_name[100];
	char author_name[20];
	double book_price;
}; _bookinfo  oneinfo{ "钢铁是怎样炼成的", "王栋", 44.50 };
bool initBook(_bookinfo,unsigned int nCount);
bool FreeAllRecource(_bookinfo, unsigned int nCount);
int _tmain(int argc, _TCHAR* argv[])
{
	_bookinfo *moreinfo;
	moreinfo = (_bookinfo*)malloc(sizeof(_bookinfo) * 10);
	memset(
	moreinfo,
		0,
		sizeof(_bookinfo) * 10
		);
	return 0;
}

