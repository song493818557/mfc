// 02_List��ʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <list>  //1 ����ͷ�ļ�
using std::list; //2 ʹ�������ռ�

int _tmain(int argc, _TCHAR* argv[])
{
	//��ʽʹ��

	list<int> obj;

	obj.push_back(10); //��β������
	obj.push_back(11); 
	obj.push_front(12);//��ͷ������
	//����
	list<int>::iterator listit = obj.begin();
	for (; listit != obj.end(); listit++)
	{
		printf("%d", *listit);
	}

	return 0;
}

