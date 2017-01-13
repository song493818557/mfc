// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

// DLL的入口函数


_declspec(dllexport)  int cppFun()
{
	return 0;
}

_declspec(dllexport)  int cppFun(int nNum)
{
	return nNum;
}

_declspec(dllexport)  int cppFun(int nNum ,char ch)
{
	return nNum;
}


int fun2()
{
	return 0;
}

extern"C"   // 以C语言的方式导出一个函数
_declspec(dllexport)  // 用于声明一个函数会被导出
int fun()
{
	fun2();
	return MessageBox(0 , L"Hello" , 0 , 0);
}


// 模块句柄 , 模块加载基址 
BOOL APIENTRY DllMain( HMODULE hModule, // DLL被加载到的内存地址
                       DWORD  ul_reason_for_call,//DllMain被调用的原因
                       LPVOID lpReserved
					 )
{
	switch(ul_reason_for_call)
	{
		case DLL_PROCESS_ATTACH: // 进程创建时被调用
			MessageBox(0 , L"进程创建时被调用" , L"DllMain" , 0);
			break;
		case DLL_THREAD_ATTACH:  // 线程创建时被调用
			MessageBox(0 , L"线程创建时被调用" , L"DllMain" , 0);
			break;
		case DLL_THREAD_DETACH:  // 线程退出时被调用
			MessageBox(0 , L"线程退出时被调用" , L"DllMain" , 0);
			break;
		case DLL_PROCESS_DETACH: // 进程退出时被调用
			MessageBox(0 , L"进程退出时被调用" , L"DllMain" , 0);
			break;
	}
	return TRUE;
}

