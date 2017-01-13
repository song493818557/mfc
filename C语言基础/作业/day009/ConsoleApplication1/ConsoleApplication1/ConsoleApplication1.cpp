// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

/*
重载前置++与重载后置++的函数头有什么区别?为下面的类实现一个前置++和后置++ 使其符合平时我们使用前置++和后置++的含义
*/
class CTest{
public:
	CTest(int number = 0) :m_nNumber(number){}
	//前置++
	CTest& operator++(){
		m_nNumber++;
		return *this;
	}
	//后置++
	CTest operator++(int ){
		CTest temp(m_nNumber);
		m_nNumber++;
		return temp;
	}
	/*int operator++(int){
		CTest temp(m_nNumber);
		m_nNumber;
		m_nNumber++;
		return temp.m_nNumber;
	}*/
private:
	int m_nNumber;
};
/************************************************************************/
/*  设计一个类 Ctime 要求其满足以下要求
    该类中包含 时 分 秒 的函数
	设置该类的时分秒的函数
	获取该类中时分秒的三个函数  getHour(),getMinute(),getSecond()
*/
/************************************************************************/
class Cctime{
	

public:
	Cctime() :m_hour(0), m_minute(0), m_second(0){}
	void setHour(int hour){  m_hour = hour;   return; }
	void setMinute(int minute){ m_minute = minute;   return; }
	void setSecond(int second){ m_second = second;   return; }
	int getHour() { return m_hour; }
	int getMinute() { return m_minute; }
	int getSecond() { return m_second; }
private:
	int m_hour;
	int m_minute;
	int m_second;

};
int _tmain(int argc, _TCHAR* argv[])
{
	//CTest aa;
	//CTest bb=++aa;
	//CTest cc = aa++;
	Cctime dd;
	dd.setHour(5);
	dd.setMinute(6);
	dd.setSecond(15);
	return 0;
}

