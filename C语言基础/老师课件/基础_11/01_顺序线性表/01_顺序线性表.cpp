// 01_˳�����Ա�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "MyList.h"


//C����������̵����ݽṹʵ�ִ��·�ʽ��
//������Ҫ���壬���ݺͺ���֮��Ĺ�ϵ���ں��ڳ���
//�Ӵ���֮�󣬹�����÷ǳ�������
//bool InsertEle(
//	int m_Data[],
//	int nData,
//	int nLoc,
//	int* m_lenth
//	)
//{
//	// 1 �������λ�ã��Ƿ񳬳���ǰ����
//	if (nLoc>m_Lenth)
//	{
//		return false;
//	}
//	// 2 ��⵱ǰ���Ա��Ƿ��Ѿ�����
//	if (m_Lenth == MAX_LENTH)
//	{
//		return false;
//	}
//	// 3 ��ʼ��������
//	// 3.1�����λ���ǲ���ĩβ
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

