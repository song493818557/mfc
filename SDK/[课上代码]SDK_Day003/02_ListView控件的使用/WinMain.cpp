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

		case WM_COMMAND:
		{
			switch(LOWORD(wParam))
			{
				case ID_MENU_OPEN:
				{
					HWND hListView = GetDlgItem(hWnd , IDC_LIST1);
					// 获取被选中的行的行号(如果当前没有被选中的行, 返回的是-1)
					int nLine = SendMessage(hListView , LVM_GETSELECTIONMARK , 0 , 0);
					if(nLine != -1)
					{
						TCHAR buff[ 20 ];
					
						ListView_GetItemText(hListView , nLine , 1 , buff , 20);
						MessageBox(hWnd , buff , _T("打开") , 0);
					}
				}
				break;
			}
		}
		break;

		case WM_NOTIFY: // 响应通用控件的消息
		{
			NMHDR* pNMHDR = (NMHDR*)lParam;
			switch(pNMHDR->code)
			{
				case NM_RCLICK:
				{
					switch(pNMHDR->idFrom)
					{
						case IDC_LIST1:
						{
							// 弹出一个右键菜单
							// 1. 加载菜单
							HMENU hMenu = LoadMenu(g_hIns , MAKEINTRESOURCE(IDR_MENU1));
							// 获取顶层菜单的子菜单(弹出菜单)
							HMENU hPopup = GetSubMenu(hMenu,0);

							POINT pt;
							GetCursorPos(&pt);//获取光标坐标(屏幕坐标)
							TrackPopupMenu(hPopup , TPM_LEFTALIGN , pt.x , pt.y , 0 , hWnd , 0);

							// 销毁菜单
							DestroyMenu(hMenu);
						}
						break;
					}
				}
				break;

				case NM_CLICK: // 处理通用控件的鼠标左键单击消息
				{
					switch(pNMHDR->idFrom ) // 筛选是哪个通用控件发出的鼠标左键单击消息
					{
						case IDC_LIST1:// ListView控件
						{
							// 当WM_NOTIFY消息是由ListView控件产生时, lParam是一个LPNMITEMACTIVATE结构体指针
							// 在这个结构体中, 保存着被点击的节点的行号和列号,以及鼠标坐标
							LPNMITEMACTIVATE lpnmitem = (LPNMITEMACTIVATE)lParam;
							

							// 获取被点击节点的文本
							TCHAR buff[ 50 ];
							ListView_GetItemText(pNMHDR->hwndFrom ,
												 lpnmitem->iItem ,
												 lpnmitem->iSubItem ,
												 buff ,
												 50
												 );
							MessageBox(hWnd , buff , 0 , 0);
						}
						break;
					}

				}
			}
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);
		default:
			return FALSE;
	}
	return TRUE;
}

void OnInitDialog(HWND hWnd)
{
	// 3. 调用初始化通用控件的函数
	InitCommonControls();
	
	// 4. 开始初始化ListView控件
	// 设置ListView的扩展风格
	//4.1 插入Column(栏或者叫列)
	HWND hListView = GetDlgItem(hWnd , IDC_LIST1);

	// 设置ListView的扩展风格:整行选中
	ListView_SetExtendedListViewStyle(hListView , LVS_EX_FULLROWSELECT|LVS_EX_CHECKBOXES);

	//4.2 配置栏信息结构体
	LV_COLUMN column;
	column.mask = LVCF_WIDTH |LVCF_TEXT|LVCF_FMT; // 配置要使用的字段
	column.pszText= _T(""); // 栏的显示文本
	column.cx = 20; // 栏的宽度
	column.fmt = LVCFMT_CENTER; // 文本居中对齐(第0个Column不居中)

	// 4.3 插入到ListView控件
	ListView_InsertColumn(hListView , /*ListView控件句柄*/
						  0 , /*序号*/
						  &column/*栏的信息结构体*/
						  );

	column.pszText = _T("姓名"); // 栏的显示文本
	column.cx = 80; // 栏的宽度
	ListView_InsertColumn(hListView , 1 , &column);

	column.pszText = _T("年龄"); // 栏的显示文本
	column.cx = 50; // 栏的宽度
	ListView_InsertColumn(hListView , 2 , &column);

	column.pszText = _T("性别"); // 栏的显示文本
	column.cx = 50; // 栏的宽度
	ListView_InsertColumn(hListView , 3 , &column);

	//5 插入行信息
	LV_ITEM item = { 0 };

	//5.1 配置行信息结构体
	item.mask = LVIF_TEXT;

	item.iItem = 0; // 行号
	item.pszText = NULL;
	//5.2 将结构体插入到ListView控件
	int nIdex = ListView_InsertItem(hListView , &item);

	// 5.3 设置指定行指定列的文本
	ListView_SetItemText(hListView , /*ListView窗口句柄*/
						 item.iItem , /*行号*/
						 1 , /*列好*/
						 _T("刘德华")/*列的显示文本*/
						 );
	ListView_SetItemText(hListView , item.iItem , 2 , _T("18"));
	ListView_SetItemText(hListView , item.iItem , 3 , _T("男"));

	++item.iItem; // 增加行号
	nIdex = ListView_InsertItem(hListView , &item);
	ListView_SetItemText(hListView , item.iItem , 1 , _T("王大锤"));
	ListView_SetItemText(hListView , item.iItem , 2 , _T("28"));
	ListView_SetItemText(hListView , item.iItem , 3 , _T("男"));
}
