// 6_03_ָ��Ͷ�ά����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <typeinfo.h>

int main()
{
	int a[4][3] = {
		{ 1, 2, 3 },
		{ 4, 5, 6 },
		{ 7, 8, 9 },
		{ 10, 11, 12 }
	};
	//������:������ʽ��ת��Ϊ�������洢���͵�ָ������
	int(*p)[3] = a; //��ǰͨ��������ʹ������ a[2][3];
	                //���ڿ���ͨ��ָ����ʹ������
	//a = p;
	printf("%s \n", typeid(a).name());  //int[4][3]
	printf("%s \n", typeid(p).name());    //int(*)[3]   
	printf("%s \n", typeid(a + 0).name());	 //int(*)[3]
	printf("%s \n", typeid(a[0]).name());	 //int[3]
	printf("%s \n", typeid(&a[0]).name());	 //int(*)[3]
	printf("%s \n", typeid(&a).name());		 //int(*)[4][3]
	printf("%s \n", typeid(a[0][0]).name()); //int
	printf("%s \n", typeid(&a[0][0]).name());//int(*)

	int i, j;
	for (i = 0, j = 0; j < 3; j++)
	{
		printf("%d\t", *(*p + j));
	}
	putchar('\n');

	for (i = 1, j = 0; j < 3; j++)
	{
		printf("%d\t", *(p[i] + j));
	}
	putchar('\n');
	for (i = 2, j = 0; j < 3; j++)
	{
		printf("%d\t", (*(p + i))[j]);
	}
	putchar('\n');
	for (i = 3, j = 0; j < 3; j++)
	{
		printf("%d\t", *(&p[0][0] +i * 3 + j));
	}
	putchar('\n');

	return 0;
}

