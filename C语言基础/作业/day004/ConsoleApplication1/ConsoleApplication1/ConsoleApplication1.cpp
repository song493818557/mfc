// index.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <stdlib.h>
//�׳˼�ͳ�ƺ���0�ĸ���
int factorial(int numb){
	int temp = 1;
	int ncount = 0;

	for (int i = numb; i > 0; i--)
	{
		temp *= i;
	}
	for (int i = 0; temp >= 9;)
	{
		i = temp % 10;
		if (i == 0)
		{
			ncount++;
		}
		temp /= 10;
	}
	return ncount;

}
//����
int rabbit(){
	int temp = 0;
	int atemp[3] = { 0 };
	atemp[0] = 1;
	//��һ���µ�����
	//�ڶ����µ�����
	//�������µ�����
	for (int i = 2; i <= 15; i++)
	{
		atemp[2] += atemp[1];//���ڶ����µ�ת�Ƶ���������  ��ʱ��ͳһ������
		atemp[1] = atemp[0];//����һ���ոճ��������� ת�Ƶ��ڶ�����  			atemp[2] += atemp[1];
		atemp[0] = atemp[2];//�ոճ��������� ���� �������µ�����ֵ 
		printf("%d��:һ���µ�����%d �����µ�����%d �����µ�����%d\n", i, atemp[0], atemp[1], atemp[2]);
	}
	temp = atemp[0] + atemp[1] + atemp[2];
	return temp;
}
//��дһ�����׵�PRINTF����
void Myprintf(char szFormat[], int nNumb){
	char dFromat[] = "%d";
	char fFromat[] = "%f";
	char cFromat[] = "%c";
	if (dFromat[1] == szFormat[1] && dFromat[0] == szFormat[0])
	{
		printf("%d\n", nNumb);
	}
	else if (fFromat[1] == szFormat[1] && fFromat[0] == szFormat[0])
	{
		printf("%f\n", nNumb);
	}
	else if (cFromat[1] == szFormat[1] && cFromat[0] == szFormat[0])
	{
		printf("%c", nNumb);
	}
	return;

}
void deblank(char string[]){
	int temp = 0;
	char gg[100] = { NULL };
	int j = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] != ' ')
		{
			gg[j] = string[i];
			j++;
		}

	}
	printf("%s", gg);

}



//ͳ���ַ��� ��ͬ�ַ����ֵĴ���
void stringcount(){
	char string[] = "acdefghijkimnpqrstuvwxyzxadfngemwqowieAZO";
	char Acount[26] = { 0 };
	int temp = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] > 96 && string[i] < 123) //��ȡ���е�Сд��ĸASCII���ֵ
		{
			temp = string[i] - 97;
		}
		else if (string[i] > 64 && string[i] < 91) //��ȡ���д�д��ĸASCII���ֵ
		{
			temp = string[i] - 65;
		}
		Acount[temp]++;
	}
	for (int i = 0; i < 26; i++)
	{
		char temp = 65 + i;
		if (Acount[i] >0)
		{
			printf("��ĸ:%c  %d\n", temp, Acount[i]);
		}
		
	}
	int i = 0;
}

//�׳����0-100�Ľ׳�
int factoriala(int numb){
	//int carry, n, j;
	//int a[40001];
	//int digit;
	//int temp, i;
	//while (scanf("%d", &n) != EOF){
	//	a[0] = 1; digit = 1;
	//	for (i = 2; i <= n; i++)
	//	{
	//		for (carry = 0, j = 1; j <= digit; ++j)
	//		{
	//			temp = a[j - 1] * i + carry;
	//			a[j - 1] = temp % 10;
	//			carry = temp / 10;
	//		}
	//		while (carry)
	//		{
	//			//digit++;
	//			a[++digit - 1] = carry % 10;
	//			carry /= 10;
	//		}
	//	}

	//	for (int k = digit; k >= 1; --k)
	//		printf("%d", a[k - 1]);
	//	printf("\n");
	//	printf("length=%d\n", digit);
	//}
	/************************************************************************/
	/* [3][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0][2][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/* [0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0][0]*/
	/************************************************************************/
	int atemp[1000] = { 0 };
	//int onetemp[1000] = { 0 };
	//int bb= _countof(atemp);
	//int ncount = 0;
	int tempa = 1;
	//	int tempb = 0;
	int carry;
	int j;
	atemp[0] = 1;
	int lenth = 1;//��ǰ����ĳ���
	for (int i = 2; i <= numb; i++)//��ȡҪ�׳˵�ֵ
	{
		for (carry = 0, j = 1; j <= lenth; j++)//��ȡ�ܵ�ֵ��ÿ��λ�� �� �׳˵�ֵ ��� carry�Ǳ����λ����?
		{
			tempa = atemp[j - 1] * i + carry;//�����λ��ʼ��  ���ѭ����ȷ���׳� ���֮�����Զ�Ǹ�λ
			atemp[j - 1] = tempa % 10;//���浱ǰ�±��λ��ֵ
			carry = tempa / 10;//���浱ǰ�±��λ���ϵ�ֵ
		}
		while (carry)//��CARRY ����0 ����ǰ�������󳤶Ȳ���
		{
			lenth++; //�����ǰ���Ȳ����Ļ�   
			atemp[lenth - 1] = carry % 10;//��ֵ%10
			carry /= 10; //��ֵ=��ֵ����10   
		}
	}
	for (int k = lenth; k >= 1; k--)
	{
		printf("%d", atemp[k - 1]);
	}
	printf("\n");
	printf("lenth:%d \n", lenth);
	return lenth;

}

void  Joseph(){

	int n, i, k, m;
	int array[50], *p;
	printf("please input the number of persons: n = \n");
	scanf_s("%d", &n,10);
	p = array;
	for (i = 0; i < n; i++)
		*(p + i) = i + 1;
	i = 0;      // i Ϊÿ��ѭ����������
	k = 0;     // k Ϊ��1,2,3����ʱ�ļ�������
	m = 0;    // mΪ�˳�������������
	while (m < n - 1)      //���˳�������n-1��ʱִ��ѭ����
	{
		if (*(p + i) != 0)
			k++;
		if (k == 3)             // ���˳����˱����Ϊ0
		{
			*(p + i) = 0;
			k = 0;
			m++;
		}
		i++;
		if (i == n)
			i = 0;
	}
	while (*p == 0)
		p++;
	printf("The last one is No. %d\n", *p);
	system("pause");
}
int _tmain(int argc, _TCHAR* argv[])
{
	// int b;
	// b= factorial(10);
	// b = rabbit();
	Myprintf("%d",55);
	Myprintf("%f", 55);
	Myprintf("%c", 78);
	//char * aa = "he llo 15 pb";
	//deblank(aa);
	//factoriala(99);
	//stringcount();
	//d
	//Joseph();
	return 0;
}

