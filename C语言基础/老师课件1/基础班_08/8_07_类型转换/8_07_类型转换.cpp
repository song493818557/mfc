// 8_07_����ת��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int main()
{
	//1.const_cast:ȥ����������(ֻ������ָ�������)
	const int nNumA = 100; //ǿ�ƴ��ڴ���ȡֵvolatile
	int * nNumB = const_cast<int *>(&nNumA);
	int & nNumC = const_cast<int &>(nNumA);
	//nNumA = 123;
	*nNumB = 777;
	nNumC = 567;

	printf("%d %d %d", nNumA, *nNumB, nNumC);
	
	//2.static_cast:��̬����ת��(�Զ�ת��,Ĭ��ת��)
	//  ��ʾ�������Ͳ�ͬ
	int nNumD = 999;
	char ch = 'w';
	nNumD = ch;			 //Ĭ��ת��
	nNumD = static_cast<int> (ch);

	//3.reinterpret_cast:ǿ��ת��(�����Զ�ת��ʱ)
	int nNumE = 233;
	int * pNumF = nullptr;
	//nNumE = pNumF;
	nNumE = (int)pNumF;
	nNumE = reinterpret_cast<int>(pNumF);
	pNumF = reinterpret_cast<int *>(nNumE);

    return 0;
}

