// 03_ָ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	//1 ����һ��ָ��,��ʹ��
	int * p = 0;//��ʶ��Ϊ0
	int Num1 = 100;
	p = &Num1;
	printf("%d\n", *p);
	*p = 200;
	printf("%d\n", Num1);
	//2 ָ�����֤
	printf("p�д洢������%d\n", p);
	printf("��p�����õ�����%d\n", *p);
	printf("Num1�����ĵ�ַ%d\n", &Num1);
	printf("Num1������ֵ%d\n", Num1);
	printf("p��������ĵ�ַ%d", &p);
	//3 ָ�������
	printf("p�д洢������%d\n", p);
	printf("p+1�õ�������%d\n", *p+1);


	char b;
	//p = &b;����ֱ�Ӹ�ֵ������ȡ��ַ֮���������͵�

	char buf[10] = "hello";
	char * p2 = buf;
	printf("��������ֵ%d", buf);//���������׵�ַ
	printf("��������ֵ%s", buf);//���BUF������ַ���
	scanf_s("%s", buf, 10);//����֤����������һ����ַ
	                       //ֵ��������׵�ַ

//	buf = p2;

	//char  p3; 'A'
	return 0;
}

