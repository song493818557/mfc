#pragma once
#include "stdafx.h"  
#include "menu.h" 
#include <conio.h>


//int  Cmap::check_helpa = 0;
//int  Cmap::Max_play = 0;//��ǰ��Ϸ��������
//int  Cmap::Goto = 0;//ȥ��ͼ�༭����ȥ̹�˴�ս
//int  Cmap::Tank_life = 5;//�ҷ�̹������ֵ
//int  Cmap::Max_Rebottank = 3;//������̹��
//int  Cmap::max_kill = 3;//����ɱ��
//int  Cmap::now_max_kill = 0;//����ɱ��
//int  Cmap::in_map = 2;//��ǰ��ͼ
//int  Cmap::check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
//int  Cmap::check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������

int   check_helpa = 0;										//static	static
int   Max_play = 0;//��ǰ��Ϸ��������						   static
int   Goto = 88;//ȥ��ͼ�༭����ȥ̹�˴�ս						static
int   Tank_life = 5;//�ҷ�̹������ֵ							 static
int   Max_Rebottank = 3;//������̹��							   static
int   max_kill = 3;//����ɱ��								   static
int   now_max_kill = 0;//����ɱ��							   static
int   in_map = 2;//��ǰ��ͼ										static
int   check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������		  static
int   check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������  			  static
int  now_map[40][40] = { 0 };


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
void WriteChar(int y, int x, char *pszChar, WORD wArr, int mapid ){	
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
	
	for (int i = 0 ; i < 7; i++)
	{
		WriteChar(20 + i, 35-kk, gggg[i], 0 | F_H_WHITE);

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
			 {  char ch1 = _getch();
				 ch = ch1;  }
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

/*
���ܣ��˵���������
 int a =m_menu_state  ��ͬ״̬��ͬ����ʽ
*/
void Cmenu::main_menu(int a){
	//Goto = 77; in_map = 1;  Max_play = 1;  return;
	system("cls");
	system("color 0f");
	m_menu_state = a; 
	switch (m_menu_state)
	{
	case 88:  Goto = 88; in_map = 2;  return;//̹�˴�ս Ĭ�ϵ�һ�ؿ���ͼ
	case 77: Goto = 77;  return;//��ͼ ��in_map ����ж����Ǹ���ͼ
	}
	m_menu_y = 7;
	main_draw();
	switch (m_menu_state)
	{		
		move_a(true);
		case 1:{
			//���˵�
			m_max_y = 19;
			show_menu(3, 8, 0);
		}break;
		case 2:{
			//������� ѡ��  Max_play ����	
			m_max_y = 13;
			show_menu(8,10,0);			
		}break;
		case 3:{
			//��Ϸ����
			m_max_y = 15;
			show_menu(10, 15, 0);
		}break;
		case 4:{
			//ѡ��༭�ĵ�ͼ	
			m_max_y = 15;
			show_menu(15, 18, 0);
		}break;
	}
	m_menu_y = 11;//���ù��λ��
	m_min_y = 11;
	menu_choose();

}
/*
���ܣ����̿�������    
*/
void Cmenu::menu_choose(){
	if (m_select == 0){
	while (m_select == 0)
	{ 
		if (_kbhit()) {
		unsigned	char ch = _getch();

		if (ch == 0xe0)
		{
			char ch1 = _getch();
			 ch = ch1;
		}
			switch (ch)
				{
					case 'w':case 'W':case 'H':
						{ 
							move_a(true);
				// ����̹��
						}break;
				case 's':case 'S':case 'P':
					{ 
						move_a(false);
					}break;
				case 'a':case 'A':case 'K':
				{
					if (m_menu_state == 3){

						switch (m_menu_y)
						{
						case 11://��ǰҳ���һ��   ��ʼ��Ϸ  ̹�˴�ս
							menu_Pnumb(max_kill, -1); break;
						case 13:
							menu_Pnumb(Tank_life, -1); break;
						case 15:
							menu_Pnumb(Max_Rebottank, -1); break;
						 				
						}
					} 
				}break;
				case 'd':case 'D':case 'M':
				{
					if (m_menu_state == 3){

						switch (m_menu_y)
						{
						case 11:// 
							menu_Pnumb(max_kill, 1); break;
						case 13:
							menu_Pnumb(Tank_life, 1); break;
						case 15:
							menu_Pnumb(Max_Rebottank, 1); break;

						}
					}
				}break;
				case 0x71:case  0x51:  case '\x1b': main_menu(1); break;
				//ȷ��ѡ�� ��ʼ�����ж���ʲô���ܵĲ��� ��Y����
				case '\r':
				{
					if (m_menu_state == 1){
						m_select = 1;						
						switch (m_menu_y)
						{
						case 11://��ǰҳ���һ��   ��ʼ��Ϸ  ̹�˴�ս
							main_menu(2); break;
						case 13:
							main_menu(3); break;//��Ϸ����
						case 15:
							main_menu(4); break;//���Ƶ�ͼ77
						case 17:
							main_menu(5); break;//��Ϸ����
						case 19:
							main_menu(6); break;//�˳���Ϸ						
						}
						
					}
					if (m_menu_state == 2){
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://���һ   
							Max_play = 1;  break;
						case 13:////��Ҷ�
							Max_play = 2; break;//��Ϸ����
						}
						main_menu(88);//����̹�˴�ս
					}
					if (m_menu_state == 3){
						main_menu(1);
					}
					if (m_menu_state == 4){//ѡ��
						m_select = 1;
						switch (m_menu_y)
						{
						case 11://��ͼһ   
							in_map = 2; break;
						case 13:////��ͼ��
							in_map = 3; break;
						case 15:////��ͼ��
							in_map = 4;  break; 
						}
						main_menu(77);//�����Ӧ�ĵ�ͼ��ͼ
					}
				// ��Ϸ�˳�
				}break;
				system("cls");
			}

		}
	}
	}
}
/*
���ܣ� ������ת���ַ��� ���������
*/
void Cmenu::menu_Pnumb(int &name, int numb){
	
	name = name + numb;
	char ch[10] = {};
	_itoa_s(name, ch, 10);
	WriteChar(m_menu_y, m_menu_x + 8, ch, wArr);
}
/*
���ܣ� ������ 
*/
void Cmenu::move_a(bool trrue){
	if (trrue) {			
		m_menu_y -= 2;		
		if (m_menu_y  <= m_max_y && m_menu_y   >= m_min_y){
			WriteChar(m_menu_y+2, m_menu_x - 2, "   ", wArr);
		}
		else
		{
			m_menu_y += 2;
			return;
		}
	}else { 
		m_menu_y += 2;
		if (m_menu_y  <= m_max_y && m_menu_y   >= m_min_y){
			WriteChar(m_menu_y - 2, m_menu_x - 2, "   ", wArr);
		}
		else
		{
			m_menu_y -= 2;
			return;
		}
	}
		WriteChar(m_menu_y, m_menu_x - 2, charaa[1], wArr); 
}
/*
���ܣ� 
������Ŀ��  
*/
void Cmenu::main_draw(){
	for (int i = 5; i < 25; i++){// ��
		for (int j = 10; j < 30; j++)//��
		{
			if (j == 10 || j == 29 || i == 5 || i == 24){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			} 
		} 
	}
	WriteChar(m_menu_y, m_menu_x, charaa[2], F_H_CYAN);
}
/*
���ܣ�ѭ����ʾ�˵� charaa    NOW �����￪ʼ MAX ���������
*/
void Cmenu::show_menu(int now, int max,int select){
	m_select = select;
	int temp = m_menu_y+2;
	for (int i = now; i < max; i++)
	{
		m_menu_y += 2;
		if (i == now) { move_a(false);  }
		WriteChar(m_menu_y, m_menu_x, charaa[i], wArr);
	} 
} 