// 9_10_转换构造.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

class CNumber
{
public:
	CNumber(){}
	explicit CNumber(int a):m_nNum(a) {} //explicit不允许此构造函数做间接转换
	CNumber(int a,int b) :m_nNum(a) {}
	~CNumber() {}
private:
	int m_nNum;
	//const int m_nNumB;
};

int main()
{
	//正常使用
	CNumber objA;
	CNumber objB();
	CNumber objC(67);
	CNumber objD(67,98);

	//objA = 99; //把其他类型的变量直接赋值给对象时,会引发隐式转换
	           //C++会尝试用变量去匹配CNumber类中的构造函数,
	           //如果匹配上,就生成一个临时对象,
	           //最后把临时对象的数据逐个赋值给objA.

	objA = (CNumber)100;  //添加explicit后,阻止隐式转换,但不能阻止强制转换
	objA = CNumber(100);

	objA = {100,220};
    return 0;
}

