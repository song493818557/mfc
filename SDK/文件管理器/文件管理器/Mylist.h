#pragma once
#include <Windows.h>
#include <CommCtrl.h>
#include <stdio.h>
#include <tchar.h>

// �˵�ID,�����Ҫ��Ӧ�˵��ĵ���¼�,��Ҫ�ڸ����ڵ�WM_COMMAND����Ӧ,�˵�ID���������µ�ö��ֵ:
typedef enum MENUID
{
	MENUID_OPEN = 0x5000,
	MENUID_DELETE
};
class CMylist
{
	DWORD m_dwColumnCount = 0;// ��¼һ���ж�����
public:
	DWORD	m_dwId;  // ListView�ؼ�����ԴID
	HWND	m_hParent;//�����ھ��
	HWND	m_hWnd;	// ListView�ؼ��Ĵ��ھ��
	HMENU	m_hMenu; // �Ҽ��˵�
	TCHAR m_NowPath[MAX_PATH]; //��ǰ������
	CMylist();
	// ���캯��
	CMylist(DWORD dwId,/*ListView����ԴID,�����Զ����ID*/
		HWND hParent,/*�����ھ��*/
		DWORD dwX = 0,/*�ڸ������е�X����*/
		DWORD dwY = 0, /*�ڸ������е�X����*/
		DWORD dwWidth = 0,/*���*/
		DWORD dwHeight = 0, /*�߶�*/
		DWORD dwStyle = WS_CHILD | WS_VISIBLE /*���ڷ��*/
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


	// ���÷��
	void SetStyle(DWORD dwStyle, DWORD pdwExStyle = 0);
	// ��ȡ���
	void GetStyle(PDWORD dwStyle, PDWORD pdwExStyle = NULL);

	// ������
	BOOL InsertColumn(DWORD dwIndex, const TCHAR* pszText, DWORD dwWdit, DWORD dwFormat = LVCFMT_LEFT);

	// ������
	BOOL InsertItem(int nLine/*��*/, int nSub/*��*/, const TCHAR* pszText/*�ı�*/);
	BOOL InsertItem(int nLine, int nSub, const DWORD dwValue/*�����ֵ*/, int nRadix = 10/*ֵ�Ľ�����*/);
	BOOL InsertItem_64(int nLine, int nSub, const ULONG64& u64Value, int nRadix = 10);
	BOOL InsertItem(int nLine, int nSub, const SYSTEMTIME& dwValue/*����һ��ʱ��*/);


	// �������ı�
	BOOL SetItemText(int nLine, int nSub, DWORD dwValue, int nRadix = 10);
	BOOL SetItemText(int nLine, int nSub, const TCHAR* pszText);

	// ��ȡ���ı�
	DWORD GetItemText(int nLine, int nSub, TCHAR* pszBuff, DWORD dwSize);
	// ��listview�ؼ���ȡһ������ֵ
	DWORD GetItemValue(int nLine, int nSub, int nRadix = 10);

	// ɾ����
	BOOL DeleteItem(int nLine);
	// ɾ����
	BOOL DeleteColumn(DWORD dwIndex);

	// ɾ��������
	void DeleteAllItem();
	// ɾ��������
	void DeleteAllColumn();

	// ��ȡ��ǰ���������
	int GetClickItem();

	int GetSelectItem();

	// ��ȡ�и���
	DWORD GetItemCount();
	// ��ȡcolumn����
	DWORD GetColumnCount();

	// �����˵�
	void  PopupMenu();
};

