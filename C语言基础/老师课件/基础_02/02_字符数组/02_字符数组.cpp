// 02_字符数组.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

int _tmain(int argc, _TCHAR* argv[])
{
	char    cArray1[6] = { 'a', '1', 'p', 'a', 's', 's' };
	char    cArray2[7] = "a1pass";
	wchar_t cArray3[6] = { L'a', L'1', L'p', L'a', L's', L's' };
	wchar_t cArray4[7] = L"a1pass";
	printf("%s\n", cArray2);//没有问题
	printf("%s\n", cArray1);//有问题的，当字符串来使用时，需要一个0为结尾

	printf("%d", sizeof(cArray1));

	printf("%d", sizeof(cArray3));

	int nCount = strnlen_s(cArray1, 6);

	nCount = wcslen(cArray4);



	//char cCh = 0;
	//scanf_s("%c", &cCh,1);
	char buf[10] = { 0 };
	scanf_s("%s", buf,10);
	return 0;
}

