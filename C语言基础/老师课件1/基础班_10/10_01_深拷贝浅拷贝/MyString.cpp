#include "stdafx.h"
#include "MyString.h"
#include <string.h>


CMyString::CMyString()
{
	m_buf = new char[255];
	m_size = 255;
	memset(m_buf, 0, 255);
}

CMyString::~CMyString()
{
	delete[] m_buf;
}

CMyString::CMyString(CMyString & str)
{
	//Ĭ�Ͽ�������,���Ǽ򵥵���������ݳ�Ա��ֵ������
	//ǳ����
	//m_size = str.m_size;
	//m_buf = str.m_buf;

	//���
	m_size = str.m_size;
	m_buf = new char[m_size];
	//memcpy(m_buf, str.m_buf, m_size);
	strcpy_s(m_buf, m_size, str.m_buf);

}
