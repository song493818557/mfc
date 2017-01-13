// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream> 
using namespace std;
//静态变量进行初始化



//编写类时 如果不定义拷贝构造函数 系统会默认为我们生成一个 以下是一个学生类 请你实现一个和系统默认拷贝构造函数同样功能的拷贝构造函数
class Cstudent{
public:
	Cstudent() :m_nAge(0), m_nId(0), m_szName(NULL) {
		++m_number;//创建对象时自动增加学生个数
	};
	Cstudent(Cstudent& object) :m_nAge(object.m_nAge), m_nId(object.m_nId){
		unsigned int nSize = strlen(object.m_szName);
		m_szName = new char[nSize + 1];
		strcpy_s(m_szName, nSize + 1, object.m_szName);
	};
	Cstudent(char * szName, int nAge, int nID) :m_nAge(nAge), m_nId(nID){
		unsigned int nSize = strlen(szName);
		m_szName = new char[nSize + 1];
		strcpy_s(m_szName, nSize + 1, szName);
	}
	//打印当前学生个数
	void prints(){
		cout << "当前学生个数:" <<m_number << endl;
	}
	~Cstudent(){
		m_number--;//销毁对象时自动删除学生个数
		delete[]m_szName;
		m_szName = nullptr;
	}
	friend void set_info(Cstudent* aa);
	friend void print_info(Cstudent * aa);
	friend class CTearch; 
private:
	char * m_szName;//姓名
	int m_nAge;//年龄
	int m_nId;//学号
	static int m_number;//学生个数
};


void set_info(Cstudent* aa){
	//Cstudent *obja = new Cstudent;

	for (int i = 0; i < Cstudent::m_number; i++)
	{
		char *tem = new char[100];
		cout << "请输入姓名 学号 年龄" << endl;
		cin >> tem >> aa[i].m_nId >> aa[i].m_nAge;
		int numb = strlen(tem);
		aa[i].m_szName = NULL;
		aa[i].m_szName = new char[numb];
		aa[i].m_szName = tem;
	}

}
void print_info(Cstudent * aa){

	for (int i = 0; i < 5; i++)
	{
		cout << aa[i].m_szName << aa[i].m_nAge << aa[i].m_nId << endl;
	}
}

int Cstudent::m_number = 0;
//定义一个老师类 有点名方法 能直接输出学生对象的姓名和学号 有另外一个方法 能够根据传入值修改学生的学号 提示 将老师类声明为学生的类的友元
class CTearch{

public:
	static void get_info(int id, Cstudent * student){
		int temp = 0;
		for (int i = 0; i < Cstudent::m_number; i++)
		{
			if (id == student[i].m_nId)
			{
				cout << student[i].m_szName << student[i].m_nAge << endl;
				temp++;
			}
		}
		if (temp == 0)
		{
			cout << "没有你点名的学生";
		}
	}
	static void change_info(int id, int nAge, char * szname, Cstudent * student){
		for (int i = 0; i < Cstudent::m_number; i++)
		{
			if (id == student[i].m_nId)
			{
				student[i].m_szName = szname;
				student[i].m_nAge = nAge;
				cout << "修改成功! " << student[i].m_szName << "---" << student[i].m_nAge << endl;
			}
		}
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	//Cstudent  studentobj;
	Cstudent  obj1[5];
	set_info(obj1);
	while (1)
	{
	print_info(obj1);
	CTearch::get_info(22, obj1);
	CTearch::change_info(22,33,"xiaoming" ,obj1);
	}
	return 0;
}

