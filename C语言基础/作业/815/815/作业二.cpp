// 815.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;
class Ccircle
{
public: 
	int m_height = 1;//�߶�
	int m_area = 2;//���
private:
	//int m_number;

};
class Ctable
{
public:
	//int m_number;
	int color = 3;//��ɫ
	int texture = 4;//����
private:

};
class Croundtable :private Ccircle, private Ctable{
public:
	void outinfo(){
		cout << m_height << m_area << color << texture <<endl;

	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	Croundtable quan;
	int temp;
	 quan.outinfo();
	return 0;
}

