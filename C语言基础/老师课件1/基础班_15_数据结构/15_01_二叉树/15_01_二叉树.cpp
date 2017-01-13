// 15_01_������.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include "MyTree.h"
#include "MyAVLTree.h"

Status printData(ElemType & e) {

	printf("%5d ", e);
	return RESULT_TRUE;
}

int main()
{
#pragma region CMyTree

	CMyTree tree;
	tree.Insert(50);
	tree.Insert(70);
	tree.Insert(30);
	tree.Insert(90);
	tree.Insert(10);
	tree.Insert(60);
	tree.Insert(40);
	tree.Insert(20);
	tree.Insert(5);
	tree.Insert(55);

	tree.show();
	printf("\nǰ��:\n");
	tree.PreOrderTraverse(tree.m_pRoot, printData);
	printf("\n����:\n");
	tree.InOrderTraverse(tree.m_pRoot, printData);
	printf("\n����:\n");
	tree.PostOrderTraverse(tree.m_pRoot, printData);
	printf("\n����:\n");
	tree.LevelOrderTraverse(tree.m_pRoot, printData);

	int depth = 0;
	tree.BiTreeDepth(tree.m_pRoot, depth);

	tree.Insert(55);//������ͬ��ֵ
	tree.show();

	tree.Delete(44);//ɾ��û�е�ֵ
	tree.show();
	tree.Delete(40);//ɾ�����ڵ�ֵ
	tree.show();
	tree.Delete(60);//ɾ�����ڵ�ֵ
	tree.show();

	//���ʹ�ÿ��ܱ��б��
	tree.Delete(30);
	tree.Delete(10);
	tree.Delete(5);
	tree.Delete(20);
	tree.show();

	tree.ClearBiTree();
	tree.show();

#pragma endregion

#pragma region CMyAVLTree
	CMyAVLTree avlTree;
	CMyTree myTree;

	for (int i = 1; i < 10; i++) //100
	{
		avlTree.Insert(i);
		myTree.Insert(i);
	}
	myTree.show();
	avlTree.show(); printf("\n===========\n");
	//avlTree.LevelOrderTraverse(avlTree.m_pRoot, printData);

	avlTree.Delete(7);//��̬�޸Ĵ���,���Լ�������
	avlTree.show(); printf("\n===========\n");

	avlTree.Delete(5);
	avlTree.show(); printf("\n===========\n");

	avlTree.Delete(2);
	avlTree.show(); printf("\n===========\n");
	avlTree.Delete(1);
	avlTree.Delete(3);
	avlTree.show(); printf("\n===========\n");
#pragma endregion

	return 0;
}

