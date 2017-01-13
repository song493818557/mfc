// 815.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class Ctime
{
public: 
	 Ctime(int hour, int minute, int second) : m_hour(hour), m_minute(minute), m_Second(second) {}
	int gethour(){		return  m_hour;		}
	int getminute(){ return  m_minute; }
	int getsecond(){ return  m_Second; }
private:
	//int m_number;
	int m_hour;
	int m_minute;
	int m_Second;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Ctime quan(5,4,49);
	int temp;
	temp=quan.gethour();
	temp = quan.getminute();
	temp = quan.getsecond();
	return 0;
}

