#include "stdafx.h"
#include "map.h"
#include <wtypes.h>
static CenemyTank reboottank[5];
Cball all_ball[256];
int Calltank::t_demo[4][3][3] = {
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
};

int Cmap::now_map[40][40] = { 0 };

void Cmap::DrawMap(){
	for (int i = 0; i < 40; i++){
		for (int j = 0; j < 40; j++)
		{
			if (Cmap::now_map[i][j] == 1){
				WriteChar(i, j, "  ", 0);
			}
			else if (Cmap::now_map[i][j] == 2){

				WriteChar(i, j, "▓", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 3){
				WriteChar(i, j, "卍", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 4){
				WriteChar(i, j, "〓", F_YELLOW);
			}
			else if (Cmap::now_map[i][j] == 5){
				WriteChar(i, j, "≈", F_H_WHITE | B_BLUE);
			}
			else if (Cmap::now_map[i][j] == 6){
				WriteChar(i, j, "■", B_H_WHITE);
			}
			else if (Cmap::now_map[i][j] == 7){
				WriteChar(i, j, "∑", 0 | B_H_GREEN);
			}
			else if (Cmap::now_map[i][j] == 8){
				WriteChar(i, j, "※", 0 | B_H_YELB_PURPLELOW);
			} //else{}
		}

	}
}
bool Cmap::cheak_bump(int position, int y, int x, int tsize){
	//now_map 之前用的
	//现在需要添加
	/*
	#define WALL_E    0x7  // ≡   丛林 （隐身）
	#define WALL_F    0x8  // ※  高速路（加速）
	
	int  a;
	int  b;
	int  c;*/
	switch (position)
	{
	case 0:
	{
		y = y - 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;
		}
		if (now_map[y][x + 1] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y][x - 1] >= 10){
			return false;
		}
		/* a = cheak_Tank_bump(position, y - 2, x + 1, 9);
		 b = cheak_Tank_bump(position, y - 2, x - 1, 9);
		 c = cheak_Tank_bump(position, y - 2, x, 9);*/
	}break;
	case 1:
	{
		y = y + 2;
		if (now_map[y][x + 1] > 1 && now_map[y][x + 1] < 7 ||
			now_map[y][x] > 1     && now_map[y][x] < 7 ||
			now_map[y][x - 1] > 1 && now_map[y][x - 1] < 7){
			return false;

		}
		if (now_map[y][x + 1] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y][x - 1] >= 10){
			return false;
		}

	}break;
	case 2:
	{
		x = x - 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y    ][x] > 1 && now_map[y    ][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		if (now_map[y + 1][x] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y - 1][x] >= 10){
			return false;
		}
		/*a = cheak_Tank_bump(position, y + 1, x + 2, 9);
		b = cheak_Tank_bump(position, y - 1, x + 2, 9);
		c = cheak_Tank_bump(position, y,     x + 2, 9);*/


	}break;
	case 3:
	{
		x = x + 2;
		if (now_map[y - 1][x] > 1 && now_map[y - 1][x] < 7 ||
			now_map[y][x] > 1 && now_map[y][x] < 7 ||
			now_map[y + 1][x] > 1 && now_map[y + 1][x] < 7){
			return false;

		}
		if (now_map[y + 1][x] >= 10 ||
			now_map[y][x] >= 10 ||
			now_map[y - 1][x] >= 10){
			return false;
		}
		/*
		a = cheak_Tank_bump(position, y + 1, x - 2, 9);
		b = cheak_Tank_bump(position, y - 1, x - 2, 9);
		c = cheak_Tank_bump(position, y,     x - 2, 9);*/

	}break;

	default:
		break;
	}
	//if ((a + b + c) <3)
	//{

	//	return FALSE;
	//	
	//}
	return true;

}

bool Cmap::cheak_Tank_bump(int position, int y, int x, int tsize){
	//now_map 之前用的
	//现在需要添加
	/*
	#define WALL_E    0x7  // ≡   丛林 （隐身）
	#define WALL_F    0x8  // ※  高速路（加速）
	||
	now_map[y - 3][x] > 1 && now_map[y - 3][x] < 7 ||
	now_map[y - 3][x - 1] > 1 && now_map[y - 3][x - 1] < 7
	*/
	if (now_map[y][x] > 1 && now_map[y][x] < 7)
	{

		return FALSE;
	}
	return true;

}

void Calltank::DrawTank(char singbo[3] = "■", int color = F_WHITE){
	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
				
			int temp = 0;
			if (t_type == 1 ){
				temp = 10;
			}
			else if (t_type == 2 ){
				temp = 11;
			}
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] > 16//坦克在草地中移动 元素   10 11   17 18都是 
				){
				temp += 7;
				now_map[lie][hang] = temp;//设置草地中  坦克的值
				WriteChar(lie, hang, "∑", 0 | B_H_YELB_PURPLELOW);
				
			}
			else
			{
				if (t_demo[t_position][i][j] == 1){
					now_map[lie][hang] = temp;//设置空白地图 坦克的值
					WriteChar(lie, hang, "■", color);

				}
			}
			
			
			//printf("%d", tankfire.t_demo[tposition][i][j]);
		}
		//printf("\n");
	}
}
void Calltank::ClerarTank(){

	for (int i = 0, lie = m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = m_x - 1; j < 3; hang++, j++){
			//WriteChar(tankfire.m_y, tankfire.m_x, "■", ' ');
			
			
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] > 16//坦克在草地中移动 元素   10 11   17 18都是 
				){
				now_map[lie][hang] = 7;//设置坦克离开草地的值
				WriteChar(lie, hang, "∑", 0 | B_H_GREEN);

			}
			else
			{			
				/*if (now_map[i][j] == 6){ 
					WriteChar(lie, hang, "■", F_WHITE); 
					now_map[lie][hang] = 6;
				}
				else{}*/
				now_map[lie][hang] = 1;//设置坦克离开空白地的值
				WriteChar(lie, hang, "  ", F_WHITE);
				
			}			
		}
		//printf("\n");
	}
}

void Cmytank::MoveTank(){

	if (!_kbhit())
	{
		return;
	}
	unsigned	char ch = _getch();
	if (ch == 0xe0)
	{
		char ch1 = _getch();
		ch = ch1;
	}
	switch (ch)
	{

	case 'w':case 'W':case 'H':
	{
		t_position = 0;
		ClerarTank();
		DrawTank();
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{//WriteChar(m_y, menu_x, menu_char1, wArr);

			ClerarTank();
			m_y--;
			DrawTank();


		}
		//WriteChar(menu_y, menu_x, menu_char, wArr);

		// 操作坦克
	}break;
	case 's':case 'S':case 'P':
	{
		t_position = 1;
		ClerarTank();
		DrawTank();
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){

			ClerarTank();
			m_y++;
			DrawTank();
		}
		// 操作坦克
	}break;
	//确定选择 开始进入判断做什么功能的操作 传Y坐标

	case 'a':case 'A':case 'K':
	{
		t_position = 2;
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){
			ClerarTank();

			m_x--;
			DrawTank();

		}
		// 操作坦克
	}break;
	case 'd':case 'D':case 'M':
	{
		t_position = 3;
		bool cheak_bumpa = Cmap::cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa){
			ClerarTank();
			m_x++;
			DrawTank();


		}
		// 操作坦克
	}break;
	// 存子弹
	case 'j':case 'J':
	{
		Firstball(t_type, b_tank, t_position, m_x, m_y, t_ball);

	}break;
	// 游戏退出
	case 'q':case 'Q':
	{

	}break;
	case '\r':
	{
		//if (menu_i == 0){
		//	system("cls");
		//	menu_i++;
		//	game_menu(start_menu);
		//}
		//if (menu_i == 2){
		//	system("cls");
		//	menu_i++;
		//	//strcpy(g_nMap, sysMap00 );
		//	DrawMap();
		//}
		// 游戏退出
	}break;
	default:
		break;
	}
}

void Cball::Firstball(int typea, int b_tank ,int position, int b_x, int b_y, char *ball_style){
	for (int i = 0; i < 256; i++)
	{
		int check_a = 0;
		int check_b = 0;
		//考虑当前的值
		//if (now_map[b_y][b_x] > 1){ check_b = 2; }
		// all_ball[i].isBullet 可用之前 判断子弹是否越界
		//如果当前数组子弹还在运行 就不遍历下一个
		if (all_ball[i].isBullet != 0)
		{
			continue;
		}
		else
		{
			switch (position)
			{
			case 0:
			{

				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y - 2;
				if (now_map[b_y - 2][b_x] > 1){					check_b = 2;				}
				if (all_ball[i].b_y >= 1){ check_a = 1; }
			}break;
			case 1:
			{
				
				all_ball[i].b_x = b_x;
				all_ball[i].b_y = b_y + 2;
				if (now_map[b_y + 2][b_x] > 1){ check_b = 2; }
				if (all_ball[i].b_y < 39){ check_a = 1; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }
			}break;
			case 2:
			{
				
				all_ball[i].b_x = b_x - 2;
				all_ball[i].b_y = b_y;
				if (all_ball[i].b_x >= 1){ check_a = 1; }
				if (now_map[b_y][b_x - 2] > 1){ check_b = 2; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }

			}break;
			case 3:
			{
				
				all_ball[i].b_x = b_x + 2;
				all_ball[i].b_y = b_y;
				if (all_ball[i].b_x <= 38){ check_a = 1; }
				if (now_map[b_y][b_x + 2] > 1){ check_b = 2; }
				//else if (now_map[b_x][b_y - 1] > 1){ check_b = 2; }

			}break;
			}
			if (check_a == 1)
			{
				all_ball[i].isBullet = 1;
				all_ball[i].b_position = position;//朝向
				all_ball[i].b_type = typea;//坦克子弹敌我
				all_ball[i].b_tank = b_tank;//那个坦克发的子弹
				if (all_ball[i].b_type == 10){
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, all_ball[i].wArr);
					}
				}
				else{
					//char t_ball[3] = "⊙";
					//敌军
					all_ball[i].wArr = 0 | F_H_GREEN;
					if (check_b == 0){
						DrawBall(all_ball[i].b_y, all_ball[i].b_x, 1, all_ball[i].wArr);
					}
				}


			}
			break;


		}

	}

}
//循环子弹
void Cball::tank_ball()
{
	for (int i = 0; i < 256; i++)
	{
		//all_ball[i]
		int ay = all_ball[i].b_y;
		int ax = all_ball[i].b_x;
		if (all_ball[i].isBullet == 0)
		{
			continue;
		}
		else
		{
			int a = 0;//判断是否隐藏子弹 1隐藏 0 不隐藏
			if ((now_map[ay][ax] == 5) ||
				(now_map[ay][ax] == 7) ||
				(now_map[ay][ax] == 8) ||
				(now_map[ay][ax] == 9))
			{
				a = 1;
			}//隐藏 a
			else
			{
				
				if ((now_map[ay][ax] == 6)){
					
					all_ball[i].isBullet = 0;
					break;
				}
				//WriteChar(all_ball[i].b_y, all_ball[i].b_x, "  ", 0 | F_H_GREEN);
				DrawBall(all_ball[i].b_y, all_ball[i].b_x, 0, F_H_GREEN);
				
			}
			switch (all_ball[i].b_position)
			{
			case 0:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay - 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y > 0)) {
						all_ball[i].b_y--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 1:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay + 1, ax, 1, i))
				{
					if (a = 1 && (all_ball[i].b_y < 40)) {
						all_ball[i].b_y++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 2:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax - 1, 1, i))
				{
					if (a = 1 && (ax > 0)) {
						all_ball[i].b_x--;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			case 3:
			{
				//子弹类型（敌我） 朝向 Y坐标 X坐标 子弹体积 当前数组 
				if (cheak_ball_bump(all_ball[i].b_type, all_ball[i].b_position, ay, ax + 1, 1, i))
				{
					if (a = 1 && (ax < 40)) {
						all_ball[i].b_x++;
						continue;
					}
				}
				else
				{
					all_ball[i].isBullet = 0;
					continue;
				}
			}break;
			}

		}
	}
}

void Cmap::DrawBall(int y, int x, int balltype, WORD wArr = 0){
	
	if (balltype == 1 ){
		WriteChar(y, x, "◎", wArr);
		now_map[y][x] = 13;
	}
	else
	{
		WriteChar(y, x, "  ", wArr);
		now_map[y][x] = 1;
	}

	

}

//检测子弹
bool Cmap::cheak_ball_bump(int typea, int position, int y, int x, int tsize, int i){
	// || now_map[y + 1][x] == 6 || now_map[y - 1][x] == 6 || now_map[y][x - 1] == 6 || now_map[y][x + 1] == 6
	if (now_map[y][x] == 6)
	{
		all_ball[i].isBullet = 0;
		return true;
	}
	//河流 丛林 高速路 箱子 子弹经过不会清除 选择不打印子弹 坐标增加
	else if ((now_map[y][x] == 5) || (now_map[y][x] == 7) || (now_map[y][x] == 8) || (now_map[y][x] == 9))
	{
		switch (now_map[y][x])
		{
		case 5:
		{
			WriteChar(y, x, "≈", F_H_PURPLE);
		}break;
		case 7:
		{
			WriteChar(y, x, "∑", B_GREEN);
		}break;
		case 9://buff
		{
			WriteChar(y, x, "※", B_H_WHITE);
		}break;
		}
	}
	else if (now_map[y][x] > 1 && now_map[y][x] < 5)
	{
		all_ball[i].isBullet = 0;
		//尝试子弹计算墙体厚度;
		if (now_map[y][x] < 4){
			now_map[y][x] = 1;
		//	WriteChar(y, x, "  ", F_H_GREEN | 0);
			DrawBall(y, x, 0, 0 | F_H_GREEN);
		}
		else
		{
			now_map[y][x]--;
		}
		return false;
	}
	else if (now_map[y][x] > 9)
	{ 
		//t_type子弹类型 1 是我方子弹 2是敌方子弹   敌方坦克 11 我方坦克10  坦克 的ID号是 b_tank
		//我方子弹打敌方坦克   b_tank 好像暂时无效
			reboottank[i].FindTank(y, x, all_ball[i].b_tank, typea,i);	
			
		return false;
	}
	else if (now_map[y][x] == 1)
	{

		DrawBall(y, x, 1, 0 | F_H_GREEN);

		return true;
	}

}
//第三个参数好像没啥用
void Calltank::FindTank(int y, int x, int b_tank, int b_type,int i ){
	int kk = 0;             //  在空白地图          在草地里
	if (b_type == 1 && (now_map[y][x] == 11 || now_map[y][x] == 18)){ //子弹打敌方坦克
		for (int k = 0; k < check_Rebottank; k++)
		{
			//如果中心点差值大于2 应该就没有机会碰到坦克
			if (abs(reboottank[k].m_y - y) > 2 && abs(reboottank[k].m_x - x) > 2)
			{
				continue;
			}
			for (int i = 0, lie = reboottank[k].m_y - 1; i < 3; lie++, i++){
				for (int j = 0, hang = reboottank[k].m_x - 1; j < 3; hang++, j++){
					if (lie == y && hang == x){
						reboottank[k].ClerarTank();
						reboottank[k].b_tank = 0;
						reboottank[k].t_online = 0;
						check_Rebottank--;
						kk = k;
						return;
					}
				}
			}
		}
	
	}
	//敌方子弹 和我方子弹对碰  或者我方子弹与敌方子弹对碰
	else if ( now_map[y][x] == 13){
		//int i = 0;
		for (int k = 0; k < 255; k++)
		{
			if (all_ball[k].b_x == x && all_ball[k].b_y == y  && all_ball[k].b_type != b_type){
				//清除当前位置的子弹 
				DrawBall(y, x, 0, 0 | F_H_GREEN);
				all_ball[k].isBullet = 0;//被碰撞的子弹
				all_ball[i].isBullet = 0;//发射的子弹
				return;
			}
		}

		//FindTank(reboottank[i].b_tank, reboottank[i].b_type);

	}
	else if (b_type == 3 && now_map[y][x] == 13){

		return ;
		//FindTank(reboottank[i].b_tank, reboottank[i].b_type);

	}
}


//机器人坦克自动移动
void CenemyTank::move_enemy()
{

	int aa = rand() % 5;
	switch (aa)
	{
	case 1:
	{
		t_position = 0;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);

		if (cheak_bumpa)
		{
			ClerarTank();
			m_y--;
			DrawTank("■", t_bg);
		}

	}break;
	case 2:
	{
		t_position = 1;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{
			ClerarTank();
			m_y++;
			DrawTank("■", t_bg);
		}
	}break;

	case 3:
	{

		t_position = 2;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{
			ClerarTank();
			m_x--;

			DrawTank("■", t_bg);
		}
	}
	break;
	case 4:
	{
		t_position = 3;
		bool cheak_bumpa = cheak_bump(t_position, m_y, m_x, 9);
		if (cheak_bumpa)
		{	//WriteChar(tankfire.m_y, menu_x, menu_char1, wArr);
			ClerarTank();
			m_x++;

			DrawTank("■", t_bg);
		}
	}
	case 5:
	{
		int bb = rand() % 100;
		if (bb < 20){
		Firstball(t_life, b_tank, t_position, m_x, m_y, t_ball);
		}
		// 发射子弹  没做子弹判断敌我
	}break;
	default:
		break;
	}
};
//坦克的自动刷新 自动生成 自动移动
void CenemyTank::production_enemy(){
	for (int i = 0; i < Max_Rebottank; i++)
	{
		//如果当前元素没有刷新 
		
		if (reboottank[i].t_online == 0)
		{
			//画坦克
			
			reboottank[i].t_online = 1;
			reboottank[i].m_x = 7;
			reboottank[i].m_y = 20;
			reboottank[i].b_tank = i;
			reboottank[i].t_bg = i+1;
			reboottank[i].DrawTank("■", t_bg);
			reboottank[i].move_enemy();
			check_Rebottank++;
			//Max_Rebottank--;
		}
		else
		{
			//如果在线就开始让他自己操作
			reboottank[i].move_enemy();
		}
	}
}

