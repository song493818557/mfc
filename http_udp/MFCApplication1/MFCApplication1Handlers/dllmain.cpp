// dllmain.cpp: DllMain 的实现。

#include "stdafx.h"
#include "resource.h"
#include "MFCApplication1Handlers_i.h"
#include "dllmain.h"
#include "xdlldata.h"

CMFCApplication1HandlersModule _AtlModule;

class CMFCApplication1HandlersApp : public CWinApp
{
public:

// 重写
	virtual BOOL InitInstance();
	virtual int ExitInstance();

	DECLARE_MESSAGE_MAP()
};

BEGIN_MESSAGE_MAP(CMFCApplication1HandlersApp, CWinApp)
END_MESSAGE_MAP()

CMFCApplication1HandlersApp theApp;

BOOL CMFCApplication1HandlersApp::InitInstance()
{
	if (!PrxDllMain(m_hInstance, DLL_PROCESS_ATTACH, NULL))
		return FALSE;
	return CWinApp::InitInstance();
}

int CMFCApplication1HandlersApp::ExitInstance()
{
	return CWinApp::ExitInstance();
}
