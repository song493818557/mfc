#pragma once
#include <iostream>
using namespace  std;

class Cteacher
{
public:
	Cteacher();
	virtual void get_wage(){}//
	virtual ~Cteacher(){}; 
};
class Cprofessor :public Cteacher
{
public:
	//���ڹ̶����� 5000 ÿ����ʱ����50 
	Cprofessor(int sub, int wage = 5000, int classtime = 50) :
		m_subsidies(sub), 
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){  
		cout << "���ڵĵĲ�����:" << m_wage <<  
			   "--��ʱ������" << m_classtime << 
			  "�����Ѿ����˶��ٸ���ʱ" << m_subsidies 
			  << "Ӧ�ý���Ĺ���Ϊ:" << m_wage + (m_classtime*m_subsidies) <<endl ; 
	}
	virtual ~Cprofessor(){};
 
private:
	int m_wage;//�̶�����
	int m_classtime;//��ʱ����
	int m_subsidies;//��ʱ����
};

class Cfprofessor :public Cteacher
{
public:
	//�����ڹ̶����� 3000 ÿ����ʱ����30 
	Cfprofessor(int sub, int wage = 5000, int classtime = 50) :
		m_subsidies(sub),
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){
		cout << "���ڵĵĲ�����:" << m_wage <<
			"--��ʱ������" << m_classtime <<
			"�����Ѿ����˶��ٸ���ʱ" << m_subsidies
			<< "Ӧ�ý���Ĺ���Ϊ:" << m_wage + (m_classtime*m_subsidies) << endl;
	}
	virtual ~Cfprofessor(){};

private:
	int m_wage;//�̶�����
	int m_classtime;//��ʱ����
	int m_subsidies;//��ʱ����
};

class Clecturer :public Cteacher
{
public:
	//��ʦ�̶����� 2000 ÿ����ʱ����20 
	Clecturer(int sub, int wage = 2000, int classtime = 20) :
		m_subsidies(sub),
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){
		cout << "���ڵĵĲ�����:" << m_wage <<
			"--��ʱ������" << m_classtime <<
			"�����Ѿ����˶��ٸ���ʱ" << m_subsidies
			<< "Ӧ�ý���Ĺ���Ϊ:" << m_wage + (m_classtime*m_subsidies) << endl;
	}
	virtual ~Clecturer(){};

private:
	int m_wage;//�̶�����
	int m_classtime;//��ʱ����
	int m_subsidies;//��ʱ����
};