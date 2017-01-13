#include "stdafx.h"
#include "MyDate.h"
#include <iostream>
using namespace std;


CMyDate::CMyDate()
{
}


CMyDate::~CMyDate()
{
}

void CMyDate::set(int m, int d, int y) {
	m_Month = m;  m_Day = d;  m_Year = y;
}
int  CMyDate::Isleapyear() {
	return  (m_Year % 4 == 0 && m_Year % 100 != 0)
		|| (m_Year % 400 == 0);
}
void CMyDate::print() {
	cout << m_Month << "/" << m_Day << "/" << m_Year << endl;
}