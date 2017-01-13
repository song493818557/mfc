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
	// 创建线程，专门用于接收客户端消息
	bool RecvSocket();
	// 接收消息的线程
	static DWORD WINAPI RecvThread(_In_ LPVOID lpParameter);
	// 删除sock
	void DeleteSock();
	// 下线
	void Leave();
	// 发送消息,用于通知其他客户端的上下线,排除sock
	void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	// 分发消息
	INT MyDispatchMessage(MESSAGE &message);
	// 匿名聊天 name默认值为nullptr，表示由服务器给客户端分配名字，否则客户端自己分配、注册或登录用
	void OnMessageAnonymous(CHAR* name = nullptr);
	// 注册账户
	INT OnMessageReg(MESSAGE &message);
	// 登录账户
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

