#include "stdafx.h"
#include <string.h>
#include <crtdbg.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
using namespace std;
class Cstring {
public:
	Cstring(char * s ){
		int temp = strlen(s) + 1;
		m_char = new char[temp];
		memset(m_char, 0, temp);
		strcpy_s(m_char, temp, s);
		m_int = new int;
	}
	Cstring(Cstring &s){
		int temp = strlen(s.m_char) + 1;
		m_char = new char[temp];
		memset(m_char, 0, temp);
		strcpy_s(m_char, temp, s.m_char);
	}
	~Cstring(){
		delete[] m_char;
		m_char = NULL;
		delete[] m_int;
		m_int = NULL;
	}
	//修改字符串的第I个元素
	void reset(int numb, char g){
		m_char[numb - 1] = g;
	}
	/************************************************************************/
	/* day 9 作业 
	1 +=(追加字符串)
	2 '='( 字符串拷贝)
	3 重载+(连接字符串)
	4 '[]'(取出字符串下标元素)
	5 '=='(判断两个字符串是否相等) 
	6 '<<'(输出流)   
	7 输入流'>>',
	8 该类添加数字转字符串 
	9 字符串转数字的功能                                                                    */
	/************************************************************************/
	//+=(追加字符串)   1 重载+(连接字符串)  参数使用引用 可以减少实参到形参的时候 创建一个临时对象
	Cstring& operator+=(Cstring&  obj){
		
		//计算2个对象相加的空间大小
		int temp = strlen(obj.m_char) + strlen(m_char) + 2; 
		char * tempchar = new char[temp];//申请一个临时空间来进行中间存储
		if (tempchar == NULL) cout << "可用空间不足"; 
		memset(tempchar, 0, temp);//初始化 确保空间内的值是干净的
		strcpy_s(tempchar, temp, m_char);
		m_char = NULL;
		//重新申请空间
		m_char = new char[temp];
		strcpy_s(m_char, temp, tempchar);
	    strcat_s(m_char, temp, obj.m_char);
		//strcpy_s(m_char, temp, obj.m_char);
		return *this;
	}
	//2 '='(字符串拷贝)参数使用引用 可以减少实参到形参的时候 创建一个临时对象
	Cstring &operator=(Cstring& obj){
		int temp = strlen(obj.m_char)+1;
		//判断是否需要重新申请空间 
		if (temp > strlen(m_char))
		{
			 m_char=NULL;
			m_char = new char[temp];
			if (m_char == NULL) cout << "可用空间不足";
			memset(m_char, 0, temp);//初始化 确保空间内的值是干净的
		}		
		strcpy_s(m_char, temp, obj.m_char);
		return *this;
	}
	//重载+(连接字符串) 
	//返回值 不能加引用 
	//不加引用就会触发拷贝构造 是因为作用域的问题会先触发tempstring析构 再去拷贝构造
	Cstring operator+(Cstring&  obj){
		//创建个临时对象 返回
		Cstring tempstring(" ");
		//计算2个对象相加的空间大小
		int temp = strlen(obj.m_char) + strlen(m_char) + 2;
		tempstring.m_char = NULL;
		tempstring.m_char = new char[temp];//申请一个临时空间来进行中间存储
		if (tempstring.m_char == NULL) cout << "可用空间不足";
		memset(tempstring.m_char, 0, temp);//初始化 确保空间内的值是干净的		 
		strcpy_s(tempstring.m_char, temp, m_char);
		strcat_s(tempstring.m_char, temp, obj.m_char);
		//strcpy_s(m_char, temp, obj.m_char);
		return tempstring;
	}
	//'[]'(取出字符串下标元素) 下标需要检测是否越界
	char operator[](int i){
		char b;
		(strlen(m_char) > i) ? b = m_char[i] : b=0;
		return b;
	}
	//'=='(判断两个字符串是否相等) 
	bool operator==(Cstring& obja){
		if (strcmp(m_char,obja.m_char) == 0 )
		{
			return true; 
		}
		return false;

	}
	//数字转字符串   
	void changgenumber(){
		 
		int templen = strlen(m_char);
		delete[] m_int;
		m_int = new int[templen];
		for (int i = 0; m_char[i] != '\0'; i++)
		{
			m_int[i] = m_char[i];
		}
		for (int i = 0; m_char[i] != '\0'; i++)
		{
			cout<<m_int[i];
		}
		//m_int = (int)atol(m_char);
		int a = 0;
		return ;
	}
	//字符串转数字
	void changgechar(){

		int templen = strlen(m_char);
		delete[] m_char;
		m_char = new char[templen];
		memset(m_char, 0, templen);
		for (int i = 0; i<templen; i++)
		{
			m_char[i] = m_int[i];
		}
		for (int i = 0; i<templen; i++)
		{
			cout << m_char[i];
		}
		//m_int = (int)atol(m_char);
		int a = 0;
		return;
	}
	friend ostream& operator<<(ostream & Ccout, Cstring obj);
	friend istream& operator>>(istream & Ccout, Cstring& obj);
private:
	char * m_char;
	int * m_int; //数字转字符 或者字符转数字用的
};
//流运算符用友元函数  对象没有写的操作 不需要引用
ostream& operator<<(ostream & Ccout, Cstring obj){
	Ccout << obj.m_char;
	return Ccout;
}
//输入对象有写的操作 需要用引用
istream& operator>>(istream & Ccout, Cstring& obj){
	Ccout >> obj.m_char;
	return Ccout;
}
int _tmain(int argc, _TCHAR* argv[])
{
	Cstring aa("abcdefghijk");
	//Cstring bb(aa);
	Cstring bb("ckkocc");
	//aa.reset(3, '8');
	//aa + bb;
	Cstring cc("hhh");
	cc= bb;
	Cstring  dd = cc+ bb;
	Cstring kk = cc;
	char  mm;
	mm = cc[2];
	if (kk==cc)//相等
	{
		printf("yes");
		if (kk==dd)//不相等
		{
			printf("yes");
		}
	}
	bb.changgenumber();

	bb.changgechar();
	cout << kk<<endl;
	cout << cc << endl;
	cin >> kk;
	cin >> cc;
	cout << kk << endl;
	cout << cc << endl;

	return 0;
}
