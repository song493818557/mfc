// 修改进程入口函数.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

// 修改入口函数
// '/entry: ' : 是链接器的参数,表示要修改入口函数
// `\"NewEntry\"` : 新的入口函数的名字
//#pragma comment(linker, "/entry:\"NewEntry\"")

int NewEntry2()
{
	MessageBox(0 , _T("NewEntry2") , _T("提示") , 0);

	return 0;
}

int NewEntry()
{
	MessageBox(0 , _T("NewEntry") , _T("提示") , 0);
	
	return 0;
}


int _tmain(int argc, _TCHAR* argv[])
{
	MessageBox(0 , _T("_tmain") , _T("提示") , 0);
	return 0;
}

