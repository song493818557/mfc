// MFCDEMOCtrl.cpp : CMFCDEMOCtrl ActiveX �ؼ����ʵ�֡�

#include "stdafx.h"
#include "MFCDEMO.h"
#include "MFCDEMOCtrl.h"
#include "MFCDEMOPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCDEMOCtrl, COleControl)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMFCDEMOCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CMFCDEMOCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// ����ӳ��

BEGIN_DISPATCH_MAP(CMFCDEMOCtrl, COleControl)
	DISP_FUNCTION_ID(CMFCDEMOCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// �¼�ӳ��

BEGIN_EVENT_MAP(CMFCDEMOCtrl, COleControl)
END_EVENT_MAP()

// ����ҳ

// TODO:  ����Ҫ��Ӹ�������ҳ��  ���ס���Ӽ���!
BEGIN_PROPPAGEIDS(CMFCDEMOCtrl, 1)
	PROPPAGEID(CMFCDEMOPropPage::guid)
END_PROPPAGEIDS(CMFCDEMOCtrl)

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMFCDEMOCtrl, "MFCDEMO.MFCDEMOCtrl.1",
	0xc56a0dbb, 0xa6a0, 0x462c, 0x9f, 0x32, 0xcb, 0x2b, 0x96, 0xaf, 0xb0, 0x9f)

// ����� ID �Ͱ汾

IMPLEMENT_OLETYPELIB(CMFCDEMOCtrl, _tlid, _wVerMajor, _wVerMinor)

// �ӿ� ID

const IID IID_DMFCDEMO = { 0x62893BF0, 0x5BF6, 0x4B73, { 0x97, 0xEB, 0x35, 0x60, 0x34, 0x74, 0x86, 0x8B } };
const IID IID_DMFCDEMOEvents = { 0x1795342B, 0x9AFC, 0x4A9C, { 0xBB, 0xAD, 0x2B, 0xCB, 0xA, 0xC6, 0x4B, 0x20 } };

// �ؼ�������Ϣ

static const DWORD _dwMFCDEMOOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCDEMOCtrl, IDS_MFCDEMO, _dwMFCDEMOOleMisc)

// CMFCDEMOCtrl::CMFCDEMOCtrlFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMFCDEMOCtrl ��ϵͳע�����

BOOL CMFCDEMOCtrl::CMFCDEMOCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  ��֤���Ŀؼ��Ƿ���ϵ�Ԫģ���̴߳������
	// �йظ�����Ϣ����ο� MFC ����˵�� 64��
	// ������Ŀؼ������ϵ�Ԫģ�͹�����
	// �����޸����´��룬��������������
	// afxRegApartmentThreading ��Ϊ 0��

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCDEMO,
			IDB_MFCDEMO,
			afxRegApartmentThreading,
			_dwMFCDEMOOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


// CMFCDEMOCtrl::CMFCDEMOCtrl - ���캯��

CMFCDEMOCtrl::CMFCDEMOCtrl()
{
	InitializeIIDs(&IID_DMFCDEMO, &IID_DMFCDEMOEvents);
	// TODO:  �ڴ˳�ʼ���ؼ���ʵ�����ݡ�
}

// CMFCDEMOCtrl::~CMFCDEMOCtrl - ��������

CMFCDEMOCtrl::~CMFCDEMOCtrl()
{
	// TODO:  �ڴ�����ؼ���ʵ�����ݡ�
}

// CMFCDEMOCtrl::OnDraw - ��ͼ����

void CMFCDEMOCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}

// CMFCDEMOCtrl::DoPropExchange - �־���֧��

void CMFCDEMOCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  Ϊÿ���־õ��Զ������Ե��� PX_ ������
}


// CMFCDEMOCtrl::OnResetState - ���ؼ�����ΪĬ��״̬

void CMFCDEMOCtrl::OnResetState()
{
	COleControl::OnResetState();  // ���� DoPropExchange ���ҵ���Ĭ��ֵ

	// TODO:  �ڴ��������������ؼ�״̬��
}


// CMFCDEMOCtrl::AboutBox - ���û���ʾ�����ڡ���

void CMFCDEMOCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCDEMO);
	dlgAbout.DoModal();
}


// CMFCDEMOCtrl::PreCreateWindow - �޸� CreateWindowEx �Ĳ���

BOOL CMFCDEMOCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}

// CMFCDEMOCtrl::IsSubclassedControl - ����һ������ؼ�

BOOL CMFCDEMOCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CMFCDEMOCtrl::OnOcmCommand - ����������Ϣ

LRESULT CMFCDEMOCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  �ڴ˽�ͨ wNotifyCode��

	return 0;
}


// CMFCDEMOCtrl ��Ϣ�������
