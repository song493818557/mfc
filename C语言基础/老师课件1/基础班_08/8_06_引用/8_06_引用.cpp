// 8_06_����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//ֵ����
void swap(int nNuma, int nNumb)
{
	int temp = nNumb;
	nNumb = nNuma;
	nNuma = temp;
}

//ָ�봫��
void swap(int * nNuma, int * nNumb)
{
	//����ָ��,û����,��Ȼ���ܸı�ʵ��
// 	int * temp = nNumb;
// 	nNumb = nNuma;
// 	nNuma = temp;
	int temp = *nNumb;
	*nNumb = *nNuma;
	*nNuma = temp;
}

//���ô���
void swap1(int &nNuma, int &nNumb)
{
	int temp = nNumb;
	nNumb = nNuma;
	nNuma = temp;
}
int main()
{
	//��ͨ����
	char ch = 'a';
	int nNumA = 100;
	int & nNum1 = nNumA;  //����һ��
	nNum1--;
	nNum1 = 987;

	//const + ����
	const int & nNum2 = nNumA;  //const���͵������ܹ�ָ����ͨ����
	const float & nNum3 = nNumA;  //const���͵������ܹ�ָ����ͨ����
	const int nNumB = 678;
	//int & nNum3 = nNumB;      //��ͨ���͵����ò��ܹ�ָ��cosnt����
	//nNum2++;                  //const���͵����ò����޸ı���(��������)
	
	nNumA++;
	printf("%f , %d , %d ", nNum3, nNum2, nNumA);


	//���ô���
	int a = 100;
	int b = 1;
	swap(a, b);    //ֵ����
	swap(&a, &b);  //ָ�봫��
	swap1(a, b);   //���ô���
	return 0;
}

