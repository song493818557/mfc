// 8-17.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "memory.h"
#include <iostream>
using std::cout;
using std::endl;

int find(char *a,char b){
	for (int i = 0;i<strlen(a);i++)
	{
		if (a[i]==b)
		{
			return i+1;
		}
	}
	return 0;
}
int find(char *a, char *b){
	
	int maxb = strlen(b);
	for (int i = 0; i < strlen(a); i++)
	{
		int anumber = 0;
		int temp = 0;
		if (a[i] == b[anumber])
		{
			for (int ia = i; (ia < strlen(a)) && (anumber < maxb); ia++)
			{
				if (a[ia] == b[anumber])
				{
					anumber++;
				//	ia++;
					
						temp = ia;
					continue;//���ؼ���
				}
				else
				{
					anumber = 0;
					break;//ʧ�� ����ƥ��B��ͷֵ
				}
			}
			if (anumber == maxb)
			{
				return temp - maxb;
			}
		}
	}
	return 0;
}


int Finsert(char *a, char b,int nLoc){

	if (strlen(a)>=nLoc){

	a[nLoc] = b;
	return 1;
	}
	else
	{
		cout << "�����λ��̫��";
		return 0;
	}
	
}

int Finsert(char *a, char *b, int nLoc){
	int maxa = strlen(a);
	int maxb = strlen(b);
	//������Ϊ
	for (int i = maxa; i > maxb; i--)
	{
		//����һλ
		int k = i + maxb;
		a[k] = a[i];
		/*for (int i = 0; i >= maxb; i++)
		{
			
		}*/
	}
	for ( int i = 0; i <maxb; i++)
	{
		//����һλ
		a[nLoc-1 + i] = b[i];
		/*for (int i = 0; i >= maxb; i++)
		{

		}*/
	}
	return 0;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char a[100] = "abcdefghiomsxa";
	char b[10] = "def";
	//char b = 'd';
	int c = find(a, b);
	//char d = 'k';
	char d[10] = "you";
	int e = Finsert(a, d,5);
	printf("abcdefghiomsxa\n");
	printf("%s\n", a);
	printf("%s\n", d);
	return 0;
}

