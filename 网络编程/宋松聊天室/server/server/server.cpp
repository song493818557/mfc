// server.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Ctcp.h"

DWORD WINAPI main_menu(_In_ LPVOID lpParameter){
	Ctcp server;
	if (!server.Init()) return 0; 
	//printf("�����������ɹ���\n�ȴ��ͻ�������...\n");
	server.Accept();
	//read_map(); Ⱥ����UI
	//draw_map(); 

	return 0;
}
int main()
{ 
	Csocket::db->LinkDataBase1();  
	//char strLink[MAX_PATH] = { 0 };
	//sprintf_s(strLink, MAX_PATH, "select * from  userdata where  uuser ='dassaa'");
	//_RESULT result; 
	////"select * from  userdata where  uuser ='dassaa'"
	////insert INSERT into user_data(user_name,user_password) VALUES(\"grfde\",\"dedwe\")
	//int temp = Csocket::db->ExeSqlByRecordSet(result, strLink);
	////menu.main_menu(1);
	//�����˵��߳�
	CreateThread(
		NULL, NULL, main_menu, (LPVOID)1, NULL, NULL);
//	WriteChar(28, 15, "�����������ɹ���", WALL1_DC);
	bool bCheck = true;
	Cmenu menu;
	menu.main_draw();
	while (bCheck)
	{
		bCheck = menu.main_menu((LPVOID)1);
		 
	}

	return 0;
}

