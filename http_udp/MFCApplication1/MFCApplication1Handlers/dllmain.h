// dllmain.h: 模块类的声明。

class CMFCApplication1HandlersModule : public ATL::CAtlDllModuleT< CMFCApplication1HandlersModule >
{
public :
	DECLARE_LIBID(LIBID_MFCApplication1HandlersLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MFCAPPLICATION1HANDLERS, "{319E3B07-CA81-4781-9DFD-00E518C54EF0}")
};

extern class CMFCApplication1HandlersModule _AtlModule;
