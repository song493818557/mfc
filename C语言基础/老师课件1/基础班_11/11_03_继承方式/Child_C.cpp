#include "stdafx.h"
#include "Child_C.h"


CChild_C::CChild_C()
{
}


CChild_C::~CChild_C()
{
}

void CChild_C::fun()//��������,���Ž��ɵļ̳и��׵�����
{					//(�����̳�,��Щ����(public)��Ϊ������,��Щ���Բ���)
	m_Money;        //�̳��˸��׵�Ǯ        �������� -> ��������
	m_Face;			//�̳��˸��׵���ò      �������� -> ��������
	//m_WenHua;		//�̳в��˸��׵�֪ʶ    ˽������ -> XXXXXXX
}
