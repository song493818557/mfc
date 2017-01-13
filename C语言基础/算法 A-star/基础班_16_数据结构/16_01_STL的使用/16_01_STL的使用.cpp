// 16_01_STL的使用.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <string>
#include <set>
#include <stack>
#include <queue>
//using namespace std;
using std::vector;
using std::list;
using std::deque;
using std::map;
using std::string;
using std::pair;
using std::set;
using std::stack;
using std::queue;

void tryVector() {
	vector<int> vec;
	vector<int> vec2 = vec;
	vector<int> vec3(vec);
	vector<int> vec4(100);

	//vector<int>::iterator it = vec.begin();

	//-------增----------
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);//插入末尾
	}
	vector<int>::iterator it = vec.begin();
	vec.insert(it + 5, 100);//插入任意位置

							//--------查-----------
	for (int i = 0; i < vec.size(); i++)   //通过[]+下标
	{
		printf("%d ", vec[i]);
	}
	printf("\n");                      //通过迭代器+偏移
	for (vector<int>::iterator it = vec.begin();
	it != vec.end(); it++)
	{
		printf("%d ", *it);
	}
	//-------修改---------------
	vec[6] = 88;
	*(vec.begin() + 6) = 66;

	//-------删除---------------
	it = vec.begin();
	vec.erase(it + 2);    //通过迭代器删除
	vec.pop_back();     //删除最后元素
						//删除指定值的元素(边遍历边删除)
	for (vector<int>::iterator it = vec.begin();
	it != vec.end(); )
	{
		if (*it == 100)
		{
			it = vec.erase(it);
		}
		else {
			printf("%d ", *it);
			//业务逻辑
			//....

			it++;
		}
		
	}

	printf("\n调用clear前的size/capacity %d,%d",vec.size(), vec.capacity());
	vec.clear();        // 删除所有元素
	printf("\n调用clear后的size/capacity %d,%d",vec.size(), vec.capacity());

	vec.swap(vector<int>());
	//vector<int>().swap(vec);

	printf("\n调用clear后的size/capacity %d,%d",vec.size(), vec.capacity());



}

void tryList() {

	list<int> li;
	list<int>::iterator it = li.begin();
	//---增--------
	for (int i = 0; i < 10; i++)
	{
		li.push_front(i);
		li.push_back(i);
	}
	//it = li.begin();
	//li.insert(it++, 99);

	//---查--------
	printf("\n");
	int i = 0;
	for (it = li.begin();it != li.end();it++, i++)
	{
		if (i == 5)
		{
			*it = 66;               //修改
			it = li.insert(it, 99); //插入
		}
		printf("%d ", *it);
	}
	//---改--------
	//---删--------
	li.pop_front();
	li.pop_back();
	for (it = li.begin(); it != li.end(); )
	{
		if (*it == 66)
		{
			it = li.erase(it);
		}
		else {
			it++;
		}
	}

}

void tryDeque() {

	deque<int> deq;
	deque<int>::iterator it = deq.begin();

	//---增--------
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	it = deq.begin();
	deq.insert(it + 3, 88);

	//---查--------
	printf("\n");
	for (int i = 0; i < deq.size(); i++)
	{
		printf("%d ", deq[i]);
	}
	for (it = deq.begin(); it != deq.end(); it++)
	{
		printf("%d ", *it);
	}
	//---修改--------
	*(deq.begin() + 5) = 66;
	deq[5] = 77;

	//---删除--------
	deq.erase(deq.begin() + 5);
	deq.pop_back();
	deq.clear();

}

void tryMap() {
	map<string, int> mm;
	map<string, int>::iterator it = mm.begin();

	//------增-------
	mm.insert(pair<string, int>("姚荣昌", 99));
	mm.insert(pair<string, int>("吴伟峰", 88));
	mm.insert(pair<string, int>("朱崇明", 77));

	mm.insert({ "宋佳星", 77 });

	mm["袁兵兵"] = 66;
	mm["刘晨星"] = 55;
	string keys[2] = { "胡亮","李东" };
	for (int i = 0; i < 2; i++)
	{
		mm[keys[i]] = i;
	}
	mm["袁兵兵"] = 55;
	mm["袁兵兵"] = 22;
	//----查询----------
	for (it = mm.begin(); it != mm.end(); it++)
	{
		printf("\n名字:%s,id:%d",
			it->first.c_str(), it->second);
		//cout<< it->first
	}

	//----查询/删除----------
	it = mm.find("孟达");
	it = mm.find("宋佳星");
	for (it = mm.begin(); it != mm.end();) {
		if (it->second == 22 || it->first == "刘晨星")
		{
			it = mm.erase(it);
		}
		else {
			it++;
		}
	}

	mm.clear();

}

void trySet() {

	set<string> testSet;
	set<string>::iterator it = testSet.begin();

	//-----增-----
	testSet.insert("朱凯");
	testSet.insert("黄晓");
	testSet.insert("沈士昌");

	testSet.insert(testSet.begin(), "余昌平");

	//-----查-----
	for (it = testSet.begin();
	it != testSet.end(); it++)
	{
		printf("\n %s ", it->c_str());
	}
	it = testSet.find("余昌平");

}

void tryStack() {
	stack<int> MyStack;
	//------增-----
	for (int i = 0; i < 10; i++)
	{
		MyStack.push(i);
	}
	//------删-----
	MyStack.pop();
	MyStack.pop();
	//------查-----
	int top = MyStack.top();

	int size = MyStack.size();

}

void tryQueue() {
	queue<int> que;
	//----增------
	for (int i = 0; i < 10; i++)
	{
		que.push(i);
	}
	//------删-----
	que.pop();
	que.pop();
	//------查-----
	int front = que.front();
	int rear = que.back();

	int size = que.size();
}

int main()
{
	//vector
	tryVector();
	//list
	tryList();
	//deque
	tryDeque();
	//map
	tryMap();
	//set
	trySet();
	//stack
	tryStack();
	//queue
	tryQueue();

	return 0;
}


