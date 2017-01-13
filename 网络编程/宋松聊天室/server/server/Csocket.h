#pragma once 
#include "Cmysql.h"
#include "Cbase64.h"
using std::vector;
using std::cin;
class Csocket
{
public:
	Csocket();
	Csocket(SOCKET sock, sockaddr_in addr);
	~Csocket();
	//创建线程 专门用于接受客户端信息
	bool RecvSocket();
	//接受消息的线程
	static DWORD WINAPI recvThread(_In_ LPVOID lpParameter); //加一个指针
	//删除sock
	 void DeleteSock();
	//通知下线
	 void Leave();
	//发送消息,用于通知其他客户端的上下线,排除sock
	 void SendSockMessage(MESSAGE &message,SOCKET sock = INVALID_SOCKET);
	//分发消息
	 int MyDispatchMessage(MESSAGE &message);
	 //reg 2
	 int Createnewuser(MESSAGE &message);
	 //login 3
	 int userlogin(MESSAGE &message);
	 //anonymous 4
	 void anonymous(string name = "123");
	 //搜索用户
	 void searchuser(MESSAGE &message);
	 //添加好友
	 void Addfriend(MESSAGE &message);

	 //1V1私聊
	 void Vchat(MESSAGE &message);
	 //查询所有在线用户
	  void Alluser(MESSAGE &message);
	 static string Allsuser();
	 //自定义CMD命令
	 static void Acmd();
	 //自定义SQL查询
	 static void Defsql(string sql);
	 //转发文件
	 void pushfile(MESSAGE &message);
	
public: 
	SOCKET m_sock;//SOCKET 保存信息
	Cbase64 base;//
	sockaddr_in m_addr;
	char m_name[NAMELENGTH];//用户昵称?
	static Cmysql *db;
	static vector<Csocket*> vecClientSock;//存放所有的客户端连接信息
};

