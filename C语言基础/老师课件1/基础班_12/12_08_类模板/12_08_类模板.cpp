// 12_08_��ģ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"


#include <stdlib.h>
#include <iostream>
using std::cout;  using std::endl;

template <class T>
class CVector {
public:
	CVector(int nCount) : m_nSize(nCount) {
		m_pData = new T[nCount];
		memset(m_pData, 0, nCount);
	}
	~CVector() { delete m_pData; }
	T operator[](int nIndex) { return m_pData[nIndex]; }

	int fun();

private:
	T  *m_pData;
	int m_nSize;
};

//������ʵ�ֳ�Ա�������﷨(���ܷ���cpp��,ֻ��һ�����.h�ļ���)
template <class T>
int CVector<T>::fun()
{
	
}

int _tmain(int argc, _TCHAR* argv[]) {
	CVector<int> objNum(15);
	cout << objNum[1] << endl;
	system("pause");
	return 0;
}

