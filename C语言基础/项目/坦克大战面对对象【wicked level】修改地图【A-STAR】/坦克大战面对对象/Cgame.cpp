#include "stdafx.h"
#include "Cgame.h"



/***
�������� �����ô�����Ϣ
����һ�����X��
���������߶�Y��
����������ӡ���ַ�
�����ģ���ӡ�ַ�������
***/
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY)
{
	//���ÿ���̨����
	SetConsoleTitleA(pszWindowTitle);
	HANDLE  hStdln, hStdOut;
	hStdln = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//��ȡ������̨�Ĵ�С
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD buffersize = { pos.X + 1, pos.Y + 1 };
	//���ÿ���̨��������С
	if (!SetConsoleScreenBufferSize(hStdOut, buffersize)){
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());
	}
	SMALL_RECT srctWindow = { 0, 0, nX, nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)){
		//���ÿ���̨��С
		printf("size err %d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1, nY + 1 };
	//���ÿ���̨��������С
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)){
		//���ÿ���̨���ڻ�����ʧ��
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());

	}
	return true;
}
void WriteChar(int y, int x, char *pszChar, WORD wArr, int mapid){
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = x * 2;
	loc.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	if (mapid == 0)
	{
		printf(pszChar);
	}
	else
	{
		switch (mapid)
		{
			// WALL1_A   "��"  // �d  ��ǽ �����ƻ�,�ƻ���̬��0x3
			// WALL1_B    "��" // ��  ��ǽ �����ƻ���0x4
			// WALL1_C    "��"  // ��   ���� �����ɴ�Խ���ӵ��ɹ���0x5
			// WALL1_D   "��"   // ��   ·��  �����ɴ�Խ���ӵ����ɹ���   0x6
			// WALL1_E    "^^"  // �� ^^  ���� ������0x7
		case 3:printf(WALL1_A); break;
		case 4:printf(WALL1_B); break;
		case 5:printf(WALL1_C); break;
		case 6:printf(WALL1_D); break;
		case 7:printf(WALL1_E); break;

		}
	}{


	}

}
//"                          |       ";
//"                   __\--__|_      "
//"   II=======OOOOO[/ ��02 ___|      "
//"             _____\______|/-----. "
//"           /____________________| "
//"            \����������/          "
//"              ~~~~~~~~~~~~~~~~    "
/*
���ܣ�Ƭͷ
*/
void Wellcome(){

	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;//�Ƿ���ʾ���
	SetConsoleTitle(L"̹�˴�ս");
	return;
	SetWindowSize("���� ̹�˴�ս", 40, 100);
	vector<char*> gggg;
	//�ƶ�̹�� 
	gggg.push_back("                        |       ");
	gggg.push_back("                 __\\--__|_      ");
	gggg.push_back(" II=======OOOOO[/ ��02 ___|      ");
	gggg.push_back("          _____\\______|/-----.  ");
	gggg.push_back("         /____________________|  ");
	gggg.push_back("          \\����������/   ");
	gggg.push_back("            ~~~~~~~~~~~~~~~~     ");
	vector<char*> chara;
	chara.push_back("@@@@@@@@  @@@                         @@@@@@@@@@                      @@@         ");
	chara.push_back("@@@@@@@@  @@@                         @@@@@@@@@@                      @@@         ");
	chara.push_back("@@@             @@ @@   @@@@@            @@@@      @@@@@@   @@@@@@@   @@@   @@@   ");
	chara.push_back("@@@       @@@  @@@@@@  @@@@@@@@          @@@@     @@@@@@@@  @@@@@@@@  @@@  @@@    ");
	chara.push_back("@@@@@@@@  @@@  @@@    @@     @@          @@@@     @@   @@@  @@@@@@@@  @@@@@@      ");
	chara.push_back("@@@@@@@@  @@@  @@@@   @@     @@          @@@@        @@@@@  @@@  @@@@ @@@@@       ");
	chara.push_back("@@@@      @@@  @@@    @@@@@@@@@          @@@@     @@@@@@@@  @@@  @@@@ @@@@@@@     ");
	chara.push_back("@@@       @@@  @@@    @@@                @@@@    @@@   @@@  @@@  @@@@ @@@@@@@@    ");
	chara.push_back("@@@       @@@  @@@     @@    @@          @@@@    @@@@@@@@@  @@@  @@@@ @@@@   @@@   ");
	chara.push_back("@@@       @@@  @@@     @@@@@@@           @@@@     @@@@@@@@  @@@  @@@@ @@@@   @@@   ");
	chara.push_back("@@@       @@@   @@       @@@             @@@@            @@     @@    @@     @@@@");
	int kk = 0;
	for (int j = 0; j < 10; j++)
	{
		kk = j;

		for (int i = 0; i < 7; i++)
		{
			WriteChar(20 + i, 35 - kk, gggg[i], 0 | F_H_WHITE);

		}
		Sleep(100);
		if (j != 9){
			for (int i = 0; i < 7; i++)
			{
				WriteChar(20 + i, 35 - kk, "                                  ", 0 | F_H_WHITE);
			}
		}
	}
	Sleep(100);

	for (int j = 0; j < 8; j++)
	{
		kk = j;
		for (int i = 0; i < 11; i++)
		{
			WriteChar(5 + i, 0 + kk, chara[i], 0 | F_H_WHITE);
		}
		Sleep(200);
		if (j < 5)
		{
			for (int i = 0; i < 11; i++)
			{
				WriteChar(5 + i, 0 + kk, "                                       ", 0 | F_H_WHITE);
			}
		}
	}
	int i = 0;
	while (i == 0)
	{
		if (_kbhit()){
			unsigned	char ch = _getch();
			if (ch == 0xe0)
			{
				char ch1 = _getch();
				ch = ch1;
			}
			if (ch == '\r') {
				//���˵�����
				WriteChar(22, 25, "                                  ", 0 | F_H_WHITE);
				for (int i = 0; i < 7; i++)
				{
					WriteChar(22, 25 + i, gggg[2], 0 | F_H_WHITE);
					Sleep(50);
					WriteChar(22, 25 + i, "                                  ", 0 | F_H_WHITE);
					Sleep(50);
				}
				Sleep(10);
				for (int i = 0; i < 7; i++)
				{
					WriteChar(22, (25 + 7 - i), gggg[2], 0 | F_H_WHITE);
					Sleep(10);
					WriteChar(22, 25 + 7 - i, "                                  ", 0 | F_H_WHITE);
					Sleep(10);
				}
				WriteChar(22, 25, gggg[2], 0 | F_H_WHITE);
				Sleep(1000);
				continue;
			}
			else
			{
				WriteChar(22, 10, "                       ", 0 | F_H_WHITE);
				Sleep(1000);
				WriteChar(22, 10, "�밴�س���������Ϸ *��*", 0 | F_H_WHITE);
			}
		}
		else
		{
			WriteChar(22, 10, "�밴�س���������Ϸ *��*", 0 | F_H_WHITE);
		}
	}
}


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
		map.read((char*)&now_map[i], 40 * 4);//ǿת����
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
		map.write((char*)&(now_map[i]), 40 * 4);//ǿת����
	}
	map.close();
	}
Cgame::Cgame()
{
}


Cgame::~Cgame()
{
}
