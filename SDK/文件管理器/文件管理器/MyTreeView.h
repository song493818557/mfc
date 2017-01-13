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
	// ���캯��
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

	// ����ڵ�
	HTREEITEM InsertItem(const TCHAR* pszText, HTREEITEM hParent = NULL, HTREEITEM hPos = TVI_LAST, DWORD_PTR dwItemData = 0);

	// ��ȡ������Ľڵ�
	HTREEITEM GetClickItem();

	// ��ȡ��ѡ�еĽڵ���
	HTREEITEM GetSelectItem();

	DWORD_PTR GetItemData(HTREEITEM item);
	void	  SetItemData(HTREEITEM item, DWORD_PTR itemData);
	// ��ȡ�ӽڵ�
	HTREEITEM GetSubItem(HTREEITEM hParent, int nPos);

	// ��ȡ���ڵ�
	HTREEITEM GetParent(HTREEITEM hItem);

	// ��ȡ�ֵܽڵ�
	HTREEITEM GetBrotherItem(HTREEITEM hBrother, int nPos);

	// �����ı����ҽڵ�
	HTREEITEM FindItem(const TCHAR* pszText);

	// ��ȡ�ڵ��ı�
	DWORD GetItemText(HTREEITEM hItem, const TCHAR *pszText, DWORD dwSize);
	// ���ýڵ��ı�
	DWORD SetItemText(HTREEITEM hItem, const TCHAR* pszText);

	// ɾ���ڵ�
	void DeleteItem(HTREEITEM hItem);
	// ɾ�����нڵ�
	void DeleteAllItem();


	bool GetTreePath(HTREEITEM hItem, TCHAR *pszPath, DWORD dwLen);
};

