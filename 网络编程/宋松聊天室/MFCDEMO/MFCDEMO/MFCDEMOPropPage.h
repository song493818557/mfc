#pragma once

// MFCDEMOPropPage.h : CMFCDEMOPropPage ����ҳ���������


// CMFCDEMOPropPage : �й�ʵ�ֵ���Ϣ������� MFCDEMOPropPage.cpp��

class CMFCDEMOPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCDEMOPropPage)
	DECLARE_OLECREATE_EX(CMFCDEMOPropPage)

// ���캯��
public:
	CMFCDEMOPropPage();

// �Ի�������
	enum { IDD = IDD_PROPPAGE_MFCDEMO };

// ʵ��
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ��Ϣӳ��
protected:
	DECLARE_MESSAGE_MAP()
};

