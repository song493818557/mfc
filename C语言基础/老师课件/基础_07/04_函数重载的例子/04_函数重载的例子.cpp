// 04_�������ص�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
//��������˵���ǣ�ͬ�����������Ǻ���������ͬ�����õ�ʱ��
//���������Զ�ƥ����ʵĺ���

//����extern "C"����������C�ķ�ʽʹ�ú���������������Ʒ��飬
//Ҳ�Ͳ�֧�ֺ�������
extern "C" int Add(int a, int b)
{
	printf("��������int�Ͳ���\n");
	return a + b;
}

extern "C" int Add(int a, char b)
{
	printf("����һ��int�Ͳ�����һ��char�Ͳ���\n");
	return a + b;
}

//char Add(int a, int b)//����ֵ���Ͳ�ͬ�����ܹ�������
//{
//	printf("��������int�Ͳ���\n");
//	return a + b;
//}



int _tmain(int argc, _TCHAR* argv[])
{
	Add(1, 2);
	Add(1, 'A');
	return 0;
}

