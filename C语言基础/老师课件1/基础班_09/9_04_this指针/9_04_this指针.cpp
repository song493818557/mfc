// 9_04_this指针.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
using namespace std;

class CTdate
{
public:
	CTdate()
	{
		m_Month = 0x1;
		m_Day = 0x2;
		m_Year = 0x3;
	}
	void printThis() {
		this->m_Day = 10;
		cout << this <<endl;
	};
private:
	int m_Month;
	int m_Day;
	int m_Year;
};


int main()
{
	CTdate date;
	cout << &date << endl;
	date.printThis();
    return 0;
}

