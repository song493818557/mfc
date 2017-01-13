#pragma once
#include "Message.h"
using std::vector;


class CMySocket
{
public:
	CMySocket();
	~CMySocket();
	// �����̣߳�ר�����ڽ��տͻ�����Ϣ
	bool RecvSocket(SOCKET sock, sockaddr_in addr);
	// ������Ϣ���߳�
	static DWORD WINAPI RecvThread(_In_ LPVOID lpParameter);
	// ɾ��sock
	static void DeleteSock(SOCKET sock);
	// ������Ϣ,����֪ͨ�����ͻ��˵�������,�ų�sock
	static void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	// �ַ���Ϣ
	static	DWORD MyDispatchMessage(MESSAGE &message,SOCKET sock);
	// 
protected:
public:
	SOCKET m_sock;
	CHAR   m_name[20];
	static vector<CMySocket> vecClientSock;
};

