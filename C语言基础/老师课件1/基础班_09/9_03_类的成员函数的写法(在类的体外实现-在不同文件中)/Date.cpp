#include "stdafx.h"
#include <iostream>
using namespace std; 

#include "Date.h"
void CTdate::set(int m, int d, int y) {
	m_Month = m;  m_Day = d;  m_Year = y;
}
int  CTdate::Isleapyear() {
	return  (m_Year % 4 == 0 && m_Year % 100 != 0)
		|| (m_Year % 400 == 0);
}
void CTdate::print() {
	cout << m_Month << "/" << m_Day << "/" << m_Year << endl;
}