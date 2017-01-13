// 10_01_深拷贝浅拷贝.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyString.h"
#include <iostream>
using namespace std;

int main()
{
	CMyString * pStr = new CMyString;
	strcpy_s(pStr->m_buf, pStr->m_size, "hello !");
	

	CMyString str1 = *pStr;
	CMyString str2(*pStr);

	delete pStr;

	cout << str1.m_buf << endl;

    return 0;
}

