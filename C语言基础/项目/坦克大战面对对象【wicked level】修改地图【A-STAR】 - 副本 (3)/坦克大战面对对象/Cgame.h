#pragma once
#include "Data.h"
 
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
};