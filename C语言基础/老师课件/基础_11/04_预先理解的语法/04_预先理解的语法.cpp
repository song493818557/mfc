// 04_Ԥ�������﷨.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class _HAHA
{
public:
	int nData;

	_HAHA* Next;
};
//15pb_11_helloworld

int _tmain(int argc, _TCHAR* argv[])
{
	_HAHA *Head;
	_HAHA FirstNode;
	_HAHA SecondNode;
	_HAHA ThirdNode;
	FirstNode.nData = 10;
	SecondNode.nData = 20;
	ThirdNode.nData = 30;
	Head = &FirstNode;
	FirstNode.Next = &SecondNode;
	SecondNode.Next = &ThirdNode;
	ThirdNode.Next = NULL;
	//    ��һ���ڵ� �ڶ���   ������
	Head->Next->     Next->   Next;

	return 0;
}

