#pragma once
#include <iostream>
using namespace  std;
class Conly
{
public: 
	//static bool ttrue;
	static Conly * creay(){
		if (m_only==NULL){			m_only = new Conly();}
		else{  cout << "����ʧ��" << endl;  }
		return m_only;
	}
	static void cc(){ cout << "�����ɹ�" << endl; }
	static Conly* m_only;
private:

	Conly() { bb = 1; }
	int bb = 0;
};
//����ģʽ
class CSingleton
{
public:
	
	static CSingleton* GetInstance()
	{ 
		return m_pInstance;
	}
	static CSingleton * m_pInstance;
private:
	CSingleton(){};
	~CSingleton(){};
};


//����ģʽ1
class SingletonStatic
{
private:
	static const SingletonStatic* m_instance;
	SingletonStatic(){}
public:
	static const SingletonStatic* getInstance()
	{
		return m_instance;
	}
};
//�ⲿ��ʼ�� before invoke main
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;
