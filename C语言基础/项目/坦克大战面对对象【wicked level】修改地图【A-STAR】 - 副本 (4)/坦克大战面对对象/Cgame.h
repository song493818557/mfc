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
using namespace std;
 
static int   check_helpa = 0;
static int   Max_play = 0;//��ǰ��Ϸ��������
static int   Goto = 88;//ȥ��ͼ�༭����ȥ̹�˴�ս
static int   Tank_life = 5;//�ҷ�̹������ֵ
static int   Max_Rebottank = 3;//������̹��
static int   max_kill = 3;//����ɱ��
static int   now_max_kill = 0;//����ɱ��
static int   in_map = 2;//��ǰ��ͼ
static int   check_Rebottank = 0;//��ʼ����ǰ���ŵ��ҷ�̹������
static int   check_play = 0;//��ʼ����ǰ���ŵ��ҷ�̹������  
static int  now_map[40][40] = { 0 };
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

};
