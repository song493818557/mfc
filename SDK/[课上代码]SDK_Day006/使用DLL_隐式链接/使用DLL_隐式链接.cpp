// 使用DLL_隐式链接.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

// 隐式链接使用DLL
//步骤
// 1. 导入头文件
//		如果没有头文件, 则需要字节声明函数
// 2. 导入静态库
extern"C" int fun();
// 导入静态库
#pragma comment(lib,"创建DLL.lib")

int _tmain(int argc, _TCHAR* argv[])
{
	// 3. 直接调用函数
	fun();
	return 0;
}

