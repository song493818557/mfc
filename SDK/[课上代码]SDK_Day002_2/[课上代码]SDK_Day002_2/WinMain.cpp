#include <windows.h>
#include <tchar.h>

COLORREF DialogColor();
void DialogFont();
void DialogPath();
void DialogPrint();

int APIENTRY WinMain(_In_ HINSTANCE hInstance ,
					 _In_opt_ HINSTANCE hPrevInstance ,
					 _In_ LPSTR lpCmdLine ,
					 _In_ int nShowCmd)
{
	// 颜色选择对话框
	DialogColor();
	// 字体选择对话框
	DialogFont();
	// 路径选择对话框
	DialogPath();
	// 打印对话框
	DialogPrint();
}


//颜色选择对话框
COLORREF DialogColor()
{
	static CHOOSECOLOR cc;
	static COLORREF    crCustColors[ 16 ];

	cc.lStructSize = sizeof(CHOOSECOLOR);
	cc.hwndOwner = NULL;
	cc.hInstance = NULL;
	cc.rgbResult = RGB(0x80 , 0x80 , 0x80);
	cc.lpCustColors = crCustColors;
	cc.Flags = CC_RGBINIT | CC_FULLOPEN;
	cc.lCustData = 0;
	cc.lpfnHook = NULL;
	cc.lpTemplateName = NULL;

	if(ChooseColor(&cc))
	{
		//选择了颜色
		int a = 3;
		TCHAR buff[ 20 ];
		_stprintf_s(buff , _T("%06X") , cc.rgbResult);
		MessageBox(NULL , buff , _T("用户选择的颜色为:") , 0);
	}

	return cc.rgbResult;
}

//字体选择对话框
void DialogFont()
{
	static CHOOSEFONT cf;
	static int        cyChar;
	static LOGFONT    lf;
	GetObject(GetStockObject(SYSTEM_FONT) , sizeof(lf) , &lf);
	cf.lStructSize = sizeof(CHOOSEFONT);
	cf.hwndOwner = NULL; //hwnd
	cf.hDC = NULL;
	cf.lpLogFont = &lf;
	cf.iPointSize = 0;
	cf.Flags = CF_INITTOLOGFONTSTRUCT | CF_SCREENFONTS | CF_EFFECTS;
	cf.rgbColors = 0;
	cf.lCustData = 0;
	cf.lpfnHook = NULL;
	cf.lpTemplateName = NULL;
	cf.hInstance = NULL;
	cf.lpszStyle = NULL;
	cf.nFontType = 0;
	cf.nSizeMin = 0;
	cf.nSizeMax = 0;

	if(ChooseFont(&cf))
	{
		//利用修改的字体，刷新整个窗口
		//InvalidateRect(hwnd, NULL, TRUE); 
	}
}

//路径选择对话框(常用于：打开，保存)
void DialogPath()
{
	TCHAR strFileName[ MAX_PATH ] = TEXT("");
	TCHAR strPath[ MAX_PATH ] = TEXT("");

	OPENFILENAME ofn = 
	{ 
		sizeof(OPENFILENAME) , 
		NULL , 
		NULL ,
		TEXT("text Files\0*.txt\0All Files\0*.*\0 \0") , 
		NULL ,
		0 , 
		1 , 
		strFileName , /*对话框获取到的保存路径*/
		MAX_PATH , 
		NULL , 
		0 , 
		strPath ,
		TEXT("对话框的标题") ,
		OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST |OFN_HIDEREADONLY | OFN_NOREADONLYRETURN , 
		0 , 
		0 ,
		TEXT(".txt") ,   //默认后缀（自定义）
		0 , NULL , NULL 
	};

	// 获取保存路径
	if(!GetSaveFileName(&ofn))//
	{
		MessageBox(0 , strFileName , 0 , 0);
	}

	// 获取打开的文件路径
	if(GetOpenFileName(&ofn))
	{
		MessageBox(0 , strFileName , 0 , 0);
	}

}

//打印对话框
void DialogPrint()
{
	static PRINTDLG pd = { sizeof(PRINTDLG) };
	pd.hwndOwner = NULL;//hwnd
	pd.Flags = PD_RETURNDC | PD_NOPAGENUMS | PD_NOSELECTION;

	if(!PrintDlg(&pd)) {
		return;//弹出打印框
	}
	else {
		//在 pd.hdc 内设置 打印内容

		//.....
	}
}