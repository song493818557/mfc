#include "stdafx.h"
#include "Cbtree.h"
//PUBLIC删除接口
void Cbtree::FDelete_Elt(int anumber){
	FDelete_main( anumber, m_root);
}
bool Cbtree::FDelete_main(int anumber, treea * &atree)
{	
	//如果是子节点的话 
	if (atree->left == NULL && atree->right == NULL){
		//如果子节点的值等于要删除的值 
		if (anumber == atree->mdata){
			delete atree;
			atree = NULL;//删除置位空   本来是这样的  
			//bool Cbtree::FDelete_main(int anumber, treea * atree) 
			//但是这样好像不好使 需要传引用
			//bool Cbtree::FDelete_main(int anumber, treea * &atree)
			return true;
		}
		else
		{
			return false;
		}
	}
	//尝试找到要删除的 等于anumber的节点值
	//如果用递归的话 需要考虑出去的地方
	
		//大于的话 根节点往右找
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
		{	//已经找到
			//获取求出左子树高度  求出右子树高度 
			int nleft = FGetTreeHeight(atree->left);
			int nright = FGetTreeHeight(atree->right);
			//如果左边的高度大于右边的高度
			//这个时候依据 左取大   右取小的方式去判断  因为他要代替父节点的mdata的值
			if (nleft > nright)
			{
				int max = FGetmax(atree->left);
				//直接进行替换 
				atree->mdata = max;
				return FDelete_main(max, atree->left);
			}
			else
			{
				int min = FGetmin(atree->right);
				//直接进行替换 
				atree->mdata = min;
				return FDelete_main(min, atree->right);
			}
			
		}

	
	
}
//插入二叉树
bool Cbtree::Finsert_Elt(int anumber){
	if (m_root == NULL)
	{
		m_height = 0;//初始化行高
		m_root = new treea;
		m_root->mdata = anumber;
		m_root->left = m_root->right = NULL;
		return 0;
	}
	int *p = new int;
	//2 如果树不为空
	treea * pTemp = m_root;
	while (true)
	{
		//如果值大于基数 就往右边找
		if (pTemp->mdata < anumber)
		{
			//如果找到是空的话 就创建插入
			if ((pTemp->right) == NULL)
			{
				pTemp->right = new treea;
				pTemp->right->mdata = anumber;
				pTemp->right->left = pTemp->right->right = NULL;//初始化他的子树节点
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
				pTemp->left->left = pTemp->left->right = NULL;//初始化他的子树节点
				return true;
			}
			else
			{
				pTemp = pTemp->left;
			}
		}

	}
}

/*获取树高*/
int  Cbtree::FGetTreeHeight(treea * atree){

	if (atree == NULL){
		return 0;
	}
	int nleft = FGetTreeHeight(atree->left);
	int nright = FGetTreeHeight(atree->right);
	int nHeight =  (nleft > nright ? nleft : nright) + 1;
	return nHeight;

}
/*获取最小值*/
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
/*获取最大值*/
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
/*获取大小
*/