// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string.h>

class Cstring {
public:
	Cstring(char * s){
		int temp = strlen(s) + 1;
		m_char = new char[temp];
		memset(m_char, 0, temp);
		strcpy_s(m_char, temp, s);
	} 
	Cstring(Cstring &s){
	int temp = strlen(s.m_char) + 1;
	  m_char = new char[temp];
	memset(m_char, 0, temp);
	strcpy_s(m_char, temp, s.m_char);
	} 
	~Cstring(){
		delete[] m_char;
		m_char = NULL;
	}
	//修改字符串的第I个元素
	void reset(int numb, char g){
		m_char[numb-1] = g;
	}
private:
	char * m_char;
};
int _tmain(int argc, _TCHAR* argv[])
{
	Cstring aa("abcdefghijk");
	Cstring bb(aa);
	aa.reset(3, '8');
	return 0;
}

