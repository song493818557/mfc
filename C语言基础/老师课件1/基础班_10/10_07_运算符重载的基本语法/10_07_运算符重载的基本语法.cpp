// 10_07_��������صĻ����﷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Counter_A.h"
#include "Counter_B.h"
#include <iostream>
using namespace std;

int main()
{
	CCounter_A count,count2(88);

	int re1 = (++count).getNum();
	int re2 = (count++).getNum();

	int re3 = count + count2;
	count.operator+( count2);  // ��Ա���� ��ʽ����

	CCounter_B countB, countB2(88);

	re1 = (++countB).getNum();
	re2 = (countB++).getNum();

	re3 = countB + countB2;
	operator+(countB, countB2); //��Ԫ���� ��ʽ����

	//cout << count;
    return 0;
}

