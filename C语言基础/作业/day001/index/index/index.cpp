// index.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//day002 -1  �Ƚ���������С ���
int getmax(int a, int b, int c){
	int temp;
	a > b ? temp=a : temp=b;
	return temp >c ? printf("%d\n", temp) : printf("%d\n", c);
	
}

//day002 -2 ��357����
void getaliquot(){
	int temp;
	scanf_s("%d", &temp);
	if (temp % 7 == 0 && temp % 3 == 0 && temp % 5 == 0)
	{
		printf("%d�ܱ�3 5 7����\n", temp);
	}
	else if (temp % 7 == 0 && temp % 3 == 0){

		printf("%d�ܱ�7 5����\n", temp);
	}
	else if (temp % 3 == 0 && temp % 5 == 0){

		printf("%d�ܱ�3 5����\n", temp);
	}
	else if (temp % 7 == 0 && temp % 5 == 0){

		printf("%d�ܱ�5 7����\n", temp);
	}
	else if (temp % 7 == 0  ){

		printf("%d�ܱ� 7����\n", temp);
	}
	else if ( temp % 5 == 0){

		printf("%d�ܱ�5 ����\n", temp);
	}
	else if (temp % 3 == 0 && temp % 5 == 0){

		printf("%d�ܱ�3����\n", temp);
	}
	else  {
		printf("%d���ܱ�3 5 7����\n", temp);
	}


}

//day002 - 6 ��ȡ�ܱ�9���� ��2����
void get92quot(){
	for (int i = 9; i < 100;i++)
	{
		if (i%9 ==2)
		{
			printf("%d\n",i);
		}
	}

}
//day002 -7 ���0~999֮�������ˮ�ɻ���
void getsxh(){
	for (int i = 1; i < 10;i++)
	{
		for (int j = 0; j < 10; j++)
		{
			for (int k = 0; k < 10; k++)
			{
				if (i*100 +j*10 +k == (i*i*i)+(j*j*j)+(k*k*k) )
				{
					printf("%d%d%d ", i, j, k);
				}
			}
		}
	}

}
//����λ��ת
void changeint(){
	int n = 38;
	int bb = 0;
	for (int i = 0; i < 4;i++)
	{
		bb=(1 << i);
		 n ^= (1 << i);
		printf("bb= %d   n= %d\n", bb,n);
	}
	int b = 0;
	return;
}
//ͳ���ж��ٸ�1
void numb1(int a ){
	int countb = 0;
	int counta = 0;
	while (a  > 1)
	{
		a % 2 == 1 ? countb++ : counta++;
		a = a / 2; 
		
	}
	a == 1 ? countb++ : counta++;

	printf("%d", countb);
}
//Helen��ʽ ����S=(A+B+c)/2; 
//��������� =  s*(s-a)*(s-b)*(s-c)
void Helen(){
	int helennumber[3] = { 0 };
	while (true)
	{
		
		scanf_s("%d %d %d", &helennumber[0], &helennumber[1], &helennumber[2]);
		int a = helennumber[0];
		int b = helennumber[1];
		int c = helennumber[2];
		int s = (a+b+c) / 2;
		int area = s*(s - a)*(s - b)*(s - c);
		if ((a + b > c)&&(a + c > b)&&(c + b > a))
		{
			printf("���Ϊ %d\n", area);
		}
		else
		{
			printf("���ܹ���������\n");
		}
		if (area > 0 )
		{
			printf("���Ϊ %d\n", area);
		}
		else
		{
			printf("���ܹ���������\n");
		}


	}
	

}
/*
���ӳ������� ���ӵ�һ��ժ�����ɸ����� ���켴����һ�� �ֳ���һ�� �ڶ������ʣ�µ����ӵ�һ�� �ֶ����һ�� ֱ����ʮ�� ֻʣ��һ�������� ���һ�����ժ���˶��ٸ�����
��һ�� X%2+1
�ڶ��� (X%2+1)%2+1
������ (X%2+1)%2+1
������ ((X%2+1)%2+1)%2+1
������ (X%2+1)%2+1
������ (X%2+1)%2+1
������ (X%2+1)%2+1
�ڰ��� (X%2+1)%2+1
�ھ��� (X%2+1)%2+1
��10��   1
*/
void monkeyandpeach(){
	int allpeach = 0;
	int day = 10;
	int temp = 1;
	for (int i = day-1; i > 0; i--)
	{
		if (i== 9)
		{
			temp = temp * 2 + 1+1;
			printf("���ӵ�%d����%d������\n", i, temp);
			continue;
		}
		temp = temp * 2 + 1;
		printf("���ӵ�%d����%d������\n", i, temp);
	}

}
int _tmain(int argc, _TCHAR* argv[])
{

	//getmax(3,7, 4);
	//getaliquot();
	//get92quot();
	//getsxh();	
	//numb1(57);
	//changeint();
	//Helen();

	//monkeyandpeach();
	//int nArray[10] = {};
	//int nOffset = 3;
	//int *p = &nArray[0]; //(a); ��ʼ *p   =  narray[0]�ĵ�ַ
	//p = nArray;//(b); ��nArray���׵�ַ���� p
	//p += nOffset; //(c)��nArray���׵�ַ������3��λ�� Ҳ�͵���nArray[3]�ĵ�ַ
	//p += 3;       //(d)��nArray[3]�ĵ�ַ������3��λ��  Ҳ�͵���nArray[6]�ĵ�ַ
	//*p += 3; //(E)nArray[6]��ֵ+3;
	//int bb = *(p + 3);    //(F)������nArray[9]�ĵ�ַ Ӧ���ǵ���0
 
	return 0;
}

