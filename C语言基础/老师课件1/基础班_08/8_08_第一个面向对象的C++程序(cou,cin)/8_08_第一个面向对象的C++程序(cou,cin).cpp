// 8_08_��һ����������C++����(cou,cin).cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
using namespace std;

void testCin()
{
	//��������
	int nNumA;
	char ch;
	float fNumB;
	char str[100] = {0};
	cin >> nNumA >>ch>>fNumB >> str;

	cin >> nNumA;
	while (cin.fail()) //���cin.failbit �Ƿ����� true;
	{
		//cin�������ʱ,���ټ�����Ӧ����,��Ҫ���⴦��
		//����ʽһ
		//cin.clear(); //	���������
		//cin.sync();  //   ����������е�����
		//cin >> nNumA;

		//����ʽ��
		cin.clear();
		char ch;
		cin >> ch;
		cin >> nNumA;
	}

	
	int nNum = 555;
	cin >> nNum;

}

void testCout()
{
	int nNumA = 987;
	char ch = 'w';
	float fNumB = 0.345;
	char str[100] = { "hello" };
	cout << "hello world" << endl;
	cout << nNumA << "\t"
		 << ch    << "  " 
		 << fNumB << "\n"
		 << str 
		 <<endl;

	cout.setf(ios::left);
	nNumA = 10;
	cout << hex << nNumA << "\n";
	cout << oct << nNumA << "\n";
	cout << dec << nNumA << "\n";
	cout << setw(10) << nNumA << endl;
	cout << setw(10) <<left<< nNumA << endl;
	cout << setw(10) <<right<< nNumA << endl;
	cout << setw(10) << setfill('0')<< right << nNumA << endl;

}

void testCout2()
{
	cout << endl;

	for (int i = 0;i<7;i++)
	{
		if (i<4)
		{
			//ǰ����       0,1,2,3
			//�ո�Խ��Խ�� 4,3,2,1
			//�Ǻ�Խ��Խ�� 1,3,5,7
			cout << setfill(' ')<<setw(4 - i) << ' ';
			cout << setfill('*')<<setw(2 * i + 1) << '*';
		}
		else {
			//������       4,5,6
			//�ո�Խ��Խ�� 2,3,4
			//�Ǻ�Խ��Խ�� 5,3,1
			/*
			4  5    7-4=3   5
			5  3    7-5=2   3
			6  1    7-6=1   1
			*/
			cout << setfill(' ') << setw(i-2) << ' ';
			cout << setfill('*') << setw( 2*(7-i)-1) << '*';
		}

		cout << endl;
	}

}
int main()
{
	
	//testCin();
	testCout();
	testCout2();
    return 0;
}

