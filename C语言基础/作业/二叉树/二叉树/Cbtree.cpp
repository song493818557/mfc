#include "stdafx.h"
#include "Cbtree.h"
//PUBLICɾ���ӿ�
void Cbtree::FDelete_Elt(int anumber){
	FDelete_main( anumber, m_root);
}
bool Cbtree::FDelete_main(int anumber, treea * &atree)
{	
	//������ӽڵ�Ļ� 
	if (atree->left == NULL && atree->right == NULL){
		//����ӽڵ��ֵ����Ҫɾ����ֵ 
		if (anumber == atree->mdata){
			delete atree;
			atree = NULL;//ɾ����λ��   ������������  
			//bool Cbtree::FDelete_main(int anumber, treea * atree) 
			//�����������񲻺�ʹ ��Ҫ������
			//bool Cbtree::FDelete_main(int anumber, treea * &atree)
			return true;
		}
		else
		{
			return false;
		}
	}
	//�����ҵ�Ҫɾ���� ����anumber�Ľڵ�ֵ
	//����õݹ�Ļ� ��Ҫ���ǳ�ȥ�ĵط�
	
		//���ڵĻ� ���ڵ�������
		if (anumber > atree->mdata){
			//atree = atree->right;
			return FDelete_main(anumber, (atree->right));
		}
		else if (anumber < atree->mdata)
		{
			//atree = atree->left;
			return FDelete_main(anumber, (atree->left));
		}
		else
		{	//�Ѿ��ҵ�
			//��ȡ����������߶�  ����������߶� 
			int nleft = FGetTreeHeight(atree->left);
			int nright = FGetTreeHeight(atree->right);
			//�����ߵĸ߶ȴ����ұߵĸ߶�
			//���ʱ������ ��ȡ��   ��ȡС�ķ�ʽȥ�ж�  ��Ϊ��Ҫ���游�ڵ��mdata��ֵ
			if (nleft > nright)
			{
				int max = FGetmax(atree->left);
				//ֱ�ӽ����滻 
				atree->mdata = max;
				return FDelete_main(max, atree->left);
			}
			else
			{
				int min = FGetmin(atree->right);
				//ֱ�ӽ����滻 
				atree->mdata = min;
				return FDelete_main(min, atree->right);
			}
			
		}

	
	
}
//���������
bool Cbtree::Finsert_Elt(int anumber){
	if (m_root == NULL)
	{
		m_height = 0;//��ʼ���и�
		m_root = new treea;
		m_root->mdata = anumber;
		m_root->left = m_root->right = NULL;
		return 0;
	}
	int *p = new int;
	//2 �������Ϊ��
	treea * pTemp = m_root;
	while (true)
	{
		//���ֵ���ڻ��� �����ұ���
		if (pTemp->mdata < anumber)
		{
			//����ҵ��ǿյĻ� �ʹ�������
			if ((pTemp->right) == NULL)
			{
				pTemp->right = new treea;
				pTemp->right->mdata = anumber;
				pTemp->right->left = pTemp->right->right = NULL;//��ʼ�����������ڵ�
				return true;
			}
			else
			{
				pTemp  = pTemp->right;
			}
		}
		else
		{
			if ((pTemp->left) == NULL)
			{
				pTemp->left = new treea;
				pTemp->left->mdata = anumber;
			//	m_root->left = m_root->right = NULL;
				pTemp->left->left = pTemp->left->right = NULL;//��ʼ�����������ڵ�
				return true;
			}
			else
			{
				pTemp = pTemp->left;
			}
		}

	}
}

/*��ȡ����*/
int  Cbtree::FGetTreeHeight(treea * atree){

	if (atree == NULL){
		return 0;
	}
	int nleft = FGetTreeHeight(atree->left);
	int nright = FGetTreeHeight(atree->right);
	int nHeight =  (nleft > nright ? nleft : nright) + 1;
	return nHeight;

}
/*��ȡ��Сֵ*/
int  Cbtree::FGetmax(treea * atree){

	if (atree == NULL){
		return 0;
	}
	int max = 0;
	while (true)
	{
		max = atree->mdata;
		atree = atree->right;
	}
	return max;

}
/*��ȡ���ֵ*/
int  Cbtree::FGetmin(treea * atree){

	if (atree == NULL){
		return 0;
	}
	int max = 0;
	while (atree != NULL)
	{
		max = atree->mdata;
		atree = atree->left;
	}
	return max;

}
/*��ȡ��С
*/