// 01_Ϊ��дһ����ʼ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


class CLocation {
public:
	CLocation()
	{
		printf("Hello world");
		m_X = 100;
		m_Y = 200;
	}



	void init(int nNumA, int nNumB)
	{
		m_X = nNumA;
		m_Y = nNumB;
	}
	int getx() { return m_X; }
	int gety() { return m_Y; }
private:
	int m_X, m_Y;  //member date
};

CLocation obj2;


int _tmain(int argc, _TCHAR* argv[])
{
	//CLocation obj[10] ;

	CLocation * p = new CLocation[5];





	//obj.init(10, 20);



	return 0;
}

