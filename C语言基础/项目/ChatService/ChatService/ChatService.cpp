// ChatService.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "Service.h"
using std::string;
DWORD WINAPI main_menu(_In_ LPVOID lpParameter){
	CService server;
	if (!server.Init()) return 0;
	printf("�����������ɹ���\n�ȴ��ͻ�������...\n");
	server.Accept();
	//read_map(); Ⱥ����UI
	//draw_map(); 
	
	return 0;
}
int main()
{
	string aa= "sdfsfd#fdsfds";
	int cc = aa.find_first_of("#");
	string bb = aa.substr(0, cc);
	string ff = aa.substr(cc+1);
	//Cmenu menu;
	//menu.main_draw();
	////menu.main_menu(1);
	////�����˵��߳�
	//CreateThread(
	//	NULL, NULL, main_menu, (LPVOID)1, NULL, NULL);
	//menu.main_menu((LPVOID)1);
	int aaaaa = 0;
    return 0;
}

