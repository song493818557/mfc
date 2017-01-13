#pragma once
//成员函数重载
class CCounter_B
{
public:
	CCounter_B(int num = 0);
	~CCounter_B();

	//单目运算符重载
	//++/--
	friend CCounter_B& operator++(CCounter_B&);//前置++
	friend CCounter_B operator++(CCounter_B&,int); //后置++,int仅仅只是标示为后置符号,并不使用


	//双目运算符重载
	friend int operator+(CCounter_B & op1,CCounter_B & op2);


	int getNum() const { return m_nNum; }
	void setNum(int val) { m_nNum = val; }
private:
	int m_nNum;
};

