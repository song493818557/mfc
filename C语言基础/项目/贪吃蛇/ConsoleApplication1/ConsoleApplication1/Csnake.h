#pragma once
using namespace std; 
#include "Cganme.h"
 
class Csnake :public Cganme
{
public:

	Csnake();
	~Csnake();
	void map_inInit();
	void draw_snake(int type = 1); 
	void snake_move();
	bool check_snake(int d,int y,int x); 
	void check_key();
private:
	int m_speed;
	clock_t m_Sstart;//�ƶ������ʱ��ʼ 
	clock_t m_Sfinish;//�ƶ������ʱ����
	int m_level;//��ǰ�ȼ�
	int m_checkover;//��⵱ǰ��Ϸ״̬(�������� 1  �ɹ� 2 ʧ��3)
	int m_max;//��󳤶�
	int m_now;//��ǰ����
	vector<_position> m_snake;
	//_position *pnode;
};

class Cfood :public Cganme
{
public:
	Cfood() :m_stay(500), m_Fstart(0){}
	void creat_food();
	void push_food();
	void draw_food(int type);
private:
	clock_t m_Fstart;//��ǰˢ�´��ʱ���ʱ��ʼ
	int m_stay; 
	int m_pfood;
	int max_food;
	vector<_position> m_food;//ʳ������� �������� �ͷ���
};