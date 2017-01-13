#pragma once
//成员函数重载
class CCounter_A
{
public:
	CCounter_A(int num=0);
	~CCounter_A();

	//单目运算符重载
	//++/--
	CCounter_A& operator++();//前置++
	CCounter_A operator++(int); //后置++,int仅仅只是标示为后置符号,并不使用


	//双目运算符重载
	int operator+(CCounter_A &);


	int getNum() const { return m_nNum; }
	void setNum(int val) { m_nNum = val; }
private:
	int m_nNum;
};

//重载符号时,返回值的类型是自定义的
//1. 前置++,返回加完以后的结果
//2. 后置++,返回加之前的结果
//3. +,不改变操作数,返回一个相加的中间变量