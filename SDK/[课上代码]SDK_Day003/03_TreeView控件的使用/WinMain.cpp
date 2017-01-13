#include <windows.h>
#include "resource.h"
#include <tchar.h>

// 1. 导入头文件
#include <commctrl.h>
// 2. 导入静态库
#pragma comment(lib,"comctl32.lib")

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

void OnInitDialog(HWND hWnd);

HINSTANCE g_hIns ;
int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	g_hIns = hInstance;
	DialogBox(hInstance , MAKEINTRESOURCE(IDD_DIALOG1) , NULL , DlgProc);
}


INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{

	switch(uMsg)
	{
		case WM_INITDIALOG:
			OnInitDialog(hWnd);
		break;

		case WM_NOTIFY:
		{
			NMHDR* pNMHDR = (NMHDR*)lParam;
			switch(pNMHDR->code)
			{
				case NM_RCLICK: // 响应右键单击消息
				{
					switch(pNMHDR->idFrom)// 筛选响应右键单击消息的x`控件ID
					{
						case IDC_TREE1:
						{
							// 获取被点击节点的文本
							TV_ITEM item = { 0 };
							// 获取当前鼠标悬停的节点
							// typedef struct tagTVHITTESTINFO
							// {
							// 	  POINT       pt; // 鼠标坐标(树控件客户区坐标)
							// 	  UINT        flags;// 标志
							// 	  HTREEITEM   hItem; // 函数返回出的节点句柄
							// } TVHITTESTINFO , *LPTVHITTESTINFO;
							TVHITTESTINFO hitTestInfo = { 0 };
							// 获取当前鼠标坐标(屏幕坐标)
							GetCursorPos(&hitTestInfo.pt);
							// 将屏幕坐标转换成树控件的客户区坐标
							ScreenToClient(pNMHDR->hwndFrom , &hitTestInfo.pt);
							hitTestInfo.flags = TVHT_ONITEM ; // 标志

							TreeView_HitTest(pNMHDR->hwndFrom , &hitTestInfo);

							// 设置要获取节点的信息
							item.mask = TVIF_TEXT;
							item.hItem = hitTestInfo.hItem ; // 设置要获取节点文本的节点句柄
							TCHAR buff[ 50 ] = { 0 };
							item.pszText = buff; // 保存缓冲区首地址(用于接收节点文本)
							item.cchTextMax = 50; // 缓冲区的最大字符个数
							TreeView_GetItem(pNMHDR->hwndFrom , &item);

							MessageBox(hWnd , buff , _T("节点文本") , 0);
						}
						break;
					}
				}
				break;
			}
		}
		break;

		case  WM_CLOSE:
			EndDialog(hWnd , 0);
		default:
			return FALSE;
			break;
	}
	return TRUE;
}


void OnInitDialog(HWND hWnd)
{
	//3. 初始化通用控件
	InitCommonControls();

	//4 插入节点到树控件

	//4.1
	HWND hTreeView = GetDlgItem(hWnd , IDC_TREE1);
	// 4.2 初始化插入结构体
	//	4.3 初始化插入节点的位置信息
	TV_INSERTSTRUCT insStruct;
	insStruct.hParent = NULL ; // 设置父节点,当父节点是NULL时,插入的节点成为根节点
	insStruct.hInsertAfter = TVI_LAST; // 和兄弟节点间的位置(插入到最后)

	// 4.4 初始化插入节点本身信息
	insStruct.item.mask = TVIF_TEXT;// 设置使用结构体中的文本字段
	insStruct.item.pszText = _T("第15期");

	// 5 将插入信息结构体传入函数,进行插入,并返回插入节点的节点句柄
	HTREEITEM hItem15期 = TreeView_InsertItem(hTreeView , &insStruct);

	// 5.1 插入一个新节点到已有节点之下
	insStruct.hParent = hItem15期; // 设置父节点句柄
	insStruct.item.pszText = _T("李老师"); // 设置节点的显示文本
	// 插入节点,并返回新节点的节点句柄
	HTREEITEM hItem李老师 = TreeView_InsertItem(hTreeView , &insStruct);

	insStruct.hParent = hItem李老师;// 设置父节点句柄
	insStruct.item.pszText = _T("李老师儿子");// 设置节点的显示文本
	// 插入节点
	TreeView_InsertItem(hTreeView , &insStruct);


	insStruct.hParent = NULL; // 设置节点的父节点句柄
	insStruct.item.pszText = _T("第14期");
	TreeView_InsertItem(hTreeView , &insStruct);
}