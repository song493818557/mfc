#include "stdafx.h"
#include "Ctree.h"


Ctree::Ctree() :m_pRoot(NULL){}
/***************************************
函数名: PreOrderTraverse
作用:前序遍历
参数0:开始位置  
说明:
/***************************************/
void Ctree::PreOrderTraverse(PNODE& pNode){
	if (pNode == NULL) return;
	printf("%d\n", pNode->nData);
	PreOrderTraverse(pNode->pLeft);
	PreOrderTraverse(pNode->pRight);
}

 /***************************************
函数名: Insert
作用:向树中插入一个数据
参数0:是要添加的数据
参数1:用于得到一个错误码
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::Insert(
	int nEle,//参数0 要插入的数据
	int & nError //参数1 错误码
	)
{
	return InsertNode(nEle, m_pRoot, nError);
}
/***************************************
函数名: GetHeight
作用:向树中插入一个数据
PNODE pTree //要获取树高的子树
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
int Ctree::GetHeight(
	PNODE pTree //要获取树高的子树
	)
{
	if (pTree == NULL)
	{
		return 0;
	}
	int nLeftHeight = GetHeight(pTree->pLeft);
	int nRightHeight = GetHeight(pTree->pRight);
	return (nLeftHeight > nRightHeight ? nLeftHeight : nRightHeight) + 1;
}

/***************************************
函数名: GetMax
作用:获取最大值的值
参数0:要获取最大值的子树
参数1:用于得到一个最大值
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::GetMax(
	PNODE pTree,//要获取最大值的子树
	int & nMax//用于得到最大的值
	)
{
	if (pTree == nullptr)
	{
		return false;
	}
	while (pTree)
	{
		nMax = pTree->nData;
		pTree = pTree->pRight;
	}
	return true;
}

/***************************************
函数名: GetMax
作用:获取最小值的值
参数0:要获取最小值的子树
参数1:用于得到一个最小值
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::GetMin(
	PNODE pTree,//要获取最大值的子树
	int & nMin//用于得到最大的值
	)
{
	if (pTree == nullptr)
	{
		return false;
	}
	while (pTree)
	{
		nMin = pTree->nData;
		pTree = pTree->pLeft;
	}
	return true;
}

/***************************************
函数名: SingleL
作用:此节点为圆心左旋
参数0:要旋转的节点 
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::SingleL(  /*此节点为圆心左旋 */
	PNODE& pNode//要旋转的节点
	)
{
	//      K2					K1
	//        \				   /  \
	//          K1			  K2   N
	//           \
	//             N
	PNODE K2 = pNode;
	PNODE K1 = pNode->pRight;
	K2->pRight = K1->pLeft;
	K1->pLeft = K2;
	pNode = K1;
	return true;
}


/***************************************
函数名: SingleR
作用:此节点为圆心右旋
参数0:要旋转的节点
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::SingleR(  /*此节点为圆心右旋 */
	PNODE& pNode//要旋转的节点
	)
{
	//        K2			K1
	//       /  		   /  \
    //      K1			  N   K2
	//     /    
	//    N
	PNODE K2 = pNode;
	PNODE K1 = pNode->pLeft;
	K2->pLeft = K1->pRight;
	K1->pRight = K2;
	pNode = K1;
	return true;
}


/***************************************
函数名: SingleLR
作用:此节点为圆心左右旋
参数0:要旋转的节点
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::SingleLR(  /*此节点为圆心左右旋 */
	PNODE& pNode//要旋转的节点
	)
{						                         
	//        K2		     K2                   N
	//       /  		    /                    / \
    //       K1		->>	   N	     ->>        K1  K2
	//       \  		  /                   
	//        N			 K1                  
	SingleL(pNode->pLeft);
	SingleR(pNode);
	return true;
}


/***************************************
函数名: SingleRL
作用:此节点为圆心右左旋
参数0:要旋转的节点
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::SingleRL(  /*此节点为圆心右左旋 */
	PNODE& pNode//要旋转的节点
	)
{
	//    K2    		 K2                       N
	//    \     		  \                      / \
  //       K1		->>	   N	     ->>        K2  K1
	//    /     		    \                 
	//   N      		     K1            
	SingleL(pNode->pRight);
	SingleR(pNode);
	return true;
}
/***************************************
函数名: InsertNode
作用:此节点为圆心右左旋
参数0:要旋转的节点
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::InsertNode(
	int nEle,//参数0:要添加的数据
	PNODE& pNode,//参数1:是要插入的子树
	int &nError//参数2:用于得到一个错误码
	){
	bool nSucess = true;
//1判断是否是要插入的节点
	if (pNode == NULL)
	{
	    pNode = new NODE;
		pNode->nData = nEle;
		pNode->pRight =  pNode->pLeft = NULL;
		return true;
	}
//2 判断要插入的数据和当前的根节点比较大小
	if (nEle > pNode->nData)
	{
		nSucess = InsertNode(nEle, pNode->pRight, nError);
	}
	else if (nEle < pNode->nData){

		nSucess = InsertNode(nEle, pNode->pLeft, nError);
	}
	// 2.1判断bool值是否为真  否则RETURN
	if (nSucess == false)
	{
		return false;
	}
//3 判断一下经历了删除之后  本节点是否平衡
	int nLheight = GetHeight(pNode->pLeft);
	int nRheight = GetHeight(pNode->pRight);
	int nSub = nLheight - nRheight;// -2  2 如果差值大于2  才不平衡
	//如果左边高
	if (nSub == 2)
	{
		nLheight = GetHeight(pNode->pLeft->pLeft);
		nRheight = GetHeight(pNode->pLeft->pRight);
		//比较当前节点的左右树高
		if (nLheight >= nRheight)
		{
			SingleR(pNode);//需要右旋
		}
		else
		{
			SingleLR(pNode);//需要左右旋
		}		
	}
	//如果右边高
	else if (nSub == -2)
	{
		nLheight = GetHeight(pNode->pRight->pLeft);
		nRheight = GetHeight(pNode->pRight->pRight);
		//比较当前节点的左右树高
		if (nLheight >= nRheight)
		{
			SingleL(pNode);//需要左旋
		}
		else
		{
			SingleRL(pNode);//需要右左旋
		}
	}
	return true;
}

/***************************************
函数名: DeleteNode
作用:此节点为圆心右左旋
参数0:要旋转的节点
返回值 用于判断此函数是否执行成功
说明:
/***************************************/
bool Ctree::DeleteNode(
	int nEle,//参数0:要添加的数据 
	PNODE &pTree,//参数1:要删除节点的子树
	int &nError//参数2:用于得到一个错误码
	){
	bool nSucess = true;
	//1判断是为空节点
	if (pTree == NULL)
	{
		return false;
	}
	//2 判断要删除的数据和当前的根节点比较大小
	if (nEle > pTree->nData)//右边找
	{
		nSucess = DeleteNode(nEle, pTree->pRight, nError);
	}
	else if (nEle < pTree->nData){

		nSucess = DeleteNode(nEle, pTree->pLeft, nError);
	}
	else
	{
		//2.1 如果是当前节点 
		//如果是叶子节点 直接删除
		if (pTree->pLeft == NULL && pTree->pRight == NULL)
		{
			delete pTree;
			pTree = NULL;
			return true;
		}
		//如果是树干(删除树干的思路就是把树干节点的子节点的 值(左大右小 与插入的时候相反)赋值到当前的树干节点 然后删除的是最后那个叶子节点) 获取当前节点的左右树高		
		int nLheight = GetHeight(pTree->pLeft);
		int nRheight = GetHeight(pTree->pRight);
		//判断谁高 
		if (nLheight > nRheight)//如果左子树高
		{
			//获取左子树的最大值 之后赋值 并到左子树中删除最大值
			int nMax = 0;
			GetMax(pTree->pLeft, nMax);
			pTree->nData = nMax;
			DeleteNode(nMax, pTree->pLeft, nError);
		}
		//如果右子树高
		else
		{
			//获取右子树的最小值 之后赋值 并到右子树中删除最小值
			int nMin = 0;
			GetMax(pTree->pRight, nMin);
			pTree->nData = nMin;
			DeleteNode(nMin, pTree->pRight, nError);
		}		
	}	
	// 2.5判断bool值是否为真  否则RETURN
	if (nSucess == false)
	{
		return false;
	} 
	//3 判断一下经历了删除之后  本节点是否平衡
	int nLheight = GetHeight(pTree->pLeft);
	int nRheight = GetHeight(pTree->pRight);
	int nSub = nLheight - nRheight;
	//如果左边高
	
	if (nSub == 2)
	{
		nLheight = GetHeight(pTree->pLeft->pLeft);
		nRheight = GetHeight(pTree->pLeft->pRight);
		// 比较当前节点的左右树高
		if (nLheight >= nRheight)
		{
			SingleR(pTree->pLeft);//需要右旋
		}
		else
		{
			SingleLR(pTree->pLeft);//需要左右旋
		} 
	}
	//如果右边高
	else if (nSub == -2)
	{
		//比较当前节点的左右树高
		nLheight = GetHeight(pTree->pRight->pLeft);
		nRheight = GetHeight(pTree->pRight->pRight);
		if (nLheight <= nRheight)
		{
			SingleR(pTree->pRight);//需要左旋
		}
		else
		{
			SingleLR(pTree->pRight);//需要右左旋
		} 
	}
	return true;
}

bool Ctree::Delete(
	int nEle,//参数0 要插入的数据
	int & nError //参数1 错误码
	){
	return DeleteNode(nEle, m_pRoot, nError);
}