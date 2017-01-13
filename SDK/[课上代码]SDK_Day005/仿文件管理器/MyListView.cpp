#include "MyListView.h"
#include <stdio.h>
#include <tchar.h>


MyListView::MyListView()
	:m_dwId(0),
	m_hParent(NULL),
	m_hWnd(NULL),
	m_dwColumnCount(0)
{

}



//************************************
// ������:  MyListView
// ��  ��:  ���캯��,����ID,����,��С,������,��񴴽���һ��listvie�ؼ�
// ����ֵ:  
// ��  ��:  DWORD dwId
// ��  ��:  DWORD dwX
// ��  ��:  DWORD dwY
// ��  ��:  DWORD dwWidth
// ��  ��:  DWORD dwHignt
// ��  ��:  HWND hParent
// ��  ��:  DWORD dwStyle
//************************************

MyListView::MyListView(DWORD dwId , 
					   HWND hParent , 
					   DWORD dwX/*=0*/ , 
					   DWORD dwY/*=0 */ , 
					   DWORD dwWidth/*=0*/ , 
					   DWORD dwHignt/*=0*/ , 
					   DWORD dwStyle/*=LVS_REPORT|WS_CHILD|WS_VISIBLE */)
{
	Create(dwId , hParent , dwX , dwY , dwWidth , dwHignt , dwStyle);
}



//************************************
// ������:  Create
// ��  ��:  ����ID,����,��С,������,��񴴽���һ��listvie�ؼ�
// ����ֵ:  
// ��  ��:  DWORD dwId
// ��  ��:  DWORD dwX
// ��  ��:  DWORD dwY
// ��  ��:  DWORD dwWidth
// ��  ��:  DWORD dwHignt
// ��  ��:  HWND hParent
// ��  ��:  DWORD dwStyle
//************************************
void MyListView::Create(DWORD dwId ,
						HWND hParent ,
						DWORD dwX ,
						DWORD dwY ,
						DWORD dwWidth ,
						DWORD dwHignt ,
						DWORD dwStyle )
{
	m_dwColumnCount = 0;
	m_dwId = dwId;
	m_hParent = hParent;
	//��ȡ�Ի����ж�ӦID�Ŀؼ�
	m_hWnd = GetDlgItem(hParent , dwId);

	// ���û�л�ȡ��,˵����ǰ�Ի�����û������ؼ�ID,��ʹ������ؼ�ID����һ��ListView�ؼ�,����ʹ��Ĭ�ϵĿؼ����
	if(m_hWnd == 0)
	{
		m_hWnd = CreateWindow(WC_LISTVIEW ,
							  L"" ,
							  dwStyle ,
							  dwX , dwY ,
							  dwWidth , dwHignt ,
							  hParent ,
							  (HMENU)m_dwId ,
							  NULL ,
							  0
							  );
	}
}






MyListView::~MyListView()
{
	if(m_hMenu)
		DestroyMenu(m_hMenu);
	m_hMenu = NULL;
}


//************************************
// ������:  InsertColumn
// ��  ��:  ����һ��
// ����ֵ:  BOOL
// ��  ��:  DWORD dwIndex ������Ŀ��
// ��  ��:  const TCHAR * pszText ���ı����ı�
// ��  ��:  DWORD dwWdit ���Ŀ��
// ��  ��:  DWORD dwFormat ���ĸ���(�ַ����뷽ʽ)
//************************************
BOOL MyListView::InsertColumn(DWORD dwIndex ,
							  const TCHAR* pszText , 
							  DWORD dwWdit , 
							  DWORD dwFormat)
{
	++m_dwColumnCount;

	LV_COLUMN stcColumn = { 0 };
	stcColumn.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT; // ����Ҫʹ�õĽṹ���ֶ�
	
	// ������ʾ�ı�
	stcColumn.pszText = (TCHAR*)pszText;// ��ʾ���ַ���
	// �������Ŀ��
	stcColumn.cx = dwWdit; // ���
	// ���������ı����뷽ʽ
	stcColumn.fmt = dwFormat;//��ʽ

	// ���뵽�ؼ�
	return ListView_InsertColumn(m_hWnd ,dwIndex ,&stcColumn);
}

//************************************
// ������:  GetStyle
// ��  ��:  ��ȡlist�ؼ��ķ��
// ����ֵ:  void
// ��  ��:  PDWORD pdwStyle ��ͨ���
// ��  ��:  PDWORD pdwExStyle ��չ���
//************************************
void MyListView::GetStyle(PDWORD pdwStyle , PDWORD pdwExStyle/*=NULL*/)
{
	// ��ȡ���
	if(pdwStyle != NULL)
	{
		// ��ȡ��ͨ���
		*pdwStyle = GetWindowLong(m_hWnd , GWL_STYLE);
	}
	if(pdwExStyle != NULL) // ��ȡ��չ���
		*pdwExStyle = GetWindowLong(m_hWnd , GWL_EXSTYLE);
}


//************************************
// ������:  SetStyle
// ��  ��:  ����list�ؼ��ķ��
// ����ֵ:  void
// ��  ��:  DWORD dwStyle ��ͨ���
// ��  ��:  DWORD dwExStyle ��չ���
//************************************
void MyListView::SetStyle(DWORD dwStyle , DWORD dwExStyle/*=0*/)
{	
	// ������ͨ���
	if(dwStyle != 0)
	{
		dwStyle = GetWindowLong(m_hWnd , GWL_STYLE) | dwStyle;
		SetWindowLong(m_hWnd ,GWL_STYLE ,dwStyle);
		
	}
	// ������չ���
	if(dwExStyle != 0)
	{
		dwExStyle |= SendMessage(m_hWnd , LVM_GETEXTENDEDLISTVIEWSTYLE , 0 , 0);
		// ������չ���
		SendMessage(m_hWnd , LVM_SETEXTENDEDLISTVIEWSTYLE , 0 , dwExStyle);
	}
}


//************************************
// ������:  InsertItem
// ��  ��:  ������Ŀ
// ����ֵ:  BOOL
// ��  ��:  int nLine ������к�
// ��  ��:  int nSub  ���������
// ��  ��:  const TCHAR * pszText ������ı�
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const TCHAR* pszText)
{
	// ���������������,��ֱ�ӷ���ʧ��
	if(nSub > m_dwColumnCount)
		return FALSE;

	// ��ȡ�ڵ����
	int dwItemCount = GetItemCount();

	LV_ITEM stcItem = { 0 };
	stcItem.mask = LVIF_TEXT;
	
	// ���Ҫ����Ľڵ���кų����ڵ�,������µĽڵ�,���Ѳ���λ����Ϊ�²���ڵ��λ��
	if(nLine >= dwItemCount)
	{
		nLine = dwItemCount;
		//���ò���λ��
		stcItem.iItem = nLine;
		// �����µĽڵ�
		ListView_InsertItem(m_hWnd , &stcItem);
	}
	
	// ���ýڵ��ı�
	ListView_SetItemText(m_hWnd ,
						 nLine ,
						 nSub ,
						 (TCHAR*)pszText
						 );
	return TRUE;
}

//************************************
// ������: InsertItem
// ��  ��: ��һ����ֵ���뵽ListView�ؼ�
// ����ֵ: BOOL
// ��  ��: int nLine �к�
// ��  ��: int nSub  �к�
// ��  ��: const DWORD dwValue Ҫ�������ֵ
// ��  ��: int nRadix		   ��ֵ�Ľ�����
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const DWORD dwValue , int nRadix)
{
	TCHAR buff[ 10 ];
	// �Ƚ���ֵת�����ַ���
	switch(nRadix)
	{
		case 10:
			swprintf_s(buff , 10 , L"%d" , dwValue);
			break;
		case 16:
			swprintf_s(buff , 10 , L"%x" , dwValue);
			break;
	}
	// ���ַ�������
	return InsertItem(nLine , nSub , buff);
}

//************************************
// ������: InsertItem
// ��  ��: ��һ��ʱ����뵽ListView
// ����ֵ: BOOL
// ��  ��: int nLine	  �к�
// ��  ��: int nSub	  �к�
// ��  ��: const SYSTEMTIME & dwValue Ҫ�����ʱ��
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const SYSTEMTIME& dwValue)
{
	TCHAR buff[ 40 ];
	// �Ƚ�ʱ��ת�����ַ���
	_stprintf_s(buff , 40 , _T("%04d/%02d/%02d-%02d:%02d:%02d") ,
				dwValue.wYear ,
				dwValue.wMonth ,
				dwValue.wDay ,
				dwValue.wHour ,
				dwValue.wMinute ,
				dwValue.wSecond);
	// ���ַ�������
	return InsertItem(nLine , nSub , buff);
}

//************************************
// ������: InsertItem_64
// ��  ��: ����һ��64λ����ֵ
// ����ֵ: BOOL
// ��  ��: int nLine �к�
// ��  ��: int nSub  �к�
// ��  ��: const ULONG64 u64Value 64λ����ֵ
// ��  ��: int nRadix			  ��ֵ�Ľ�����
//************************************
BOOL MyListView::InsertItem_64(int nLine , int nSub , const ULONG64& u64Value , int nRadix /*= 10*/)
{
	TCHAR buff[ 20 ];
	// �Ƚ���ֵת�����ַ���
	switch(nRadix)
	{
		case 10:
			swprintf_s(buff , 20 , L"%I64d" , u64Value);
			break;
		case 16:
			swprintf_s(buff , 20 , L"%I64x" , u64Value);
			break;
	}
	// �����ַ���
	return InsertItem(nLine , nSub , buff);
}

//************************************
// ������:  GetClickItem
// ��  ��:  ��ȡ��ǰ������Ľڵ���к�
// ����ֵ:  int	����ɹ�,���ؽڵ���к�, ���򷵻�-1
// ��  ��:  PDWORD pSubItem
//************************************
int MyListView::GetClickItem()
{
	LV_HITTESTINFO hitInfo = { 0 };

	// ��ȡ��ǰ�������
	GetCursorPos(&hitInfo.pt);
	hitInfo.flags = LVHT_ABOVE;

	// ����Ļ����ת���ɿͻ�������
	ScreenToClient(m_hWnd , &hitInfo.pt);

	// ��ȡ��ǰ������ڵĽڵ�
	ListView_HitTest(m_hWnd , &hitInfo.pt);
	
	// ���ػ�ȡ���Ľڵ��к�, ���û���򷵻�-1
	return hitInfo.iItem;
}

//************************************
// ������:  SetItemText
// ��  ��:  ����ָ����ָ�����Ľڵ���ı�
// ����ֵ:  BOOL
// ��  ��:  int nLine �к�
// ��  ��:  int nSub  ����
// ��  ��:  const TCHAR * pszText �ı�
//************************************
BOOL MyListView::SetItemText(int nLine , int nSub , const TCHAR* pszText)
{
	ListView_SetItemText(m_hWnd ,
						 nLine ,
						 nSub ,
						 (TCHAR*)pszText
						 );
	return TRUE;
}

BOOL MyListView::SetItemText(int nLine , int nSub , DWORD dwValue , int nRadix/*= 10*/)
{
	return InsertItem(nLine , nSub , dwValue , nRadix);
}


//************************************
// ������:  GetItemText
// ��  ��:  ��ȡָ����ָ�������ı�
// ����ֵ:  DWORD
// ��  ��:  int nLine �к�
// ��  ��:  int nSub ����
// ��  ��:  TCHAR * pszBuff ������
// ��  ��:  DWORD dwSize ����������ַ�����
//************************************
DWORD MyListView::GetItemText(int nLine , int nSub , TCHAR* pszBuff , DWORD dwSize)
{
	ListView_GetItemText(m_hWnd ,
						 nLine , /*���������*/
						 nSub , /*���������*/
						 pszBuff ,
						 dwSize);

	return TRUE;

// 	LV_ITEM stcItem ;
// 	stcItem.iSubItem = (nSub);
// 	stcItem.cchTextMax = (dwSize);
// 	stcItem.pszText = (pszBuff);
// 	return SendMessage(m_hWnd , LVM_GETITEMTEXT , nLine , (LPARAM)&stcItem);
}

//************************************
// ������:  GetItemCount
// ��  ��:  ��ȡ����
// ����ֵ:  DWORD
//************************************
DWORD MyListView::GetItemCount()
{
	return ListView_GetItemCount(m_hWnd);
}

//************************************
// ������:  GetColumnCount
// ��  ��:  ��ȡ���ĸ���
// ����ֵ:  DWORD
//************************************
DWORD MyListView::GetColumnCount()
{
	return m_dwColumnCount;
}

//************************************
// ������:  DeleteItem
// ��  ��:  ɾ���ڵ�
// ����ֵ:  BOOL
// ��  ��:  int nLine
//************************************
BOOL MyListView::DeleteItem(int nLine)
{
	return ListView_DeleteItem(m_hWnd , nLine);
}

//************************************
// ������:  DeleteColumn
// ��  ��:  ɾ����
// ����ֵ:  BOOL
// ��  ��:  DWORD dwIndex
//************************************
BOOL MyListView::DeleteColumn(DWORD dwIndex)
{
	--m_dwColumnCount;
	return ListView_DeleteColumn(m_hWnd , dwIndex);
}

//************************************
// ������:  DeleteAllItem
// ��  ��:  ɾ�����нڵ�
// ����ֵ:  void
//************************************
void MyListView::DeleteAllItem()
{
	ListView_DeleteAllItems(m_hWnd);
}

//************************************
// ������:  DeleteAllColumn
// ��  ��:  ɾ��������
// ����ֵ:  void
//************************************
void MyListView::DeleteAllColumn()
{
	// ѭ��ɾ����һ��,��ListViewû����ʱ,ListView_DeleteColumn�ͻ᷵��FALSE
	while(ListView_DeleteColumn(m_hWnd , 0));
}

DWORD MyListView::GetItemValue(int nLine , int nSub , int nRadix)
{
	TCHAR buff[ 20 ];
	// ��ȡ�ڵ��ı�
	if(0 != GetItemText(nLine , nSub , buff , 20))
		return wcstol(buff , NULL , nRadix); // ���ı�ת������ֵ
	return 0;
}

// �����Ҽ��˵�
void MyListView::PopupMenu()
{
	if(m_hMenu == NULL) // ���û�в˵�,���ȴ����˵�
	{
		// ��������˵�
		m_hMenu = CreateMenu();

		// ���������˵�
		HMENU hPopUp = CreatePopupMenu();

		// �򵯳��˵�����˵��� 
		AppendMenu(hPopUp , /*������Ĳ˵����*/
				   MF_STRING , /*Ҫ��������ݱ��(��������ַ���)*/
				   MENUID_OPEN , /*�˵���ID*/
				   _T("��")/*�˵�����ʾ�ı�*/
				   );
		AppendMenu(hPopUp , MF_STRING , MENUID_DELETE , _T("ɾ��"));


		// �������˵����뵽����˵�,��Ϊ����˵�������ֱ�Ӳ���˵���
		AppendMenu(m_hMenu , /* �����˵��Ĳ˵����*/
				   MF_POPUP ,/*Ҫ��������ݵı��(�������һ�������˵�)*/
				   (UINT_PTR)hPopUp , /*�����˵��Ĳ˵����*/
				   _T("�ļ�")/*�����˵�����ʾ�ı�*/
				   );
	}

	POINT	pt;
	GetCursorPos(&pt); // ��ȡ�������(��Ļ����)

	TrackPopupMenu(GetSubMenu(m_hMenu , 0) ,/*Ҫ�����Ĳ˵��ľ��,�����Ƕ���˵�,�����������ȡ�˶���˵����Ӳ˵�(Ҳ���ǵ����˵�)*/
				   TPM_LEFTALIGN , /*�˵��ı����뷽ʽ*/
				   pt.x , pt.y , /*�˵�����ʾ����*/
				   0 , // ����
				   m_hParent , /*���ղ˵������Ϣ�Ĵ��ھ��(����ѡ�񸸴���)*/
				   0);
}



// ��ȡ��ǰ��ѡ�е�����к�,���û��,�򷵻�-1
int MyListView::GetSelectItem()
{
	return SendMessage(m_hWnd , LVM_GETSELECTIONMARK,0,0);
}




