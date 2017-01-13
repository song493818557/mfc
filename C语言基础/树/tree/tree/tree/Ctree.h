#pragma once
class Ctree
{ 
public:
	Ctree();

public:
	typedef struct _NODE{
		int nData;
		_NODE *pLeft;
		_NODE *pRight;
	}NODE, *PNODE;
public:
	bool Insert(
		int nEle,//参数0 要插入的数据
		int & nError //参数1 错误码
		);
	bool Delete(
		int nEle,//参数0 要插入的数据
		int & nError //参数1 错误码
		);
	//前序遍历
	void PreOrder(){
		PreOrderTraverse(m_pRoot);
	}
		void InOrder();//中序遍历
		void PostOrder();//后序遍历
private:
	bool InsertNode(
		int nEle,//参数0:要添加的数据
		PNODE &pNode,//参数1:是要插入的子树
		int &nError//参数2:用于得到一个错误码
		);
	bool DeleteNode(
		int nEle,//参数0:要添加的数据
		PNODE &pTree,//参数1:要删除节点的子树
		int &nError//参数2:用于得到一个错误码
		);
	int GetHeight(// 获取树高
		PNODE pTree //要获取树高的子树
		);
	bool GetMax(
		PNODE pTree,//要获取最大值的子树
		int & nMax//用于得到最大的值
		);
	bool GetMin(
		PNODE pTree,//要获取最大值的子树
		int & nMin//用于得到最大的值
		);
	bool SingleL(  /*此节点为圆心左旋 */
		PNODE& pNode//要旋转的节点
		);
	bool SingleR(  /*此节点为圆心右旋 */
		PNODE& pNode//要旋转的节点
		);
	bool SingleLR(  /*此节点为圆心左右旋 */
		PNODE& pNode//要旋转的节点
		);
	bool SingleRL(  /*此节点为圆心右左旋 */
		PNODE& pNode//要旋转的节点
		);
	void PreOrderTraverse(PNODE& pNode);
	void InOrderTraverse(PNODE& pNode);
	void PostOrderTraverse(PNODE& pNode);
private:
	PNODE m_pRoot;
};

