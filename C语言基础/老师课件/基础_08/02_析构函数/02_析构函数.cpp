// 02_��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
int g_Num = 0;
class CTest
{
public:
	CTest()  {  // ���캯��
		m_num = g_Num;
		g_Num++;

		//printf("����%d�Ź���",m_num);
		m_szName = new char[20];

	}
	~CTest() {  // ��������
		printf("����%d������", m_num);
		delete[] m_szName;
	}
	void Shifang()
	{
		delete[]m_szName;
	}
protected:
	char *m_szName;
	int m_num;
};

CTest obj1;

int _tmain(int argc, _TCHAR* argv[])
{
	//CTest obj;//������������Զ����ù��캯��
	//obj.Shifang();
	//CTest * p = new CTest;

	//delete p;

	return 0;//�ֲ����󼴽��Զ����٣����Զ�������������
}

