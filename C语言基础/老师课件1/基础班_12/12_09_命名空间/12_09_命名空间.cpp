// 12_09_�����ռ�.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <iostream>
#include "��ͷ.h"

namespace Outer                //���������ռ�
{
	int nNumA = 10;             
	int fun_a() { nNumA++; }   //�����������ڲ�,ʵ��Ҳ���ڲ�
	int fun_b();               //�����������ڲ�,ʵ�����ⲿ
	class CLASS                //��
	{
	public:
		int fun_c();
		int fun_d() {}
	};      
	namespace Inner
	{
		int nNumA = 999;
		int fun_a() { nNumA++; } //�����������ڲ�,ʵ��Ҳ���ڲ�
		int fun_aa();            //�����������ڲ�,ʵ�����ⲿ
	}

}
int Outer::fun_b()
{

}
int Outer::CLASS::fun_c()
{

}
int Outer::Inner::fun_aa()
{}

using namespace std;//���Ƽ�ʹ��
using std::cout;    //�Ƽ�����ʹ��
using std::cin;
using std::endl;

int main()
{
	//һ.����ֱ�ӷ���
	//nNumA;

	//��.ͨ�����ֵ�������(������)
	Outer::nNumA;
	Outer::Inner::nNumA;

	//��.ͨ����������,������(�Ƽ�ʹ�����ַ�ʽ)
	using Outer::nNumA;
	using Outer::fun_a;
	nNumA;
	fun_a(); 

	//��.ͨ�����������ռ�������
	namespace hehe = Outer;
	using namespace hehe;      //���������ռ�ı���
	//using namespace Outer;
	using namespace Inner;
	fun_b();
	fun_aa();
	fun111111();               //��֮��ͬ���ļ�,ͬһ�������ռ�

	
	

    return 0;
}

