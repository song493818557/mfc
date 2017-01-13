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
	//�޸��ַ����ĵ�I��Ԫ��
	void reset(int numb, char g){
		m_char[numb - 1] = g;
	}
	/************************************************************************/
	/* day 9 ��ҵ 
	1 +=(׷���ַ���)
	2 '='( �ַ�������)
	3 ����+(�����ַ���)
	4 '[]'(ȡ���ַ����±�Ԫ��)
	5 '=='(�ж������ַ����Ƿ����) 
	6 '<<'(�����)   
	7 ������'>>',
	8 �����������ת�ַ��� 
	9 �ַ���ת���ֵĹ���                                                                    */
	/************************************************************************/
	//+=(׷���ַ���)   1 ����+(�����ַ���)  ����ʹ������ ���Լ���ʵ�ε��βε�ʱ�� ����һ����ʱ����
	Cstring& operator+=(Cstring&  obj){
		
		//����2��������ӵĿռ��С
		int temp = strlen(obj.m_char) + strlen(m_char) + 2; 
		char * tempchar = new char[temp];//����һ����ʱ�ռ��������м�洢
		if (tempchar == NULL) cout << "���ÿռ䲻��"; 
		memset(tempchar, 0, temp);//��ʼ�� ȷ���ռ��ڵ�ֵ�Ǹɾ���
		strcpy_s(tempchar, temp, m_char);
		m_char = NULL;
		//��������ռ�
		m_char = new char[temp];
		strcpy_s(m_char, temp, tempchar);
	    strcat_s(m_char, temp, obj.m_char);
		//strcpy_s(m_char, temp, obj.m_char);
		return *this;
	}
	//2 '='(�ַ�������)����ʹ������ ���Լ���ʵ�ε��βε�ʱ�� ����һ����ʱ����
	Cstring &operator=(Cstring& obj){
		int temp = strlen(obj.m_char)+1;
		//�ж��Ƿ���Ҫ��������ռ� 
		if (temp > strlen(m_char))
		{
			 m_char=NULL;
			m_char = new char[temp];
			if (m_char == NULL) cout << "���ÿռ䲻��";
			memset(m_char, 0, temp);//��ʼ�� ȷ���ռ��ڵ�ֵ�Ǹɾ���
		}		
		strcpy_s(m_char, temp, obj.m_char);
		return *this;
	}
	//����+(�����ַ���) 
	//����ֵ ���ܼ����� 
	//�������þͻᴥ���������� ����Ϊ�������������ȴ���tempstring���� ��ȥ��������
	Cstring operator+(Cstring&  obj){
		//��������ʱ���� ����
		Cstring tempstring(" ");
		//����2��������ӵĿռ��С
		int temp = strlen(obj.m_char) + strlen(m_char) + 2;
		tempstring.m_char = NULL;
		tempstring.m_char = new char[temp];//����һ����ʱ�ռ��������м�洢
		if (tempstring.m_char == NULL) cout << "���ÿռ䲻��";
		memset(tempstring.m_char, 0, temp);//��ʼ�� ȷ���ռ��ڵ�ֵ�Ǹɾ���		 
		strcpy_s(tempstring.m_char, temp, m_char);
		strcat_s(tempstring.m_char, temp, obj.m_char);
		//strcpy_s(m_char, temp, obj.m_char);
		return tempstring;
	}
	//'[]'(ȡ���ַ����±�Ԫ��) �±���Ҫ����Ƿ�Խ��
	char operator[](int i){
		char b;
		(strlen(m_char) > i) ? b = m_char[i] : b=0;
		return b;
	}
	//'=='(�ж������ַ����Ƿ����) 
	bool operator==(Cstring& obja){
		if (strcmp(m_char,obja.m_char) == 0 )
		{
			return true; 
		}
		return false;

	}
	//����ת�ַ���   
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
	//�ַ���ת����
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
	int * m_int; //����ת�ַ� �����ַ�ת�����õ�
};
//�����������Ԫ����  ����û��д�Ĳ��� ����Ҫ����
ostream& operator<<(ostream & Ccout, Cstring obj){
	Ccout << obj.m_char;
	return Ccout;
}
//���������д�Ĳ��� ��Ҫ������
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
	if (kk==cc)//���
	{
		printf("yes");
		if (kk==dd)//�����
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
