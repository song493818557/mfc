// ����DLL�ı�д.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "����DLL�ı�д.h"


// ���ǵ���������һ��ʾ��
DLL_API int n����DLL�ı�д=0;

// ���ǵ���������һ��ʾ����
DLL_API int fn����DLL�ı�д(void)
{
	return 42;
}

// �����ѵ�����Ĺ��캯����
// �й��ඨ�����Ϣ������� ����DLL�ı�д.h
C����DLL�ı�д::C����DLL�ı�д()
{
	return;
}
