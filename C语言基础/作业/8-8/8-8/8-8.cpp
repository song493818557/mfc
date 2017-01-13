// 8-8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <memory.h>
#include <string.h>
struct _bookinfo
{
	char* book_name;
	char* author_name;
	double book_price;
}; _bookinfo  oneinfo{ "钢铁是怎样炼成的", "王栋", 44.50 };
bool initBook(_bookinfo* &moreinfo, unsigned int nCount){
	moreinfo = (_bookinfo*)malloc(sizeof(_bookinfo) * nCount);

	if (!moreinfo)
	{
		return false;
	}
	memset(moreinfo, 0, sizeof(_bookinfo) * nCount);

	return true;
}
bool FreeAllRecource(_bookinfo* &moreinfo, unsigned int nCount)
{
	if (!moreinfo)
	{
		return true;
	}

// 	for (int i = 0; i < nCount;i++)
// 	{
// 		moreinfo[i]
// 
// 	}
	if (!moreinfo->book_name)
	{
		free(moreinfo->book_name);
		moreinfo->book_name = nullptr;
	}
	if (!moreinfo->author_name)
	{
		free(moreinfo->author_name);
		moreinfo->author_name = nullptr;
	}


	free(moreinfo);
	moreinfo = nullptr;


}



int _tmain(int argc, _TCHAR* argv[])
{
	_bookinfo *moreinfo = nullptr;
	initBook(moreinfo,10);


	free(moreinfo);
	moreinfo = nullptr;

	_bookinfo objA;
	char szBookName[20] = {};
	scanf_s("%s", szBookName,20);
	objA.book_name = (char*)malloc(strlen(szBookName) + 1);
	memset(objA.book_name, 0, strlen(szBookName) + 1);
	strcpy_s(objA.book_name, strlen(szBookName),szBookName);
	objA.book_price = 12.90;





	return 0;
}

