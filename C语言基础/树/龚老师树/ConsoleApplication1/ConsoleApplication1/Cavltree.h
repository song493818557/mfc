#pragma once
#include "Gtree.h" 
class Cavltree:public CMyTree
{
public:
	Cavltree();
	~Cavltree();
	virtual Status Insert(  /**�����в����½ڵ�,����ֵ��Ϊe,Ԫ�ظ�����1*/
		ElemType e,            //[in] �������ֵ
		PNODE pNode = nullptr  //[out] ���ز����λ��
		);

	virtual Status Delete(  /**��ֵΪe�Ľڵ�������ɾ��,Ԫ�ظ�����1*/
		ElemType e,            //[in] ɾ����Ԫ��ֵ
		PNODE pNode = nullptr  //[out] ����ɾ����λ��
		);

	/**��ת(ƽ��)*/
	Status BalanceTree(PNODE & pNode);

	/**�ҵ���*/
	Status SingleR(PNODE & pNode);
	/**����*/
	Status SingleL(PNODE & pNode);
	/**����˫��*/
	Status DoubleLR(PNODE & pNode);
	/**����˫��*/
	Status DoubleRL(PNODE & pNode);
};

