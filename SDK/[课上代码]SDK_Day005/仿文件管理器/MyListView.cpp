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
// 函数名:  MyListView
// 功  能:  构造函数,传入ID,坐标,大小,父窗口,风格创建出一个listvie控件
// 返回值:  
// 形  参:  DWORD dwId
// 形  参:  DWORD dwX
// 形  参:  DWORD dwY
// 形  参:  DWORD dwWidth
// 形  参:  DWORD dwHignt
// 形  参:  HWND hParent
// 形  参:  DWORD dwStyle
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
// 函数名:  Create
// 功  能:  传入ID,坐标,大小,父窗口,风格创建出一个listvie控件
// 返回值:  
// 形  参:  DWORD dwId
// 形  参:  DWORD dwX
// 形  参:  DWORD dwY
// 形  参:  DWORD dwWidth
// 形  参:  DWORD dwHignt
// 形  参:  HWND hParent
// 形  参:  DWORD dwStyle
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
	//获取对话框中对应ID的控件
	m_hWnd = GetDlgItem(hParent , dwId);

	// 如果没有获取到,说明当前对话框中没有这个控件ID,则使用这个控件ID创建一个ListView控件,否则使用默认的控件句柄
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
// 函数名:  InsertColumn
// 功  能:  插入一栏
// 返回值:  BOOL
// 形  参:  DWORD dwIndex 栏的栏目数
// 形  参:  const TCHAR * pszText 栏的标题文本
// 形  参:  DWORD dwWdit 栏的宽度
// 形  参:  DWORD dwFormat 栏的个数(字符对齐方式)
//************************************
BOOL MyListView::InsertColumn(DWORD dwIndex ,
							  const TCHAR* pszText , 
							  DWORD dwWdit , 
							  DWORD dwFormat)
{
	++m_dwColumnCount;

	LV_COLUMN stcColumn = { 0 };
	stcColumn.mask = LVCF_WIDTH | LVCF_TEXT | LVCF_FMT; // 设置要使用的结构体字段
	
	// 设置显示文本
	stcColumn.pszText = (TCHAR*)pszText;// 显示的字符串
	// 设置栏的宽度
	stcColumn.cx = dwWdit; // 宽度
	// 设置栏的文本对齐方式
	stcColumn.fmt = dwFormat;//格式

	// 插入到控件
	return ListView_InsertColumn(m_hWnd ,dwIndex ,&stcColumn);
}

//************************************
// 函数名:  GetStyle
// 功  能:  获取list控件的风格
// 返回值:  void
// 形  参:  PDWORD pdwStyle 普通风格
// 形  参:  PDWORD pdwExStyle 扩展风格
//************************************
void MyListView::GetStyle(PDWORD pdwStyle , PDWORD pdwExStyle/*=NULL*/)
{
	// 获取风格
	if(pdwStyle != NULL)
	{
		// 获取普通风格
		*pdwStyle = GetWindowLong(m_hWnd , GWL_STYLE);
	}
	if(pdwExStyle != NULL) // 获取扩展风格
		*pdwExStyle = GetWindowLong(m_hWnd , GWL_EXSTYLE);
}


//************************************
// 函数名:  SetStyle
// 功  能:  设置list控件的风格
// 返回值:  void
// 形  参:  DWORD dwStyle 普通风格
// 形  参:  DWORD dwExStyle 扩展风格
//************************************
void MyListView::SetStyle(DWORD dwStyle , DWORD dwExStyle/*=0*/)
{	
	// 设置普通风格
	if(dwStyle != 0)
	{
		dwStyle = GetWindowLong(m_hWnd , GWL_STYLE) | dwStyle;
		SetWindowLong(m_hWnd ,GWL_STYLE ,dwStyle);
		
	}
	// 设置扩展风格
	if(dwExStyle != 0)
	{
		dwExStyle |= SendMessage(m_hWnd , LVM_GETEXTENDEDLISTVIEWSTYLE , 0 , 0);
		// 设置扩展风格
		SendMessage(m_hWnd , LVM_SETEXTENDEDLISTVIEWSTYLE , 0 , dwExStyle);
	}
}


//************************************
// 函数名:  InsertItem
// 功  能:  插入项目
// 返回值:  BOOL
// 形  参:  int nLine 插入的行号
// 形  参:  int nSub  插入的栏好
// 形  参:  const TCHAR * pszText 插入的文本
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const TCHAR* pszText)
{
	// 如果插入列数超出,则直接返回失败
	if(nSub > m_dwColumnCount)
		return FALSE;

	// 获取节点个数
	int dwItemCount = GetItemCount();

	LV_ITEM stcItem = { 0 };
	stcItem.mask = LVIF_TEXT;
	
	// 如果要插入的节点的行号超出节点,则插入新的节点,并把插入位置设为新插入节点的位置
	if(nLine >= dwItemCount)
	{
		nLine = dwItemCount;
		//设置插入位置
		stcItem.iItem = nLine;
		// 插入新的节点
		ListView_InsertItem(m_hWnd , &stcItem);
	}
	
	// 设置节点文本
	ListView_SetItemText(m_hWnd ,
						 nLine ,
						 nSub ,
						 (TCHAR*)pszText
						 );
	return TRUE;
}

//************************************
// 函数名: InsertItem
// 功  能: 将一个数值插入到ListView控件
// 返回值: BOOL
// 参  数: int nLine 行号
// 参  数: int nSub  列好
// 参  数: const DWORD dwValue 要插入的数值
// 参  数: int nRadix		   数值的进制数
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const DWORD dwValue , int nRadix)
{
	TCHAR buff[ 10 ];
	// 先将数值转换成字符串
	switch(nRadix)
	{
		case 10:
			swprintf_s(buff , 10 , L"%d" , dwValue);
			break;
		case 16:
			swprintf_s(buff , 10 , L"%x" , dwValue);
			break;
	}
	// 将字符串插入
	return InsertItem(nLine , nSub , buff);
}

//************************************
// 函数名: InsertItem
// 功  能: 将一个时间插入到ListView
// 返回值: BOOL
// 参  数: int nLine	  行号
// 参  数: int nSub	  列号
// 参  数: const SYSTEMTIME & dwValue 要插入的时间
//************************************
BOOL MyListView::InsertItem(int nLine , int nSub , const SYSTEMTIME& dwValue)
{
	TCHAR buff[ 40 ];
	// 先将时间转化成字符串
	_stprintf_s(buff , 40 , _T("%04d/%02d/%02d-%02d:%02d:%02d") ,
				dwValue.wYear ,
				dwValue.wMonth ,
				dwValue.wDay ,
				dwValue.wHour ,
				dwValue.wMinute ,
				dwValue.wSecond);
	// 将字符串插入
	return InsertItem(nLine , nSub , buff);
}

//************************************
// 函数名: InsertItem_64
// 功  能: 插入一个64位的数值
// 返回值: BOOL
// 参  数: int nLine 行号
// 参  数: int nSub  列号
// 参  数: const ULONG64 u64Value 64位的数值
// 参  数: int nRadix			  数值的进制数
//************************************
BOOL MyListView::InsertItem_64(int nLine , int nSub , const ULONG64& u64Value , int nRadix /*= 10*/)
{
	TCHAR buff[ 20 ];
	// 先将数值转换成字符串
	switch(nRadix)
	{
		case 10:
			swprintf_s(buff , 20 , L"%I64d" , u64Value);
			break;
		case 16:
			swprintf_s(buff , 20 , L"%I64x" , u64Value);
			break;
	}
	// 插入字符串
	return InsertItem(nLine , nSub , buff);
}

//************************************
// 函数名:  GetClickItem
// 功  能:  获取当前被点击的节点的行号
// 返回值:  int	如果成功,返回节点的行号, 否则返回-1
// 形  参:  PDWORD pSubItem
//************************************
int MyListView::GetClickItem()
{
	LV_HITTESTINFO hitInfo = { 0 };

	// 获取当前鼠标坐标
	GetCursorPos(&hitInfo.pt);
	hitInfo.flags = LVHT_ABOVE;

	// 将屏幕坐标转换成客户区坐标
	ScreenToClient(m_hWnd , &hitInfo.pt);

	// 获取当前鼠标所在的节点
	ListView_HitTest(m_hWnd , &hitInfo.pt);
	
	// 返回获取到的节点行号, 如果没有则返回-1
	return hitInfo.iItem;
}

//************************************
// 函数名:  SetItemText
// 功  能:  设置指定行指定栏的节点的文本
// 返回值:  BOOL
// 形  参:  int nLine 行号
// 形  参:  int nSub  栏好
// 形  参:  const TCHAR * pszText 文本
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
// 函数名:  GetItemText
// 功  能:  获取指定行指定栏的文本
// 返回值:  DWORD
// 形  参:  int nLine 行号
// 形  参:  int nSub 栏号
// 形  参:  TCHAR * pszBuff 缓冲区
// 形  参:  DWORD dwSize 缓冲区最大字符个数
//************************************
DWORD MyListView::GetItemText(int nLine , int nSub , TCHAR* pszBuff , DWORD dwSize)
{
	ListView_GetItemText(m_hWnd ,
						 nLine , /*被点击的行*/
						 nSub , /*被点击的列*/
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
// 函数名:  GetItemCount
// 功  能:  获取个数
// 返回值:  DWORD
//************************************
DWORD MyListView::GetItemCount()
{
	return ListView_GetItemCount(m_hWnd);
}

//************************************
// 函数名:  GetColumnCount
// 功  能:  获取栏的个数
// 返回值:  DWORD
//************************************
DWORD MyListView::GetColumnCount()
{
	return m_dwColumnCount;
}

//************************************
// 函数名:  DeleteItem
// 功  能:  删除节点
// 返回值:  BOOL
// 形  参:  int nLine
//************************************
BOOL MyListView::DeleteItem(int nLine)
{
	return ListView_DeleteItem(m_hWnd , nLine);
}

//************************************
// 函数名:  DeleteColumn
// 功  能:  删除栏
// 返回值:  BOOL
// 形  参:  DWORD dwIndex
//************************************
BOOL MyListView::DeleteColumn(DWORD dwIndex)
{
	--m_dwColumnCount;
	return ListView_DeleteColumn(m_hWnd , dwIndex);
}

//************************************
// 函数名:  DeleteAllItem
// 功  能:  删除所有节点
// 返回值:  void
//************************************
void MyListView::DeleteAllItem()
{
	ListView_DeleteAllItems(m_hWnd);
}

//************************************
// 函数名:  DeleteAllColumn
// 功  能:  删除所有栏
// 返回值:  void
//************************************
void MyListView::DeleteAllColumn()
{
	// 循环删除第一个,当ListView没有栏时,ListView_DeleteColumn就会返回FALSE
	while(ListView_DeleteColumn(m_hWnd , 0));
}

DWORD MyListView::GetItemValue(int nLine , int nSub , int nRadix)
{
	TCHAR buff[ 20 ];
	// 获取节点文本
	if(0 != GetItemText(nLine , nSub , buff , 20))
		return wcstol(buff , NULL , nRadix); // 将文本转换成数值
	return 0;
}

// 弹出右键菜单
void MyListView::PopupMenu()
{
	if(m_hMenu == NULL) // 如果没有菜单,则先创建菜单
	{
		// 创建顶层菜单
		m_hMenu = CreateMenu();

		// 创建弹出菜单
		HMENU hPopUp = CreatePopupMenu();

		// 向弹出菜单插入菜单项 
		AppendMenu(hPopUp , /*被插入的菜单句柄*/
				   MF_STRING , /*要插入的内容标记(插入的是字符串)*/
				   MENUID_OPEN , /*菜单项ID*/
				   _T("打开")/*菜单项显示文本*/
				   );
		AppendMenu(hPopUp , MF_STRING , MENUID_DELETE , _T("删除"));


		// 将弹出菜单插入到顶层菜单,因为顶层菜单不允许直接插入菜单项
		AppendMenu(m_hMenu , /* 顶级菜单的菜单句柄*/
				   MF_POPUP ,/*要插入的内容的标记(插入的是一个弹出菜单)*/
				   (UINT_PTR)hPopUp , /*弹出菜单的菜单句柄*/
				   _T("文件")/*弹出菜单的显示文本*/
				   );
	}

	POINT	pt;
	GetCursorPos(&pt); // 获取鼠标坐标(屏幕坐标)

	TrackPopupMenu(GetSubMenu(m_hMenu , 0) ,/*要弹出的菜单的句柄,不能是顶层菜单,所有在这里获取了顶层菜单的子菜单(也就是弹出菜单)*/
				   TPM_LEFTALIGN , /*菜单文本对齐方式*/
				   pt.x , pt.y , /*菜单的显示坐标*/
				   0 , // 保留
				   m_hParent , /*接收菜单点击消息的窗口句柄(这里选择父窗口)*/
				   0);
}



// 获取当前被选中的项的行号,如果没有,则返回-1
int MyListView::GetSelectItem()
{
	return SendMessage(m_hWnd , LVM_GETSELECTIONMARK,0,0);
}




