#pragma once
#include "stdafx.h"
#include "Data.h"

int sysMap00[40][40] = {
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_D, 1, 1, 1, WALL_D, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, WALL_D, WALL_D, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D

};

_tankball myball[256] = { 0 };

int g_nMap[40][40] = { 0 };//ȫ�������ʼ��

char g_game_menu[11][70] = {
	"			��������������������������������������������������",
	"			��                                              ��",
	"			��                                              ��",
	"			��              ̹�˴�ս Max ^_^                ��",
	"			��              ��  ��ʼ��Ϸ	                ��",
	"			��              ��  ��Ϸ����	                ��",
	"			��              ��  ���Ƶ�ͼ	                ��",
	"			��              ��  ��Ϸ����	                ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��������������������������������������������������" };
char start_menu[11][70] = {
	"			��������������������������������������������������",
	"			��                                              ��",
	"			��                                              ��",
	"			��              ̹�˴�ս Max ^_^                ��",
	"			��              ��  Player  	                ��",
	"			��              ��  Player  	                ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��                                              ��",
	"			��������������������������������������������������" };

_tankfire tankfire = { 10, {
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
}, 0, 25, 37, MISSILETYPE_1,0x000 };
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
}, 0, 34, 5, MISSILETYPE_1,0x0040 };