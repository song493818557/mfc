#include "stdafx.h"
#include "MyAVLTree.h"


CMyAVLTree::CMyAVLTree():CMyTree()
{
}


CMyAVLTree::~CMyAVLTree()
{
}

/************************************
* Access:    virtual public 
* 函数功能:  在树中插入新节点,并将值设为e,元素个数加1
* 
* 参数列表:
*   ElemType e:    [in] 插入的新值
*   PNODE pNode:   [out] 返回插入的位置
*
* 返回值:    Status
* 
*************************************/
Status CMyAVLTree::Insert( ElemType e, PNODE pNode /* = nullptr */ )
{
    //1. 插入数据,返回插入节点副本
    NODE insNode;
    Status result = CMyTree::Insert(e, &insNode);

    if (result!=RESULT_TRUE)
    {
        return RESULT_FALSE;
    }

    //2.从插入点父节点开始,依次判断是否平衡,直到根节点.
    PNODE pFather = insNode.pFather;
    BalanceTree(pFather);

    //3.设置返回值
    if (pNode)
    {
        *pNode = insNode;
    }
    return RESULT_TRUE;
}

/************************************
* Access:    virtual public 
* 函数功能:  将值为e的节点在树中删除,元素个数减1
* 
* 参数列表:
*   ElemType e:     [in] 删除的元素值
*   PNODE pNode:    [out] 返回删除的位置
*
* 返回值:    Status
* 
*************************************/
Status CMyAVLTree::Delete( ElemType e, PNODE pNode /* = nullptr */ )
{
    //1.删除数据,返回删除节点副本
    NODE delNode;
    Status result = CMyTree::Delete(e, &delNode);

    if (result !=RESULT_TRUE)
    {
        return RESULT_FALSE;
    }

    //2.从删除点父节点开始,依次判断是否平衡,直到根节点
    PNODE pFather = delNode.pFather;
    BalanceTree(pFather);

    //3.设置返回值
    if (pNode)
    {
        *pNode = delNode;
    }
    return RESULT_TRUE;
}

Status CMyAVLTree::BalanceTree(PNODE & pNode)
{
    while (pNode != nullptr )//&& pNode!= m_pRoot
    {
        //1.分四种情况开始旋转
        int LChildDepth, RChildDepth;
        BiTreeDepth(pNode->pLChild, LChildDepth);
        BiTreeDepth(pNode->pRChild, RChildDepth);

        //1.1 - 1.2
        if (LChildDepth - RChildDepth>1)
        {
            BiTreeDepth(pNode->pLChild->pLChild, LChildDepth);
            BiTreeDepth(pNode->pLChild->pRChild, RChildDepth);
            if (LChildDepth >= RChildDepth) 
            {
                //  1.1 左子树高 - 右子树高 > 1 ; 左.左子树高 >= 左.右子树高
                //      右单旋
                //      K2
                //     /
                //    K1
                //   / 
                //  N   
                SingleR(pNode);
            }else {
                //  1.2 左子树高 - 右子树高 > 1 ; 左.左子树高  < 左.右子树高
                //      左右旋
                //      K2
                //     /
                //    K1
                //     \
                //      N
                DoubleLR(pNode);
            }
        
        //1.3 - 1.4
        }else if (RChildDepth- LChildDepth>1)
        {
            BiTreeDepth(pNode->pRChild->pLChild, LChildDepth);
            BiTreeDepth(pNode->pRChild->pRChild, RChildDepth);
            if (RChildDepth>=LChildDepth)
            {
                //  1.3 右子树高 - 左子树高 > 1 ; 右.右子树高 >= 右.左子树高
                //      左单旋
                //      K2
                //       \
                //        K1
                //         \
                //          N
                SingleL(pNode);
            }else {
                //  1.4 右子树高 - 左子树高 > 1 ; 右.右子树高  < 右.左子树高
                //      右左旋
                //      K2
                //       \
                //        K1
                //       /
                //      N
                DoubleRL(pNode);
            }
        }

        //2. 继续向上迭代
        pNode = pNode->pFather;
    }
   
    return RESULT_TRUE;
}

Status CMyAVLTree::SingleR(PNODE & pNode)
{
     //左子树高 - 右子树高 > 1 ; 左.左子树高 >= 左.右子树高
     //      右单旋
     //      K2              K1
     //     /               / \
     //    K1       ->     N   K2
     //   / \                 /
     //  N   T               T
     // 步骤:
     //   1. 将K1的右子树保存到K2的左子树中
     //   2. 将K1的右子树置为K2
     //

    //1. 先确定 K2,K1
    PNODE K2 = pNode;
    PNODE K1 = K2->pLChild;
    PNODE T = K1->pRChild;

    //2. 将K1的右子树保存到K2的左子树中
    K2->pLChild = T;

    //3. 将K1的右子树置为K2
    K1->pRChild = K2;

    //4. 重置节点中的父节点指针信息
    K1->pFather = K2->pFather;
    K2->pFather = K1;
    if (T)
    {
        T->pFather = K2;
    }

    //5. 与外部重新连起来(修改外部指针,指向新的局部根节点)
    if (K1->pFather == nullptr) 
    {
    //    5.1 若不平衡的点(pNode)是根节点,只需改变 m_pRoot
        m_pRoot = K1;

    }else if (K1->Data < K1->pFather->Data)
    {
    //    5.2 若不平衡的点(pNode)是其父节点的左子节点
        K1->pFather->pLChild = K1;
    }
    else {
    //    5.3 若不平衡的点(pNode)是其父节点的右子节点
        K1->pFather->pRChild = K1;
    }

    return RESULT_TRUE;
}

Status CMyAVLTree::SingleL(PNODE & pNode)
{
    //  右子树高 - 左子树高 > 1 ; 右.右子树高 >= 右.左子树高
    //      左单旋
    //      K2                 K1
    //       \                / \
    //        K1      ->     K2  N
    //       / \              \
    //      T   N              T
    //
    //步骤:
    //    1. 将K1的左子树保存到K2的右子树中
    //    2. 将K1的左子树置为K2

    //1. 先确定 K2,K1,T
    PNODE K2 = pNode;
    PNODE K1 = K2->pRChild;
    PNODE T = K1->pLChild;

    //2. 将K1的左子树保存到K2的右子树中
    K2->pRChild = T;

    //3. 将K1的左子树置为K2
    K1->pLChild = K2;

    //4. 重置节点中的父节点指针信息
    K1->pFather = K2->pFather;
    K2->pFather = K1;
    if (T)
    {
        T->pFather = K2;
    }

    //5. 与外部重新连起来(修改外部指针,指向新的局部根节点)
    //    5.1 若不平衡的点(pNode)是根节点, 只需改变 m_pRoot
    if (K1->pFather==nullptr)
    {
        m_pRoot = K1;
    }else if (K1->Data < K1->pFather->Data)
    {
    //    5.2 若不平衡的点(pNode)是其父节点的左子节点
        K1->pFather->pLChild = K1;
    }
    else {
    //    5.3 若不平衡的点(pNode)是其父节点的右子节点
        K1->pFather->pRChild = K1;
    }

    return RESULT_TRUE;
}

Status CMyAVLTree::DoubleLR(PNODE & pNode)
{
    //  左子树高 - 右子树高 > 1 ; 左.左子树高  < 左.右子树高
    //      左右旋
    //      K2              K2            N   
    //     /               /             / \
    //    K1      ->      N       ->    K1  K2
    //     \             / 
    //      N           K1
    //
    // 步骤:
    //   1. 以K2的左子树做根节点,左单旋
    //   2. 以K2 做根节点,右单旋

    SingleL(pNode->pLChild);
    SingleR(pNode);

    return RESULT_TRUE;
}

Status CMyAVLTree::DoubleRL(PNODE & pNode)
{
    //  右子树高 - 左子树高 > 1 ; 右.右子树高  < 右.左子树高
    //      右左旋
    //      K2          K2             N
    //       \           \            / \
    //        K1   ->     N    ->    K2  K1
    //       /             \
    //      N               K1
    //
    // 步骤:
    //  1. 以K2的右子树做根节点,右单旋
    //  2. 以K2做根节点,左单旋
    SingleR(pNode->pRChild);
    SingleL(pNode);

    return RESULT_TRUE;
}
