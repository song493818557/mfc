// 14_01_��ʽ���Ա�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyList.h"


int main()
{
	// CMyList list;
	// list.InsertList(44);
	// list.InsertList(55);
	// list.InsertList(66);
	// list.InsertList(77);
	// list.InsertList(88);
	// 
	// list.InsertList(7878, 2);
	// int nRe = 0;
	// list.DeleteList(nRe, 2);
	// list.DeleteList(nRe, 2);



	//1.��ʼ��
	CMyList list;

	//2.��������()
	for (int i = 0; i < 100; i++)
	{
		//list.InsertList(i);   //�������Ա�β��
		list.InsertList(i, 0);//�������Ա�ͷ��
	}

	//3.ɾ������(ɾ������Զ�ǰ��,����ɾ���Ķ��ǵ���)
	for (int i = 0; i < 100; i++)
	{
		int deleteValue = 0;//ElemType
		list.DeleteList( deleteValue,i);
		printf("%3d ", deleteValue);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
	printf("\n");

	//4.��ѯָ��λ��Ԫ��(����)
	int len = 0;
	list.ListLength(len);
	for (int i = 0; i < len; i++)
	{
		int elemValue;//ElemType
		list.GetElem(i, elemValue);
		printf("%3d ", elemValue);
		if ((i + 1) % 10 == 0)
		{
			printf("\n");
		}
	}
	//  ��ѯԪ�ص�λ��
	int pos = -1;
	list.LocateElem(0, 80, pos);
	//5.�޸�Ԫ��
	list.SetElem(pos, 99);
	//6.��������
	bool isEmpty = true;
	list.ListEmpty(isEmpty);
	list.ClearList();
	list.ListEmpty(isEmpty);
    return 0;
}

