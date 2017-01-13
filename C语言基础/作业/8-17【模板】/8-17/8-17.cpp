// 8-17.cpp : �������̨Ӧ�ó������ڵ㡣
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
	//��ʼ�� һ��ʼ������ �����ַ�����
	Clist(T maxlength = 2){
		m_nowlength = 0;
		m_maxlength = maxlength;
		m_Date = new T[m_maxlength + sizeof(T)*2];
		memset(m_Date, NULL, m_maxlength);
	};
	bool Finsert(T Tnumber, int mlenght){
		//Ҫ�����λ�ò���С�����ֵ �� 0
		if (mlenght >m_maxlength && mlenght<0 && mlenght> m_nowlength)
		{
			return false;
		}
		//������ֵ�͵�ǰ��ֵ��� ��ô����Ҫ����
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
			//m_Date = m_temp; ������ 
			delete[]m_temp;
			
		}
		int temp = m_Date[mlenght];
		if (mlenght==m_nowlength){
			m_Date[m_nowlength] = Tnumber;
		}
		else
		{
			//��ǰ������λ�� 
			for (int i = m_nowlength - 1; i >= mlenght; i--)
			{
				m_Date[i+1] = m_Date[i];
			}
			m_Date[mlenght] = Tnumber;			
		}
		m_nowlength++;
		return true;
	}

	//�����������
	~Clist(){
		delete[]m_Date;
	};
	T Fdelete(int dnumber, T &Ela){
		//���ָ������ִ������ļ�¼�� �ͷ���ʧ��
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
	//��ӡ���
	void Fprint(){
		for (int i = 0; i < m_nowlength;i++)
		{
			cout << m_Date[i] << endl;
		}
	}
	//��ʼ���������Ա�L�Ѵ��ڣ�0 <= i <ListLength(L)
	//�����������e����L�е�i������Ԫ�ص�ֵ
	void GetElem(int dnumber, T &e){
		e = m_Date[dnumber];
		//return 0;
	}
	//ListLength(L) : 
	//��ʼ���������Ա�L�Ѵ���         �������������L��Ԫ�ظ���
	int ListLength(){
		return m_nowlength + 1;
	}
	//LocateElem(L, e) :
	//��ʼ���������Ա�L�Ѵ��ڡ�
	//������������������Ա��е�1����e��ȵ�����Ԫ�ص�λ�򡣲������򷵻� - 1
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
	//��ʼ���������Ա�L�Ѵ��ڣ�0 <= i <ListLength(L)
	//�����������e�滻L�е�i������Ԫ�ص�ֵ
	void SetElem(int dnumber, T &e){
		m_Date[dnumber] = e;
	}
	//��ʼ���������Ա�L�Ѵ���
	//�����������LΪ�ձ��򷵻�true�����򷵻�false
	bool ListEmpty(){
		if (m_Date == NULL)
		{
			return true;
		}
		return false;
	}
	//ClearList(&L) :
	//��ʼ���������Ա�L�Ѵ���         �����������L����Ϊ�ձ�
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

