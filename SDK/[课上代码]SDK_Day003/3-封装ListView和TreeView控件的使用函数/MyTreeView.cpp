#include "MyTreeView.h"
#include <tchar.h>


MyTreeView::MyTreeView()
	:m_hWnd(),
	m_hParent(),
	m_dwId()
{
}

MyTreeView::MyTreeView(DWORD dwId , 
					   HWND hParent , 
					   DWORD dwX /*= 0 */ , 
					   DWORD dwY /*= 0 */ , 
					   DWORD dwWidth /*= 0 */ , 
					   DWORD dwHignt /*= 0 */ , 
					   DWORD dwStyle /*= TVS_LINESATROOT| TVS_HASLINES |TVS_HASBUTTONS | WS_CHILD | WS_VISIBLE */
					   )
					   :m_hParent(),
					   m_hWnd(),
					   m_dwId()
{
	Create(dwId , hParent , dwX , dwY , dwWidth , dwHignt , dwStyle);
}


MyTreeView::~MyTreeView()
{
}

//************************************
// ������:  Create
// ��  ��:  ����TreeView�ؼ�
// ����ֵ:  void
// ��  ��:  DWORD dwId �ؼ�����ԴID
// ��  ��:  HWND hParent �����ڵĴ��ھ��
// ��  ��:  DWORD dwX    ��ʼ����
// ��  ��:  DWORD dwY
// ��  ��:  DWORD dwWidth ���
// ��  ��:  DWORD dwHignt 
// ��  ��:  DWORD dwStyle ���
//************************************
void MyTreeView::Create(DWORD dwId , 
						HWND hParent , 
						DWORD dwX /*= 0 */ , 
						DWORD dwY /*= 0 */ , 
						DWORD dwWidth /*= 0 */ , 
						DWORD dwHignt /*= 0 */ , 
						DWORD dwStyle /*= LVS_REPORT | WS_CHILD | WS_VISIBLE */)
{
	m_dwId = dwId;
	m_hParent = hParent;
	// ����ڸ������ܹ��õ�����ؼ��Ĵ��ھ��,��ζ��TreeView�Ѿ�������
	// �����������´���
	// (����ڸ��������ܹ��ҵ��ؼ��Ĵ��ھ��, ������һ����������Դ�ļ�.)
	m_hWnd = GetDlgItem(hParent , dwId);

	if(m_hWnd == 0)
	{
		m_hWnd = CreateWindow(WC_TREEVIEW ,
							  L"" ,
							  dwStyle ,
							  dwX , dwY ,
							  dwWidth , dwHignt ,
							  hParent ,
							  (HMENU)m_dwId ,
							  NULL ,
							  0);
	}
}


//************************************
// ������:  InsertItem
// ��  ��:  ����ڵ�
// ����ֵ:  HTREEITEM ���سɹ����뵽TreeView�ؼ��нڵ�ľ��
// ��  ��:  const TCHAR * pszText  �ڵ���ı�
// ��  ��:  HTREEITEM hParent �ڵ�ĸ��ڵ�
// ��  ��:  HTREEITEM hPos �ڵ�Ĳ���λ��
//************************************
HTREEITEM MyTreeView::InsertItem(const TCHAR* pszText , HTREEITEM hParent , HTREEITEM hPos , DWORD_PTR dwItemData)
{
	TVINSERTSTRUCT tvIns = { 0 };
	tvIns.hParent = hParent; /*��ʼ���ڵ�ĸ��ڵ�*/
	tvIns.hInsertAfter = hPos;/*��ʼ���ڵ�Ĳ���λ��*/
	tvIns.item.mask = TVIF_TEXT;/*���ýڵ���Ҫʹ�õ��ֶ�*/

	tvIns.item.pszText = (TCHAR*)pszText; /*��ʼ���ڵ���ı�*/

	// ����ڵ�
	return TreeView_InsertItem(m_hWnd , &tvIns);
}


//************************************
// ������:  DeleteItem
// ��  ��:  ɾ���ڵ�
// ����ֵ:  void
// ��  ��:  HTREEITEM hItem
//************************************
void MyTreeView::DeleteItem(HTREEITEM hItem)
{
	if(hItem != NULL)
		TreeView_DeleteItem(m_hWnd , hItem);
}

//************************************
// ������:  GetClickItem
// ��  ��:  ��ȡ��ǰ������Ľڵ�
// ����ֵ:  HTREEITEM
//************************************
HTREEITEM MyTreeView::GetClickItem()
{
	TV_HITTESTINFO TVHitInfo;
	TVHitInfo.flags = TVHT_ONITEM; /*���÷�Χ*/
	GetCursorPos(&TVHitInfo.pt); // ��ȡ��ǰ��������
	ScreenToClient(m_hWnd , &TVHitInfo.pt); // ����Ļ����ת����TreeView�ؼ�������

	// ��ȡ��ǰ������ڵĽڵ�ľ��
	TreeView_HitTest(m_hWnd , &TVHitInfo);

	// ���ؾ��
	return TVHitInfo.hItem;
}

//************************************
// ������:  GetItemText
// ��  ��:  ��ȡ�ڵ���ı�
// ����ֵ:  DWORD
// ��  ��:  HTREEITEM hItem Ҫ��ȡ�ı��Ľڵ�ľ��,
// ��  ��:  const TCHAR * pszText ����ڵ��ı��Ļ�����
// ��  ��:  DWORD dwSize ������������ַ���
//************************************
DWORD MyTreeView::GetItemText(HTREEITEM hItem , const TCHAR *pszText , DWORD dwSize)
{
	TVITEM tvItem = { 0 };
	tvItem.mask = TVIF_TEXT; // ����Ҫ��ȡ������
	tvItem.pszText = (TCHAR*)pszText; // ���ý��սڵ��ı��Ļ�����
	tvItem.cchTextMax = dwSize; // ���û������ĳ���
	tvItem.hItem = hItem; // ����Ҫ��ȡ�Ľڵ�ľ��

	// ��ȡ�ڵ���Ϣ
	return TreeView_GetItem(m_hWnd , &tvItem);
}


//************************************
// ������:  SetItemText
// ��  ��:  ���ýڵ��ı�
// ����ֵ:  DWORD
// ��  ��:  HTREEITEM hItem Ҫ�ı��Ľڵ�ľ��
// ��  ��:  const TCHAR * pszText Ҫ���õ��ı�
//************************************
DWORD MyTreeView::SetItemText(HTREEITEM hItem , const TCHAR* pszText)
{
	TVITEM tvItem = { 0 };
	tvItem.mask = TVIF_TEXT; // ���ýڵ�Ҫ�����õ��ֶ�
	tvItem.hItem = hItem; // �������ı��Ľڵ���
	tvItem.pszText = (TCHAR*)pszText; // Ҫ���õ��ı�

	return TreeView_SetItem(m_hWnd ,&tvItem);

}

//************************************
// ������:  GetSubItem
// ��  ��:  ��ȡһ���ڵ��µ�ָ��λ�ô����ӽڵ�
// ����ֵ:  HTREEITEM �����ӽڵ�ľ��,���û�иýڵ��򷵻�NULL
// ��  ��:  HTREEITEM hParent ���ڵ�Ľڵ���
// ��  ��:  int nPos  λ��(����)
//************************************
HTREEITEM MyTreeView::GetSubItem(HTREEITEM hParent , int nPos)
{
	
	if(hParent == NULL)
	{
		return TreeView_GetRoot(m_hWnd); // ֱ�ӷ��ظ��ڵ�
	}
	
	// ��ȡ�ӽڵ�
	HTREEITEM hItem = TreeView_GetChild(m_hWnd , hParent);

	// ��ȡ����ڵ���ֵܽڵ�
	return GetBrotherItem(hItem , nPos);
}

//************************************
// ������:  GetBrotherItem
// ��  ��:  ��ȡ�ֵܽڵ�
// ����ֵ:  HTREEITEM �����ֵܽڵ�Ľڵ���
// ��  ��:  HTREEITEM hBrother ������ֵܽڵ�ľ��
// ��  ��:  int nPos �ֵܽڵ�ľ���(����)
//************************************
HTREEITEM MyTreeView::GetBrotherItem(HTREEITEM hBrother , int nPos)
{
	if(hBrother == NULL)
		hBrother = TreeView_GetRoot(m_hWnd);


	// ��ȡ��һ���ֵܽڵ�,ֱ��nPos==0��ʱ��,�����ܻ�ȡ���ڵ���(���û����ô���ֵܽڵ�,��hBrother����NULL)
	while(nPos > 0 && hBrother)
	{
		hBrother = TreeView_GetNextItem(m_hWnd , hBrother , TVGN_NEXT);
		--nPos;
	}

	return hBrother;
}

//************************************
// ������:  FindItem
// ��  ��:  ���ݽڵ��ı������ҽڵ�
// ����ֵ:  HTREEITEM
// ��  ��:  const TCHAR * pszText
//************************************
HTREEITEM MyTreeView::FindItem(const TCHAR* pszText)
{
	return FindItem(TreeView_GetRoot(m_hWnd) , pszText);
}


//************************************
// ������:  FindItem
// ��  ��:  ���ҽڵ�(�ݹ麯��)
// ����ֵ:  HTREEITEM
// ��  ��:  HTREEITEM hParent
// ��  ��:  const TCHAR * pszText
//************************************
HTREEITEM MyTreeView::FindItem(HTREEITEM hParent , const TCHAR* pszText)
{
	if(hParent == NULL)
		return NULL;

	static TCHAR buff[ 50 ];
	static HTREEITEM hItem = 0;
	static HTREEITEM hFind = 0;

	for(int i = 0 ;NULL != (hItem = GetBrotherItem(hParent , i)); ++i)
	{
		GetItemText(hParent , buff , 50);
		if(wcscmp(buff , pszText) == 0)
			return hParent;

		// �ݹ���ҽڵ�
		hFind = FindItem(GetSubItem(hItem , 0) , pszText);
		if(hFind != NULL)
			return hFind;
	}

	return NULL;
}

//************************************
// ������:  GetParent
// ��  ��:  ��ȡһ���ڵ�ĸ��ڵ�
// ����ֵ:  HTREEITEM
// ��  ��:  HTREEITEM hParent
//************************************
HTREEITEM MyTreeView::GetParent(HTREEITEM hItem)
{
	return TreeView_GetParent(m_hWnd , hItem);
}

//************************************
// ������:  DeleteAllItem
// ��  ��:  ɾ�����нڵ�
// ����ֵ:  void
//************************************
void MyTreeView::DeleteAllItem()
{
	TreeView_DeleteAllItems(m_hWnd);
}

//************************************
// ������: GetItemData
// ��  ��: ��ȡ�ڵ�ĸ�������
// ����ֵ: DWORD_PTR
// ��  ��: HTREEITEM hItem
//************************************
DWORD_PTR MyTreeView::GetItemData(HTREEITEM hItem)
{
	TV_ITEM stcItem = { 0 };
	stcItem.mask = TVIF_PARAM;
	stcItem.hItem = hItem;
	TreeView_GetItem(m_hWnd , &stcItem);
	return stcItem.lParam;
}

//************************************
// ������: SetItemData
// ��  ��: �������������õ��ڵ���,
// ����ֵ: void
// ��  ��: HTREEITEM hItem
// ��  ��: DWORD_PTR itemData(�������ݿ�����һ��ָ��)
//************************************
void MyTreeView::SetItemData(HTREEITEM hItem , DWORD_PTR itemData)
{
	TV_ITEM stcItem = { 0 };
	stcItem.mask = TVIF_PARAM;
	stcItem.hItem = hItem;
	stcItem.lParam = itemData;
	TreeView_SetItem(m_hWnd , &stcItem);
}

//************************************
// ������: GetTreePath
// ��  ��: ��ȡ�����ļ�ϵͳ�������ļ�·��, 
// ����ֵ: bool
// ��  ��: HTREEITEM hItem	�ڵ���,��Ϊ��ĩβ���ļ���,
// ��  ��: TCHAR * pszPath
// ��  ��: DWORD dwLen
//************************************
bool MyTreeView::GetTreePath(HTREEITEM hItem , TCHAR *pszPath , DWORD dwLen)
{
	if(hItem == NULL)
		return false;

	//��ȡ��ǰ�ڵ���ı�
	if(!GetItemText(hItem , pszPath , MAX_PATH))
		return false;

	// �жϻ�ȡ���Ľڵ����Ƿ����·���ָ���,�����,��ȥ����
	int nDirSplitIndex = _tcslen(pszPath) - 1;
	if(pszPath[ nDirSplitIndex ] == '\\')
		pszPath[ nDirSplitIndex ] = 0; // ��0ȥ��

	
	TCHAR temp[ MAX_PATH ];
	*temp = 0;
	
	HTREEITEM hParent = hItem;
	while(1)
	{
		// ��ȡ���ڵ�ľ��
		hParent = GetParent(hParent);
		// ������ڵ�Ϊ��,˵����ǰ�Ѿ��Ƕ���Ŀ¼,������ѭ��
		if(hParent == NULL)
			break;

		// ��ȡ���ڵ���ı�
		GetItemText(hParent , temp , MAX_PATH);
		// �����ڵ���ı��͵�ǰ���ı�ƴ����һ��
		_stprintf_s(temp , dwLen , _T("%s\\%s") , temp , pszPath);
		_tcscpy_s(pszPath , dwLen , temp);
	}

	return true;
}

HTREEITEM MyTreeView::GetSelectItem()
{
	return TreeView_GetSelection(m_hWnd);
}




