#include "stdafx.h"
#include "Cball.h"
/*
���ܣ���һ��������ӵ�
int typea,   �ӵ���������
int b_tank ,  ̹��ID
int position, ����
int b_x   b_y, �ӵ�XY ����
char *ball_style  �ӵ����
*/
void Cball::Firstball(int typea, int b_tank, int position, int b_x, int b_y, char ball_style[3]){
	for (int i = 0; i < 256; i++)
	{
		int check_a = 0;//��ǰ���ӵ��Ƿ�40X40��Խ��
		//int check_b = 0;//�����ӵ����¸���ʾ�ĵط��Ƿ��ǿյ�
		//if (now_map[b_y][b_x] > 1){ check_b = 2; }
		// all_ball[i].isBullet ����֮ǰ �ж��ӵ��Ƿ�Խ��
		//�����ǰ�����ӵ��������� �Ͳ�������һ��
		if (all_ball[i].isBullet != 0){ continue; }
		else
		{
			all_ball[i].isBullet = 1;
			all_ball[i].b_x = b_x;
			all_ball[i].b_y = b_y;
			switch (position)
			{
			case 0: all_ball[i].b_y -= 2; break;
			case 1: all_ball[i].b_y += 2; break;
			case 2:all_ball[i].b_x -= 2; break;
			case 3:all_ball[i].b_x += 2; break;
			}
			/*if (all_ball[i].b_x < 39 || all_ball[i].b_x > 0 ||
			all_ball[i].b_y < 39 || all_ball[i].b_y > 0 )
			{ */
			if (cheak_ball_bump(all_ball[i].b_type, position, all_ball[i].b_y, all_ball[i].b_x, 1, i))
			{
				//DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, 0 | F_H_GREEN);
				all_ball[i].b_position = position;//����
				all_ball[i].b_type = typea;//̹���ӵ�����
				all_ball[i].b_tank = b_tank;//�Ǹ�̹�˷����ӵ�
				(all_ball[i].b_type == 1) ? all_ball[i].wArr = 0 | F_H_GREEN : all_ball[i].wArr = 0 | F_H_GREEN; //̹���ӵ���ʽ��ֵ
			}
			else{ all_ball[i].isBullet = 0; }
			return;
		}
	}
}
/*
���ܣ�ѭ���ӵ�
*/
void Cball::tank_ball()
{
	for (int i = 0; i < 50; i++)
	{
		int ay = all_ball[i].b_y;
		int ax = all_ball[i].b_x;
		if (all_ball[i].isBullet == 0 || now_map[ay][ax] == 6)
		{
			all_ball[i].isBullet = 0;
			continue;
		}
		switch (all_ball[i].b_position)
		{
		case 0: --ay; break;
		case 1: ++ay;  break;
		case 2: --ax; break;
		case 3: ++ax;  break;
		}

		if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax, 1, i))
		{
			all_ball[i].b_y = ay;
			all_ball[i].b_x = ax;
			continue;
		}


	}
}

/*
���ܣ����ӵ�
int balltype �ж���������ǻ��ӵ�
WORD wArr = 0  ���屳����ɫ
*/
void Cmap::DrawBall(int y, int x, int balltype, WORD wArr = 0){

	if (balltype == 1){

		switch (now_map[y][x])
		{
		case 5: WriteChar(y, x, WALL1_C, WALL1_GC); return;//���� true
		case 7: WriteChar(y, x, WALL1_E, WALL1_GC); return;//�ݵ� true
		case 9: WriteChar(y, x, WALL1_G, WALL1_GC); return;//BUFF true 
		case 20:WriteChar(y, x, BUFF_SPEED_GRAPHICS, WALL1_GC); return;
		case 21:WriteChar(y, x, BUFF_GOD_GRAPHICS, WALL1_GC); return;
		case 22:WriteChar(y, x, BUFF_SHIELD_GRAPHICS, WALL1_GC); return;
		}
		now_map[y][x] = 13;
		WriteChar(y, x, "��", MAPBG | wArr);
	}
	else
	{

		switch (now_map[y][x])
		{
		case 5: WriteChar(y, x, WALL1_C, WALL1_CC); return;//���� true
		case 7: WriteChar(y, x, WALL1_E, WALL1_EC); return;//�ݵ� true
		case 9: WriteChar(y, x, WALL1_G, WALL1_GC); return;//BUFF true 
		case 20:WriteChar(y, x, BUFF_SPEED_GRAPHICS, BUFF_BG); return;
		case 21:WriteChar(y, x, BUFF_GOD_GRAPHICS, BUFF_BG); return;
		case 22:WriteChar(y, x, BUFF_SHIELD_GRAPHICS, BUFF_BG); return;
		}
		now_map[y][x] = 1;
		WriteChar(y, x, "  ", MAPBG);
	}
}
