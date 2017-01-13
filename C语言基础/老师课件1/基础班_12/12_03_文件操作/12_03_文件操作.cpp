// 12_03_文件操作.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	//文件输出
	ofstream cfout("c:\\context.txt");    //绝对路径,c盘需要管理员权限//属性,连接,清单文件
	//ofstream cfout("context.txt",ios::app); //相对路径

	cfout << "今天天气不错 \n"
		<< 123434 << endl;


	//文件输入
	ifstream cfin("c:\\context.txt");
	while (!cfin.eof())
	{
		char str[1024] = { 0 };
		cfin >> str;
		cout << str << endl;
	}
	

    return 0;
}

