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
	//默认拷贝够着,就是简单的逐个把数据成员的值赋过来
	//浅拷贝
	//m_size = str.m_size;
	//m_buf = str.m_buf;

	//深拷贝
	m_size = str.m_size;
	m_buf = new char[m_size];
	//memcpy(m_buf, str.m_buf, m_size);
	strcpy_s(m_buf, m_size, str.m_buf);

}
