#include "stdafx.h"
#include "Csnake.h"


Csnake::Csnake()
{
}


Csnake::~Csnake()
{
}
void Csnake::map_inInit(){
	 DrawMap();
	  m_speed = 30;
	  m_Sstart = 0;
	  m_checkover = 1; 
	  m_level = 1 ;//当前等级
	  m_max = 50;//最大长度
	  m_now = 2;//当前长度
	  m_snake.push_back({ UP, 25, 25, F_GREEN | F_RED });
	  m_snake.push_back({ UP, 24, 25, F_GREEN | F_GREEN });
	 draw_snake();
}
//type = 1 画  type = 2 清除
void Csnake::draw_snake(int type){
	int temp = m_snake.size(); 
	char * wall; 
	WORD tcolor,thead;
	bool nmapFull = true;//地图应该填充0或者1
	if (type == 1) { wall = WALL1_B; tcolor = B_WHITE | B_WHITE;  thead = B_WHITE | F_RED; }
	else{ wall = "  "; tcolor = H_H_H;  thead = H_H_H; nmapFull = false; }
	for (int i = 0; i < m_snake.size(); i++)
	{
		if (i == 0) { WriteChar(m_snake[i].p_y, m_snake[i].p_x, wall, thead); }
			   else{ WriteChar(m_snake[i].p_y, m_snake[i].p_x, wall, tcolor); } 
			   now_map[m_snake[i].p_y][m_snake[i].p_x] = nmapFull;
	}

}
bool Csnake::check_snake(int d ,int y, int x){
	if (now_map[y][x] == 1) { m_checkover = 3; return 1; } //判断是否撞到了障碍物
	if (m_snake.size() == m_max){ m_checkover = 2; return 1; }//判断是否撞到了障碍物
	if (now_map[y][x] == 2)//判断是否吃到了食物
	{
		m_snake.push_back(m_snake[m_now - 1]);
		switch (m_snake[m_now].p_direction)
		{
		case UP:  m_snake[m_now].p_y++; break;  
		case DOWN:  m_snake[m_now].p_y--; break;
		case LEFT:  m_snake[m_now].p_x++; break;
		case RIGHT:  m_snake[m_now].p_x--; break;
		}
		++m_now;
	}
	for (int i = m_now -1; i > 0; i--)
	{
		m_snake[i] = m_snake[i - 1];
	}
	m_snake[0] = { d, y, x, 1 | 1 };
}
void Csnake::check_key()
{
	if (!_kbhit()) return;
	unsigned	char ch = _getch();
	if (ch == 0xe0)
	{
		char ch1 = _getch();
		ch = ch1;
	}
	switch (ch)
	{
	case 'w':case 'W':case 'H': m_snake[0].p_direction != DOWN ? m_snake[0].p_direction = UP : 1; break;
	case 's':case 'S':case 'P': m_snake[0].p_direction != UP ? m_snake[0].p_direction = DOWN : 1;  break;
	case 'a':case 'A': case 'K':m_snake[0].p_direction != RIGHT ? m_snake[0].p_direction = LEFT : 1; break;
	case 'd':case 'D': case 'M':m_snake[0].p_direction != LEFT ? m_snake[0].p_direction = RIGHT : 1; break;
	case 'q':case 'Q':
	{
		int check_help = 0;
		myhelp(2);
		//check_help();
	}break;
	case '\r':
	{
		// 游戏退出
	}break;
	default: return;
	}
}
void Csnake::snake_move(){
	//时间片 判断当前蛇是否符合移动时间
	if (!Canmove(m_Sstart, m_speed)){
		return;
	}
	check_key();
	int y = m_snake[0].p_y;
	int x = m_snake[0].p_x;
	draw_snake(0);
	switch (m_snake[0].p_direction)
	{
	case UP: { check_snake(m_snake[0].p_direction, --y, x); } break;
	case DOWN:  check_snake(m_snake[0].p_direction,++y, x); break;
	case LEFT:  check_snake(m_snake[0].p_direction,y, --x); break;
	case RIGHT:  check_snake(m_snake[0].p_direction,y, ++x); break;
	}
	if (m_checkover == 1){  draw_snake(1); }
	else if (m_checkover == 2)Printf_lost_win(1);
	else { Printf_lost_win(2); }
}
//时间片 判断当前坦克是否符合移动时间
bool Cganme::Canmove(clock_t &nStart, int nSpeed){
	clock_t nSfinish = clock();//截至到当前 是否可以动作
	double  duration;
	duration = nSfinish - nStart; /// CLOCKS_PER_SEC;
	if ((duration / 5) >= nSpeed)//判断允许是否移动
	{
		nStart = clock(); //移动后 重新进行计数 
		return true;
	}
	else
	{
		return false;
	}

}


void Cfood::creat_food(){
	max_food = max_food+50;
	m_Fstart = clock();
	 for (int i = 0; i < max_food;)
	{
		int ty = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		int tx = (double)rand() / (RAND_MAX + 1) * (38 - 1) + 1;
		if ()
		{
		}
		i++;
		m_food.push_back({ ty, tx, 0 });
	} 
	
} 
void Cfood::push_food(){
	if (!Canmove(m_Fstart, m_stay)){
		return;
	}
	draw_food(1);
}
void Cfood::draw_food(int type){
	char * wall;
	WORD  thead;
	if (type == 1) { wall = FOOD;   thead = FOOD_COLOR; } 
	else
	{
		return;
	} 
	WriteChar(27, 26, wall, thead);
	now_map[27][26] = 2;
	/*WriteChar(m_food[m_pfood].p_y, m_food[m_pfood].p_x, "  ", H_H_H);
	now_map[m_food[m_pfood].p_y][m_food[m_pfood].p_x] == 0;
	 m_pfood = rand() % (max_food - 1);
	 WriteChar(m_food[m_pfood].p_y, m_food[m_pfood].p_x, wall, thead);
	 now_map[m_food[m_pfood].p_y][m_food[m_pfood].p_x] == 2;*/
}