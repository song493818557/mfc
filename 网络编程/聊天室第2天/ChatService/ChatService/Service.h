#pragma once

#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")

class CService
{
public:
	CService();
	~CService();
	// ��ʼ��������
	bool Init();
	// �����������Դ
	void Clean();
	// �ȴ��ͻ�������
	bool Accept();
protected:
	SOCKET m_ListenSock;
};

