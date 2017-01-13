#include <windows.h>
#include <tchar.h>
#include "resource.h"

// 导入通用控件的头文件
#include <commctrl.h>
// 导入通用控件的静态库
#pragma comment(lib,"Comctl32.lib")

INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam);

int WINAPI WinMain(_In_ HINSTANCE hInstance , _In_opt_ HINSTANCE hPrevInstance , _In_ LPSTR lpCmdLine , _In_ int nShowCmd)
{
	// 弹出资源中的对话框
	DialogBox(hInstance ,
			  MAKEINTRESOURCE(IDD_DIALOG1) ,
			  NULL ,
			  DlgProc
			  );
}

const TCHAR* MyGetDriveType(const TCHAR* pDriveBuff)
{
	UINT uType = GetDriveType(pDriveBuff);
	const TCHAR* pType = NULL;
	switch(uType)
	{
		case DRIVE_NO_ROOT_DIR:pType = _T("无效的根路径"); break;
		case DRIVE_REMOVABLE:pType = _T("可移动磁盘 "); break;
		case DRIVE_FIXED:pType = _T("硬盘 "); break;
		case DRIVE_REMOTE:pType = _T("网络磁盘"); break;
		case DRIVE_CDROM:
		{
			pType = _T(" 光盘驱动器 ");
			GetVolumeInformation(pDriveBuff , 0 , 0 , 0 , 0 , 0 , 0 , 0);
			if(21 == GetLastError()) // 获取最后的错误信息
			{
				pType = _T("光盘驱动器(无光盘)");
			}
			else
				pType = _T("光盘驱动器(有光盘)");
			//printf("(%s光盘)" , 21==GetLastError()?"无":"有");
		}
		break;
		case DRIVE_RAMDISK:pType = _T("RAM磁盘"); break;
		case DRIVE_UNKNOWN:pType = _T("未知驱动器"); break;
	}

	return pType;
}


INT_PTR CALLBACK DlgProc(HWND hWnd , UINT uMsg , WPARAM wParam , LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_INITDIALOG: // 响应对话框初始化消息
		{
			// 初始化通用控件
			InitCommonControls();

			// 初始化ListView控件
		    // 盘符 | 卷的标题 | 文件系统 | 剩余空间 | 总空间 | 驱动器类型

			// 获取ListView控件的窗口句柄
			HWND hListView = GetDlgItem(hWnd , IDC_LIST1);

			// 设置扩展风格
			ListView_SetExtendedListViewStyle(hListView , LVS_EX_FULLROWSELECT);
			
			LV_COLUMN column = { 0 };

			// 说明结构体中的哪个字段是有效的
			column.mask = LVCF_TEXT|LVCF_WIDTH|LVCF_FMT;
			column.fmt = LVCFMT_LEFT; // 文字左对齐
			column.cx = 40; // 宽度
			column.pszText = _T("盘符");
			ListView_InsertColumn(hListView , 0 , &column);

			column.cx = 80; // 宽度
			column.pszText = _T("卷的标题");
			ListView_InsertColumn(hListView ,1 , &column);

			column.cx = 60; // 宽度
			column.pszText = _T("文件系统");
			ListView_InsertColumn(hListView , 2 , &column);

			column.cx = 100; // 宽度
			column.pszText = _T("剩余空间");
			ListView_InsertColumn(hListView , 3 , &column);

			column.cx = 100; // 宽度
			column.pszText = _T("总空间");
			ListView_InsertColumn(hListView , 4 , &column);

			column.cx = 100; // 宽度
			column.pszText = _T("驱动器类型");
			ListView_InsertColumn(hListView , 5 , &column);


			// 获取所有驱动器
			TCHAR driveBuff[ MAX_PATH ];
			GetLogicalDriveStrings(MAX_PATH , driveBuff);

			TCHAR *pDriveBuff = driveBuff;
			LV_ITEM item = { 0 };
			item.mask = LVIF_TEXT;

			TCHAR volumeName[ MAX_PATH ];
			TCHAR fileSystemName[ 50 ];

			do 
			{
				*pDriveBuff;
				// 插入盘符
				item.pszText = pDriveBuff; // 将盘符缓冲区首地址赋值
				ListView_InsertItem(hListView , &item);

				GetVolumeInformation(pDriveBuff ,
									 volumeName , MAX_PATH ,
									 0 , 0 , 0 ,
									 fileSystemName , 50);
				
				// 将卷的标题,和卷的文件系统设置到当前行的节点上
				ListView_SetItemText(hListView , item.iItem , 1 , volumeName);
				ListView_SetItemText(hListView , item.iItem , 2 , fileSystemName);

				// 驱动器空间信息
				// 总空间信息, 剩余的空间信息
				DWORD dwSectorsPerCluster ;
				DWORD dwBytesPerSector;
				DWORD dwNumberOfFreeClusters ;
				DWORD dwTotalNumberOfClusters;
				GetDiskFreeSpace(pDriveBuff ,
								 &dwSectorsPerCluster ,// 每簇扇区数
								 &dwBytesPerSector , // 每个扇区的字节数
								 &dwNumberOfFreeClusters ,// 剩余空间的簇的个数
								 &dwTotalNumberOfClusters// 总空间的簇的个数
								 );

				// 计算出剩余空间的字节数
				UINT64 freeByte = 1;
				freeByte = dwNumberOfFreeClusters;
				freeByte *= dwSectorsPerCluster;
				freeByte *= dwBytesPerSector;
				// 计算出总空间的字节数
				UINT64 totalByte = 1;
				totalByte = dwTotalNumberOfClusters;
				totalByte *= dwSectorsPerCluster;
				totalByte *= dwBytesPerSector;

				TCHAR buff[ 50 ];
				// 将整形的值转换成字符串
				_stprintf_s(buff , 50 , _T("%I64d") , freeByte);
				// 将剩余空间字节数插入到listview
				ListView_SetItemText(hListView , item.iItem , 3 , buff);

				// 将整形的值转换成字符串
				_stprintf_s(buff , 50 , _T("%I64d") , totalByte);
				// 将剩余空间字节数插入到listview
				ListView_SetItemText(hListView , item.iItem , 4 , buff);

				// 获取驱动器类型
				const TCHAR* pType = MyGetDriveType(pDriveBuff);
				ListView_SetItemText(hListView , item.iItem , 5 , (TCHAR*)pType);


				pDriveBuff += 4;
				item.iItem++; // 递增以插入到第二行;
			} while(*pDriveBuff);
		}
		break;

		case WM_CLOSE:
			EndDialog(hWnd , 0);

		default: return FALSE;
			break;
	}
	return TRUE;
}

