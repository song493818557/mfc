#pragma once
#include <iostream>
using namespace  std;
class Conly
{
public: 
	//static bool ttrue;
	static Conly * creay(){
		if (m_only==NULL){			m_only = new Conly();}
		else{  cout << "创建失败" << endl;  }
		return m_only;
	}
	static void cc(){ cout << "创建成功" << endl; }
	static Conly* m_only;
private:

	Conly() { bb = 1; }
	int bb = 0;
};
//懒汉模式
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


//懒汉模式1
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
//外部初始化 before invoke main
const SingletonStatic* SingletonStatic::m_instance = new SingletonStatic;
