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
	//教授固定工资 5000 每个课时补贴50 
	Cprofessor(int sub, int wage = 5000, int classtime = 50) :
		m_subsidies(sub), 
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){  
		cout << "教授的的补贴是:" << m_wage <<  
			   "--课时补贴是" << m_classtime << 
			  "该月已经上了多少个课时" << m_subsidies 
			  << "应该结算的工资为:" << m_wage + (m_classtime*m_subsidies) <<endl ; 
	}
	virtual ~Cprofessor(){};
 
private:
	int m_wage;//固定工资
	int m_classtime;//课时补贴
	int m_subsidies;//课时数量
};

class Cfprofessor :public Cteacher
{
public:
	//副教授固定工资 3000 每个课时补贴30 
	Cfprofessor(int sub, int wage = 5000, int classtime = 50) :
		m_subsidies(sub),
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){
		cout << "教授的的补贴是:" << m_wage <<
			"--课时补贴是" << m_classtime <<
			"该月已经上了多少个课时" << m_subsidies
			<< "应该结算的工资为:" << m_wage + (m_classtime*m_subsidies) << endl;
	}
	virtual ~Cfprofessor(){};

private:
	int m_wage;//固定工资
	int m_classtime;//课时补贴
	int m_subsidies;//课时数量
};

class Clecturer :public Cteacher
{
public:
	//教师固定工资 2000 每个课时补贴20 
	Clecturer(int sub, int wage = 2000, int classtime = 20) :
		m_subsidies(sub),
		m_wage(wage),
		m_classtime(classtime){};
	virtual void get_wage(){
		cout << "教授的的补贴是:" << m_wage <<
			"--课时补贴是" << m_classtime <<
			"该月已经上了多少个课时" << m_subsidies
			<< "应该结算的工资为:" << m_wage + (m_classtime*m_subsidies) << endl;
	}
	virtual ~Clecturer(){};

private:
	int m_wage;//固定工资
	int m_classtime;//课时补贴
	int m_subsidies;//课时数量
};