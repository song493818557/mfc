// 01_顺序线性表.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "MyList.h"


//C语言面向过程的数据结构实现大致方式，
//我们需要理清，数据和函数之间的关系，在后期程序
//庞大了之后，管理会变得非常不方便
//bool InsertEle(
//	int m_Data[],
//	int nData,
//	int nLoc,
//	int* m_lenth
//	)
//{
//	// 1 检测插入的位置，是否超出当前长度
//	if (nLoc>m_Lenth)
//	{
//		return false;
//	}
//	// 2 检测当前线性表是否已经满了
//	if (m_Lenth == MAX_LENTH)
//	{
//		return false;
//	}
//	// 3 开始插入数据
//	// 3.1插入的位置是不是末尾
//	if (nLoc == m_Lenth)
//	{
//		m_Data[nLoc] = nData;
//	}
//	else
//	{
//		for (int i = m_Lenth - 1; i >= nLoc; i--)
//		{
//			m_Data[i + 1] = m_Data[i];
//		}
//		m_Data[nLoc] = nData;
//	}
//	m_Lenth++;
//	return true;
//}
//int m_Data[MAX_LENTH];
//int m_Lenth;
//InsertEle(m_Data, 10, 0, &m_Lenth);
//
//m_Data[10] = 10;

int _tmain(int argc, _TCHAR* argv[])
{
	int nEle = 0;
	CMyList obj;
	obj.InsertEle(10, 0);
	obj.InsertEle(11, 0);
	obj.InsertEle(12, 0);
	obj.DeleteEle(1, nEle);
	obj.InsertEle(14, 0);
	obj.PrintAll();

	//14 12  10

	
	return 0;
}

