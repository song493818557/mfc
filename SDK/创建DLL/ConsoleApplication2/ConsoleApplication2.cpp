// ConsoleApplication2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h" 
#include <iostream> 
#include <stdlib.h> 
#include <time.h>  
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	//587884D9
	/* 
	EAX 00275240
	ECX 587884D9
	*/
	int a,b,c;
	srand((unsigned)time(NULL));
	while (true)
	{
		printf("��ʼѭ��\n");
		a = (rand() % (100000 - 1000)) + 1000;  //�����
		printf("a = %Xh\n",a);
		b = a % 0xd;
		if (b >= 0x6)
		{
			printf("%x  >= 0x6\n ", b);
			if (b >= 0xc)
			{
				printf("%X  >= 0xC\n", b);
				printf("23333\n����ѭ��\n");
			}
			else{
				printf("%X  <= 0xC\n �˳�ѭ��\n", b);
				c = 2;
				break;
			}
		}
		else
		{
			printf("%X  <= 0x6\n", b);
			printf("%X,�˳�ѭ��\n", b);
			c = 1;
			break;
		}
	} 
	switch (c)
	{
	case 1: printf("---1111---\n");   break;
	case 2:	printf("---2222---\n");	break;
		 
	}
	system("pause");
	return 0;
}

