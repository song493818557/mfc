#pragma once

// MFCDEMO.h : MFCDEMO.DLL ����ͷ�ļ�

#if !defined( __AFXCTL_H__ )
#error "�ڰ������ļ�֮ǰ������afxctl.h��"
#endif

#include "resource.h"       // ������


// CMFCDEMOApp : �й�ʵ�ֵ���Ϣ������� MFCDEMO.cpp��

class CMFCDEMOApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

