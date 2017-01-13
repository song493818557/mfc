#pragma once
#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <tchar.h>

// 菜单ID,如果想要响应菜单的点击事件,需要在父窗口的WM_COMMAND中响应,菜单ID将会是以下的枚举值:
typedef enum MENUID
{
	MENUID_OPEN = 0x5000,
	MENUID_DELETE
};
class CMylist
{
	DWORD m_dwColumnCount = 0;// 记录一共有多少栏
public:
	DWORD	m_dwId;  // ListView控件的资源ID
	HWND	m_hParent;//父窗口句柄
	HWND	m_hWnd;	// ListView控件的窗口句柄
	HMENU	m_hMenu; // 右键菜单
	TCHAR m_NowPath[MAX_PATH]; //当前的坐标
	CMylist();
	// 构造函数
	CMylist(DWORD dwId,/*ListView的资源ID,或者自定义的ID*/
		HWND hParent,/*父窗口句柄*/
		DWORD dwX = 0,/*在父窗口中的X坐标*/
		DWORD dwY = 0, /*在父窗口中的X坐标*/
		DWORD dwWidth = 0,/*宽度*/
		DWORD dwHeight = 0, /*高度*/
		DWORD dwStyle = WS_CHILD | WS_VISIBLE /*窗口风格*/
		);

	~CMylist();


public:
	void Create(DWORD dwId,
		HWND hParent,
		DWORD dwX = 0,
		DWORD dwY = 0,
		DWORD dwWidth = 0,
		DWORD dwHeight = 0,
		DWORD dwStyle = WS_CHILD | WS_VISIBLE | LVS_ICON
		);


	// 设置风格
	void SetStyle(DWORD dwStyle, DWORD pdwExStyle = 0);
	// 获取风格
	void GetStyle(PDWORD dwStyle, PDWORD pdwExStyle = NULL);

	// 插入栏
	BOOL InsertColumn(DWORD dwIndex, const TCHAR* pszText, DWORD dwWdit, DWORD dwFormat = LVCFMT_LEFT);

	// 插入列
	BOOL InsertItem(int nLine/*行*/, int nSub/*列*/, const TCHAR* pszText/*文本*/);
	BOOL InsertItem(int nLine, int nSub, const DWORD dwValue/*插入的值*/, int nRadix = 10/*值的进制数*/);
	BOOL InsertItem_64(int nLine, int nSub, const ULONG64& u64Value, int nRadix = 10);
	BOOL InsertItem(int nLine, int nSub, const SYSTEMTIME& dwValue/*插入一个时间*/);


	// 设置列文本
	BOOL SetItemText(int nLine, int nSub, DWORD dwValue, int nRadix = 10);
	BOOL SetItemText(int nLine, int nSub, const TCHAR* pszText);

	// 获取列文本
	DWORD GetItemText(int nLine, int nSub, TCHAR* pszBuff, DWORD dwSize);
	// 从listview控件获取一个整形值
	DWORD GetItemValue(int nLine, int nSub, int nRadix = 10);

	// 删除列
	BOOL DeleteItem(int nLine);
	// 删除栏
	BOOL DeleteColumn(DWORD dwIndex);

	// 删除所有列
	void DeleteAllItem();
	// 删除所有栏
	void DeleteAllColumn();

	// 获取当前被点击的列
	int GetClickItem();

	int GetSelectItem();

	// 获取列个数
	DWORD GetItemCount();
	// 获取column个数
	DWORD GetColumnCount();

	// 弹出菜单
	void  PopupMenu();
};

