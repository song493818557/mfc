// 9_03_��ĳ�Ա������д��(���������ʵ��).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CTdate
{
public:
	void set(int m, int d, int y);
	int  Isleapyear();
	void print();
private:
	int m_Month;
	int m_Day;
	int m_Year;
};

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


int main()
{
	CTdate date;
	date.set(10, 8, 2000);
	date.Isleapyear();

    return 0;
}

