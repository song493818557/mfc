// 9_11_��������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class CLocation {
public:
	CLocation(CLocation& obj) // ��������
		:m_X(obj.m_X), m_Y(obj.m_Y) {
		cout << "Copy initialization\n";
	}
	CLocation(int nX, int nY) // ��ͨ���ι���
		:m_X(nX), m_Y(nY)
	{}
private:
	int m_X, m_Y;
};
CLocation  fun_A(CLocation  obj) { return obj; }
CLocation& fun_B(CLocation& obj) { return obj; }

int _tmain(int argc, _TCHAR* argv[]) {
	CLocation objA(3, 4);
	CLocation objB(objA);          //1.����һ������,������һ����������ʼ����
	fun_A(objB);                   //2.��һ���������β��������,ʵ��Ҳ������� ʱ����ÿ���������
								   //3.��һ�������ķ���ֵ�������,return�������Ҳ������� ʱ ,����ÿ�������

	CLocation& objD = fun_B(objB);//ע�⣺���ô��β����ÿ������죬���÷���ֵҲ�����ÿ�������

	CLocation objB = objA;  //��ͬ���͵ı�����ʼ������,����ÿ�������
	CLocation objC(objA);   //ͬ��

	objC = objB;            //��ֵ:���� ����= �ĺ���

	return 0;
}


