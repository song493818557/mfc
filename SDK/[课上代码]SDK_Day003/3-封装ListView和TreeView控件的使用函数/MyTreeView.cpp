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
// 函数名:  Create
// 功  能:  创建TreeView控件
// 返回值:  void
// 形  参:  DWORD dwId 控件的资源ID
// 形  参:  HWND hParent 父窗口的窗口句柄
// 形  参:  DWORD dwX    开始坐标
// 形  参:  DWORD dwY
// 形  参:  DWORD dwWidth 宽度
// 形  参:  DWORD dwHignt 
// 形  参:  DWORD dwStyle 风格
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
	// 如果在父窗口能够得到这个控件的窗口句柄,意味着TreeView已经被创建
	// 这里则不再重新创建
	// (如果在父窗口中能够找到控件的窗口句柄, 父窗口一般是来自资源文件.)
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
// 函数名:  InsertItem
// 功  能:  插入节点
// 返回值:  HTREEITEM 返回成功插入到TreeView控件中节点的句柄
// 形  参:  const TCHAR * pszText  节点的文本
// 形  参:  HTREEITEM hParent 节点的父节点
// 形  参:  HTREEITEM hPos 节点的插入位置
//************************************
HTREEITEM MyTreeView::InsertItem(const TCHAR* pszText , HTREEITEM hParent , HTREEITEM hPos , DWORD_PTR dwItemData)
{
	TVINSERTSTRUCT tvIns = { 0 };
	tvIns.hParent = hParent; /*初始化节点的父节点*/
	tvIns.hInsertAfter = hPos;/*初始化节点的插入位置*/
	tvIns.item.mask = TVIF_TEXT;/*设置节点需要使用的字段*/

	tvIns.item.pszText = (TCHAR*)pszText; /*初始化节点的文本*/

	// 插入节点
	return TreeView_InsertItem(m_hWnd , &tvIns);
}


//************************************
// 函数名:  DeleteItem
// 功  能:  删除节点
// 返回值:  void
// 形  参:  HTREEITEM hItem
//************************************
void MyTreeView::DeleteItem(HTREEITEM hItem)
{
	if(hItem != NULL)
		TreeView_DeleteItem(m_hWnd , hItem);
}

//************************************
// 函数名:  GetClickItem
// 功  能:  获取当前被点击的节点
// 返回值:  HTREEITEM
//************************************
HTREEITEM MyTreeView::GetClickItem()
{
	TV_HITTESTINFO TVHitInfo;
	TVHitInfo.flags = TVHT_ONITEM; /*设置范围*/
	GetCursorPos(&TVHitInfo.pt); // 获取当前光标的坐标
	ScreenToClient(m_hWnd , &TVHitInfo.pt); // 将屏幕坐标转换成TreeView控件的坐标

	// 获取当前光标所在的节点的句柄
	TreeView_HitTest(m_hWnd , &TVHitInfo);

	// 返回句柄
	return TVHitInfo.hItem;
}

//************************************
// 函数名:  GetItemText
// 功  能:  获取节点的文本
// 返回值:  DWORD
// 形  参:  HTREEITEM hItem 要获取文本的节点的句柄,
// 形  参:  const TCHAR * pszText 保存节点文本的缓冲区
// 形  参:  DWORD dwSize 缓冲区的最大字符数
//************************************
DWORD MyTreeView::GetItemText(HTREEITEM hItem , const TCHAR *pszText , DWORD dwSize)
{
	TVITEM tvItem = { 0 };
	tvItem.mask = TVIF_TEXT; // 设置要获取的内容
	tvItem.pszText = (TCHAR*)pszText; // 设置接收节点文本的缓冲区
	tvItem.cchTextMax = dwSize; // 设置缓冲区的长度
	tvItem.hItem = hItem; // 设置要获取的节点的句柄

	// 获取节点信息
	return TreeView_GetItem(m_hWnd , &tvItem);
}


//************************************
// 函数名:  SetItemText
// 功  能:  设置节点文本
// 返回值:  DWORD
// 形  参:  HTREEITEM hItem 要文本的节点的句柄
// 形  参:  const TCHAR * pszText 要设置的文本
//************************************
DWORD MyTreeView::SetItemText(HTREEITEM hItem , const TCHAR* pszText)
{
	TVITEM tvItem = { 0 };
	tvItem.mask = TVIF_TEXT; // 设置节点要被设置的字段
	tvItem.hItem = hItem; // 被设置文本的节点句柄
	tvItem.pszText = (TCHAR*)pszText; // 要设置的文本

	return TreeView_SetItem(m_hWnd ,&tvItem);

}

//************************************
// 函数名:  GetSubItem
// 功  能:  获取一个节点下的指定位置处的子节点
// 返回值:  HTREEITEM 返回子节点的句柄,如果没有该节点则返回NULL
// 形  参:  HTREEITEM hParent 父节点的节点句柄
// 形  参:  int nPos  位置(索引)
//************************************
HTREEITEM MyTreeView::GetSubItem(HTREEITEM hParent , int nPos)
{
	
	if(hParent == NULL)
	{
		return TreeView_GetRoot(m_hWnd); // 直接返回父节点
	}
	
	// 获取子节点
	HTREEITEM hItem = TreeView_GetChild(m_hWnd , hParent);

	// 获取这个节点的兄弟节点
	return GetBrotherItem(hItem , nPos);
}

//************************************
// 函数名:  GetBrotherItem
// 功  能:  获取兄弟节点
// 返回值:  HTREEITEM 返回兄弟节点的节点句柄
// 形  参:  HTREEITEM hBrother 传入的兄弟节点的句柄
// 形  参:  int nPos 兄弟节点的距离(索引)
//************************************
HTREEITEM MyTreeView::GetBrotherItem(HTREEITEM hBrother , int nPos)
{
	if(hBrother == NULL)
		hBrother = TreeView_GetRoot(m_hWnd);


	// 获取下一个兄弟节点,直到nPos==0的时候,且仍能获取到节点句柄(如果没有那么多兄弟节点,则hBrother等于NULL)
	while(nPos > 0 && hBrother)
	{
		hBrother = TreeView_GetNextItem(m_hWnd , hBrother , TVGN_NEXT);
		--nPos;
	}

	return hBrother;
}

//************************************
// 函数名:  FindItem
// 功  能:  根据节点文本来查找节点
// 返回值:  HTREEITEM
// 形  参:  const TCHAR * pszText
//************************************
HTREEITEM MyTreeView::FindItem(const TCHAR* pszText)
{
	return FindItem(TreeView_GetRoot(m_hWnd) , pszText);
}


//************************************
// 函数名:  FindItem
// 功  能:  查找节点(递归函数)
// 返回值:  HTREEITEM
// 形  参:  HTREEITEM hParent
// 形  参:  const TCHAR * pszText
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

		// 递归查找节点
		hFind = FindItem(GetSubItem(hItem , 0) , pszText);
		if(hFind != NULL)
			return hFind;
	}

	return NULL;
}

//************************************
// 函数名:  GetParent
// 功  能:  获取一个节点的父节点
// 返回值:  HTREEITEM
// 形  参:  HTREEITEM hParent
//************************************
HTREEITEM MyTreeView::GetParent(HTREEITEM hItem)
{
	return TreeView_GetParent(m_hWnd , hItem);
}

//************************************
// 函数名:  DeleteAllItem
// 功  能:  删除所有节点
// 返回值:  void
//************************************
void MyTreeView::DeleteAllItem()
{
	TreeView_DeleteAllItems(m_hWnd);
}

//************************************
// 函数名: GetItemData
// 功  能: 获取节点的附加数据
// 返回值: DWORD_PTR
// 参  数: HTREEITEM hItem
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
// 函数名: SetItemData
// 功  能: 将附加数据设置到节点中,
// 返回值: void
// 参  数: HTREEITEM hItem
// 参  数: DWORD_PTR itemData(附加数据可以是一个指针)
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
// 函数名: GetTreePath
// 功  能: 获取树形文件系统的完整文件路径, 
// 返回值: bool
// 参  数: HTREEITEM hItem	节点句柄,作为最末尾的文件夹,
// 参  数: TCHAR * pszPath
// 参  数: DWORD dwLen
//************************************
bool MyTreeView::GetTreePath(HTREEITEM hItem , TCHAR *pszPath , DWORD dwLen)
{
	if(hItem == NULL)
		return false;

	//获取当前节点的文本
	if(!GetItemText(hItem , pszPath , MAX_PATH))
		return false;

	// 判断获取到的节点中是否带有路径分隔符,如果有,则去除掉
	int nDirSplitIndex = _tcslen(pszPath) - 1;
	if(pszPath[ nDirSplitIndex ] == '\\')
		pszPath[ nDirSplitIndex ] = 0; // 填0去除

	
	TCHAR temp[ MAX_PATH ];
	*temp = 0;
	
	HTREEITEM hParent = hItem;
	while(1)
	{
		// 获取父节点的句柄
		hParent = GetParent(hParent);
		// 如果父节点为空,说明当前已经是顶层目录,则跳出循环
		if(hParent == NULL)
			break;

		// 获取父节点的文本
		GetItemText(hParent , temp , MAX_PATH);
		// 将父节点的文本和当前的文本拼接在一起
		_stprintf_s(temp , dwLen , _T("%s\\%s") , temp , pszPath);
		_tcscpy_s(pszPath , dwLen , temp);
	}

	return true;
}

HTREEITEM MyTreeView::GetSelectItem()
{
	return TreeView_GetSelection(m_hWnd);
}




