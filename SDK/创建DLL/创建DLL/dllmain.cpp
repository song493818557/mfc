// dllmain.cpp : 定义 DLL 应用程序的入口点。
#include "stdafx.h"
//DLL的入口函数 类似_tMain _winMain
/*
隐私连接
包含头文件
连接LIB文件
直接调用函数

把包含所有的DLL 先预先载入内存 再进入主函数运行

显式链接
显示连接需要三个函数
1 LoadLibrary  将DLL文件载入进程空间 并返回句柄
2 GetProcAddress 获取函数的地址  1句柄  函数名 得到函数地址 通过函数指针调用函数
3 FreeLibrary  释放DLL
*/
extern "C" //PE里面完全一样 如果支持C语言的话 就必须得用 extern "C"    不加extern C的 话 就是C++默认的函数粉碎机制
_declspec(dllexport)
int fun(){ 
	MessageBox(0, L"AA", L"DLL", 0);
	return 1;
}
BOOL APIENTRY DllMain( HMODULE hModule, //DLL被加载到的内存地址   模块句柄 模块加载基址
                       DWORD  ul_reason_for_call,//DLLMAIN被调用的原因
                       LPVOID lpReserved  
					 )
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH: //进程创建时被调用
		MessageBox(0, L"DLL_PROCESS_ATTACH", L"DLLMAIN", 0); break;
	case DLL_THREAD_ATTACH:	 //线程创建时 被调用
		MessageBox(0, L"DLL_THREAD_ATTACH", L"DLLMAIN", 0); break;
	case DLL_THREAD_DETACH:	//线程销毁时被调用
		MessageBox(0, L"DLL_THREAD_DETACH", L"DLLMAIN", 0); break;
	case DLL_PROCESS_DETACH:	//进程销毁时 被调用:
		MessageBox(0, L"DLL_PROCESS_DETACH", L"DLLMAIN", 0); break;
		break;
	}
	return TRUE;
}

