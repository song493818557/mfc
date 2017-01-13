#include <windows.h>
#include "resource.h"
#include "MyListView.h"
#include "MyTreeView.h"
#include <tchar.h>
#include "MyDir.h"

MyListView g_myListView;
MyTreeView g_myTreeView;


// 窗口回调函数
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

// WM_INITDIALOG初始化消息处理函数
void OnInitDaialog(HWND hWnd);

// WM_COMMAND消息的处理函数
DWORD OnCommand(HWND hWnd  , WPARAM wParam, LPARAM lParam);

// WM_NOTIFY消息的处理函数
DWORD OnNotify(HWND hWmd , LPARAM lParam);

int APIENTRY WinMain(_In_ HINSTANCE hInstance ,
					 _In_opt_ HINSTANCE hPrevInstance ,
					 _In_ LPSTR lpCmdLine ,
					 _In_ int nShowCmd)
{
	DialogBox(hInstance ,MAKEINTRESOURCE(IDD_DIALOG1) ,NULL ,DlgProc);
}


// 对话框的回调函数
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	// 筛选消息类型
	switch(uMsg)
	{
		// 窗口被创建的消息,有且只有一次,在调用创建对话框的函数之后产生这个消息 
		case WM_INITDIALOG:
			OnInitDaialog(hWnd);
		break;

		// 响应控件发送出来的消息
		case WM_COMMAND:
			return OnCommand(hWnd , wParam , lParam);

		case WM_NOTIFY:
			return OnNotify(hWnd , lParam);
		
			// 响应窗口被关闭的消息,(关闭后,窗口只是被隐藏,进程并没有退出)
		case WM_CLOSE:
			// 调用销毁窗口的函数,触发WM_DESTROY消息
			return DestroyWindow(hWnd);

			//响应窗口被销毁的消息
		case WM_DESTROY:
			PostQuitMessage(0); // 发送退出进程的消息
			break;
	}

	// 如果消息没有被处理只能返回FALSE
	return FALSE;
}

// WM_COMMAND消息的处理函数
DWORD OnCommand(HWND hWnd , WPARAM wParam , LPARAM lParam)
{
	// 根据ID的不同,来区别对待
	switch(LOWORD(wParam))
	{
		case MENUID_OPEN:
		{
			// 获取ListView被选中的节点的文本
			TCHAR fileName[ MAX_PATH ];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

			// 获取TreeView控件被选中节点组成的文件路径
			TCHAR filePath[ MAX_PATH ];
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*获取被选中的节点句柄*/
									 filePath , MAX_PATH);

			// 拼接成完整的文件路径
 			TCHAR param[ MAX_PATH ];
			_stprintf_s(param , MAX_PATH , _T("%s %s\\%s") , _T(" /e,/select, ") , filePath , fileName);
			// 使用资源管理器打开文件, 并选中文件
			ShellExecute(NULL , L"open" , L"explorer" , param , NULL , SW_SHOW);
		}
		break;

		case MENUID_DELETE:
		{
			// 获取ListView被选中的节点的文本
			TCHAR fileName[ MAX_PATH ];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

			// 获取TreeView控件被选中节点组成的文件路径
			TCHAR filePath[ MAX_PATH ];
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*获取被选中的节点句柄*/
									 filePath , MAX_PATH);

			// 拼接成完整的文件路径
			_stprintf_s(filePath , MAX_PATH , _T("%s\\%s") , filePath , fileName);

			// 弹出提示
			if(MessageBox(hWnd , filePath , _T("确定要删除?") , MB_OKCANCEL))
			{
				g_myListView.DeleteItem(nIndex);
				//DeleteFile(filePath);
			}
		}
		break;
	}

	return TRUE;
}

void OnInitDaialog(HWND hWnd)
{
	RECT deskTopRt = { 0 };
	RECT dlgRt = { 0 };
	// 获取桌面窗口的面积
	GetWindowRect(GetDesktopWindow() , &deskTopRt);
	GetClientRect(hWnd , &dlgRt);

	// 移动窗口
	SetWindowPos(hWnd , HWND_TOP ,
				 (deskTopRt.right - dlgRt.right) / 2 ,
				 (deskTopRt.bottom - dlgRt.bottom) / 2 ,
				 0 , 0 ,
				 SWP_NOSIZE /*只移动窗口,不改变大小*/
				 );


	// 创建一个list控件
	g_myListView.Create(0x1000 , hWnd , 301 , 0 , 600 , 300);
	// 设置扩展风格
	g_myListView.SetStyle(LVS_REPORT , LVS_EX_FULLROWSELECT);

	// 插入栏
	g_myListView.InsertColumn(0 , _T("名称") ,120);
	g_myListView.InsertColumn(1 , _T("类型") , 50);
	g_myListView.InsertColumn(2 , _T("大小") , 80);
	g_myListView.InsertColumn(3 , _T("修改日期") , 145);
	g_myListView.InsertColumn(4 , _T("创建日期") , 145);

	// 创建Tree控件
	g_myTreeView.Create(0x1001 , hWnd , 0 , 0 , 300 , 300);

	// 获取所有的盘符
	TCHAR szDrivers[ MAX_PATH ];
	GetLogicalDriveStrings(MAX_PATH , szDrivers);
	TCHAR* pTemp = szDrivers;
	// 将所有的盘符都插入到Tree控件
	HTREEITEM hItem;
	int nIndex = 0;
	do{
		hItem = g_myTreeView.InsertItem(pTemp);
		g_myTreeView.SetItemData(hItem , nIndex);

		pTemp += _tcslen(pTemp) + 1;
	} while(*pTemp);
}

DWORD OnNotify(HWND hWmd , LPARAM lParam)
{
	// WM_NOTIFY消息, lParam保存着LPNMHDR 结构体的地址
	
	LPNMHDR pNmHdr = (LPNMHDR)lParam;
	
	// 判断具体的消息
	switch(pNmHdr->code)
	{
		case NM_RCLICK: // 右键单击事件
		{
			if(pNmHdr->idFrom == g_myListView.m_dwId) // 判断产生右键单击事件的控件ID是否是ListView控件
			{
				// 弹出菜单
				g_myListView.PopupMenu();
			}
		}
		break;
		case NM_DBLCLK:
		{
			if(pNmHdr->idFrom == g_myListView.m_dwId) // 判断产生右键单击事件的控件ID是否是ListView控件
			{
				// 获取ListView被选中的节点的文本
				TCHAR fileName[ MAX_PATH ];
				int nIndex = g_myListView.GetSelectItem();
				g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

				// 获取TreeView控件被选中节点组成的文件路径
				TCHAR filePath[ MAX_PATH ];
				g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*获取被选中的节点句柄*/
										 filePath , MAX_PATH);

				// 拼接成完整的文件路径
				_stprintf_s(filePath , MAX_PATH , _T("%s\\%s") , filePath , fileName);

				MyDir dir;
				bool tem = dir.ListDir(filePath,1);
				//将所有目录插入到树控件
				//将所有文件插入到list控件
				g_myListView.DeleteAllItem(); // 先删除ListView控件的所有项
				int j = 0;
				for(auto &i : dir.m_Filelist)
				{
					g_myListView.InsertItem(j , 0 , i.m_szFileName);
					g_myListView.InsertItem(j , 1 , i.m_bIsDir ? _T("文件夹"):_T("文件"));
					g_myListView.InsertItem_64(j , 2 , i.m_qwSize , 10);
					g_myListView.InsertItem(j , 3 , i.m_LastWriteTime);
					g_myListView.InsertItem(j , 4 , i.m_CreationTime);
					++j;
				}
			}
		}
		break;

		case NM_CLICK:// 鼠标左键点击事件
		{
			// 判断是哪个控件发出的消息
			if(pNmHdr->idFrom == g_myTreeView.m_dwId) // 判断产生消息的控件ID是否是TreeView控件
			{
				BOOL bShowDir = TRUE;
				// 获取被点击节点的序号
				// 获取路径
				TCHAR path[ MAX_PATH ];
				HTREEITEM hClickItem = g_myTreeView.GetClickItem();
				if(g_myTreeView.GetSubItem(hClickItem , 0) == NULL)
					bShowDir = FALSE;


				if(!g_myTreeView.GetTreePath(hClickItem , path , MAX_PATH))
					break;

				// 遍历这个路径, 并将得到文件信息插入到listView控件.
				MyDir dir;
			bool tem =	dir.ListDir(path,1);


				//将所有目录插入到树控件
				//将所有文件插入到list控件
				g_myListView.DeleteAllItem(); // 先删除ListView控件的所有项
				int j = 0;
				for(auto &i : dir.m_Filelist)
				{
					if(bShowDir && i.m_bIsDir)
					{
						g_myTreeView.InsertItem(i.m_szFileName , hClickItem);
						g_myListView.InsertItem(j , 0 , i.m_szFileName);
						g_myListView.InsertItem(j , 1 , _T("文件夹") );
						//g_myListView.InsertItem_64(j , 2 , i.m_qwSize , 10);
						//g_myListView.InsertItem(j , 3 , i.m_LastWriteTime);
						//g_myListView.InsertItem(j , 4 , i.m_CreationTime);
						++j;
					}
					else
					{
						//L"名称" , 3
						//L"大小" , 1
						//L"修改日期"
						//L"创建日期"
						g_myListView.InsertItem(j , 0 , i.m_szFileName);
						g_myListView.InsertItem(j , 1 , _T("文件"));
						g_myListView.InsertItem_64(j , 2 , i.m_qwSize , 10);
						g_myListView.InsertItem(j , 3 , i.m_LastWriteTime);
						g_myListView.InsertItem(j , 4 , i.m_CreationTime);
						++j;
					}
				}
			}
		}
		break;
	}

	return 0;
}