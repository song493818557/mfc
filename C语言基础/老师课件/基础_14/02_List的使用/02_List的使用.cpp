// 02_List的使用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <list>  //1 包含头文件
using std::list; //2 使用命名空间

int _tmain(int argc, _TCHAR* argv[])
{
	//正式使用

	list<int> obj;

	obj.push_back(10); //在尾部插入
	obj.push_back(11); 
	obj.push_front(12);//在头部插入
	//遍历
	list<int>::iterator listit = obj.begin();
	for (; listit != obj.end(); listit++)
	{
		printf("%d", *listit);
	}

	return 0;
}

