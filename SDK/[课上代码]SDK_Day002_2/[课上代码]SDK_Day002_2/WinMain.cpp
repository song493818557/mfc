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
	// ��ɫѡ��Ի���
	DialogColor();
	// ����ѡ��Ի���
	DialogFont();
	// ·��ѡ��Ի���
	DialogPath();
	// ��ӡ�Ի���
	DialogPrint();
}


//��ɫѡ��Ի���
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
		//ѡ������ɫ
		int a = 3;
		TCHAR buff[ 20 ];
		_stprintf_s(buff , _T("%06X") , cc.rgbResult);
		MessageBox(NULL , buff , _T("�û�ѡ�����ɫΪ:") , 0);
	}

	return cc.rgbResult;
}

//����ѡ��Ի���
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
		//�����޸ĵ����壬ˢ����������
		//InvalidateRect(hwnd, NULL, TRUE); 
	}
}

//·��ѡ��Ի���(�����ڣ��򿪣�����)
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
		strFileName , /*�Ի����ȡ���ı���·��*/
		MAX_PATH , 
		NULL , 
		0 , 
		strPath ,
		TEXT("�Ի���ı���") ,
		OFN_OVERWRITEPROMPT | OFN_PATHMUSTEXIST |OFN_HIDEREADONLY | OFN_NOREADONLYRETURN , 
		0 , 
		0 ,
		TEXT(".txt") ,   //Ĭ�Ϻ�׺���Զ��壩
		0 , NULL , NULL 
	};

	// ��ȡ����·��
	if(!GetSaveFileName(&ofn))//
	{
		MessageBox(0 , strFileName , 0 , 0);
	}

	// ��ȡ�򿪵��ļ�·��
	if(GetOpenFileName(&ofn))
	{
		MessageBox(0 , strFileName , 0 , 0);
	}

}

//��ӡ�Ի���
void DialogPrint()
{
	static PRINTDLG pd = { sizeof(PRINTDLG) };
	pd.hwndOwner = NULL;//hwnd
	pd.Flags = PD_RETURNDC | PD_NOPAGENUMS | PD_NOSELECTION;

	if(!PrintDlg(&pd)) {
		return;//������ӡ��
	}
	else {
		//�� pd.hdc ������ ��ӡ����

		//.....
	}
}