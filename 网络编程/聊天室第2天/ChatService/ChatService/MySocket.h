#pragma once
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#include<vector>
using std::vector;
#include "Message.h"
#include "DataBaseCtrl.h"
#define MESSAGEBUF 1024
class CMySocket
{
public:
	CMySocket();
	CMySocket(SOCKET sock,sockaddr_in addr);
	~CMySocket();
	// �����̣߳�ר�����ڽ��տͻ�����Ϣ
	bool RecvSocket();
	// ������Ϣ���߳�
	static DWORD WINAPI RecvThread(_In_ LPVOID lpParameter);
	// ɾ��sock
	void DeleteSock();
	// ����
	void Leave();
	// ������Ϣ,����֪ͨ�����ͻ��˵�������,�ų�sock
	void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	// �ַ���Ϣ
	INT MyDispatchMessage(MESSAGE &message);
	// �������� nameĬ��ֵΪnullptr����ʾ�ɷ��������ͻ��˷������֣�����ͻ����Լ����䡢ע����¼��
	void OnMessageAnonymous(CHAR* name = nullptr);
	// ע���˻�
	INT OnMessageReg(MESSAGE &message);
	// ��¼�˻�
	INT OnMessageLogin(MESSAGE &message);
	//protected:
public:
	SOCKET m_sock;
	sockaddr_in m_addr;
#define NAMELENGTH 50
	CHAR   m_name[NAMELENGTH];
	static CDataBaseCtrl* pDataBase;
	static vector<CMySocket*> pvecClientSock;
};

