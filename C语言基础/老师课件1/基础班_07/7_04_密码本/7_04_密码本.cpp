// 7_04_���뱾.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "ctrl.h"
/*
�汾����
1.���ļ����� 
2.��̬�ڴ�
3.�ļ��洢
4.���ܴ���
*/
int main()
{
	//PASSWORD  pwd[NUM] = { 0 }; //��������
	PPASSWORD pPwd = nullptr;
	int nCount = 0;               //��ǰ�������
	g_size = 0;                   //��ǰ���뱾����

	readInfo(&pPwd,&nCount);

	while (true)
	{
		printf("��������ѡ��:\n");
		printf("1 �鿴��������:\n");
		printf("2 ��������:\n");
		printf("3 ɾ������:\n");
		printf("4 �޸�����:\n");
		printf("5 ��ѯ����:\n");
		printf("6 ��������(�ı�):\n");
		printf("7 ��������(������):\n");

		OPTION op;
		scanf_s("%d", &op);

		switch (op)
		{
		case �鿴����:
			searchAllInfo(pPwd, nCount);
			break;
		case ����:
			insertInfo(pPwd, &nCount);
			break;
		case ɾ��:
			deleteInfo(pPwd, &nCount);
			break;
		case �޸�:
			alterInfo(pPwd, nCount);
			break;
		case ��ѯ:
			searchInfo(pPwd, nCount);
			break;
		case �����ı�:
			SaveInfoA(pPwd, nCount);
			break;
		case ���������:
			SaveInfoB(pPwd, nCount);
			break;
		default:
			break;
		}
	}
    return 0;
}

