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
	// 1 �������λ�ã��Ƿ񳬳���ǰ����
	if (nLoc>m_Lenth)
	{
		return false;
	}
	// 2 ��⵱ǰ���Ա��Ƿ��Ѿ�����
	if (m_Lenth == MAX_LENTH)
	{
		return false;
	}
	// 3 ��ʼ��������
	// 3.1�����λ���ǲ���ĩβ
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
	//1 λ�ò���ȷ
	if (nLoc>=m_Lenth)
	{
		return false;
	}
	//2 ����Ҫ��ɾ��������
	Ele = m_Data[nLoc];
	//3 ��ʼɾ��
	for (int i = nLoc; i < m_Lenth-1; i++)
	{
		m_Data[i] = m_Data[i + 1];
	}
	m_Lenth--;
	return true;
}