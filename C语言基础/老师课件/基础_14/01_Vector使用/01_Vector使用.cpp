// 01_Vector使用.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <vector> // 1 包含头文件，注意没有.h
#include <set>
using std::vector;// 2 使用命名空间
using std::set;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> obj;
	vector<int> obj2;
	obj.push_back(0);
	obj.push_back(1);
	obj.push_back(2);
	obj.push_back(3);
	obj.push_back(4);
	obj.push_back(5);

	//第一种遍历方式
	//for (int i = 0; i < obj.size(); i++)
	//{
	//	printf("%d ", obj[i]);
	//	//printf("%d ", obj.at(i));上面和下面的规则是一样的
	//}
	//第二种遍历方式
	vector<int>::iterator vecit = obj.begin();//迭代器
	for (; vecit != obj.end(); vecit++)
	{
		printf("%d  ", *vecit);
	}
	vecit = obj.begin()+2;
	obj.insert(vecit, 10);//注意insert需要传递迭代器
	int a = 0;
	obj.pop_back( );             //删除最后一个数据
	obj.erase(obj.begin() + 2);  //删除指定位置的元素，注意要传递迭代器
	obj.clear();                 //清空

	obj2.push_back(100);
	obj2.push_back(200);
	obj2.push_back(300);
	obj2.push_back(400);
	obj2.push_back(500);
	obj.swap(obj2);
	obj[0] = 10;


	return 0;
}

