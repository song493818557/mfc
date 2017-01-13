// MFCDEMO.cpp : CMFCDEMOApp 和 DLL 注册的实现。

#include "stdafx.h"
#include "MFCDEMO.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


CMFCDEMOApp theApp;

const GUID CDECL _tlid = { 0xB4778FC4, 0x8620, 0x40EE, { 0x80, 0x81, 0x24, 0x5B, 0xF8, 0x2A, 0x22, 0xEA } };
const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;



// CMFCDEMOApp::InitInstance - DLL 初始化

BOOL CMFCDEMOApp::InitInstance()
{
	BOOL bInit = COleControlModule::InitInstance();

	if (bInit)
	{
		// TODO:  在此添加您自己的模块初始化代码。
	}

	return bInit;
}



// CMFCDEMOApp::ExitInstance - DLL 终止

int CMFCDEMOApp::ExitInstance()
{
	// TODO:  在此添加您自己的模块终止代码。

	return COleControlModule::ExitInstance();
}



// DllRegisterServer - 将项添加到系统注册表

STDAPI DllRegisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(TRUE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}



// DllUnregisterServer - 将项从系统注册表中移除

STDAPI DllUnregisterServer(void)
{
	AFX_MANAGE_STATE(_afxModuleAddrThis);

	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return ResultFromScode(SELFREG_E_TYPELIB);

	if (!COleObjectFactoryEx::UpdateRegistryAll(FALSE))
		return ResultFromScode(SELFREG_E_CLASS);

	return NOERROR;
}
