// 08_仿写一个栈的操作类.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Test
{
public:
	Test(){};
	~Test(){};

private:
	int m_a;
	int m_b;
};

template <typename T>
class Stack
{
public:
	Stack() :m_Top(0)
	{
		memset(Array, 0, sizeof(T) * 200);
	}
	void push(T Data)  //进栈操作
	{
		Array[m_Top] = Data;
		m_Top++;
	}
	T pop()             //出栈操作
	{
		int temp = Array[m_Top];
		m_Top--;
		return temp;
	}
private:
	T Array[200];
	int m_Top;
};





int _tmain(int argc, _TCHAR* argv[])
{
	Stack<int> obj;
	//Stack<Test> obj2;

	//Test hehe;
	//Test haha;
	//obj2.push(hehe);
	//obj2.push(haha);




	return 0;
}

