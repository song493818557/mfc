// 10_03_��̬��Ա����.cpp : �������̨Ӧ�ó������ڵ㡣
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
	static void showcount(CCounter obj)
	{
		cout << obj.m_nCount << endl;
		//m_nCount = 10;    //��̬��Ա����ֱ��ʹ�÷Ǿ�̬���ݳ�Ա
		m_nNum = 100;
	}
	
private:
	int m_nCount;
	static int m_nNum;
};
int CCounter::m_nNum = 0;

int _tmain(int argc, _TCHAR* argv[]) {
	CCounter objA(15), objB(16);
	CCounter::showcount(objA);    //�Ƽ�ʹ��������ʹ�þ�̬��Ա����
	objB.showcount(objB);         //���Ƽ�ʹ�ö�����.��̬��Ա����
	return 0;
}

