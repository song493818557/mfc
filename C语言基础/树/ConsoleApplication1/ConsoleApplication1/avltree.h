#pragma once


class Cavltree
{
public:
	//

	typedef struct  _NODE
	{
		int Data;  //数据存放区
		_NODE *Pright; //右指针
		_NODE *Pleft;//左指针
	}NODE, *PNODE;
	Cavltree();
	~Cavltree();
	void  PreOrderTraverse(PNODE& pNode);
	void Traverse(){ return PreOrderTraverse(m_root); }
	bool deletree(int nData){ return deletree(m_root,nData); }
	int getmax(PNODE Pnode);//获取最大值
	int getmin(PNODE Pnode);//获取最小值
	bool inserttree(int nData){

		return   inserttree(m_root,nData);
	}
private:
	bool deletree(PNODE& Pnode, int nData);
	NODE* m_root;
	bool inserttree(PNODE& pNode, int nData);
	int get_treeheight(PNODE& pNode){
		if (pNode == NULL)
	   {
		   return true;
	   }
		int nleft_height = get_treeheight(pNode->Pleft);
		int nright_height = get_treeheight(pNode->Pright);
		return	(nleft_height > nright_height ? nleft_height : nright_height) + 1;
	};
	void singR(PNODE& pNode){
		//        K2			K1
		//       /  		   /  \
        //      K1			  N   K2
		//     /    
		//    N
		PNODE K2 = pNode;
		PNODE K1 = pNode->Pleft;
		K2->Pleft = K1->Pright;
		K1->Pright = K2;
		pNode = K1;
	}
	void singL(PNODE& pNode){
		//   K2			        K1
		//     \      		   /  \
        //      K1			  K2   N
		//        \  
		//         N
		PNODE K2 = pNode;
		PNODE K1 = pNode->Pright;
		K2->Pright = K1->Pleft;
		K1->Pleft = K2;
		pNode = K1;
	}
	void singLR(PNODE& pNode){
		//   K2			        K1
		//     \      		   /  \
        //      K1			  K2   N
		//        \  
		//         N
		 
		singL(pNode->Pleft);
		singR(pNode);
	}
	void singRL(PNODE& pNode){
		//   K2			        K1
		//     \      		   /  \
        //      K1			  K2   N
		//        \  
		//         N
		singR(pNode->Pright);
		singL(pNode);
	}
};

