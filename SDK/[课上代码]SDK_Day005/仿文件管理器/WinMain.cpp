#include <windows.h>
#include "resource.h"
#include "MyListView.h"
#include "MyTreeView.h"
#include <tchar.h>
#include "MyDir.h"

MyListView g_myListView;
MyTreeView g_myTreeView;


// ���ڻص�����
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

// WM_INITDIALOG��ʼ����Ϣ������
void OnInitDaialog(HWND hWnd);

// WM_COMMAND��Ϣ�Ĵ�����
DWORD OnCommand(HWND hWnd  , WPARAM wParam, LPARAM lParam);

// WM_NOTIFY��Ϣ�Ĵ�����
DWORD OnNotify(HWND hWmd , LPARAM lParam);

int APIENTRY WinMain(_In_ HINSTANCE hInstance ,
					 _In_opt_ HINSTANCE hPrevInstance ,
					 _In_ LPSTR lpCmdLine ,
					 _In_ int nShowCmd)
{
	DialogBox(hInstance ,MAKEINTRESOURCE(IDD_DIALOG1) ,NULL ,DlgProc);
}


// �Ի���Ļص�����
INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	// ɸѡ��Ϣ����
	switch(uMsg)
	{
		// ���ڱ���������Ϣ,����ֻ��һ��,�ڵ��ô����Ի���ĺ���֮����������Ϣ 
		case WM_INITDIALOG:
			OnInitDaialog(hWnd);
		break;

		// ��Ӧ�ؼ����ͳ�������Ϣ
		case WM_COMMAND:
			return OnCommand(hWnd , wParam , lParam);

		case WM_NOTIFY:
			return OnNotify(hWnd , lParam);
		
			// ��Ӧ���ڱ��رյ���Ϣ,(�رպ�,����ֻ�Ǳ�����,���̲�û���˳�)
		case WM_CLOSE:
			// �������ٴ��ڵĺ���,����WM_DESTROY��Ϣ
			return DestroyWindow(hWnd);

			//��Ӧ���ڱ����ٵ���Ϣ
		case WM_DESTROY:
			PostQuitMessage(0); // �����˳����̵���Ϣ
			break;
	}

	// �����Ϣû�б�����ֻ�ܷ���FALSE
	return FALSE;
}

// WM_COMMAND��Ϣ�Ĵ�����
DWORD OnCommand(HWND hWnd , WPARAM wParam , LPARAM lParam)
{
	// ����ID�Ĳ�ͬ,������Դ�
	switch(LOWORD(wParam))
	{
		case MENUID_OPEN:
		{
			// ��ȡListView��ѡ�еĽڵ���ı�
			TCHAR fileName[ MAX_PATH ];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

			// ��ȡTreeView�ؼ���ѡ�нڵ���ɵ��ļ�·��
			TCHAR filePath[ MAX_PATH ];
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*��ȡ��ѡ�еĽڵ���*/
									 filePath , MAX_PATH);

			// ƴ�ӳ��������ļ�·��
 			TCHAR param[ MAX_PATH ];
			_stprintf_s(param , MAX_PATH , _T("%s %s\\%s") , _T(" /e,/select, ") , filePath , fileName);
			// ʹ����Դ���������ļ�, ��ѡ���ļ�
			ShellExecute(NULL , L"open" , L"explorer" , param , NULL , SW_SHOW);
		}
		break;

		case MENUID_DELETE:
		{
			// ��ȡListView��ѡ�еĽڵ���ı�
			TCHAR fileName[ MAX_PATH ];
			int nIndex = g_myListView.GetSelectItem();
			g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

			// ��ȡTreeView�ؼ���ѡ�нڵ���ɵ��ļ�·��
			TCHAR filePath[ MAX_PATH ];
			g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*��ȡ��ѡ�еĽڵ���*/
									 filePath , MAX_PATH);

			// ƴ�ӳ��������ļ�·��
			_stprintf_s(filePath , MAX_PATH , _T("%s\\%s") , filePath , fileName);

			// ������ʾ
			if(MessageBox(hWnd , filePath , _T("ȷ��Ҫɾ��?") , MB_OKCANCEL))
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
	// ��ȡ���洰�ڵ����
	GetWindowRect(GetDesktopWindow() , &deskTopRt);
	GetClientRect(hWnd , &dlgRt);

	// �ƶ�����
	SetWindowPos(hWnd , HWND_TOP ,
				 (deskTopRt.right - dlgRt.right) / 2 ,
				 (deskTopRt.bottom - dlgRt.bottom) / 2 ,
				 0 , 0 ,
				 SWP_NOSIZE /*ֻ�ƶ�����,���ı��С*/
				 );


	// ����һ��list�ؼ�
	g_myListView.Create(0x1000 , hWnd , 301 , 0 , 600 , 300);
	// ������չ���
	g_myListView.SetStyle(LVS_REPORT , LVS_EX_FULLROWSELECT);

	// ������
	g_myListView.InsertColumn(0 , _T("����") ,120);
	g_myListView.InsertColumn(1 , _T("����") , 50);
	g_myListView.InsertColumn(2 , _T("��С") , 80);
	g_myListView.InsertColumn(3 , _T("�޸�����") , 145);
	g_myListView.InsertColumn(4 , _T("��������") , 145);

	// ����Tree�ؼ�
	g_myTreeView.Create(0x1001 , hWnd , 0 , 0 , 300 , 300);

	// ��ȡ���е��̷�
	TCHAR szDrivers[ MAX_PATH ];
	GetLogicalDriveStrings(MAX_PATH , szDrivers);
	TCHAR* pTemp = szDrivers;
	// �����е��̷������뵽Tree�ؼ�
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
	// WM_NOTIFY��Ϣ, lParam������LPNMHDR �ṹ��ĵ�ַ
	
	LPNMHDR pNmHdr = (LPNMHDR)lParam;
	
	// �жϾ������Ϣ
	switch(pNmHdr->code)
	{
		case NM_RCLICK: // �Ҽ������¼�
		{
			if(pNmHdr->idFrom == g_myListView.m_dwId) // �жϲ����Ҽ������¼��Ŀؼ�ID�Ƿ���ListView�ؼ�
			{
				// �����˵�
				g_myListView.PopupMenu();
			}
		}
		break;
		case NM_DBLCLK:
		{
			if(pNmHdr->idFrom == g_myListView.m_dwId) // �жϲ����Ҽ������¼��Ŀؼ�ID�Ƿ���ListView�ؼ�
			{
				// ��ȡListView��ѡ�еĽڵ���ı�
				TCHAR fileName[ MAX_PATH ];
				int nIndex = g_myListView.GetSelectItem();
				g_myListView.GetItemText(nIndex , 0 , fileName , MAX_PATH);

				// ��ȡTreeView�ؼ���ѡ�нڵ���ɵ��ļ�·��
				TCHAR filePath[ MAX_PATH ];
				g_myTreeView.GetTreePath(g_myTreeView.GetSelectItem() , /*��ȡ��ѡ�еĽڵ���*/
										 filePath , MAX_PATH);

				// ƴ�ӳ��������ļ�·��
				_stprintf_s(filePath , MAX_PATH , _T("%s\\%s") , filePath , fileName);

				MyDir dir;
				bool tem = dir.ListDir(filePath,1);
				//������Ŀ¼���뵽���ؼ�
				//�������ļ����뵽list�ؼ�
				g_myListView.DeleteAllItem(); // ��ɾ��ListView�ؼ���������
				int j = 0;
				for(auto &i : dir.m_Filelist)
				{
					g_myListView.InsertItem(j , 0 , i.m_szFileName);
					g_myListView.InsertItem(j , 1 , i.m_bIsDir ? _T("�ļ���"):_T("�ļ�"));
					g_myListView.InsertItem_64(j , 2 , i.m_qwSize , 10);
					g_myListView.InsertItem(j , 3 , i.m_LastWriteTime);
					g_myListView.InsertItem(j , 4 , i.m_CreationTime);
					++j;
				}
			}
		}
		break;

		case NM_CLICK:// ����������¼�
		{
			// �ж����ĸ��ؼ���������Ϣ
			if(pNmHdr->idFrom == g_myTreeView.m_dwId) // �жϲ�����Ϣ�Ŀؼ�ID�Ƿ���TreeView�ؼ�
			{
				BOOL bShowDir = TRUE;
				// ��ȡ������ڵ�����
				// ��ȡ·��
				TCHAR path[ MAX_PATH ];
				HTREEITEM hClickItem = g_myTreeView.GetClickItem();
				if(g_myTreeView.GetSubItem(hClickItem , 0) == NULL)
					bShowDir = FALSE;


				if(!g_myTreeView.GetTreePath(hClickItem , path , MAX_PATH))
					break;

				// �������·��, �����õ��ļ���Ϣ���뵽listView�ؼ�.
				MyDir dir;
			bool tem =	dir.ListDir(path,1);


				//������Ŀ¼���뵽���ؼ�
				//�������ļ����뵽list�ؼ�
				g_myListView.DeleteAllItem(); // ��ɾ��ListView�ؼ���������
				int j = 0;
				for(auto &i : dir.m_Filelist)
				{
					if(bShowDir && i.m_bIsDir)
					{
						g_myTreeView.InsertItem(i.m_szFileName , hClickItem);
						g_myListView.InsertItem(j , 0 , i.m_szFileName);
						g_myListView.InsertItem(j , 1 , _T("�ļ���") );
						//g_myListView.InsertItem_64(j , 2 , i.m_qwSize , 10);
						//g_myListView.InsertItem(j , 3 , i.m_LastWriteTime);
						//g_myListView.InsertItem(j , 4 , i.m_CreationTime);
						++j;
					}
					else
					{
						//L"����" , 3
						//L"��С" , 1
						//L"�޸�����"
						//L"��������"
						g_myListView.InsertItem(j , 0 , i.m_szFileName);
						g_myListView.InsertItem(j , 1 , _T("�ļ�"));
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