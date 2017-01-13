// 8-17.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "memory.h"
#include <iostream>
using std::cout;
using std::endl;
template<typename T>
class Clist
{
public:
	//初始化 一开始等于四 考虑字符类型
	Clist(T maxlength = 2){
		m_nowlength = 0;
		m_maxlength = maxlength;
		m_Date = new T[m_maxlength + sizeof(T)*2];
		memset(m_Date, NULL, m_maxlength);
	};
	bool Finsert(T Tnumber, int mlenght){
		//要插入的位置不能小于最大值 和 0
		if (mlenght >m_maxlength && mlenght<0 && mlenght> m_nowlength)
		{
			return false;
		}
		//如果最大值和当前的值相等 那么就需要扩容
		if (m_maxlength == m_nowlength){
			m_maxlength = m_maxlength * 2;
			T* m_temp = new T[m_maxlength];
			for (int i = 0; i < m_nowlength; i++)
			{
				m_temp[i] = m_Date[i];
			}
			delete[]m_Date;
			m_Date = new T[m_maxlength];
			for (int i = 0; i < m_nowlength; i++)
			{
				m_Date[i] = m_temp[i];
			}
			//m_Date = m_temp; 方法二 
			delete[]m_temp;
			
		}
		int temp = m_Date[mlenght];
		if (mlenght==m_nowlength){
			m_Date[m_nowlength] = Tnumber;
		}
		else
		{
			//当前的数组位置 
			for (int i = m_nowlength - 1; i >= mlenght; i--)
			{
				m_Date[i+1] = m_Date[i];
			}
			m_Date[mlenght] = Tnumber;			
		}
		m_nowlength++;
		return true;
	}

	//析构清空数据
	~Clist(){
		delete[]m_Date;
	};
	T Fdelete(int dnumber, T &Ela){
		//如果指向的数字大于最大的记录数 就返回失败
		if (dnumber >= m_nowlength)
		{
			return 0;
		}
		 Ela = m_Date[dnumber];
		for (int i = dnumber; i < m_nowlength-1; i++)
	   {
		   m_Date[i] = m_Date[i + 1];
	   }
		m_nowlength--;
		return true;
	}
	//打印结果
	void Fprint(){
		for (int i = 0; i < m_nowlength;i++)
		{
			cout << m_Date[i] << endl;
		}
	}
	//初始条件：线性表L已存在，0 <= i <ListLength(L)
	//操作结果：用e返回L中第i个数据元素的值
	void GetElem(int dnumber, T &e){
		e = m_Date[dnumber];
		//return 0;
	}
	//ListLength(L) : 
	//初始条件：线性表L已存在         操作结果：返回L中元素个数
	int ListLength(){
		return m_nowlength + 1;
	}
	//LocateElem(L, e) :
	//初始条件：线性表L已存在。
	//操作结果：返回在线性表中第1个与e相等的数据元素的位序。不存在则返回 - 1
	int LocateElem(T e){
		for (int i = 0; i < m_nowlength;i++)
		{
			if (m_Date[i] == e)
			{
				return i;
			}
		}

		return -1;
	}
	//SetElem(L, i, e) :
	//初始条件：线性表L已存在，0 <= i <ListLength(L)
	//操作结果：用e替换L中第i个数据元素的值
	void SetElem(int dnumber, T &e){
		m_Date[dnumber] = e;
	}
	//初始条件：线性表L已存在
	//操作结果：若L为空表，则返回true，否则返回false
	bool ListEmpty(){
		if (m_Date == NULL)
		{
			return true;
		}
		return false;
	}
	//ClearList(&L) :
	//初始条件：线性表L已存在         操作结果：将L重置为空表
	void ClearList(){
		 
		memset(m_Date, NULL, m_maxlength);
		m_Date = NULL;
	}
private:
	T * m_Date;
	T m_nowlength;
	T m_maxlength;
};
 
int _tmain(int argc, _TCHAR* argv[])
{
	Clist<int> Alist;
	bool o=Alist.ListEmpty();
	Alist.Finsert(1,0);
	Alist.Finsert(2, 0);
	Alist.Finsert(4, 1);
	Alist.Finsert(3, 0);
	Alist.Finsert(5, 0);
	Alist.Finsert(8, 3);
	Alist.Finsert(8, 0);
	int a = Alist.Fdelete(6, a);
	int b;
	Alist.GetElem(4, b);
	int c = Alist.ListLength();
	int d=9;
	d=Alist.LocateElem(d);
	int f = 6;
	Alist.SetElem(6,f);
	 o = Alist.ListEmpty();
	Alist.Fprint();
	return 0;
}

