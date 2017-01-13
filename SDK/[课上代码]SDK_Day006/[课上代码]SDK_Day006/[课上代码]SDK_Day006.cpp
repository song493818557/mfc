// [课上代码]SDK_Day006.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <tchar.h>
#include <thread>

using   std::thread;
int _tmain(int argc, _TCHAR* argv[])
{
	__declspec (thread) class aa;
	aa.
	STARTUPINFOW startInfo = { 0 };//进程启动信息结构体
	startInfo.cb = sizeof(STARTUPINFOW);
	PROCESS_INFORMATION processInfo = { 0 }; // 函数输出的进程信息

	//HANDLE hTrhea; <== 父进程拥有的句柄

	CreateProcess(_T("C:\\Program Files (x86)\\Tencent\\QQ\\Bin\\QQScLauncher.exe") ,// 进程文件路径
				  NULL , // 命令行参数
				  0 , // 进程安全属性
				  0 , //线程安全属性
				  FALSE ,//创建出的子进程是否继承父进程的句柄
				  0 ,
				  0 ,// 环境变量快
				  0 ,//进程当前目录
				  &startInfo ,
				  &processInfo
				  );

	
	return 0;
}

