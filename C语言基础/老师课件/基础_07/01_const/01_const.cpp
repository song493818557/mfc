// 01_const.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	const int a = 10;
	int Arrayp[a] = {1,2,3,4};
	int b = 0;
//	a = 100;  ���������޸�
	//��һ�����
	int const * p1 = NULL;
	 //p�Ǳ���������ָ���µ�λ��
	p1 = &b;
	//*p = 100;//����ģ�����ͨ��*p�޸�ָ���λ��
	//�ڶ������
	const int  *  p2 = NULL;
	//ͬ��
	//���������
	int  * const p3 = NULL;
	//p3 = &b;//����ģ�p3�ǳ���������ָ���µ�λ��
	*p3 = 100;//��ȷ��
	return 0;
}

