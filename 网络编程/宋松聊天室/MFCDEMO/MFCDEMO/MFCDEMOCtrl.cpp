// MFCDEMOCtrl.cpp : CMFCDEMOCtrl ActiveX 控件类的实现。

#include "stdafx.h"
#include "MFCDEMO.h"
#include "MFCDEMOCtrl.h"
#include "MFCDEMOPropPage.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCDEMOCtrl, COleControl)

// 消息映射

BEGIN_MESSAGE_MAP(CMFCDEMOCtrl, COleControl)
	ON_MESSAGE(OCM_COMMAND, &CMFCDEMOCtrl::OnOcmCommand)
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()

// 调度映射

BEGIN_DISPATCH_MAP(CMFCDEMOCtrl, COleControl)
	DISP_FUNCTION_ID(CMFCDEMOCtrl, "AboutBox", DISPID_ABOUTBOX, AboutBox, VT_EMPTY, VTS_NONE)
END_DISPATCH_MAP()

// 事件映射

BEGIN_EVENT_MAP(CMFCDEMOCtrl, COleControl)
END_EVENT_MAP()

// 属性页

// TODO:  按需要添加更多属性页。  请记住增加计数!
BEGIN_PROPPAGEIDS(CMFCDEMOCtrl, 1)
	PROPPAGEID(CMFCDEMOPropPage::guid)
END_PROPPAGEIDS(CMFCDEMOCtrl)

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMFCDEMOCtrl, "MFCDEMO.MFCDEMOCtrl.1",
	0xc56a0dbb, 0xa6a0, 0x462c, 0x9f, 0x32, 0xcb, 0x2b, 0x96, 0xaf, 0xb0, 0x9f)

// 键入库 ID 和版本

IMPLEMENT_OLETYPELIB(CMFCDEMOCtrl, _tlid, _wVerMajor, _wVerMinor)

// 接口 ID

const IID IID_DMFCDEMO = { 0x62893BF0, 0x5BF6, 0x4B73, { 0x97, 0xEB, 0x35, 0x60, 0x34, 0x74, 0x86, 0x8B } };
const IID IID_DMFCDEMOEvents = { 0x1795342B, 0x9AFC, 0x4A9C, { 0xBB, 0xAD, 0x2B, 0xCB, 0xA, 0xC6, 0x4B, 0x20 } };

// 控件类型信息

static const DWORD _dwMFCDEMOOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCDEMOCtrl, IDS_MFCDEMO, _dwMFCDEMOOleMisc)

// CMFCDEMOCtrl::CMFCDEMOCtrlFactory::UpdateRegistry -
// 添加或移除 CMFCDEMOCtrl 的系统注册表项

BOOL CMFCDEMOCtrl::CMFCDEMOCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO:  验证您的控件是否符合单元模型线程处理规则。
	// 有关更多信息，请参考 MFC 技术说明 64。
	// 如果您的控件不符合单元模型规则，则
	// 必须修改如下代码，将第六个参数从
	// afxRegApartmentThreading 改为 0。

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


// CMFCDEMOCtrl::CMFCDEMOCtrl - 构造函数

CMFCDEMOCtrl::CMFCDEMOCtrl()
{
	InitializeIIDs(&IID_DMFCDEMO, &IID_DMFCDEMOEvents);
	// TODO:  在此初始化控件的实例数据。
}

// CMFCDEMOCtrl::~CMFCDEMOCtrl - 析构函数

CMFCDEMOCtrl::~CMFCDEMOCtrl()
{
	// TODO:  在此清理控件的实例数据。
}

// CMFCDEMOCtrl::OnDraw - 绘图函数

void CMFCDEMOCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& /* rcInvalid */)
{
	if (!pdc)
		return;

	DoSuperclassPaint(pdc, rcBounds);
}

// CMFCDEMOCtrl::DoPropExchange - 持久性支持

void CMFCDEMOCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO:  为每个持久的自定义属性调用 PX_ 函数。
}


// CMFCDEMOCtrl::OnResetState - 将控件重置为默认状态

void CMFCDEMOCtrl::OnResetState()
{
	COleControl::OnResetState();  // 重置 DoPropExchange 中找到的默认值

	// TODO:  在此重置任意其他控件状态。
}


// CMFCDEMOCtrl::AboutBox - 向用户显示“关于”框

void CMFCDEMOCtrl::AboutBox()
{
	CDialogEx dlgAbout(IDD_ABOUTBOX_MFCDEMO);
	dlgAbout.DoModal();
}


// CMFCDEMOCtrl::PreCreateWindow - 修改 CreateWindowEx 的参数

BOOL CMFCDEMOCtrl::PreCreateWindow(CREATESTRUCT& cs)
{
	cs.lpszClass = _T("BUTTON");
	return COleControl::PreCreateWindow(cs);
}

// CMFCDEMOCtrl::IsSubclassedControl - 这是一个子类控件

BOOL CMFCDEMOCtrl::IsSubclassedControl()
{
	return TRUE;
}

// CMFCDEMOCtrl::OnOcmCommand - 处理命令消息

LRESULT CMFCDEMOCtrl::OnOcmCommand(WPARAM wParam, LPARAM lParam)
{
	WORD wNotifyCode = HIWORD(wParam);

	// TODO:  在此接通 wNotifyCode。

	return 0;
}


// CMFCDEMOCtrl 消息处理程序
