// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

/*
����ǰ��++�����غ���++�ĺ���ͷ��ʲô����?Ϊ�������ʵ��һ��ǰ��++�ͺ���++ ʹ�����ƽʱ����ʹ��ǰ��++�ͺ���++�ĺ���
*/
class CTest{
public:
	CTest(int number = 0) :m_nNumber(number){}
	//ǰ��++
	CTest& operator++(){
		m_nNumber++;
		return *this;
	}
	//����++
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
/*  ���һ���� Ctime Ҫ������������Ҫ��
    �����а��� ʱ �� �� �ĺ���
	���ø����ʱ����ĺ���
	��ȡ������ʱ�������������  getHour(),getMinute(),getSecond()
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

