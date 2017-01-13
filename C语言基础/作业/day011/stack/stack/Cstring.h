#pragma once
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
//创建命名空间
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
	void insert(int data);//插入
	void adelete(int data);//删除
	void asearch(int data);//搜索
	//最大值排序为1  最小值排序为2
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