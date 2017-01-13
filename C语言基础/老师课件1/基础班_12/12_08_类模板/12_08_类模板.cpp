// 12_08_类模板.cpp : 定义控制台应用程序的入口点。
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

//类体外实现成员函数的语法(不能放在cpp中,只能一起放在.h文件中)
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

