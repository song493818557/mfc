#include "stdafx.h"
#include "Cgame.h"
#include <fstream>
#include <stdlib.h>
#include <iostream>
using namespace std;

void Cgame::get_Message(int& nChar)//��ȡ�¼�����
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	
	SetConsoleMode(hStdin, ENABLE_WINDOW_INPUT | ENABLE_MOUSE_INPUT); 
		//�ȴ��¼� 
		ReadConsoleInput(hStdin, &stcRecord, 1, &dwRead);
		//�����¼�
		if (stcRecord.EventType == KEY_EVENT){ 
			KEY_EVENT_RECORD ker = stcRecord.Event.KeyEvent;
			if (ker.bKeyDown){
				nChar = ker.wVirtualKeyCode;
				return;
			}
		}
	return ;
}

void Cgame::read_map(int in_map){

	string path[] = { MAPPATH, MAPNAME }; 
	ifstream map; 
	char ch[4] ={};
	_itoa_s(in_map, ch, 4);
	path[0].append(ch + path[1]); 
	map.open(path->c_str(), ios::in | ios::binary);
	if (!map) { wcout << L"�޷���"<< path->c_str()<<",\n";  }    
	for (int i = 0; i < 40; i++) {
		map.read((char*)&Cmap::now_map[i], 40 * 4);//ǿת����
	}
	map.close();
	//char cChar;
	//while (map.get(cChar))
	//	wcout.put(cChar);
	////Cmap::now_map 
}
void Cgame::get_max(){

}
void Cgame::save_map(int in_map){
	//�������  ���in_mapIDС��2  ���ҵ�����û���������ļ���
	//string path[] = { "c:\\a\\c\\", ".txt" };
	string path[] = { MAPPATH, MAPNAME };
	ofstream map;void get_max();
	char ch[4] = {};
	_itoa_s(in_map, ch, 4);
	path[0].append(ch + path[1]);
	map.open(path->c_str(), ios::out | ios::binary);
	if (!map) { wcout << L"�޷���" << path->c_str() << ",\n"; }
	for (int i = 0; i < 40; i++) {
		map.write((char*)&Cmap::now_map[i], 40 * 4);//ǿת����
	}
	map.close();
	}
Cgame::Cgame()
{
}


Cgame::~Cgame()
{
}
