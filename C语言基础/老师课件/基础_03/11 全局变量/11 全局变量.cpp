// 11 ȫ�ֱ���.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

//extern int g_Num;//extern�����þ��ǣ�����������ڴ��ļ��У�ȥ����ļ���һ��
int g_Num;

void Fun(int a)
{
	printf("%d", g_Num);
	if (a%2 == 0)
	{
		g_Num = 1;
	}
	else
	{
		g_Num = 0;
	}

}

void fun()
{
	static int a = 10;//static �����ھֲ�������ʱ������ʹ�ñ���ֵһֱ������ס
	                  //�����˳��˺�������һ�ν��뺯����ʱ�򣬻�����һ���뿪����
	                  //ʱ���ֵ��
	printf("%d", a);
	a++;
}
int _tmain(int argc, _TCHAR* argv[])
{
	//Fun(2);
	//int g_Num = 4;
	//printf("%d", g_Num);


	fun();
	fun();
	fun();
	return 0;
}

