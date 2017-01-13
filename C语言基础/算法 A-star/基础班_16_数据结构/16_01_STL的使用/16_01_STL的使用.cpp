// 16_01_STL��ʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
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

	//-------��----------
	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);//����ĩβ
	}
	vector<int>::iterator it = vec.begin();
	vec.insert(it + 5, 100);//��������λ��

							//--------��-----------
	for (int i = 0; i < vec.size(); i++)   //ͨ��[]+�±�
	{
		printf("%d ", vec[i]);
	}
	printf("\n");                      //ͨ��������+ƫ��
	for (vector<int>::iterator it = vec.begin();
	it != vec.end(); it++)
	{
		printf("%d ", *it);
	}
	//-------�޸�---------------
	vec[6] = 88;
	*(vec.begin() + 6) = 66;

	//-------ɾ��---------------
	it = vec.begin();
	vec.erase(it + 2);    //ͨ��������ɾ��
	vec.pop_back();     //ɾ�����Ԫ��
						//ɾ��ָ��ֵ��Ԫ��(�߱�����ɾ��)
	for (vector<int>::iterator it = vec.begin();
	it != vec.end(); )
	{
		if (*it == 100)
		{
			it = vec.erase(it);
		}
		else {
			printf("%d ", *it);
			//ҵ���߼�
			//....

			it++;
		}
		
	}

	printf("\n����clearǰ��size/capacity %d,%d",vec.size(), vec.capacity());
	vec.clear();        // ɾ������Ԫ��
	printf("\n����clear���size/capacity %d,%d",vec.size(), vec.capacity());

	vec.swap(vector<int>());
	//vector<int>().swap(vec);

	printf("\n����clear���size/capacity %d,%d",vec.size(), vec.capacity());



}

void tryList() {

	list<int> li;
	list<int>::iterator it = li.begin();
	//---��--------
	for (int i = 0; i < 10; i++)
	{
		li.push_front(i);
		li.push_back(i);
	}
	//it = li.begin();
	//li.insert(it++, 99);

	//---��--------
	printf("\n");
	int i = 0;
	for (it = li.begin();it != li.end();it++, i++)
	{
		if (i == 5)
		{
			*it = 66;               //�޸�
			it = li.insert(it, 99); //����
		}
		printf("%d ", *it);
	}
	//---��--------
	//---ɾ--------
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

	//---��--------
	for (int i = 0; i < 10; i++)
	{
		deq.push_back(i);
	}
	it = deq.begin();
	deq.insert(it + 3, 88);

	//---��--------
	printf("\n");
	for (int i = 0; i < deq.size(); i++)
	{
		printf("%d ", deq[i]);
	}
	for (it = deq.begin(); it != deq.end(); it++)
	{
		printf("%d ", *it);
	}
	//---�޸�--------
	*(deq.begin() + 5) = 66;
	deq[5] = 77;

	//---ɾ��--------
	deq.erase(deq.begin() + 5);
	deq.pop_back();
	deq.clear();

}

void tryMap() {
	map<string, int> mm;
	map<string, int>::iterator it = mm.begin();

	//------��-------
	mm.insert(pair<string, int>("Ҧ�ٲ�", 99));
	mm.insert(pair<string, int>("��ΰ��", 88));
	mm.insert(pair<string, int>("�����", 77));

	mm.insert({ "�μ���", 77 });

	mm["Ԭ����"] = 66;
	mm["������"] = 55;
	string keys[2] = { "����","�" };
	for (int i = 0; i < 2; i++)
	{
		mm[keys[i]] = i;
	}
	mm["Ԭ����"] = 55;
	mm["Ԭ����"] = 22;
	//----��ѯ----------
	for (it = mm.begin(); it != mm.end(); it++)
	{
		printf("\n����:%s,id:%d",
			it->first.c_str(), it->second);
		//cout<< it->first
	}

	//----��ѯ/ɾ��----------
	it = mm.find("�ϴ�");
	it = mm.find("�μ���");
	for (it = mm.begin(); it != mm.end();) {
		if (it->second == 22 || it->first == "������")
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

	//-----��-----
	testSet.insert("�쿭");
	testSet.insert("����");
	testSet.insert("��ʿ��");

	testSet.insert(testSet.begin(), "���ƽ");

	//-----��-----
	for (it = testSet.begin();
	it != testSet.end(); it++)
	{
		printf("\n %s ", it->c_str());
	}
	it = testSet.find("���ƽ");

}

void tryStack() {
	stack<int> MyStack;
	//------��-----
	for (int i = 0; i < 10; i++)
	{
		MyStack.push(i);
	}
	//------ɾ-----
	MyStack.pop();
	MyStack.pop();
	//------��-----
	int top = MyStack.top();

	int size = MyStack.size();

}

void tryQueue() {
	queue<int> que;
	//----��------
	for (int i = 0; i < 10; i++)
	{
		que.push(i);
	}
	//------ɾ-----
	que.pop();
	que.pop();
	//------��-----
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


