// 9_07_初始化的不确定问题.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CDesk  // 定义一个办公桌类
{ 
public: 
	int weight;  
	int high;  
	int width;  
	int length;
};
class CStool // 定义一个椅子类
{ 
public: 
	int weight;  
	int high;  
	int width;  
	int length;
};

CDesk g_objDesk;  // 全局对象

void fun() {
	static CStool objStool; // 局部静态对象
	CDesk objDesk;          // 局部对象
}
int _tmain(int argc, _TCHAR* argv[])
{
	CStool objS;             // 局部对象
	CDesk *pobj = new CDesk; // 堆对象
	CDesk  obj[50];          // 局部对象数组
	delete pobj;
	fun();
	return 0;
}


