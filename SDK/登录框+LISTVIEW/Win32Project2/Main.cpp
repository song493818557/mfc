#include <windows.h>
#include "resource.h"
#include <tchar.h>  
#define  DRAW_LINE 1 //直线
#define  DRAW_ELLI 2 //椭圆
#define  DRAW_RECT 3 //矩形

INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
DWORD  g_dwChoose;//当前选择的几何图案 1=>直线

POINT g_begPos; //开始坐标
POINT g_endPos; //结束坐标
HDC g_hMemDC; //内存兼容DC
HDC g_hClientDC; //窗口客户区DC

INT_PTR CALLBACK WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd){

	DialogBox(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DlgProc); 
}
VOID CALLBACK OnInitDialog(HWND hWnd){
	
	HWND radio = GetDlgItem(hWnd, IDC_RADIO1);
	//设置单选按钮界面上的效果
	SendMessage(radio, BM_SETCHECK, 1, 0);
	//发送单选按钮时间消息
	SendMessage(hWnd, WM_COMMAND, MAKEWPARAM(IDC_RADIO1, 0), (LPARAM)radio);
	g_hClientDC = GetDC(hWnd);//窗口客户区DC
	g_hMemDC = CreateCompatibleDC(g_hClientDC); //将窗口客户区复制一份到内存DC
	RECT rt;
	GetClientRect(hWnd, &rt);
	HBITMAP hBitmap = CreateCompatibleBitmap(g_hClientDC, rt.right, rt.bottom);
	//将内存兼容位图选入到内存兼容DC中 
	//如果内存兼容DC上没有内存兼容位图  是无法直接在上面绘制图案的
	SelectObject(g_hMemDC, hBitmap);
	//创建一个画刷
	//把画刷选入内存兼容DC中
	HBRUSH hBrush = CreateSolidBrush(RGB(255, 255, 255));
	//将画刷选入到内存兼容DC中
	SelectObject(g_hMemDC, hBrush);

	//使用画矩形的函数 将内存兼容DC的背景刷一遍 
	//在画矩形的搓额很难过中 函数会使用内存兼容DC中已有的GDI对象
	//来填充内存
	Rectangle(g_hMemDC, 10, 10, rt.right, rt.bottom);

}
INT_PTR CALLBACK DlgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	static bool bIsLbuttonDowm = false;
	switch (uMsg)
	{
		
			case WM_INITDIALOG:{
				OnInitDialog(hWnd);
			}break; 
			case  WM_COMMAND:{
				switch (LOWORD(wParam))  //判断发出的WM_COMMAND的窗口ID
				{
				case IDC_RADIO1:g_dwChoose = DRAW_LINE; break; 
				case IDC_RADIO2:g_dwChoose = DRAW_ELLI; break;
				case IDC_RADIO3:g_dwChoose = DRAW_RECT; break;
				}
			}break;
			case WM_LBUTTONDOWN:{
				bIsLbuttonDowm = true;
				g_begPos.x = LOWORD(lParam);
				g_begPos.y = HIWORD(lParam);

			}break;
			case WM_MOUSEMOVE:{
				if (bIsLbuttonDowm)
				{
					g_endPos.x = LOWORD(lParam);
					g_endPos.y = HIWORD(lParam);
					//获取客户区的大小
					RECT rt;
					GetClientRect(hWnd, &rt);

					// 将内存DC的内容拷贝到窗口DC中
					BitBlt(g_hClientDC,/*目标DC*/
						0, 0, /*开始坐标*/
						rt.right, rt.bottom,/*高和宽*/
						g_hMemDC,  /*源DC*/
						0, 0,/*源DC被拷贝的开始坐标*/
						SRCCOPY/*只拷贝的标志*/
						);
					MoveToEx(g_hClientDC, g_begPos.x, g_begPos.y, 0);
					LineTo(g_hClientDC, g_endPos.x, g_endPos.y);
				} 
			}break;
			case WM_LBUTTONUP:{
				bIsLbuttonDowm = FALSE;
				g_endPos.x = LOWORD(lParam);
				g_endPos.y = HIWORD(lParam);
				//现在窗口DC上进行绘制
				switch (g_dwChoose)
				{ 
				case DRAW_LINE:
					//先画出直线
				{
					MoveToEx(g_hClientDC, g_begPos.x, g_begPos.y, 0);
					LineTo(g_hClientDC, g_endPos.x, g_endPos.y); }
					break;
				case DRAW_RECT: Rectangle(g_hClientDC, g_begPos.x, g_begPos.y, g_endPos.x, g_endPos.y); break;

				case DRAW_ELLI:{
					HBRUSH hBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
					SelectObject(g_hClientDC, hBrush);
					Ellipse(g_hClientDC, g_begPos.x, g_begPos.y, g_endPos.x, g_endPos.y);
				} break;
				}
				RECT rt;
				GetClientRect(hWnd, &rt);
				// 将内存DC的内容拷贝到窗口DC中
				BitBlt(g_hMemDC,/*目标DC*/
					0, 0, /*开始坐标*/
					rt.right, rt.bottom,/*高和宽*/
					g_hClientDC,  /*源DC*/
					0, 0,/*源DC被拷贝的开始坐标*/
					SRCCOPY/*只拷贝的标志*/
					);
				//将有效区域全部变为无效
				InvalidateRect(hWnd, NULL, FALSE);
			
			}break;
			case WM_PAINT:{
				PAINTSTRUCT ps = { 0 };
				//获取无效区域
				BeginPaint(hWnd,&ps);
				RECT rt;
				//获取客户区大小
				GetClientRect(hWnd, &rt);
				//将内存DC的内容拷贝到窗口DC中
				BitBlt(g_hClientDC,/*目标DC*/
					0, 0, /*开始坐标*/
					rt.right, rt.bottom,/*高和宽*/
					g_hMemDC,  /*源DC*/
					0, 0,/*源DC被拷贝的开始坐标*/
					SRCCOPY/*只拷贝的标志*/
					);
				//将无效区域全部变为有效
				EndPaint(hWnd, &ps);

			}break;
			case  WM_DESTROY:{
				//释放DC
				DeleteDC(g_hMemDC); //内存DC
				ReleaseDC(hWnd, g_hMemDC);//客户端窗口DC
			}break;
			case WM_CLOSE:{
				EndDialog(hWnd, 0);  
			}break;
			default: return FALSE;  
	}
	return true;
}