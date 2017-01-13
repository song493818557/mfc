// 815.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdlib.h>
using std::cout;
using std::cin;
using std::endl;
using namespace std;
class Cstring
{
public: 
	////将字符串初始化传到内存里面去
	////Cstring(){}
	////将字符串初始化传到内存里面去
	Cstring(char* achar){
		m_char = new char[strlen(achar) + 1];
		memset(m_char, 0, strlen(achar) + 1);
		memcpy_s(m_char, strlen(achar) + 1, achar, strlen(achar));
	}
	/*Cstring(Cstring& a) {

		m_char = new char[strlen(a.m_char)+1];

		memcpy_s(m_char, strlen(a.m_char) + 1, a.m_char, strlen(a.m_char));
		}*/
	Cstring operator+(Cstring& bb ){
		char * Tmp;
		int len = (strlen(m_char) + strlen(bb.m_char) + 1);
		Tmp = new char[len];
		strcpy_s(Tmp, len, m_char);//内存拷贝
		strncat_s(Tmp, len, bb.m_char, strlen(bb.m_char));//字符串组合

		//delete[]m_char;
		//m_char = Tmp;
		//strcpy_s(Tmp, 41, bb.m_char);//内存拷贝
		//realloc(Tmp,81);
		//strncat_s(Tmp, 80, m_char, strlen(m_char));//字符串组合
	
		Cstring temp(Tmp);
		
		return temp;

	}
	void operator+=(Cstring& bb){
		//char * Tmp;
		int len = (strlen(m_char) + strlen(bb.m_char) + 1);
		realloc(m_char, len);
		strncat_s(m_char, len, bb.m_char, strlen(bb.m_char));//字符串组合
	}
	char& operator[](int a){
		if (a > strlen(m_char))
		{
		//	cout << "太大了";
			return m_char[a];
		}
		
	}
	bool operator==(Cstring& bb){
		if (m_char==bb.m_char)
		{
			//cout << "相同";
			return true;
		}
		return false;
	}
	/*Cstring operator=(Cstring const &bb){
		m_char = new char[strlen(bb.m_char) + 1];
		memset(m_char, 0, strlen(bb.m_char) + 1);
		memcpy_s(m_char, strlen(m_char), bb.m_char, strlen(bb.m_char));

		}*/

	~Cstring(){
		
		m_char = nullptr;
		delete[] m_char;
	}
	void Freset(char* achar){
		m_char = NULL;
		delete[] m_char;
		m_char = new char[sizeof(achar) + 1];
		memcpy_s(m_char, 20, achar, 20);
	}
	void Fdelete(){
		m_char = NULL;
		//delete[] m_char;
	}
	void Flen(){
		int m = strlen(m_char);
	//	cout << m << endl;
	}
	void Flena(int i){
	//	cout << m_char[i-1] << endl;		
	}
	void Flenb(char  aa,int i){
		m_char[i - 1] = aa;
		//cout << m_char[i - 1] << endl;
	}
	friend ostream &operator<< (ostream &os, Cstring b);
	friend istream &operator>>(istream &is, Cstring b);
private:
	char * m_char;
	//int m_number;

};
ostream &operator<< (ostream &os, Cstring b){
	os << b.m_char;
	return os;

}
istream &operator>> (istream &is, Cstring b){
	is >> b.m_char;
	return is;

}
int _tmain(int argc, _TCHAR* argv[])
{

	
	//Cstring ToString("abcdefgh");
	//Cstring Astring(ToString);
	Cstring Astring("abcdefghaa");
	Cstring ToString("bbbb");
	cout << ToString;
	cin >> ToString;
	//ToString += Astring;
	
//	char i = ToString[5];
	//bool i = (ToString == Astring);
	//Cstring Bstring = ToString + Astring;
	//Cstring Bstring = Astring + ToString;
	//Cstring Cstring = Astring;
	/*Astring.Flenb('h',3);
	 Astring.Freset("ywssddx");
	Astring.Fdelete(); */
//	int a = 0;
	
	return 0;
}

