#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
//���������ռ�
namespace mystring{
class Cstring
{
public:
	Cstring();
	void input();
	void copy(char *address, char *address1);
	~Cstring();
};

class Castring{
public:
	Castring() :m_maxlength(5), m_length(0){ 
		m_data = new int[m_maxlength];
		memset(m_data, 0, m_maxlength);
	}
	void insert(int data);//����
	void adelete(int data);//ɾ��
	void asearch(int data);//����
	//���ֵ����Ϊ1  ��Сֵ����Ϊ2
	void ashort(int data);
	~Castring(){
		delete[]m_data;
	}
private:
	int * m_data;
	int m_length;
	int m_maxlength;
};
}