// MFCDEMOPropPage.cpp : CMFCDEMOPropPage 属性页类的实现。

#include "stdafx.h"
#include "MFCDEMO.h"
#include "MFCDEMOPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCDEMOPropPage, COlePropertyPage)

// 消息映射

BEGIN_MESSAGE_MAP(CMFCDEMOPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// 初始化类工厂和 guid

IMPLEMENT_OLECREATE_EX(CMFCDEMOPropPage, "MFCDEMO.MFCDEMOPropPage.1",
	0x262485bc, 0xa4f, 0x416e, 0xbf, 0xe, 0x6f, 0x3f, 0xcd, 0xba, 0x83, 0xb3)

// CMFCDEMOPropPage::CMFCDEMOPropPageFactory::UpdateRegistry -
// 添加或移除 CMFCDEMOPropPage 的系统注册表项

BOOL CMFCDEMOPropPage::CMFCDEMOPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCDEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCDEMOPropPage::CMFCDEMOPropPage - 构造函数

CMFCDEMOPropPage::CMFCDEMOPropPage() :
	COlePropertyPage(IDD, IDS_MFCDEMO_PPG_CAPTION)
{
}

// CMFCDEMOPropPage::DoDataExchange - 在页和属性间移动数据

void CMFCDEMOPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCDEMOPropPage 消息处理程序
