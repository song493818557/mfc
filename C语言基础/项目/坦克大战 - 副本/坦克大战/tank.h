#pragma once
#include "stdafx.h"
struct _tankfire{
	int t_life;//����ֵ
	int t_demo[4][3][3];//̹��ģ�;ŷ���  �ĸ�ģ��
	int t_position;//����̹�˷���
	int m_x;//��Ҳ�����̹���ƶ�x����
	int m_y;//��Ҳ�����̹���ƶ�y����
	int t_ball;//�ӵ�
	//int t_move[100][100];//�ƶ�����

	//int t_npc_stank;//С̹��
	//int t_npc_jtank;//��Ӣ̹��
	//int t_npc_btank;//BOSS̹��

}; _tankfire tankfire = { 10, {
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
}, 0, 25, 37, MISSILETYPE_1 };
_tankfire tankRobot = { 5, {
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
}, 0, 34, 5, MISSILETYPE_1 };
