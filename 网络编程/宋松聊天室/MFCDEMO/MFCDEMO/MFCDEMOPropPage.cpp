// MFCDEMOPropPage.cpp : CMFCDEMOPropPage ����ҳ���ʵ�֡�

#include "stdafx.h"
#include "MFCDEMO.h"
#include "MFCDEMOPropPage.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

IMPLEMENT_DYNCREATE(CMFCDEMOPropPage, COlePropertyPage)

// ��Ϣӳ��

BEGIN_MESSAGE_MAP(CMFCDEMOPropPage, COlePropertyPage)
END_MESSAGE_MAP()

// ��ʼ���๤���� guid

IMPLEMENT_OLECREATE_EX(CMFCDEMOPropPage, "MFCDEMO.MFCDEMOPropPage.1",
	0x262485bc, 0xa4f, 0x416e, 0xbf, 0xe, 0x6f, 0x3f, 0xcd, 0xba, 0x83, 0xb3)

// CMFCDEMOPropPage::CMFCDEMOPropPageFactory::UpdateRegistry -
// ��ӻ��Ƴ� CMFCDEMOPropPage ��ϵͳע�����

BOOL CMFCDEMOPropPage::CMFCDEMOPropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCDEMO_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}

// CMFCDEMOPropPage::CMFCDEMOPropPage - ���캯��

CMFCDEMOPropPage::CMFCDEMOPropPage() :
	COlePropertyPage(IDD, IDS_MFCDEMO_PPG_CAPTION)
{
}

// CMFCDEMOPropPage::DoDataExchange - ��ҳ�����Լ��ƶ�����

void CMFCDEMOPropPage::DoDataExchange(CDataExchange* pDX)
{
	DDP_PostProcessing(pDX);
}

// CMFCDEMOPropPage ��Ϣ�������
