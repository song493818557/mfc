// 10 �ֲ�����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	int NumA = 10;

	if (5>3)
	{
		int NumA = 5;
		int NumB = 100;
		printf("%d", NumA);//ʹ�õ���С��Χ��NumA
	}
	printf("%d", NumA);//ʹ�õ��Ǵ�Χ��NumA
	//printf("%d", NumB);//�޷�ʹ���뿪���������NumB
	return 0;
}

void Fun()
{
	//printf("%d", NumA);//����ģ��ֲ�����ֻ�����Լ��ĺ�����{}��ʹ��
}