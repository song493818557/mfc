#pragma once

// MFCDEMOCtrl.h : CMFCDEMOCtrl ActiveX �ؼ����������


// CMFCDEMOCtrl : �й�ʵ�ֵ���Ϣ������� MFCDEMOCtrl.cpp��

class CMFCDEMOCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCDEMOCtrl)

// ���캯��
public:
	CMFCDEMOCtrl();

// ��д
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// ʵ��
protected:
	~CMFCDEMOCtrl();

	DECLARE_OLECREATE_EX(CMFCDEMOCtrl)    // �๤���� guid
	DECLARE_OLETYPELIB(CMFCDEMOCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCDEMOCtrl)     // ����ҳ ID
	DECLARE_OLECTLTYPE(CMFCDEMOCtrl)		// �������ƺ�����״̬

	// ����ؼ�֧��
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// ��Ϣӳ��
	DECLARE_MESSAGE_MAP()

// ����ӳ��
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// �¼�ӳ��
	DECLARE_EVENT_MAP()

// ���Ⱥ��¼� ID
public:
	enum {
	};
};

