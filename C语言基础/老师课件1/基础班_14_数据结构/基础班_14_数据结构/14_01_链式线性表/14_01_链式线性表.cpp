// 14_01_链式线性表.cpp : 定义控制台应用程序的入口点。
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



	//1.初始化
	CMyList list;

	//2.插入数据()
	for (int i = 0; i < 100; i++)
	{
		//list.InsertList(i);   //插入线性表尾部
		list.InsertList(i, 0);//插入线性表头部
	}

	//3.删除数据(删除后会自动前移,所以删除的都是单数)
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

	//4.查询指定位置元素(遍历)
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
	//  查询元素的位置
	int pos = -1;
	list.LocateElem(0, 80, pos);
	//5.修改元素
	list.SetElem(pos, 99);
	//6.其他功能
	bool isEmpty = true;
	list.ListEmpty(isEmpty);
	list.ClearList();
	list.ListEmpty(isEmpty);
    return 0;
}

