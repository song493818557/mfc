// 04_预先理解的语法.cpp : 定义控制台应用程序的入口点。
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
	//    第一个节点 第二个   第三个
	Head->Next->     Next->   Next;

	return 0;
}

