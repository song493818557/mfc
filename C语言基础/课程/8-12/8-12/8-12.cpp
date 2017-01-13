// 8-12.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using std::endl;
using std::cout;
//void test(){
//	printf("yes");
//}
struct _onebingxiang
{
	int a;
	int b;
	void test(){ printf("yes"); }
}onebingxiang;
class CTest{
public:CTest(int i) :m_j(i), m_i(i){};
	   void fun(){
		   cout << m_i << endl << m_j;
	   }
private: int m_j; int m_i;
	   

};
; int _tmain(int argc, _TCHAR* argv[])
{
	CTest objTest(98);
	objTest.fun();
	
	/*_onebingxiang aa;
	aa.test();*/

	return 0;
}

