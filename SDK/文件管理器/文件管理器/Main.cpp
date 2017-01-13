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
//��ʼ��
void OnInitDialog(HWND hWnd){
	g_myListView.Create(IDC_LIST1, hWnd);
	g_myListView.SetStyle(LVS_REPORT, LVS_EX_FULLROWSELECT);
	g_myListView.InsertColumn(0, _T("����"), 150);
	g_myListView.InsertColumn(1, _T("����"), 80);
	g_myListView.InsertColumn(2, _T("��С"), 80);
	g_myListView.InsertColumn(3, _T("�޸�����"), 145);
	g_myListView.InsertColumn(4, _T("��������"), 145); 

	g_myTreeView.Create(IDC_TREE1, hWnd);
	//��ȡ�����̷�
	TCHAR szDrivers[MAX_PATH];
	GetLogicalDriveStrings(MAX_PATH, szDrivers);
	TCHAR * pTemp = szDrivers;
	//�������̷������뵽TREE�ؼ�
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
		if (pNmHdr ->idFrom == g_myTreeView.m_dwId) //�ж��Ƿ������ؼ������ĵ����Ϣ
		{
			bool bShwoDir = TRUE;
			//��ȡ������Ľڵ����
			//��ȡ·��
			TCHAR path[MAX_PATH];
			HTREEITEM hClickItem = g_myTreeView.GetClickItem();
			//���û������  �Ͳ���ʾ
			if (g_myTreeView.GetSubItem(hClickItem,0)== NULL) bShwoDir = FALSE;
			//�����ȡ����·����ַ �ͽ���
			if (!g_myTreeView.GetTreePath(hClickItem,path,MAX_PATH)) break; 
			//������ȡ����·��
			MyDir dir;
			bool tem = dir.ListDir(path, 1);
			_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), path);
			//������Ŀ¼���뵽���ؼ�
			//�������ļ������뵽LIST�ؼ�
			g_myListView.DeleteAllItem();//��ɾ��LISTVIEW�ؼ���������
			//dir.m_Filelist.
			// g_myTreeView.DeleteItem(hClickItem);
			// g_myTreeView.DeleteAllItem();
			//�����ļ���С����
			dir.m_Filelist.sort(CompareRules);
			//dir.m_Filelist.sort(greater<MyFile>()); 
 			int j = 0;
			for (auto &i : dir.m_Filelist)
			{ 
					g_myTreeView.InsertItem(i.m_szFileName, hClickItem);//�� ����
					g_myListView.InsertItem(j, 0, i.m_szFileName);
					g_myListView.InsertItem(j, 1, i.m_szFiletype); 
					g_myListView.InsertItem_64(j, 2, i.m_qwSize, 10);
					g_myListView.InsertItem(j, 3, i.m_LastWriteTime);
					g_myListView.InsertItem(j, 4, i.m_CreationTime);  
				++j;
			} 
		} 
	}break; 
	case NM_RCLICK:{//�б��Ҽ��˵�
		if (pNmHdr->idFrom == g_myListView.m_dwId)//�ж��Ƿ����б�ؼ������ĵ����Ϣ
		{ 
			//�������˵� POPUPMENU���д��봴���˵�
			g_myListView.m_hMenu = LoadMenu(g_hIns, MAKEINTRESOURCE(IDR_MENU1));
			g_myListView.PopupMenu();
		} 
	}break;
	case NM_DBLCLK:{//�б�˫��
		if (pNmHdr->idFrom == g_myListView.m_dwId)//�ж��Ƿ����б�ؼ������ĵ����Ϣ
		{ 
			// ��ȡListView��ѡ�еĽڵ���ı�
			TCHAR fileName[MAX_PATH];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex, 0, fileName, MAX_PATH);
			//��ȡTREEVIEW�ؼ���ѡ�нڵ���ɵ��ļ�·��
			TCHAR filePath[MAX_PATH] = {0};
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem(), filePath, MAX_PATH);

			if (filePath ==0)
			{
				_stprintf_s(filePath, MAX_PATH, _T("C:\\%s"), fileName);
			}
			else
			{
				//ƴ�ӳ�����������·��
				_stprintf_s(filePath, MAX_PATH, _T("%s\\%s"), filePath, fileName);
			}
			


			//������ȡ����·��
			MyDir dir;
			bool tem = dir.ListDir(filePath, 1); 
			_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), filePath);
			//������Ŀ¼���뵽���ؼ�
			//�������ļ������뵽LIST�ؼ�
			g_myListView.DeleteAllItem();//��ɾ��LISTVIEW�ؼ���������
			//dir.m_Filelist. 
			//dir.m_Filelist.sort(dir.m_Filelist.begin(), dir.m_Filelist.end(), dir.CompareRules);
			//�����ļ���С����
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

			//������ȡ����·��
			MyDir dir;
			bool tem = dir.ListDir(g_myListView.m_NowPath, 1);
			//_stprintf_s(g_myListView.m_NowPath, MAX_PATH, _T("%s"), filePath);
			//������Ŀ¼���뵽���ؼ�
			//�������ļ������뵽LIST�ؼ�
			g_myListView.DeleteAllItem();//��ɾ��LISTVIEW�ؼ���������
			//dir.m_Filelist. 
			//dir.m_Filelist.sort(dir.m_Filelist.begin(), dir.m_Filelist.end(), dir.CompareRules);
			//�����ļ���С����
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