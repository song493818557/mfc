#include "stdafx.h"
#include "map.h"
#include <wtypes.h>

Cball all_ball[256];
int Calltank::t_demo[4][3][3] = {
	{ { 0, 1, 0 },
	{ 1, 0, 1 },
	{ 1, 0, 1 } },
	{ { 1, 0, 1 },
	{ 1, 0, 1 },
	{ 0, 1, 0 } },
	{ { 0, 1, 1 },
	{ 1, 0, 0 },
	{ 0, 1, 1 } },
	{ { 1, 1, 0 },
	{ 0, 0, 1 },
	{ 1, 1, 0 } }
};

int Cmap::now_map[40][40] = { 0 };

void Cmap::DrawMap(){
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			if (Cmap::now_map[i][j] == 1){
				WriteChar(i, j, "  ", 0);
			}
			else if (Cmap::now_map[i][j] == 2){

				WriteChar(i, j, "��", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 3){
				WriteChar(i, j, "�d", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 4){
				WriteChar(i, j, "��", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 5){
				WriteChar(i, j, "��", F_H_WHITE | B_BLUE);
			}
			else if (Cmap::now_map[i][j] == 6){
				WriteChar(i, j, "��", B_H_WHITE);
			}
			else if (Cmap::now_map[i][j] == 7){
				WriteChar(i, j, "��", 0 | B_H_GREEN);
			}
			else if (Cmap::now_map[i][j] == 8){
				WriteChar(i, j, "��", 0 | B_H_YELB_PURPLELOW);
			} //else{}
		}

	}
}
bool Cmap::cheak_bump(int position, int y, int x, int tsize){
	//now_map ֮ǰ�õ�
	//������Ҫ���
	/*
	#define WALL_E    0x7  // ��   ���� ������
	#define WALL_F    0x8  // ��  ����·�����٣�
	
	int  a;
	int  b;
	int  c;*/
	switch (position)
	{
	case 0:
	{
		y = y - 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;
		}
		/* a = cheak_Tank_bump(position, y - 2, x + 1, 9);
		 b = cheak_Tank_bump(position, y - 2, x - 1, 9);
		 c = cheak_Tank_bump(position, y - 2, x, 9);*/
	}break;
	case 1:
	{
		y = y + 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1     && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;

		}

	}break;
	case 2:
	{
		x = x - 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y    ][x] > 1 && now_map[y    ][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		/*a = cheak_Tank_bump(position, y + 1, x + 2, 9);
		b = cheak_Tank_bump(position, y - 1, x + 2, 9);
		c = cheak_Tank_bump(position, y,     x + 2, 9);*/


	}break;
	case 3:
	{
		x = x + 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		/*
		a = cheak_Tank_bump(position, y + 1, x - 2, 9);
		b = cheak_Tank_bump(position, y - 1, x - 2, 9);
		c = cheak_Tank_bump(position, y,     x - 2, 9);*/

	}break;

	default:
		break;
	}
	//if ((a + b + c) <3)
	//{

	//	return FALSE;
	//	
	//}
	return true;

}

bool Cmap::cheak_Tank_bump(int position, int y, int x, int tsize){
	//now_map ֮ǰ�õ�
	//������Ҫ���
	/*
	#define WALL_E    0x7  // ��   ���� ������
	#define WALL_F    0x8  // ��  ����·�����٣�
	||
	now_map[y - 3][x] > 1 && now_map[y - 3][x] < 7 ||
	now_map[y - 3][x - 1] > 1 && now_map[y - 3][x - 1] < 7
	*/
	if (now_map[y][x] > 1 && now_map[y][x] < 7)
	{

		return FALSE;
	}
	return true;

}

void Calltank::DrawTank(char singbo[3] = "��", int color = F_WHITE){
	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "��", ' ');

			if (now_map[lie][hang] == 7){
				now_map[lie][hang] = 7;
				WriteChar(lie, hang, "��", 0 | B_H_GREEN);
			}
			else  if (now_map[lie][hang] == 8){
				now_map[lie][hang] = 8;
				WriteChar(lie, hang, singbo, 0 | B_H_YELB_PURPLELOW);
			}
			else  if (now_map[lie][hang] == 6){
				WriteChar(lie, hang, "��", B_H_WHITE);
				now_map[lie][hang] = 6;
			}
			else  if (now_map[lie][hang] == 5){
				WriteChar(lie, hang, "��", B_H_WHITE);
				now_map[lie][hang] = 5;
			}
			else if (Calltank::t_demo[t_position][i][j] == 1){
				if (t_type == 1 && now_map[lie][hang] < 2){
					//now_map[lie][hang] = 10;
				}
				else if (t_type == 2 && now_map[lie][hang] < 2){
					//now_map[lie][hang] = 11;
				}
				WriteChar(lie, hang, singbo, color);
			}
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		//printf("\n");
	}
}
void Calltank::ClerarTank(){

	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "��", ' ');
			if (now_map[lie][hang] == 7){
				WriteChar(lie, hang, "��", 0 | B_H_GREEN);
			}
			else  if (now_map[lie][hang] == 8){
				WriteChar(lie, hang, "��", 0 | B_H_YELB_PURPLELOW);
			}
			else  if (now_map[lie][hang] == 6){
				WriteChar(lie, hang, "��", B_H_WHITE);
				now_map[lie][hang] = 6;
			}
			else  if (now_map[lie][hang] == 5){
				WriteChar(lie, hang, "��", B_H_WHITE);
				now_map[lie][hang] = 5;
			}
			else {
				WriteChar(lie, hang, "  ", F_WHITE);
				now_map[lie][hang] = 1;
				//����ͼԪ����Ϊ1
				if (now_map[lie][hang] < 2){ now_map[lie][hang] = 1; }

			}
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		//printf("\n");
	}
}

void Cmytank::MoveTank(){

	if (!_kbhit())
	{
		return;
	}
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
		t_position = 0;
		ClerarTank();
		DrawTank();
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{//WriteChar(m_y, menu_x, menu_char1, wArr);

			ClerarTank();
			m_y--;
			DrawTank();


		}
		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// ����̹��
	}break;
	case 's':case 'S':case 'P':
	{
		t_position = 1;
		ClerarTank();
		DrawTank();
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){

			ClerarTank();
			m_y++;
			DrawTank();
		}
		// ����̹��
	}break;
	//ȷ��ѡ�� ��ʼ�����ж���ʲô���ܵĲ��� ��Y����

	case 'a':case 'A':case 'K':
	{
		t_position = 2;
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){
			ClerarTank();

			m_x--;
			DrawTank();

		}
		// ����̹��
	}break;
	case 'd':case 'D':case 'M':
	{
		t_position = 3;
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){
			ClerarTank();
			m_x++;
			DrawTank();


		}
		// ����̹��
	}break;
	// ���ӵ�
	case 'j':case 'J':
	{
		Firstball(t_life, t_position, m_x, m_y, t_ball);

	}break;
	// ��Ϸ�˳�
	case 'q':case 'Q':
	{

	}break;
	case '\r':
	{
		//if (menu_i == 0){
		//	system("cls");
		//	menu_i++;
		//	game_menu(start_menu);
		//}
		//if (menu_i == 2){
		//	system("cls");
		//	menu_i++;
		//	//strcpy(g_nMap, sysMap00 );
		//	DrawMap();
		//}
		// ��Ϸ�˳�
	}break;
	default:
		break;
	}
}

void Cball::Firstball(int typea, int position, int b_x, int b_y, char *ball_style){
	for (int i = 0; i < 256; i++)
	{
		int check_a = 0;
		int check_b = 0;
		//���ǵ�ǰ��ֵ
		//if (now_map[b_y][b_x] > 1){ check_b = 2; }
		// all_ball[i].isBullet ����֮ǰ �ж��ӵ��Ƿ�Խ��
		//�����ǰ�����ӵ��������� �Ͳ�������һ��
		if (all_ball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (position)
			{
			case 0:
			{

				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y - 2;
				if (now_map[b_y - 2][b_x] > 1){
					check_b = 2;
				}

				if (all_ball[i].b_y >= 1){ check_a = 1; }
			}break;
			case 1:
			{
				
				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y + 2;
				if (now_map[b_y + 2][b_x] > 1){ check_b = 2; }
				if (all_ball[i].b_y < 39){ check_a = 1; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }
			}break;
			case 2:
			{
				
				all_ball[i].b_x = b_x - 2;
				all_ball[i].b_y = b_y;
				if (all_ball[i].b_x >= 1){ check_a = 1; }
				if (now_map[b_y][b_x - 2] > 1){ check_b = 2; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }

			}break;
			case 3:
			{
				
				all_ball[i].b_x = b_x + 2;
				all_ball[i].b_y = b_y;
				if (all_ball[i].b_x <= 38){ check_a = 1; }
				if (now_map[b_y][b_x + 2] > 1){ check_b = 2; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }

			}break;
			}
			if (check_a == 1)
			{
				all_ball[i].isBullet = 1;
				all_ball[i].b_position = position;//����
				all_ball[i].b_type = typea;//̹���ӵ�����
				//	WriteChar(all_ball[i].b_y, all_ball[i].b_x, "��", 0 | F_H_GREEN);
				if (all_ball[i].b_type == 10){
					//char t_ball[3] = "��"; �Ҿ�
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, "��", all_ball[i].wArr);
					}
				}
				else{
					//char t_ball[3] = "��";
					//�о�
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, "��", all_ball[i].wArr);
					}
				}


			}
			break;


		}

	}

}
//ѭ���ӵ�
void Cball::tank_ball()
{
	for (int i = 0; i < 256; i++)
	{
		//all_ball[i]
		int ay = all_ball[i].b_y;
		int ax = all_ball[i].b_x;
		if (all_ball[i].isBullet == 0)
		{
			continue;
		}
		else
		{
			int a = 0;//�ж��Ƿ������ӵ� 1���� 0 ������
			if ((now_map[ay][ax] == 5) ||
				(now_map[ay][ax] == 7) ||
				(now_map[ay][ax] == 8) ||
				(now_map[ay][ax] == 9))
			{
				a = 1;
			}//���� a
			else
			{
				
				if ((now_map[ay][ax] == 6)){
					all_ball[i].isBullet = 0;
					break;
				}
				WriteChar(all_ball[i].b_y, all_ball[i].b_x, "  ", 0 | F_H_GREEN);
				//WriteChar(all_ball[i].b_y, all_ball[i].b_x, "  ", 0 | F_H_GREEN);
			}
			switch (all_ball[i].b_position)
			{
			case 0:
			{
				//�ӵ����ͣ����ң� ���� Y���� X���� �ӵ���� ��ǰ���� 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay - 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y > 0)) {
						all_ball[i].b_y--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 1:
			{
				//�ӵ����ͣ����ң� ���� Y���� X���� �ӵ���� ��ǰ���� 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay + 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y < 40)) {
						all_ball[i].b_y++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 2:
			{
				//�ӵ����ͣ����ң� ���� Y���� X���� �ӵ���� ��ǰ���� 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax - 1, 1, i))
				{
					if (a = 1 && (ax > 0)) {
						all_ball[i].b_x--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 3:
			{
				//�ӵ����ͣ����ң� ���� Y���� X���� �ӵ���� ��ǰ���� 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax + 1, 1, i))
				{
					if (a = 1 && (ax < 40)) {
						all_ball[i].b_x++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			}

		}
	}
}
//����ӵ�
bool Cmap::cheak_ball_bump(int typea, int position, int y, int x, int tsize, int i){
	// || now_map[y + 1][x] == 6 || now_map[y - 1][x] == 6 || now_map[y][x - 1] == 6 || now_map[y][x + 1] == 6
	if (now_map[y][x] == 6)
	{
		//		WriteChar(y, x, "  ", 0 | B_H_WHITE);
		//WriteChar(y, x, "��", 0 | F_H_GREEN);
		all_ball[i].isBullet = 0;
		return true;
	}
	//���� ���� ����· ���� �ӵ������������ ѡ�񲻴�ӡ�ӵ� ��������
	else if ((now_map[y][x] == 5) || (now_map[y][x] == 7) || (now_map[y][x] == 8) || (now_map[y][x] == 9))
	{
		switch (now_map[y][x])
		{
		case 5:
		{
			WriteChar(y, x, "��", F_H_PURPLE);
		}break;
		case 7:
		{
			WriteChar(y, x, "��", B_GREEN);
		}break;
		case 8:
		{
			WriteChar(y, x, "��", B_BLUE);
		}break;
		case 9://buff
		{
			WriteChar(y, x, "��", B_H_WHITE);
		}break;
		}
		//WriteChar(y, x, "��", B_H_WHITE);
	}
	//
	else if (now_map[y][x] > 1 && now_map[y][x] < 5)
	{
		//WriteChar(y, x, "  ", 0 | 0);
		all_ball[i].isBullet = 0;
		//�����ӵ�����ǽ����;
		if (now_map[y][x] < 4){
			now_map[y][x] = 1;
			WriteChar(y, x, "  ", F_H_GREEN | 0);
		}
		else
		{
			//WriteChar(y, x, "  ", F_H_GREEN | 0);
			now_map[y][x]--;
		}
		//now_map[y][x]--;
		return false;
	}
	else if (now_map[y][x] == 1)
	{

		DrawBall(y, x, "��", 0 | F_H_GREEN);

		return true;
	}

}
void Cmap::DrawBall(int y, int x, char singbo[3] = "��", WORD wArr = 0){

	WriteChar(y, x, singbo, wArr);

}

void CenemyTank::move_enemy()
{
	//DrawTank("��", t_bg);
	int aa = rand() % 5;
	switch (aa)
	{
	case 1:
	{
		/*ClerarTank();
		if (m_y > 2){
			t_position = 0;
			DrawTank("��", F_H_BLUE);
		}
		*/
		t_position = 0;
		bool cheak_bumpa = cheak_bump(t_position, m_y , m_x, 9);

		if (cheak_bumpa)
		{
			//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_y--;
			
			DrawTank("��", F_H_BLUE);
			}
		//else{
		//	cheak_bumpa = cheak_bump(t_position, m_y + 1, m_x, 9);

		//	if (cheak_bumpa)
		//	{
		//		ClerarTank();
		//		m_y++;
		//		t_position = 1;
		//		DrawTank("��", F_H_BLUE);
		//		// m_y = m_y + 1;
		//		// m_y = m_y + 1;}
		//	}
		//}

	}break;
	case 2:
	{
		
		/*if (m_y < 37){
			ClerarTank();
			t_position = 1;
			DrawTank("��", F_H_BLUE);
		}*/
		t_position = 1;
		bool cheak_bumpa = cheak_bump(t_position, m_y , m_x, 9);
		if (cheak_bumpa)
		{
			//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_y++;
			
			DrawTank("��", F_H_BLUE);
			}
	/*	else{
			cheak_bumpa = cheak_bump(t_position, m_y - 1, m_x, 9);

			if (cheak_bumpa)
			{
			ClerarTank();
			m_y--;
			t_position = 0;
			DrawTank("��", F_H_BLUE | F_H_BLUE);
			}
		
		} 
		*/

		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// ����̹��
	}break;

	case 3:
	{
		/*
		if (m_x > 2){
		ClerarTank();
		t_position = 2;
		DrawTank("��", F_H_BLUE);
		}*/
		t_position = 2;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_x--;
			
			DrawTank("��", F_H_BLUE);
		}
		//else
		//{
		//	cheak_bumpa = cheak_bump(t_position, m_y, m_x + 1, 9);

		//	if (cheak_bumpa)
		//	{
		//		//�����жϲ��� �ͽ������ ��ӡ������̹�� 
		//		ClerarTank();
		//		m_x++;
		//		t_position = 3;
		//		DrawTank("��", F_H_BLUE);
		//	}
		//
	}
break;
	case 4:
	{
		/*ClerarTank();
		if (m_x < 37){
			t_position = 3;
			DrawTank("��", F_H_BLUE);
		}*/
		t_position = 3;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{	//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_x++;
			
			DrawTank("��", F_H_BLUE);
		}
		//else
		//{
		//	cheak_bumpa = cheak_bump(t_position, m_y, m_x - 1, 9);

		//	if (cheak_bumpa)
		//	{
		//		ClerarTank();
		//		m_x--;
		//		t_position = 2;
		//		DrawTank("��", F_H_BLUE);
		//	}
		//	// m_x = m_x - 1;
		//	//m_x = m_x + 1;
		//}
	}//WriteChar(menu_y, menu_x, menu_char, wArr);


		// ����̹��
	 case 5:
	{
		Firstball(t_life, t_position, m_x, m_y, t_ball);
		// �����ӵ�  û���ӵ��жϵ���
	}break;
	default:
		break;
	}
};