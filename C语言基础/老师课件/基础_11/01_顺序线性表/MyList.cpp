#include "stdafx.h"
#include "MyList.h"


CMyList::CMyList() :m_Lenth(0)
{
}


CMyList::~CMyList()
{
}
bool CMyList::InsertEle(
	int nData,
	int nLoc
	)
{
	// 1 检测插入的位置，是否超出当前长度
	if (nLoc>m_Lenth)
	{
		return false;
	}
	// 2 检测当前线性表是否已经满了
	if (m_Lenth == MAX_LENTH)
	{
		return false;
	}
	// 3 开始插入数据
	// 3.1插入的位置是不是末尾
	if (nLoc==m_Lenth)
	{
		m_Data[nLoc] = nData;
	}
	else
	{
		for (int i = m_Lenth - 1; i >= nLoc; i--)
		{
			m_Data[i + 1] = m_Data[i];
		}
		m_Data[nLoc] = nData;
	}
	m_Lenth++;
	return true;
}


bool CMyList::DeleteEle(
	int nLoc,
	int& Ele
	)
{
	//1 位置不正确
	if (nLoc>=m_Lenth)
	{
		return false;
	}
	//2 保存要被删除的数据
	Ele = m_Data[nLoc];
	//3 开始删除
	for (int i = nLoc; i < m_Lenth-1; i++)
	{
		m_Data[i] = m_Data[i + 1];
	}
	m_Lenth--;
	return true;
}