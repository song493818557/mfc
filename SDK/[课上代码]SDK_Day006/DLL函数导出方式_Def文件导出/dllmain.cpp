// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"

// 使用.DEF文件导出函数

int fun()
{
	return 0;
}

int fun2()
{
	return 0;
}


BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

