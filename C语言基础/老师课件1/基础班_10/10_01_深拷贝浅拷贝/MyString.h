#pragma once
class CMyString
{
public:
	CMyString();
	~CMyString();
	CMyString(CMyString &);//���ǳ����������

	char * m_buf;
	int m_size;
};

