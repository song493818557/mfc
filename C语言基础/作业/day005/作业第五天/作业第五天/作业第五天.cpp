// ��ҵ������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <string.h>
#include <stdlib.h>
//ʵ�������ַ����ĸ���(�β���ָ�����)
void  charstrcpy(char *astring,char *bstring){
	int ssize = strlen(astring);
	for (int i = 0; i < ssize;i++)
	{
		bstring[i] = astring[i];
	}
}
//ɾ�����з���ĸ�ַ�
void deletenochar(char *astring){
	int ssize = strlen(astring);
	char *bstring = (char*)malloc(ssize);
	memset(bstring, 0, ssize);

	for (int i = 0, j = 0; i < ssize; i++)
	{
		if ((astring[i] > 0x0041 && astring[i]<0x005a) || (astring[i]> 0x0061 && astring[i]< 0x007a))
		{
			bstring[j] = astring[i];//����������ֵ	
			j++;
		}
		astring[i] = 0;//����		
	}
	for (int i = 0; i < strlen(bstring);i++)
	{
		astring[i] = bstring[i];
	}
	free(bstring);
	//������ָ���ַ��ֵ  ���������� ���Ѿ�û����
	//astring  = bstring;
}

//�����ַ��� �����ڴ�  �����ڴ��ַ
char*  getnumb(){
	char  astring[100] = {0};
	scanf_s("%s", astring,100); 
	char * aa = (char *)malloc(strlen(astring));
	memset(aa, 0, strlen(astring)); 
	for (int i = 0; i < strlen(astring);i++)
	{
		aa[i] = astring[i];
	}
	//aa = astring; 
	//free(aa);
	return aa;
}
//
int _tmain(int argc, _TCHAR* argv[])
{
	char a[] = ">?@[]5544.,>?~!@&^^ffskddxmdfdf";
	char b[20] = {0};
	//charstrcpy(a,b);
	//deletenochar(a);
	char*  gg = getnumb();
	free(gg);
	return 0;
}

