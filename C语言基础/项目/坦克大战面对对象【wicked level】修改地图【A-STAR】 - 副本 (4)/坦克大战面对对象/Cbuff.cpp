#include "stdafx.h"
#include "Cbuff.h"


clock_t Cbuff::m_Fstart = 0;//在当前地图存活时间计时开始
int Cbuff::m_stay = 1000;//在当前地图存活的总时间
int Cbuff::m_pfood = 0;
int Cbuff::max_food = 10;
vector<POSTION> Cbuff::m_food;//buff的数组 包括坐标 和方向
char MAP_BUFF[][3] = { "55", BUFF_GOD_GRAPHICS, BUFF_SPEED_GRAPHICS, BUFF_SHIELD_GRAPHICS };
void Cbuff::creat_buff(){ 
	
	m_Fstart = clock();
	int i = 0;
	while (i < max_food)//优化下 不刷在障碍物里面   38 值得的是地图大小
	{
		int ty = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		int tx = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		if ((now_map[ty][tx]) == 1)
		{
			i++;
			m_food.push_back({ ty, tx, 0 });
		}
	}
}
void Cbuff::push_buff(){
	if (!Canmove(m_Fstart, m_stay)){
		return;
	}
	draw_buff((double)rand() / (RAND_MAX + 1) * (4 - 1) + 1);//随机刷1-3状态的BUFF
	//draw_buff(1); 
}
void Cbuff::draw_buff(int type){
	char * wall;
//	WORD  thead;
	wall = MAP_BUFF[type]; 
	WriteChar(27, 26, wall, BUFF_BG);
	now_map[27][26] = 20 + type;
	m_food.clear();
	m_food.push_back({ 27, 26 ,0 });
	m_food.push_back({ 23, 26, 0 });
	clearbuff();
	/*m_pfood = rand() % (max_food - 1);*/
	m_pfood = rand() % 2;
	WriteChar(m_food[m_pfood].nY, m_food[m_pfood].nX, wall, BUFF_BG);
	now_map[m_food[m_pfood].nY][m_food[m_pfood].nX] = 20 + type;
}
void Cbuff::clearbuff(){ 
	WriteChar(m_food[m_pfood].nY, m_food[m_pfood].nX, "  ", MAPBG);
	now_map[m_food[m_pfood].nY][m_food[m_pfood].nX] = 1;
}