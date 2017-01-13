#pragma once
#include "Csocket.h"
class Ctcp
{
public:
	Ctcp();
	~Ctcp();
	//初始化服务器
	bool Init();
	//清理服务器资源
	void Clean();
	//等待客户端链接
	bool Accept();
private:
	SOCKET m_ListenSock;
};

