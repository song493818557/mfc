// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
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
	/*        作业1                                                              */
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
	/*               作业2                                                  */
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
	/*               作业3                                                  */
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
	/*               作业4                                                  */
	/************************************************************************/
	/************************************************************************/
	/*               作业5            实现一个只能生成一个的类             */
	/***********************************************************************
	Conly::m_only = NULL;
	Conly::m_only = Conly::creay();
	Conly::cc();
	//Conly bb;*/
	//懒汉模式2
	CSingleton* aa = CSingleton::GetInstance();
	/************************************************************************/
	/* 二、饿汉模式：即无论是否调用该类的实例，在程序开始时就会产生一个该
	类的实例，并在以后仅返回此实例。
	由静态初始化实例保证其线程安全性，WHY？因为静态实例初始化
	在程序开始时进入主函数之前就由主线程以单线程方式完成了初始化，不必担心
	多线程问题。
	故在性能需求较高时，应使用这种模式，避免频繁的锁争夺。																									   */
	/************************************************************************/
//	const SingletonStatic * aa = SingletonStatic::getInstance();
	/************************************************************************/
	/*             懒汉模式2                                                  */
	/************************************************************************/
	/*Singleton* singleton1 = Singleton::getInstance();
	Singleton* singleton2 = Singleton::getInstance();

	if (singleton1 == singleton2)
	fprintf(stderr, "singleton1 = singleton2\n");*/
	return 0;
}

