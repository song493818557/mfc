// ChatService.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "Service.h"
using std::string;
DWORD WINAPI main_menu(_In_ LPVOID lpParameter){
	CService server;
	if (!server.Init()) return 0;
	printf("启动服务器成功！\n等待客户端连接...\n");
	server.Accept();
	//read_map(); 群聊室UI
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
	////创建菜单线程
	//CreateThread(
	//	NULL, NULL, main_menu, (LPVOID)1, NULL, NULL);
	//menu.main_menu((LPVOID)1);
	int aaaaa = 0;
    return 0;
}

