// 8-12.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "sources.h"
using std::endl;
using std::cin;
using std::cout;
int _tmain(int argc, _TCHAR* argv[])
{

	//_man *aa  = new _man[10];
	_count_Machine surpercount;
	//�����ǰ���
	
	for (int temp = 1; 1;)
	{
		system("cls");
		//printf("��������ʽ������+ - * / %\n");
		printf("1 = ʹ�õ�ǰ���ʽ���� 2= ɾ�����ʽ 3 = �޸ı��ʽ1-5 \n");
		surpercount.outputresult();
		temp = surpercount.user_input();
		switch (temp)
		{
		case 1:
			//�ȴ��û�����
			printf("����������:44 55���Եó���ǰ���ʽ�Ľ�� %\n");
			surpercount.input_number(); break;
			
		case 2:
			//ɾ�����ʽ
			//printf("��������ʽ������+ - * / %\n");
			surpercount.delete_expression(); break;
		case 3:
			//�޸ı��ʽ
			printf("��������ʽ������+ - * / % \n");
			surpercount.expression(); break;
		default:
			break;
		}
		//������ʽ�����
		
		


	}
	
	
	//surpercount.call();
	//int &n = aa.chang;
	
	//���ûʲô����
	return 0;
}

