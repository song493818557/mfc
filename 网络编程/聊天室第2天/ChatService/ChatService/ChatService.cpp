// ChatService.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Service.h"
#include "DataBaseCtrl.h"
#include "MySocket.h"


int main()
{
	CService server;
	/*CDataBaseCtrl dataBase;
	dataBase.LinkDataBase("���������ݿ�.udl");
	RESULT re;
	dataBase.ExeSqlByRecordSet(re, string("INSERT INTO user_data(user_name,user_password) VALUES(\"haha\",\"hehe\")"));*/
	if (!server.Init()) return 0;
	// �������ݿ�
	CMySocket::pDataBase->LinkDataBase("���������ݿ�.udl");
	printf("�����������ɹ���\n�ȴ��ͻ�������...\n");
	server.Accept();
    return 0;
}

