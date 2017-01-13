// 使用DLL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>

//extern"C" 防止C++的名称粉碎机制
extern"C" int fun(); // 声明函数
typedef int(*fnFun)(); // 定义函数指针类型


int _tmain(int argc, _TCHAR* argv[])
{
	// 1. 显式链接
	//1.1 加载DLL
	// hDll : DLL的加载基址
	HMODULE hDll = LoadLibrary(L"创建DLL.dll");

	fnFun pfnFun = nullptr ; // 函数指针类型的变量
	// 1.2 获取DLL中的函数的地址
	pfnFun = (fnFun)GetProcAddress(hDll , "fun");
	// 1.3 调用函数
	pfnFun();

	//1.4 释放DLL
	FreeLibrary(hDll);

	return 0;
}

