// 03_map.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <map>
using std::map;
using std::pair;
int _tmain(int argc, _TCHAR* argv[])
{
	//  key  value
	map<int, char> obj; //插入的时候，key是不能重复的，相当于一个标识

	obj.insert(pair<int ,char>(10, 'A'));//插入数据的话，需要按对插入
	obj.insert(pair<int, char>(11, 'B'));
	obj.insert(pair<int, char>(12, 'B'));
	obj.insert(pair<int, char>(14, 'B'));

	printf("%c", obj[14]);  //想要获得某一个Key的value
	return 0;

}

