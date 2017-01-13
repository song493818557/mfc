#pragma once
#include <Windows.h>
#include <CommCtrl.h>

class MyTreeView
{

public:
	DWORD m_dwId;
	HWND m_hParent;
	HWND m_hWnd;


	MyTreeView();
	// 构造函数
	MyTreeView(DWORD dwId,
		HWND hParent,
		DWORD dwX = 0,
		DWORD dwY = 0,
		DWORD dwWidth = 0,
		DWORD dwHignt = 0,
		DWORD dwStyle = TVS_LINESATROOT | TVS_HASLINES | TVS_HASBUTTONS | WS_CHILD | WS_VISIBLE
		);

	~MyTreeView();



	HTREEITEM FindItem(HTREEITEM hParent, const TCHAR* pszText);
public:
	void Create(DWORD dwId,
		HWND hParent,
		DWORD dwX = 0,
		DWORD dwY = 0,
		DWORD dwWidth = 0,
		DWORD dwHignt = 0,
		DWORD dwStyle = TVS_LINESATROOT | TVS_HASLINES | TVS_HASBUTTONS | WS_CHILD | WS_VISIBLE
		);

	// 插入节点
	HTREEITEM InsertItem(const TCHAR* pszText, HTREEITEM hParent = NULL, HTREEITEM hPos = TVI_LAST, DWORD_PTR dwItemData = 0);

	// 获取被点击的节点
	HTREEITEM GetClickItem();

	// 获取被选中的节点句柄
	HTREEITEM GetSelectItem();

	DWORD_PTR GetItemData(HTREEITEM item);
	void	  SetItemData(HTREEITEM item, DWORD_PTR itemData);
	// 获取子节点
	HTREEITEM GetSubItem(HTREEITEM hParent, int nPos);

	// 获取父节点
	HTREEITEM GetParent(HTREEITEM hItem);

	// 获取兄弟节点
	HTREEITEM GetBrotherItem(HTREEITEM hBrother, int nPos);

	// 根据文本查找节点
	HTREEITEM FindItem(const TCHAR* pszText);

	// 获取节点文本
	DWORD GetItemText(HTREEITEM hItem, const TCHAR *pszText, DWORD dwSize);
	// 设置节点文本
	DWORD SetItemText(HTREEITEM hItem, const TCHAR* pszText);

	// 删除节点
	void DeleteItem(HTREEITEM hItem);
	// 删除所有节点
	void DeleteAllItem();


	bool GetTreePath(HTREEITEM hItem, TCHAR *pszPath, DWORD dwLen);
};

