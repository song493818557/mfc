#pragma once 
#include "MySocket.h" 

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

