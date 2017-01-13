// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <iostream> 
using namespace std;
//��̬�������г�ʼ��



//��д��ʱ ��������忽�����캯�� ϵͳ��Ĭ��Ϊ��������һ�� ������һ��ѧ���� ����ʵ��һ����ϵͳĬ�Ͽ������캯��ͬ�����ܵĿ������캯��
class Cstudent{
public:
	Cstudent() :m_nAge(0), m_nId(0), m_szName(NULL) {
		++m_number;//��������ʱ�Զ�����ѧ������
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
	//��ӡ��ǰѧ������
	void prints(){
		cout << "��ǰѧ������:" <<m_number << endl;
	}
	~Cstudent(){
		m_number--;//���ٶ���ʱ�Զ�ɾ��ѧ������
		delete[]m_szName;
		m_szName = nullptr;
	}
	friend void set_info(Cstudent* aa);
	friend void print_info(Cstudent * aa);
	friend class CTearch; 
private:
	char * m_szName;//����
	int m_nAge;//����
	int m_nId;//ѧ��
	static int m_number;//ѧ������
};


void set_info(Cstudent* aa){
	//Cstudent *obja = new Cstudent;

	for (int i = 0; i < Cstudent::m_number; i++)
	{
		char *tem = new char[100];
		cout << "���������� ѧ�� ����" << endl;
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
//����һ����ʦ�� �е������� ��ֱ�����ѧ�������������ѧ�� ������һ������ �ܹ����ݴ���ֵ�޸�ѧ����ѧ�� ��ʾ ����ʦ������Ϊѧ���������Ԫ
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
			cout << "û���������ѧ��";
		}
	}
	static void change_info(int id, int nAge, char * szname, Cstudent * student){
		for (int i = 0; i < Cstudent::m_number; i++)
		{
			if (id == student[i].m_nId)
			{
				student[i].m_szName = szname;
				student[i].m_nAge = nAge;
				cout << "�޸ĳɹ�! " << student[i].m_szName << "---" << student[i].m_nAge << endl;
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

