// 9_05_�ɼ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int MyClass1;


class MyClass1
{
public:
	int m_data;
	void print() {
		//2.�������˱���
		printf("%d", ::MyClass1);  //ȫ�ֱ�����������,ͨ��::������
								   //���������::,�ᵽ���������ⲿȥѰ�ҷ���
	}
};

//1.�౻������
void fun(int MyClass1)
{
	MyClass1 = 10;
	class MyClass1 obj;  //������������,���class ǰ׺��ʹ����
	obj.m_data = 10;
}


int main()
{
    return 0;
}

