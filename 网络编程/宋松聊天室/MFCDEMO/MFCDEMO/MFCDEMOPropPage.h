#pragma once

// MFCDEMOPropPage.h : CMFCDEMOPropPage 属性页类的声明。


// CMFCDEMOPropPage : 有关实现的信息，请参阅 MFCDEMOPropPage.cpp。

class CMFCDEMOPropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCDEMOPropPage)
	DECLARE_OLECREATE_EX(CMFCDEMOPropPage)

// 构造函数
public:
	CMFCDEMOPropPage();

// 对话框数据
	enum { IDD = IDD_PROPPAGE_MFCDEMO };

// 实现
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 消息映射
protected:
	DECLARE_MESSAGE_MAP()
};

