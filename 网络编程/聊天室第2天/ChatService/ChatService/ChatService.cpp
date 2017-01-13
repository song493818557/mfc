// ChatService.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Service.h"
#include "DataBaseCtrl.h"
#include "MySocket.h"


int main()
{
	CService server;
	/*CDataBaseCtrl dataBase;
	dataBase.LinkDataBase("聊天室数据库.udl");
	RESULT re;
	dataBase.ExeSqlByRecordSet(re, string("INSERT INTO user_data(user_name,user_password) VALUES(\"haha\",\"hehe\")"));*/
	if (!server.Init()) return 0;
	// 连接数据库
	CMySocket::pDataBase->LinkDataBase("聊天室数据库.udl");
	printf("启动服务器成功！\n等待客户端连接...\n");
	server.Accept();
    return 0;
}

