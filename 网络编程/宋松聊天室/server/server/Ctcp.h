#pragma once
#include "Csocket.h"
class Ctcp
{
public:
	Ctcp();
	~Ctcp();
	//��ʼ��������
	bool Init();
	//�����������Դ
	void Clean();
	//�ȴ��ͻ�������
	bool Accept();
private:
	SOCKET m_ListenSock;
};

