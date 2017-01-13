#pragma once

// MFCDEMOCtrl.h : CMFCDEMOCtrl ActiveX 控件类的声明。


// CMFCDEMOCtrl : 有关实现的信息，请参阅 MFCDEMOCtrl.cpp。

class CMFCDEMOCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCDEMOCtrl)

// 构造函数
public:
	CMFCDEMOCtrl();

// 重写
public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();

// 实现
protected:
	~CMFCDEMOCtrl();

	DECLARE_OLECREATE_EX(CMFCDEMOCtrl)    // 类工厂和 guid
	DECLARE_OLETYPELIB(CMFCDEMOCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCDEMOCtrl)     // 属性页 ID
	DECLARE_OLECTLTYPE(CMFCDEMOCtrl)		// 类型名称和杂项状态

	// 子类控件支持
	BOOL IsSubclassedControl();
	LRESULT OnOcmCommand(WPARAM wParam, LPARAM lParam);

// 消息映射
	DECLARE_MESSAGE_MAP()

// 调度映射
	DECLARE_DISPATCH_MAP()

	afx_msg void AboutBox();

// 事件映射
	DECLARE_EVENT_MAP()

// 调度和事件 ID
public:
	enum {
	};
};

