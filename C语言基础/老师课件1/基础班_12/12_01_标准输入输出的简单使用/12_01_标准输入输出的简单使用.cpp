// 12_01_��׼��������ļ�ʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{
	char str[] = { "hello" };
	int nNum = 10;
	//�ӱ�׼�豸�ж�ȡ
	cin >> nNum ;                //����  ,����������뿴��һ�����Ŀ��
	 
	cout << nNum <<str<< endl;   //��ʾ��
	cerr << nNum <<str<< endl;   //��ʾ��
				  
	clog << nNum <<str<< endl;   //���ڴ�ӡ

    return 0;
}

