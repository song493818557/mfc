// 测试进程当前目录和工作目录.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

int _tmain(int argc, _TCHAR* argv[])
{
	WCHAR currDirectory[ MAX_PATH ];
	SetCurrentDirectory(L"C:\\");
	// 获取进程的当前目录
	GetCurrentDirectory(MAX_PATH , currDirectory);

	MessageBox(NULL , currDirectory , L"进程当前目录" , 0);

	// 设置当前工作目录的API:
	
	return 0;
}

