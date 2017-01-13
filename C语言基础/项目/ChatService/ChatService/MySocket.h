#pragma once
#include "Message.h"
using std::vector;


class CMySocket
{
public:
	CMySocket();
	~CMySocket();
	// 创建线程，专门用于接收客户端消息
	bool RecvSocket(SOCKET sock, sockaddr_in addr);
	// 接收消息的线程
	static DWORD WINAPI RecvThread(_In_ LPVOID lpParameter);
	// 删除sock
	static void DeleteSock(SOCKET sock);
	// 发送消息,用于通知其他客户端的上下线,排除sock
	static void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	// 分发消息
	static	DWORD MyDispatchMessage(MESSAGE &message,SOCKET sock);
	// 
protected:
public:
	SOCKET m_sock;
	CHAR   m_name[20];
	static vector<CMySocket> vecClientSock;
};

