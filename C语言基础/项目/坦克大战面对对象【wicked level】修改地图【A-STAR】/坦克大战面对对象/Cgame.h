#pragma once
#include "Data.h"
#include <string>
#include <vector> 
#include <conio.h>
#include <fstream>
#include <stdlib.h>
#include <iostream>
#include <wtypes.h>
#include <time.h>
#include "Cball.h"
using namespace std;

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
void WriteChar(int y, int x, char *pszChar, WORD wArr, int mapid = 0);
void Wellcome();
class Cgame
{
public:
	Cgame();
	~Cgame();
	/*
	���ܣ�ѭ�������������¼�
	*/
	static int max_map;//����ͼ����
	void get_Message(int& nChar);
	void read_map(int in_map);
	void save_map(int in_map);
	void get_max();
	static  int check_Rebottank;
	static  int check_play;
	static  int Tank_life;
	static  int Max_Rebottank;
	static  int Max_play;
	static  int Goto;
	static  int now_max_kill;
	static  int check_helpa;
	static  int max_kill;//��ɱ���ֵ ���ڵ��ھ͹���
	static  int in_map;//��ǰ��ͼ 
	static  int now_level;
	static int now_map[40][40];
};
int  Cgame::check_helpa = 0;
int  Cgame::Max_play = 0;//��ǰ��Ϸ��������
int  Cgame::Goto = 0;//ȥ��ͼ�༭����ȥ̹�˴�ս
int  Cgame::Tank_life = 5;//�ҷ�̹������ֵ
int  Cgame::Max_Rebottank = 3;//������̹��
int  Cgame::max_kill = 3;//����ɱ��
int  Cgame::now_max_kill = 0;//����ɱ��
int  Cgame::in_map = 2;//��ǰ��ͼ
int  Cgame::check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
int  Cgame::check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
Cball all_ball[256];
//̹��ģ��
int Calltank::t_demo[4][3][3] = {
	{ { 2, 1, 2 },
	{ 1, 4, 1 },
	{ 1, 3, 1 } },
	{ { 1, 3, 1 },
	{ 1, 4, 1 },
	{ 2, 1, 2 } },
	{ { 2, 1, 1 },
	{ 1, 4, 3 },
	{ 2, 1, 1 } },
	{ { 1, 1, 2 },
	{ 3, 4, 1 },
	{ 1, 1, 2 } }
};