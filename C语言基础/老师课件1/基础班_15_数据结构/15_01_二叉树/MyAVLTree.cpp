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
* ��������:  �����в����½ڵ�,����ֵ��Ϊe,Ԫ�ظ�����1
* 
* �����б�:
*   ElemType e:    [in] �������ֵ
*   PNODE pNode:   [out] ���ز����λ��
*
* ����ֵ:    Status
* 
*************************************/
Status CMyAVLTree::Insert( ElemType e, PNODE pNode /* = nullptr */ )
{
    //1. ��������,���ز���ڵ㸱��
    NODE insNode;
    Status result = CMyTree::Insert(e, &insNode);

    if (result!=RESULT_TRUE)
    {
        return RESULT_FALSE;
    }

    //2.�Ӳ���㸸�ڵ㿪ʼ,�����ж��Ƿ�ƽ��,ֱ�����ڵ�.
    PNODE pFather = insNode.pFather;
    BalanceTree(pFather);

    //3.���÷���ֵ
    if (pNode)
    {
        *pNode = insNode;
    }
    return RESULT_TRUE;
}

/************************************
* Access:    virtual public 
* ��������:  ��ֵΪe�Ľڵ�������ɾ��,Ԫ�ظ�����1
* 
* �����б�:
*   ElemType e:     [in] ɾ����Ԫ��ֵ
*   PNODE pNode:    [out] ����ɾ����λ��
*
* ����ֵ:    Status
* 
*************************************/
Status CMyAVLTree::Delete( ElemType e, PNODE pNode /* = nullptr */ )
{
    //1.ɾ������,����ɾ���ڵ㸱��
    NODE delNode;
    Status result = CMyTree::Delete(e, &delNode);

    if (result !=RESULT_TRUE)
    {
        return RESULT_FALSE;
    }

    //2.��ɾ���㸸�ڵ㿪ʼ,�����ж��Ƿ�ƽ��,ֱ�����ڵ�
    PNODE pFather = delNode.pFather;
    BalanceTree(pFather);

    //3.���÷���ֵ
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
        //1.�����������ʼ��ת
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
                //  1.1 �������� - �������� > 1 ; ��.�������� >= ��.��������
                //      �ҵ���
                //      K2
                //     /
                //    K1
                //   / 
                //  N   
                SingleR(pNode);
            }else {
                //  1.2 �������� - �������� > 1 ; ��.��������  < ��.��������
                //      ������
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
                //  1.3 �������� - �������� > 1 ; ��.�������� >= ��.��������
                //      ����
                //      K2
                //       \
                //        K1
                //         \
                //          N
                SingleL(pNode);
            }else {
                //  1.4 �������� - �������� > 1 ; ��.��������  < ��.��������
                //      ������
                //      K2
                //       \
                //        K1
                //       /
                //      N
                DoubleRL(pNode);
            }
        }

        //2. �������ϵ���
        pNode = pNode->pFather;
    }
   
    return RESULT_TRUE;
}

Status CMyAVLTree::SingleR(PNODE & pNode)
{
     //�������� - �������� > 1 ; ��.�������� >= ��.��������
     //      �ҵ���
     //      K2              K1
     //     /               / \
     //    K1       ->     N   K2
     //   / \                 /
     //  N   T               T
     // ����:
     //   1. ��K1�����������浽K2����������
     //   2. ��K1����������ΪK2
     //

    //1. ��ȷ�� K2,K1
    PNODE K2 = pNode;
    PNODE K1 = K2->pLChild;
    PNODE T = K1->pRChild;

    //2. ��K1�����������浽K2����������
    K2->pLChild = T;

    //3. ��K1����������ΪK2
    K1->pRChild = K2;

    //4. ���ýڵ��еĸ��ڵ�ָ����Ϣ
    K1->pFather = K2->pFather;
    K2->pFather = K1;
    if (T)
    {
        T->pFather = K2;
    }

    //5. ���ⲿ����������(�޸��ⲿָ��,ָ���µľֲ����ڵ�)
    if (K1->pFather == nullptr) 
    {
    //    5.1 ����ƽ��ĵ�(pNode)�Ǹ��ڵ�,ֻ��ı� m_pRoot
        m_pRoot = K1;

    }else if (K1->Data < K1->pFather->Data)
    {
    //    5.2 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
        K1->pFather->pLChild = K1;
    }
    else {
    //    5.3 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
        K1->pFather->pRChild = K1;
    }

    return RESULT_TRUE;
}

Status CMyAVLTree::SingleL(PNODE & pNode)
{
    //  �������� - �������� > 1 ; ��.�������� >= ��.��������
    //      ����
    //      K2                 K1
    //       \                / \
    //        K1      ->     K2  N
    //       / \              \
    //      T   N              T
    //
    //����:
    //    1. ��K1�����������浽K2����������
    //    2. ��K1����������ΪK2

    //1. ��ȷ�� K2,K1,T
    PNODE K2 = pNode;
    PNODE K1 = K2->pRChild;
    PNODE T = K1->pLChild;

    //2. ��K1�����������浽K2����������
    K2->pRChild = T;

    //3. ��K1����������ΪK2
    K1->pLChild = K2;

    //4. ���ýڵ��еĸ��ڵ�ָ����Ϣ
    K1->pFather = K2->pFather;
    K2->pFather = K1;
    if (T)
    {
        T->pFather = K2;
    }

    //5. ���ⲿ����������(�޸��ⲿָ��,ָ���µľֲ����ڵ�)
    //    5.1 ����ƽ��ĵ�(pNode)�Ǹ��ڵ�, ֻ��ı� m_pRoot
    if (K1->pFather==nullptr)
    {
        m_pRoot = K1;
    }else if (K1->Data < K1->pFather->Data)
    {
    //    5.2 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
        K1->pFather->pLChild = K1;
    }
    else {
    //    5.3 ����ƽ��ĵ�(pNode)���丸�ڵ�����ӽڵ�
        K1->pFather->pRChild = K1;
    }

    return RESULT_TRUE;
}

Status CMyAVLTree::DoubleLR(PNODE & pNode)
{
    //  �������� - �������� > 1 ; ��.��������  < ��.��������
    //      ������
    //      K2              K2            N   
    //     /               /             / \
    //    K1      ->      N       ->    K1  K2
    //     \             / 
    //      N           K1
    //
    // ����:
    //   1. ��K2�������������ڵ�,����
    //   2. ��K2 �����ڵ�,�ҵ���

    SingleL(pNode->pLChild);
    SingleR(pNode);

    return RESULT_TRUE;
}

Status CMyAVLTree::DoubleRL(PNODE & pNode)
{
    //  �������� - �������� > 1 ; ��.��������  < ��.��������
    //      ������
    //      K2          K2             N
    //       \           \            / \
    //        K1   ->     N    ->    K2  K1
    //       /             \
    //      N               K1
    //
    // ����:
    //  1. ��K2�������������ڵ�,�ҵ���
    //  2. ��K2�����ڵ�,����
    SingleR(pNode->pRChild);
    SingleL(pNode);

    return RESULT_TRUE;
}
