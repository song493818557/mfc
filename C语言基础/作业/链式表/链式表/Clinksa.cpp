#include "stdafx.h"
#include "Clinksa.h"
Clinks::Clinks() :m_head(NULL), m_lenth(0)
{

}
bool Clinks::Finsert(int nLoc, int ndata){
	//如果该类的头长度为0  代表刚刚开始
	if (m_lenth == 0 || nLoc == 0)
	{
		Nothing *Newthis = new Nothing;//创建对象
		Newthis->Ndata = ndata;//赋值
		//如何保存地址 
		Newthis->Pnext = m_head;// 当前Newthis对象的指针指向 Clinks 的头部 当前PNEXT的指针位置是空的
		m_head = Newthis;//Clinks的头部指针 指向刚刚赋值的的NEW NOTHING 的位置 
						//因为它是从位置0插入的 也就是最前面
		m_lenth++;
		return true;
	}
	//插入的位置太大了
	if (m_lenth < nLoc)
	{
		return false;
	}
	//开始正常插入
	Nothing *Newtemp =m_head;//创建对象
	for (int i = 0; i < nLoc - 1;i++)
	{
		Newtemp = Newtemp->Pnext;//找到需要插入的位置的前一个

	}
	Nothing *Newthis = new Nothing;//创建对象
	Newthis->Ndata = ndata;
	Newthis->Pnext = Newtemp->Pnext;
	Newtemp->Pnext = Newthis;

	m_lenth++;
	return true;

}

int Clinks::Fselect(int e, int &ndata){

	Nothing *Newtemp = m_head;//创建对象

	for (int i = 0; i < m_lenth; i++)
	{
		if (Newtemp->Ndata == e)
		{
			ndata = Newtemp->Ndata;
			return ndata;
		}
		else
		{
			Newtemp = Newtemp->Pnext;//继续寻找下一个
		}
		

	}
	return true;

}

void Clinks::Fdeleteall(){
	Nothing * temp = m_head;
	for (int i = 0; i < m_lenth; i++)
	{		 
			m_head = temp;
			temp = temp->Pnext;//继续寻找下一个
			delete m_head;
	}
	m_head = NULL;
	m_lenth = 0;
	delete temp;
	return;

}

//删除指定位置的链表对象 并且把值返回;
int Clinks::Fdelete(int nloc, int &ndata){
	//如果位置大于等于长度
	if (nloc >= m_lenth)
	{
		return -1;
	}
	if (nloc == 0)
	{
		Nothing * Newthis = m_head;
		ndata = m_head->Ndata;
		m_head = m_head->Pnext;
		//保存要删除的数据
		
		delete Newthis;
		m_lenth--;
		return ndata;

	}
	Nothing * Ntem = m_head;
	//通过m_head和NLOC  来获得要删除的对象的位置,首先找被删除点的前一个点
	for (int i = 0; i < nloc - 1; i++)
	{
		Ntem = Ntem->Pnext;
	}
	//找到位置后创建一个新的对象保存前一点的位置
	Nothing * Newthis = Ntem->Pnext;
	Ntem->Pnext = Ntem->Pnext->Pnext;
	//保存要删除的数据
	ndata = Ntem->Ndata;
	delete Newthis;
	m_lenth--;
	return ndata;

	//
}