// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Csnake.h"


int _tmain(int argc, _TCHAR* argv[])
{
	/*
	�Զ�ˢ��ʳ��
	�Զ��ƶ�
	ֻ��3���ƶ�����
	�ж���Ӯ
	�ٶȿ���
	��ײ���
	*/
	Csnake ssnake;
	Cfood sfood;
	sfood.creat_food();
	ssnake.map_inInit();
	int checkpoint = ssnake.in_map;
	while (ssnake.in_map == checkpoint)
	{
		 
		ssnake.snake_move();
		sfood.push_food();
	}
	return 0;
}

