// 12_10_�쳣����.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <exception>
#include <iostream>
//using namespace std;
using std::cout;
using std::endl;

int divide(int nNuma, int nNumb)
{
	if (nNumb==0)
	{
		//__LINE__ �к�
		//__FILE__ �ļ���

		//�׳��쳣
		//throw 'a';    //��������ʽת��,���ܱ�catch(int)����
		//throw 999;
		//throw "����Ϊ��";
	}
	return nNuma / nNumb; //ϵͳ���Ҳ��throw
}

int main()
{
	try
	{
		//���ܻ����Ĵ���,����try������
		int a = divide(199, 0);
	}
	//ƥ���ʱ��,��������ת��
	catch (const std::exception& e)
	{
		//����������,���ʹ������
		cout << e.what();
	}
	catch (int e)     
	{
		cout << e << endl;
	}
	catch (const char * e)
	{
		cout << e << endl;
		//1.�ͷ�һЩ��Դ

		//2.д������־
		
	}
	catch (...)//��������(��������,��������)
	{ 
		cout << "δ���쳣"<<endl;
	}

    return 0;
}

