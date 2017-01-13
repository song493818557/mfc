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
	clock_t m_Sstart;//移动间隔计时开始 
	clock_t m_Sfinish;//移动间隔计时结束
	int m_level;//当前等级
	int m_checkover;//检测当前游戏状态(包括正常 1  成功 2 失败3)
	int m_max;//最大长度
	int m_now;//当前长度
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
	clock_t m_Fstart;//当前刷新存活时间计时开始
	int m_stay; 
	int m_pfood;
	int max_food;
	vector<_position> m_food;//食物的数组 包括坐标 和方向
};