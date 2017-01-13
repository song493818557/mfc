// 04_构造的初始化列表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>
#include <iostream>
using std::cin;

static int number;
class CStudent
{
public:
	CStudent() :m_nAge(0), m_nID(0), m_szName(NULL){
		m_szName = new char[20];
		//strcpy_s(m_szName, 20, szName);
		number++;
	};
	//拷贝函数时特殊处理学生姓名 为其申请内存空间
	   CStudent(CStudent &obj){
		   unsigned int nSize = strlen(obj.m_szName)+1;
		   this->m_szName = new char[nSize];
		   strcpy_s(this->m_szName, nSize, obj.m_szName);
	   }
	   //初始化的时候 赋值
	   CStudent(char * szName,int nAge,int nID):m_nAge(nAge),m_nID(nID){
		   unsigned int nSize = strlen(szName) + 1;
		   this->m_szName = new char[nSize];
		   strcpy_s(this->m_szName, nSize, szName);
	   }
	   
	   int get_number(){
		   return number;

	   }
	   //析构时 释放学生姓名 内存空间
	   ~CStudent(){
		   delete[]m_szName;
		   m_szName = nullptr;

	   }
	   friend void Setinfo();
	   friend void Outinfo();
private:
	char* m_szName;//姓名
	int m_nAge;//年龄
	int m_nID;//学号
  
};
CStudent *sarr = new CStudent[5];
void Setinfo(){
	
	
	for (int i = 0; i < 5;i++)
	{
		char aa[20];
		//scanf_s("%s", &aa,20);sarr[i].m_szName
		//cin >> aa;
		//
		//cin >> aa;//
		//cin >> sarr[i].m_nID >> sarr[i].m_nAge;
		scanf_s("%s %d %d", sarr[i].m_szName,20, &sarr[i].m_nID, &sarr[i].m_nAge);
		//memcpy_s(sarr[i].m_szName, 20, aa, 20);
		//scanf_s("%d %d", &sarr[i].m_nID, &sarr[i].m_nAge);
		int c = 0;
	}
}
void Outinfo(){
	for (int i = 0; i < 5; i++)
	{
		//scanf_s("%s", sarr[i].m_szName);
		printf("姓名：%s ID：%d 年龄：%d", sarr[i].m_szName, sarr[i].m_nID, sarr[i].m_nAge);
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	CStudent xiaoming("xiaoming",17,22);
	CStudent xiaolan("xiaolan", 14, 20);
	CStudent xiaohong(xiaoming);
	Setinfo();
	Outinfo();
	return 0;
}

