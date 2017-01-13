#pragma once
class CMyDate
{
public:
	CMyDate();
	~CMyDate();
	void set(int m, int d, int y);
	int  Isleapyear();
	void print();
private:
	int m_Month;
	int m_Day;
	int m_Year;
};

