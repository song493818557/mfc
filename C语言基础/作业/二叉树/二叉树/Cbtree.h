#pragma once

class Cbtree
{
public:
	typedef struct treea
	{
		int mdata;
		treea *left;
		treea *right;
	};
	Cbtree():m_root(NULL){}
	//前后序
	void Pre()
	{
		PreList(m_root);
	}
	//中序
	void Premidell()
	{
		printf("%d ", m_root->mdata);
		PreList(m_root->left);
		PreList(m_root->right);
	}

public:
	//插入
	bool Finsert_Elt(int anumber);
	//删除
	void FDelete_Elt(int anumber);

	
private:
	void  Prehight()
	{
		printf("%d ", m_height);
	}
	void PreList(treea* pNode)
	{
		if (pNode == NULL)
		{
			return;
		}

		 PreList(pNode->right);
		printf("%d  ", pNode->mdata);
		PreList(pNode->left);

	}
	bool FDelete_main(int anumber, treea * &m_root);
	int  FGetTreeHeight(treea * atree);
	int  FGetmax(treea * atree);
	int  FGetmin(treea * atree);
	int m_height;
	treea* SigleLeft(treea* k1, treea * k2){
	k2->right =	k1->left;
	k1->left = k2;
	}
	treea* SigleRight(treea* k1, treea * k2){
		k2->left = k1->right;
		k1->right = k2;
	}
	treea* SigleRL(treea* k1, treea * k2){
		SigleRight(k1,  k2);
		SigleLeft(k1, k2);
	}
	treea* SigleLR(treea* k1, treea * k2){
		k2->left = k1->right;
		k1->right = k2;
	}
	treea* m_root;
};

