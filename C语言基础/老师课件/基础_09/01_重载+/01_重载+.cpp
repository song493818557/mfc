// 01_重载+.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
class CTime
{
public:
	CTime operator+(CTime const &Other)           //成员方式的重载
	{
		int nDay = (this->m_Hour + Other.m_Hour) / 24;
		nDay = nDay+ this->m_Day + Other.m_Day;
		int nHour = (this->m_Hour + Other.m_Hour) % 24;

		CTime Temp(nDay, nHour);
		return Temp;
	}  
	//friend CTime operator+(CTime const &Time1, CTime const &Time2);//友元的方式重载


public:
	CTime Add(CTime Other)
	{
		int nDay = (this->m_Hour + Other.m_Hour) / 24;
		nDay = nDay + this->m_Day + Other.m_Day;
		int nHour = (this->m_Hour + Other.m_Hour) % 24;

		CTime Temp(nDay, nHour);
		return Temp;
	}
	CTime(int nDay = 0, int nHour = 0) :m_Day(nDay),m_Hour(nHour)
	{

	}

private:
	int m_Hour;
	int m_Day;
};

//
//CTime operator+(CTime const &Time1,CTime const &Time2)
//{
//	int nDay = (Time1.m_Hour + Time2.m_Hour) / 24;
//	nDay = nDay + Time1.m_Day + Time2.m_Day;
//	int nHour = (Time1.m_Hour + Time2.m_Hour) % 24;
//
//	CTime Temp(nDay, nHour);
//	return Temp;
//}


int _tmain(int argc, _TCHAR* argv[])
{
	CTime objA(1,8);
	CTime objB(0,23);
	CTime objF(0, 23);
	CTime objE(0, 23);
	CTime objC;
	CTime objD;
	CTime objG;
	//objG = objA.operator+(objB);
	objC = objA + objB;
	//operator+(objA, objB);

	//objD = objA.Add(objB).Add(objF).Add(objE);
	
	
	return 0;
}

