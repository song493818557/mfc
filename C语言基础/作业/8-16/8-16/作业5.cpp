// 8-16.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;

//template < typename T2>
template < typename T1>

class Csearch{
public:
	//初始化赋值
	//INT 数组和 CHAR数组的
	//Csearch(int cc[], int gg) {
	//	m_Maxlenth = gg;
	//	Array = new T1[m_Maxlenth + 1];
	//	memset(Array, 0, gg*sizeof(int));
	//	//strncat_s(Array, gg, cc, gg);
	//	memcpy_s(Array, gg*sizeof(int), cc, gg*sizeof(int));
	//}
	Csearch(T1*  cc, int gg) {
		m_Maxlenth = gg;
		Array = new T1[m_Maxlenth + 1];
		memset(Array, 0, (m_Maxlenth + 1)*sizeof(T1));
		memcpy_s(Array, gg*sizeof(T1), cc, gg*sizeof(T1));
		//strncat_s(Array, m_Maxlenth, cc, m_Maxlenth);
	}

	/*T1 search(T1 b){
		//int sTrlen = strlen(Array);
		for (int i = 0; i < m_Maxlenth; i++)
		{
			if (Array[i] == b)
			{
				
				return i+1;
				break;
			}			
		}
		return 0;}*/
	int search(T1 b){
		
		for (int i = 0; i < m_Maxlenth; i++)
		{
			if (Array[i] == b)
			{

				return i + 1;
				break;
			}
		}
		return 0;
	}

private:
	T1* Array;
	int m_Maxlenth;
};

 

int _tmain(int argc, _TCHAR* argv[])
{
	///char bb[] = {"qwertyuiopasdfghjkl"};
	char bb[] = { "qwertyuiopasdfghjkl" };
	int jj[] = {5,3,4,9,8,7,6,0,1,2 };
	Csearch<char> bbb(bb,21);
Csearch<int> cc(jj, 11);
	int j = bbb.search('g');
	int q = cc.search(7);
	//c=Fmax(a, d);
	return 0;
}

