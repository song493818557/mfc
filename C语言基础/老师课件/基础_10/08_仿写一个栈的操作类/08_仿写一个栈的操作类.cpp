// 08_��дһ��ջ�Ĳ�����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	void push(T Data)  //��ջ����
	{
		Array[m_Top] = Data;
		m_Top++;
	}
	T pop()             //��ջ����
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

