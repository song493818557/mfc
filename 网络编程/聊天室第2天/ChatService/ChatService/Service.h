#pragma once

#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

class CService
{
public:
	CService();
	~CService();
	// 初始化服务器
	bool Init();
	// 清理服务器资源
	void Clean();
	// 等待客户端连接
	bool Accept();
protected:
	SOCKET m_ListenSock;
};

