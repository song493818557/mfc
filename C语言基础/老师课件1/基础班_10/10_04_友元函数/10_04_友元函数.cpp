// 10_04_��Ԫ����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;


class CCounter
{
public:
	CCounter(int nNum)
	{
		m_nCount = nNum;
	}
	friend void showcount(CCounter &obj); //������Ԫ����

private:
	int m_nCount;
};

void showcount(CCounter &obj)            //ʵ����Ԫ����
{
	cout << obj.m_nCount << endl;        //����������ͨ������ʹ��private,protect��Ա
}

int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(15);
	//objA.showcount(objA);   //��Ԫ�������ǳ�Ա����,����ͨ������������

	showcount(objA);
	return 0;
}

