#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	CMyString(CMyString &);//深拷贝浅拷贝的问题

	char * m_buf;
	int m_size;
};

