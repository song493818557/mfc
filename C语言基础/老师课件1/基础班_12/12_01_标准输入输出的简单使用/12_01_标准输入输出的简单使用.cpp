// 12_01_标准输入输出的简单使用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char str[] = { "hello" };
	int nNum = 10;
	//从标准设备中读取
	cin >> nNum ;                //键盘  ,若输入错误，请看第一天的项目。
	 
	cout << nNum <<str<< endl;   //显示器
	cerr << nNum <<str<< endl;   //显示器
				  
	clog << nNum <<str<< endl;   //用于打印

    return 0;
}

