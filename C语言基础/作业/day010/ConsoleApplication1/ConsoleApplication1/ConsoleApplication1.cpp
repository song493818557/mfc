// ConsoleApplication1.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Animal.h"
#include "Cshape.h"
#include <time.h>
#include "Cteacher.h"
#include "Conly.h"
#include "CgetInstance.h"

void RangedRandDemo(int range_min, int range_max, int &n)
{
	// Generate random numbers in the half-closed interval
	// [range_min, range_max). In other words,
	// range_min <= random number < range_max
	n = (double)rand() / (RAND_MAX + 1) * (range_max - range_min)
			+ range_min; }

int _tmain(int argc, _TCHAR* argv[])
{
	/************************************************************************/
	/*        ��ҵ1                                                              */
	/************************************************************************/
	//CCat cat;
	//cat.nNuma=2;
	//CLeopard leopard;
	//leopard.nNuma = 2;
	//CAnimal Animal;
	//CAnimal * p = &Animal;
	//p->miao();
	//p = &cat;
	//p->miao();
	//p = &leopard;
	//p->miao();
	/************************************************************************/
	/*               ��ҵ2                                                  */
	/************************************************************************/	
	Cshape * aa[10];
	srand((unsigned)time(NULL));
 
	CRectangle ra[5];
	Circle ca[5];
	int temp = 0, tra = 0, tca = 0;
	for (int i = 0; i < 10; i++)
	{
		if (i % 2 == 0)
		{
			aa[i] = new CRectangle;
			tra++;
		}
		else
		{
			aa[i] = new Circle;
			tca++;
		}
		RangedRandDemo(2, 20, temp);
		aa[i]->seta(temp);
	}
	for (int i = 0; i < 10; i++)
	{
		aa[i]->Area();
	}
	//

	/************************************************************************/
	/*               ��ҵ3                                                  */
	/************************************************************************/
	/*Cteacher * bb[6];
	Cprofessor proa(10);
	Cprofessor prob(20);
	Cfprofessor fproa(10);
	Cfprofessor fprob(20);
	Clecturer teachera(10);
	Clecturer teacherb(20);
	bb[0] = &proa;
	bb[1] = &prob;
	bb[2] = &fproa;
	bb[3] = &fprob;
	bb[4] = &teachera;
	bb[5] = &teacherb;
	for (int i = 0; i < 6;i++)
	{
	bb[i]->get_wage();
	}*/
	/************************************************************************/
	/*               ��ҵ4                                                  */
	/************************************************************************/
	/************************************************************************/
	/*               ��ҵ5            ʵ��һ��ֻ������һ������             */
	/***********************************************************************
	Conly::m_only = NULL;
	Conly::m_only = Conly::creay();
	Conly::cc();
	//Conly bb;*/
	//����ģʽ2
	CSingleton* aa = CSingleton::GetInstance();
	/************************************************************************/
	/* ��������ģʽ���������Ƿ���ø����ʵ�����ڳ���ʼʱ�ͻ����һ����
	���ʵ���������Ժ�����ش�ʵ����
	�ɾ�̬��ʼ��ʵ����֤���̰߳�ȫ�ԣ�WHY����Ϊ��̬ʵ����ʼ��
	�ڳ���ʼʱ����������֮ǰ�������߳��Ե��̷߳�ʽ����˳�ʼ�������ص���
	���߳����⡣
	������������ϸ�ʱ��Ӧʹ������ģʽ������Ƶ���������ᡣ																									   */
	/************************************************************************/
//	const SingletonStatic * aa = SingletonStatic::getInstance();
	/************************************************************************/
	/*             ����ģʽ2                                                  */
	/************************************************************************/
	/*Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2)
	fprintf(stderr, "singleton1 = singleton2\n");*/
	return 0;
}

