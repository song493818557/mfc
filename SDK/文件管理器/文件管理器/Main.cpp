#include "resource.h"
#include "Mylist.h" 
#include <commctrl.h>
#include "MyTreeView.h" 
#include "MyDir.h"
#include <xfunctional>
#include <algorithm>

using namespace std;
#pragma comment (lib,"comctl32.lib")
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
void OnInitDialog(HWND hWnd);
void OnNotify(HWND hWnd, LPARAM lParam);
HINSTANCE g_hIns;
CMylist g_myListView;
MyTreeView g_myTreeView;
int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){

	g_hIns = hInstance;
	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1),0,DlgProc);
}

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG: OnInitDialog(hWnd); break;
	case WM_NOTIFY:		 OnNotify(hWnd, lParam); break;
	case WM_CLOSE:
		EndDialog(hWnd, 0);
		//break;
	default: return false;
		break;
	}
	return true;
}
//初始化
void OnInitDialog(HWND hWnd){
	g_myListView.Create(IDC_LIST1, hWnd);
	g_myListView.SetStyle(LVS_REPORT, LVS_EX_FULLROWSELECT);
	g_myListView.InsertColumn(0, _T("名称"), 150);
	g_myListView.InsertColumn(1, _T("类型"), 80);
	g_myListView.InsertColumn(2, _T("大小"), 80);
	g_myListView.InsertColumn(3, _T("修改日期"), 145);
	g_myListView.InsertColumn(4, _T("创建日期"), 145); 

	g_myTreeView.Create(IDC_TREE1, hWnd);
	//获取所有盘符
	TCHAR szDrivers[MAX_PATH];
	GetLogicalDriveStrings(MAX_PATH, szDrivers);
	TCHAR * pTemp = szDrivers;
	//将所有盘符都插入到TREE控件
	HTREEITEM hItem;
	int nIndex = 0;
	do
	{
		hItem = g_myTreeView.InsertItem(pTemp);
		g_myTreeView.SetItemData(hItem, nIndex);
		pTemp += _tcslen(pTemp) + 1;
	} while (*pTemp);
}
void OnNotify(HWND hWnd,LPARAM lParam){

	LPNMHDR pNmHdr = (LPNMHDR)lParam;
	switch (pNmHdr->code)
	{

	case NM_CLICK:{
		if (pNmHdr ->idFrom == g_myTreeView.m_dwId) //判断是否由树控件产生的点击消息
		{
			bool bShwoDir = TRUE;
			//获取被点击的节点序号
			//获取路径
			TCHAR path[MAX_PATH];
			HTREEITEM hClickItem = g_myTreeView.GetClickItem();
			//如果没有子项  就不显示
			if (g_myTreeView.GetSubItem(hClickItem,0)== NULL) bShwoDir = FALSE;
			//如果获取不到路径地址 就结束
			if (!g_myTreeView.GetTreePath(hClickItem,path,MAX_PATH)) break; 
			//遍历获取到的路径
			MyDir dir;
			bool tem = dir.ListDir(path, 1);
			_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), path);
			//将所有目录插入到树控件
			//将所有文件都插入到LIST控件
			g_myListView.DeleteAllItem();//先删除LISTVIEW控件的所有项
			//dir.m_Filelist.
			// g_myTreeView.DeleteItem(hClickItem);
			// g_myTreeView.DeleteAllItem();
			//按照文件大小排序
			dir.m_Filelist.sort(CompareRules);
			//dir.m_Filelist.sort(greater<MyFile>()); 
 			int j = 0;
			for (auto &i : dir.m_Filelist)
			{ 
					g_myTreeView.InsertItem(i.m_szFileName, hClickItem);//树 子列
					g_myListView.InsertItem(j, 0, i.m_szFileName);
					g_myListView.InsertItem(j, 1, i.m_szFiletype); 
					g_myListView.InsertItem_64(j, 2, i.m_qwSize, 10);
					g_myListView.InsertItem(j, 3, i.m_LastWriteTime);
					g_myListView.InsertItem(j, 4, i.m_CreationTime);  
				++j;
			} 
		} 
	}break; 
	case NM_RCLICK:{//列表右键菜单
		if (pNmHdr->idFrom == g_myListView.m_dwId)//判断是否由列表控件产生的点击消息
		{ 
			//载入界面菜单 POPUPMENU里有代码创建菜单
			g_myListView.m_hMenu = LoadMenu(g_hIns, MAKEINTRESOURCE(IDR_MENU1));
			g_myListView.PopupMenu();
		} 
	}break;
	case NM_DBLCLK:{//列表双击
		if (pNmHdr->idFrom == g_myListView.m_dwId)//判断是否由列表控件产生的点击消息
		{ 
			// 获取ListView被选中的节点的文本
			TCHAR fileName[MAX_PATH];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex, 0, fileName, MAX_PATH);
			//获取TREEVIEW控件被选中节点组成的文件路径
			TCHAR filePath[MAX_PATH] = {0};
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem(), filePath, MAX_PATH);

			if (filePath ==0)
			{
				_stprintf_s(filePath, MAX_PATH, _T("C:\\%s"), fileName);
			}
			else
			{
				//拼接成完整的中文路径
				_stprintf_s(filePath, MAX_PATH, _T("%s\\%s"), filePath, fileName);
			}
			


			//遍历获取到的路径
			MyDir dir;
			bool tem = dir.ListDir(filePath, 1); 
			_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), filePath);
			//将所有目录插入到树控件
			//将所有文件都插入到LIST控件
			g_myListView.DeleteAllItem();//先删除LISTVIEW控件的所有项
			//dir.m_Filelist. 
			//dir.m_Filelist.sort(dir.m_Filelist.begin(), dir.m_Filelist.end(), dir.CompareRules);
			//按照文件大小排序
			//dir.m_Filelist.sort(greater<MyFile>()); 
			dir.m_Filelist.sort(CompareRules);
			int j = 0; 
			for (auto &i : dir.m_Filelist)
			{ 
				g_myListView.InsertItem(j, 0, i.m_szFileName);
				g_myListView.InsertItem(j, 1, i.m_szFiletype);
				g_myListView.InsertItem_64(j, 2, i.m_qwSize, 10);
				g_myListView.InsertItem(j, 3, i.m_LastWriteTime);
				g_myListView.InsertItem(j, 4, i.m_CreationTime);
				++j;
			}
		}
	}break;
		case LVN_COLUMNCLICK:{
			LPNMLISTVIEW temp = (LPNMLISTVIEW)lParam;
			MyFile::Enumsort = (sortEnum)temp->iSubItem;

			//遍历获取到的路径
			MyDir dir;
			bool tem = dir.ListDir(g_myListView.m_NowPath, 1);
			//_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), filePath);
			//将所有目录插入到树控件
			//将所有文件都插入到LIST控件
			g_myListView.DeleteAllItem();//先删除LISTVIEW控件的所有项
			//dir.m_Filelist. 
			//dir.m_Filelist.sort(dir.m_Filelist.begin(), dir.m_Filelist.end(), dir.CompareRules);
			//按照文件大小排序
			//dir.m_Filelist.sort(greater<MyFile>()); 
			dir.m_Filelist.sort(CompareRules);
			int j = 0;
			for (auto &i : dir.m_Filelist)
			{
				g_myListView.InsertItem(j, 0, i.m_szFileName);
				g_myListView.InsertItem(j, 1, i.m_szFiletype);
				g_myListView.InsertItem_64(j, 2, i.m_qwSize, 10);
				g_myListView.InsertItem(j, 3, i.m_LastWriteTime);
				g_myListView.InsertItem(j, 4, i.m_CreationTime);
				++j;
			}
		} break;
	} 
}