#include "stdafx.h"
#include "Clinksa.h"
Clinks::Clinks() :m_head(NULL), m_lenth(0)
{

}
bool Clinks::Finsert(int nLoc, int ndata){
	//��������ͷ����Ϊ0  ����ոտ�ʼ
	if (m_lenth == 0 || nLoc == 0)
	{
		Nothing *Newthis = new Nothing;//��������
		Newthis->Ndata = ndata;//��ֵ
		//��α����ַ 
		Newthis->Pnext = m_head;// ��ǰNewthis�����ָ��ָ�� Clinks ��ͷ�� ��ǰPNEXT��ָ��λ���ǿյ�
		m_head = Newthis;//Clinks��ͷ��ָ�� ָ��ոո�ֵ�ĵ�NEW NOTHING ��λ�� 
						//��Ϊ���Ǵ�λ��0����� Ҳ������ǰ��
		m_lenth++;
		return true;
	}
	//�����λ��̫����
	if (m_lenth < nLoc)
	{
		return false;
	}
	//��ʼ��������
	Nothing *Newtemp =m_head;//��������
	for (int i = 0; i < nLoc - 1;i++)
	{
		Newtemp = Newtemp->Pnext;//�ҵ���Ҫ�����λ�õ�ǰһ��

	}
	Nothing *Newthis = new Nothing;//��������
	Newthis->Ndata = ndata;
	Newthis->Pnext = Newtemp->Pnext;
	Newtemp->Pnext = Newthis;

	m_lenth++;
	return true;

}

int Clinks::Fselect(int e, int &ndata){

	Nothing *Newtemp = m_head;//��������

	for (int i = 0; i < m_lenth; i++)
	{
		if (Newtemp->Ndata == e)
		{
			ndata = Newtemp->Ndata;
			return ndata;
		}
		else
		{
			Newtemp = Newtemp->Pnext;//����Ѱ����һ��
		}
		

	}
	return true;

}

void Clinks::Fdeleteall(){
	Nothing * temp = m_head;
	for (int i = 0; i < m_lenth; i++)
	{		 
			m_head = temp;
			temp = temp->Pnext;//����Ѱ����һ��
			delete m_head;
	}
	m_head = NULL;
	m_lenth = 0;
	delete temp;
	return;

}

//ɾ��ָ��λ�õ�������� ���Ұ�ֵ����;
int Clinks::Fdelete(int nloc, int &ndata){
	//���λ�ô��ڵ��ڳ���
	if (nloc >= m_lenth)
	{
		return -1;
	}
	if (nloc == 0)
	{
		Nothing * Newthis = m_head;
		ndata = m_head->Ndata;
		m_head = m_head->Pnext;
		//����Ҫɾ��������
		
		delete Newthis;
		m_lenth--;
		return ndata;

	}
	Nothing * Ntem = m_head;
	//ͨ��m_head��NLOC  �����Ҫɾ���Ķ����λ��,�����ұ�ɾ�����ǰһ����
	for (int i = 0; i < nloc - 1; i++)
	{
		Ntem = Ntem->Pnext;
	}
	//�ҵ�λ�ú󴴽�һ���µĶ��󱣴�ǰһ���λ��
	Nothing * Newthis = Ntem->Pnext;
	Ntem->Pnext = Ntem->Pnext->Pnext;
	//����Ҫɾ��������
	ndata = Ntem->Ndata;
	delete Newthis;
	m_lenth--;
	return ndata;

	//
}