// 11_09_ʹ�ô��麯��������ӿڱ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Animal.h"
#include "Tiger.h"
#include "Monkey.h"


int main()
{
	//����ӿڱ��(�߼���ϵ���ǻ��ڽӿ�)
	CAnimal * animal[10];


	for (int i = 0; i < 5; i++)
	{
		animal[i] = new CTiger; //�滻������࣬������벻��Ҫ�޸�
	}
	for (int i = 5; i < 10; i++)
	{
		animal[i] = new CMonkey; //��������࣬������벻��Ҫ�޸�
	}


	//������붼�ǻ��ڽӿڹ���������
	for (int i = 0; i < 10; i++)
	{
		animal[i]->eat();   //ͨ������ָ����ʹ���������
							//ͨ���ӿ������þ���ĺ���ʵ��
	}
	return 0;
}


