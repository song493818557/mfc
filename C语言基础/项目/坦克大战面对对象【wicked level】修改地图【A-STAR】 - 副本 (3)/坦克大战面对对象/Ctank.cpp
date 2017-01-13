#include "stdafx.h"
#include "Ctank.h"



/*
功能：检测坦克碰撞
position：方向
Y  X 坐标
tsize：物体所占大小 //打算A*用的
*/
bool Calltank::cheak_bump(Calltank &tank, int position, int uy, int ux){

	tank.t_position = position;
	int ty = tank.m_y;
	int tx = tank.m_x;
	ClerarTank(ty, tx);
	DrawTank(tank);
	switch (position)
	{
	case 0: ty -= 2; break;
	case 1: ty += 2; break;
	case 2:tx -= 2; break;
	case 3:tx += 2; break;
	}
	int check[] = { 1, 7, 13 };//能移动的元素,8 ,9, 13 
	int checkbuff[] = { 20, 21, 22 };//能移动的元素,8 ,9, 13 
	int checka[] = { 3, 4, 5, 6, 10, 11, 17, 18 };//不能移动的元素
	vector<int> temp_value;
	temp_value.push_back(now_map[ty][tx]);
	if (tx == tank.m_x)//代表是坐标Y改变了
	{
		temp_value.push_back(now_map[ty][tx - 1]);
		temp_value.push_back(now_map[ty][tx + 1]);
	}
	else if (ty == tank.m_y)//代表是坐标Y改变了
	{
		temp_value.push_back(now_map[ty - 1][tx]);
		temp_value.push_back(now_map[ty + 1][tx]);
	}
	//加上了BUFF系统后  不适合用这种方法
	//vector <int>::difference_type   df_typ1=0, df_typ2=0; 
	////俩个相加是否等于9
	//df_typ1 = count(temp_value.begin(), temp_value.end(), check[0]);
	//df_typ2 = count(temp_value.begin(), temp_value.end(), check[1]);
	int  buff_xy = 0;
	for (; buff_xy < 4; buff_xy++)//获取为空的BUFF状态下标
	{
		if (tank.buff_type[buff_xy] != 0) break;
	}
	for (int i = 0; i < 3; i++)
	{
		if (temp_value[i] == 1 || temp_value[i] == 7 || temp_value[i] == 13){}//检测是否可以通过
		//检测是否有BUFF
		else if (temp_value[i]> 19)  {
			//开启BUFF
			tank.buff_type[temp_value[i] - 20] = temp_value[i];
			tank.buff_Start[temp_value[i] - 20] = clock();
			tank.buff_state = true;
			clearbuff();
		}
		else  { return false; }
	}
	ClerarTank(tank.m_y, tank.m_x);
	tank.m_y = uy;
	tank.m_x = ux;
	DrawTank(tank);

	/*
	for (int i = 0; i < _countof(check);i++)
	{
	if (check[i] == temp_value[0]||
	check[i] == temp_value[1]||
	check[i] == temp_value[2])
	{
	}
	}*/
	//temp_value.
	//if ((now_map[ty][tx + 1] > 1 && now_map[ty][tx + 1] < 7 ||
	//	now_map[ty][tx	  ] > 1 && now_map[ty][tx	] < 7 ||
	//	now_map[ty][tx - 1] > 1 && now_map[ty][tx - 1] < 7) && 
	//	(now_map[ty][tx + 1] >= 10 ||
	//	 now_map[ty][tx	   ] >= 10 ||
	//	 now_map[ty][tx - 1] >= 10)){
	//	return false;
	//} 
	return true;

}
/*
功能： 检测坦克碰撞  【暂时没用】
position：方向
Y  X 坐标
tsize：物体所占大小 //打算A*用的
*/

/*
功能：画坦克
singbo：自定义图形 //但是好像会输出烫烫
color：自定义打印颜色
*/
void Calltank::DrawTank(Calltank &tank){
	int temp = 0;
	int temp_numb = 0;
	(tank.t_type == 1) ? temp = 10 : temp = 11;
	for (int i = 0, lie = tank.m_y - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tank.m_x - 1; j < 3; hang++, j++){
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] == 17 ||
				now_map[lie][hang] == 18 //坦克在草地中移动 元素   10 11   17 18都是 
				){
				now_map[lie][hang] = temp + 7;//设置草地中  坦克的值
				WriteChar(lie, hang, "∑", 0 | B_H_YELB_PURPLELOW);
			}
			else
			{
				int  kk = t_demo[tank.t_position][i][j] - 1;
				if (kk + 1 == 1){
					now_map[lie][hang] = temp;//设置空白地图 坦克的值
					WriteChar(lie, hang, "■", tank.t_bg);
				}
				//显示坦克BUFF

				else if (kk + 1 > 1 && tank.buff_state == true){
					char TANK_BUFF[][3] = { "55", WALL1_F, BUFF_SPEED_GRAPHICS, BUFF_SHIELD_GRAPHICS };
					//我方tankbuff时间*2  t_type 1  我方坦克 2 敌方坦克  
					int buff_time = tank.buff_time[kk];
					(tank.t_type == 1) ? buff_time = tank.buff_time[kk] * 2 : 1;
					clock_t  temptime = tank.buff_Start[kk];//用个临时变量接受开始的时间 有引用
					if ((tank.buff_type[kk] == kk + 20) && !Canmove(temptime, buff_time))
					{
						WriteChar(lie, hang, TANK_BUFF[kk], BUFF_BG);
						now_map[lie][hang] = temp;
						temp_numb++;
					}
					else { tank.buff_type[kk] = -1; }

					//if (t_demo[tank.t_position][i][j] == 2 && tank.buff_type[1] == 21){
					//	WriteChar(lie, hang, " |", BUFF_BG);
					//	//tank.gettankbuff(t_demo[tank.t_position][i][j],i,j);
					//}
					//else if (t_demo[tank.t_position][i][j] == 3 && tank.buff_type[2] == 22){
					//	WriteChar(lie, hang, BUFF_SPEED_GRAPHICS, BUFF_BG);
					//	//tank.gettankbuff(t_demo[tank.t_position][i][j],i,j);
					//}
					//else if (t_demo[tank.t_position][i][j] == 4 && tank.buff_type[3] == 23){
					//	WriteChar(lie, hang, BUFF_SHIELD_GRAPHICS, BUFF_BG);
					//	//tank.gettankbuff(t_demo[tank.t_position][i][j],i,j);
					//}

				}
			}
		}
	}
	if (temp_numb == 0) tank.buff_state = false;//更新BUFF 
}

/*
功能：清除坦克
*/
void Calltank::ClerarTank(int ty, int tx){

	for (int i = 0, lie = ty - 1; i < 3; lie++, i++){
		for (int j = 0, hang = tx - 1; j < 3; hang++, j++){
			if (now_map[lie][hang] == 7 ||//坦克第一次进草地
				now_map[lie][hang] == 17 ||
				now_map[lie][hang] == 18 //坦克在草地中移动 元素   10 11   17 18都是 
				){
				now_map[lie][hang] = 7;//设置坦克离开草地的值
				WriteChar(lie, hang, "∑", 0 | B_H_GREEN);
			}
			else
			{
				now_map[lie][hang] = 1;//设置坦克离开空白地的值
				WriteChar(lie, hang, "  ", MAPBG);

			}
		}
		//printf("\n");
	}
}
/*
功能：控制我方坦克移动  和玩家的键盘监控
*/

//void Cmytank::MoveStep(){
//
//}
//int y, int x, int type = 2
//void Calltank::MoveTank(){
//	 
//	//char ch;
//	//get_char(ch);
//	int ch;
//	get_Message(ch);
//	//if (ch == -52)  return;  
//	int uy = 0;
//	int ux = 0;
//	if (ch == 0x57 || ch == 0x41 || ch == 0x44 || ch == 0x53 || ch == 0x4A )
//	{
//		if (mytanka[0].buff_type[2] != 22)
//		{
//			if (!Canmove(mytanka[0].start, mytanka[0].t_speed / 2))return;
//		}
//		else{
//			if (!Canmove(mytanka[0].start, mytanka[0].t_speed / 10))return;
//		}
//		switch (ch)
//		{
//		case 0x57:{uy = mytanka[0].m_y - 1;  ux = mytanka[0].m_x;  cheak_bump(mytanka[0], 0, uy, ux);  }break;
//		case 0x53:{uy = mytanka[0].m_y + 1; ux = mytanka[0].m_x; cheak_bump(mytanka[0], 1, uy, ux); }break;
//		case 0x41:{ux = mytanka[0].m_x - 1; uy = mytanka[0].m_y; cheak_bump(mytanka[0], 2, uy, ux); }break;
//		case 0x44:{ux = mytanka[0].m_x + 1; uy = mytanka[0].m_y; cheak_bump(mytanka[0], 3, uy, ux); }break;
//			// 存子弹
//		case 0x4A:
//		{
//			mytanka[0].Firstball(mytanka[0].t_type, mytanka[0].b_tank, mytanka[0].t_position, mytanka[0].m_x, mytanka[0].m_y, mytanka[0].t_ball);
//		}break;
//		}
//	}
//	else
//	{
//		if (mytanka[1].buff_type[2] != 22)
//		{
//			if (!Canmove(mytanka[1].start, mytanka[1].t_speed / 2))return;
//		}
//		else{
//			if (!Canmove(mytanka[1].start, mytanka[1].t_speed / 8))return;
//		}
//		switch (ch)
//		{
//		case 0x26:{uy = mytanka[1].m_y - 1; ux = mytanka[1].m_x; cheak_bump(mytanka[1], 0, uy, ux);  }break;
//		case 0x28:{uy = mytanka[1].m_y + 1; ux = mytanka[1].m_x; cheak_bump(mytanka[1], 1, uy, ux); }break;
//		case 0x25:{ux = mytanka[1].m_x - 1; uy = mytanka[1].m_y; cheak_bump(mytanka[1], 2, uy, ux); }break;
//		case 0x27:{ux = mytanka[1].m_x + 1; uy = mytanka[1].m_y; cheak_bump(mytanka[1], 3, uy, ux); }break;
//			// 存子弹
//		case 0x4C: mytanka[1].Firstball(mytanka[1].t_type, mytanka[1].b_tank, mytanka[1].t_position, mytanka[1].m_x, mytanka[1].m_y, mytanka[1].t_ball); break;
//	}
//	}
//	// 游戏退出
//	//switch (ch){
//	//case 'q':case 'Q':
//	//{
//	//	int check_help = 0;
//	//	mytanka[1].myhelp(2);
//	//	mytanka[1].check_help(); 
//	//}break;
//	//case '\r':
//	//{
//	//	//if (menu_i == 0){
//	//	//	system("cls");
//	//	//	menu_i++;
//	//	//	game_menu(start_menu);
//	//	//}
//	//	//if (menu_i == 2){
//	//	//	system("cls");
//	//	//	menu_i++;
//	//	//	//strcpy(g_nMap, sysMap00 );
//	//	//	DrawMap();
//	//	//}
//	//	// 游戏退出
//	//}break; 
//	//}
//}
void Calltank::MoveTank(){

	char ch;
	get_char(ch);
	if (ch == -52)  return;
	int uy = 0;
	int ux = 0;
	if (ch == 0x57 || ch == 0x41 || ch == 0x44 || ch == 0x53 || ch == 0x4A)
	{
		if (mytanka[0].buff_type[2] != 22)
		{
			if (!Canmove(mytanka[0].start, mytanka[0].t_speed))return;
		}
		else{
			if (!Canmove(mytanka[0].start, mytanka[0].t_speed / 2))return;
		}
		switch (ch)
		{
		case 'w':case 0x57:{uy = mytanka[0].m_y - 1;  ux = mytanka[0].m_x;  cheak_bump(mytanka[0], 0, uy, ux);  }break;
		case 's':case 0x53:{uy = mytanka[0].m_y + 1; ux = mytanka[0].m_x; cheak_bump(mytanka[0], 1, uy, ux); }break;
		case 'a':case 0x41:{ux = mytanka[0].m_x - 1; uy = mytanka[0].m_y; cheak_bump(mytanka[0], 2, uy, ux); }break;
		case 'd':case 0x44:{ux = mytanka[0].m_x + 1; uy = mytanka[0].m_y; cheak_bump(mytanka[0], 3, uy, ux); }break;
			// 存子弹
		case 0x4A:
		{
			mytanka[0].Firstball(mytanka[0].t_type, mytanka[0].b_tank, mytanka[0].t_position, mytanka[0].m_x, mytanka[0].m_y, mytanka[0].t_ball);
		}break;
		}
	}
	else
	{
		if (mytanka[1].buff_type[2] != 22)
		{
			if (!Canmove(mytanka[1].start, mytanka[1].t_speed / 2))return;
		}
		else{
			if (!Canmove(mytanka[1].start, mytanka[1].t_speed / 8))return;
		}
		switch (ch)
		{
		case 0x26:{uy = mytanka[1].m_y - 1; ux = mytanka[1].m_x; cheak_bump(mytanka[1], 0, uy, ux);  }break;
		case 0x28:{uy = mytanka[1].m_y + 1; ux = mytanka[1].m_x; cheak_bump(mytanka[1], 1, uy, ux); }break;
		case 0x25:{ux = mytanka[1].m_x - 1; uy = mytanka[1].m_y; cheak_bump(mytanka[1], 2, uy, ux); }break;
		case 0x27:{ux = mytanka[1].m_x + 1; uy = mytanka[1].m_y; cheak_bump(mytanka[1], 3, uy, ux); }break;
			// 存子弹
		case 0x4C: mytanka[1].Firstball(mytanka[1].t_type, mytanka[1].b_tank, mytanka[1].t_position, mytanka[1].m_x, mytanka[1].m_y, mytanka[1].t_ball); break;
		}
	}
}




void Calltank::FindTank(int y, int x, int b_tank, int b_type, int i){
	int kk = 0;             //  在空白地图          在草地里
	if (now_map[y][x] == 10 || now_map[y][x] == 17 || now_map[y][x] == 11 || now_map[y][x] == 18){ //子弹打敌方坦克
		if (b_type == 1){//我方子弹打坦克
			for (int k = 0; k < check_Rebottank; k++)
			{
				//如果中心点差值大于2 应该就没有机会碰到坦克
				if (abs(reboottank[k].m_y - y) > 2 && abs(reboottank[k].m_x - x) > 2)  continue;
				for (int i = 0, lie = reboottank[k].m_y - 1; i < 3; lie++, i++){
					for (int j = 0, hang = reboottank[k].m_x - 1; j < 3; hang++, j++){
						if (lie == y && hang == x){

							if (reboottank[k].buff_state == true) {
								//检测无敌和护盾BUFF
								if (gettankbuff(mytanka[k], k)){ return; }
							}
							if (reboottank[k].t_hp > 0) reboottank[k].t_hp--;//判断HP是否大于0
							else if (reboottank[k].t_hp == 0){
								//如果坦克没有HP还有生命值的话
								//生命值 T_LIFE的处理交给刷新的地方
								//reboottank[k].ClerarTank();
								//reboottank[k].b_tank = 0;
								ClerarTank(reboottank[k].m_y, reboottank[k].m_x);
								reboottank[k].t_online = 0;
								check_Rebottank--;
							}
							return;
						}
					}
				}
			}
		}
		else //敌方子弹打我方坦克
		{

			for (int k = 0; k < Max_play; k++)
			{
				//如果中心点差值大于2 应该就没有机会碰到坦克
				if (abs(mytanka[k].m_y - y) > 2 && abs(mytanka[k].m_x - x) > 2 && mytanka[k].t_online == 0)
				{
					continue;
				}
				for (int i = 0, lie = mytanka[k].m_y - 1; i < 3; lie++, i++){
					for (int j = 0, hang = mytanka[k].m_x - 1; j < 3; hang++, j++){
						if (lie == y && hang == x){
							bool nSuceess = true;
							if (mytanka[k].buff_state == true) {
								//检测无敌和护盾BUFF
								if (gettankbuff(mytanka[k], k)) return;
							}
							if (mytanka[k].t_hp > 0) mytanka[k].t_hp--;//判断HP是否大于0
							else if (mytanka[k].t_hp == 0){
								//如果坦克没有HP还有生命值的话
								//生命值 T_LIFE的处理交给刷新的地方
								//reboottank[k].ClerarTank();
								//reboottank[k].b_tank = 0;
								ClerarTank(mytanka[k].m_y, mytanka[k].m_x);
								mytanka[k].t_online = 0;
								check_play--;
							}
							return;
						}
					}
				}
			}
		}

	}
	//敌方子弹 和我方子弹对碰  或者我方子弹与敌方子弹对碰
	else if (now_map[y][x] == 13){
		//int i = 0;
		for (int k = 0; k < 255; k++)
		{
			if (all_ball[k].b_x == x && all_ball[k].b_y == y  && all_ball[k].b_type != b_type){
				DrawBall(y, x, 0, 0 | F_H_GREEN);//清除当前位置的子弹 
				all_ball[k].isBullet = 0;//被碰撞的子弹
				all_ball[i].isBullet = 0;//发射的子弹
				return;
			}
		}
	}
}

/*
功能：根据敌方坦克在线数减一 + 我方杀敌数加一

*/
void Cmytank::MyKill(){
	now_max_kill--;//击杀数加1
	char ch[10] = {};
	_itoa_s(now_max_kill, ch, 10);
	WriteChar(7, 51, "  ", B_H_WHITE | B_H_WHITE);
	WriteChar(7, 51, ch, B_H_WHITE | B_H_WHITE);
}

//功能：我方坦克的自动刷新 自动生成 
void Cmytank::production_mytank(){
	for (int i = 0; i < Max_play; i++)
	{
		if (mytanka[i].t_online == 0){
			if (mytanka[i].t_life > 0){
				//我方坦克复活	 
				if (check_point(1, mytanka[i].m_y, mytanka[i].m_x))
				{
					char ch[8] = {};
					//_itoa_s(mytanka[i].t_life, ch, 9);
					_itoa_s(mytanka[i].t_life, ch, 8);
					if (i == 0){
						WriteChar(3, 51, "  ", B_H_WHITE | B_H_WHITE);
						WriteChar(3, 51, ch, B_H_WHITE | B_H_WHITE);
						mytanka[i].t_bg = TANK_G;
					}
					if (i == 1){
						WriteChar(5, 51, "  ", B_H_WHITE | B_H_WHITE);
						WriteChar(5, 51, ch, B_H_WHITE | B_H_WHITE);
						mytanka[i].t_bg = TANK_G1;
					}
					//开启BUFF
					mytanka[i].buff_type[1] = 21;
					mytanka[i].buff_Start[1] = clock();
					mytanka[i].buff_state = true;
					mytanka[i].t_online = 1;
					mytanka[i].b_tank = 6 + i;//我方坦克的
					mytanka[i].t_life--;
					mytanka[i].t_hp = 2;
					DrawTank(mytanka[i]);
					check_play = check_play + 1;
				}
			}
		}
		//MoveTank(mytanka[i]);
	}

}
/*
功能：所有坦克 和地图元素在新的游戏的初始化
*/
void Calltank::inInit_mytank(){
	//我方坦克初始化
	for (int i = 0; i < 2; i++)
	{
		mytanka[i].buff_type = { -1, -1, -1, -1 };
		mytanka[i].buff_Start = { 0, 0, 0, 0 };
		mytanka[i].buff_time = { 0, 1000, 80000, 3000 };
		mytanka[i].t_speed = 20;
		mytanka[i].t_hp = 2;
		mytanka[i].t_life = Tank_life;//生命值 私有值 
		mytanka[i].t_online = 0;//判定是否已经在线 私有值 
	}
	////敌方坦克初始化
	for (int i = 0; i < 5; i++)
	{
		reboottank[i].buff_type = { -1, -1, -1, -1 };
		reboottank[i].buff_Start = { 0, 0, 0, 0 };
		reboottank[i].t_speed = 40;
		reboottank[i].t_life = 1;//生命值 私有值 
		reboottank[i].buff_time = { 0, 1000, 80000, 3000 };
		reboottank[i].t_online = 0;//判定是否已经在线 私有值 
	}
	////子弹初始化
	for (int i = 0; i < 256; i++)
	{
		all_ball[i].isBullet = 0;//判定子弹是否可用 私有值 
	}
}
/*
功能：所有坦克 判断所有坦克的速度
*/

/*
功能：机器人坦克自动移动 发射子弹
*/
bool CenemyTank::move_enemy(CenemyTank &tank, int aa)
{
	//时间片 判断当前坦克是否符合移动时间
	if (!Canmove(tank.start, tank.t_speed)){
		return false;
	}
	if (tank.t_online == 0)
	{
		return false;
	}
	int y = tank.m_y;
	int x = tank.m_x;
	switch (aa)
	{
	case 1:{y--;  cheak_bump(tank, 0, y, x); }break;
	case 2:{y++;  cheak_bump(tank, 1, y, x); }break;
	case 3:{x--;  cheak_bump(tank, 2, y, x); }break;
	case 4:{x++;  cheak_bump(tank, 3, y, x); }break;
	case 5:
	{
		int bb = rand() % 10;//限制一定30%的几率才能发出子弹
		if (bb < 5){
			Firstball(tank.t_type, tank.b_tank, tank.t_position, tank.m_x, tank.m_y, tank.t_ball);
			tank.realfind = true;
		}
	}break;
	}
	return true;
};
//功能：敌方坦克的自动刷新 自动生成 
void CenemyTank::production_enemy(){
	for (int i = 0; i < Max_Rebottank; i++)
	{
		//如果当前元素没有刷新		
		if (reboottank[i].t_online == 0)
		{
			reboottank[i].b_tank = i;
			reboottank[i].t_bg = i + 1;
			reboottank[i].t_hp = 2;//每次进到这里来 HP重新设置成2
			if (reboottank[i].t_life == 0)
			{
				if (now_max_kill > 0) {
					mytanka[0].MyKill();
				}
				reboottank[i].t_life = 1;
				reboottank[i].t_online = 0;
			}
			else
			{
				reboottank[i].t_life--;
				//随机刷新位置
				if (check_point(0, reboottank[i].m_y, reboottank[i].m_x))
				{
					DrawTank(reboottank[i]);
					reboottank[i].t_online = 1;
					check_Rebottank++;
				}
			}
			//Max_Rebottank--;
		}
		if (reboottank[i].Wayfind == false && reboottank[i].realfind == true){
			bool distance = abs(reboottank[i].m_x - mytanka[0].m_x) > 6 || abs(reboottank[i].m_y - mytanka[0].m_y) > 6;//判断下开启寻路的距离条件
			if (distance)
			{
				reboottank[i].t_speed = 20;
				reboottank[i].sTart = { reboottank[i].m_y, reboottank[i].m_x, reboottank[i].t_position };
				reboottank[i].eNd = { mytanka[0].m_y, mytanka[0].m_x, mytanka[0].t_position };
				reboottank[i].Wayfind = 1;
			}
		}

		if (reboottank[i].Wayfind == false){
			int randnumb = rand() % 6; //不是自动寻路就用随机的
			reboottank[i].move_enemy(reboottank[i], randnumb);
		}
		else
		{
			reboottank[i].Wayfind_enemy(reboottank[i], i);
		}
	}
}
bool Calltank::check_point(int b_type, int &y, int &x){
	int temp_y[] = { 2, 37 };
	int temp_x[][3] = { { 2, 37, 25 }, { 10, 30, 37 } };
	//我方坦克刷新点
	int tempmax = _countof(temp_x[b_type]);
	for (int p = 0; p < tempmax; p++)
	{
		bool nSucess = true;
		int ty = temp_y[b_type] - 1;
		int tx = temp_x[b_type][p] - 1;
		/*检测九宫格是否都为空 可以进行刷新*/
		for (int i = 0; i < 3; ty++, i++){
			for (int j = 0; j < 3; tx++, j++){
				if (now_map[ty][tx] != 1)
				{
					nSucess = false;
					break;
				}
			}
			if (!nSucess) { break; }
		}
		if (nSucess) {
			y = temp_y[b_type];
			x = temp_x[b_type][p];
			return true;
		}
	}
	return false;
}
void CenemyTank::Wayfind_enemy(CenemyTank &aa, int tankid){
	//操作最大的M_PATH的值 就是离坦克最近的那个值
	int temp = aa.m_Path.size() - 1;
	//如果没有合适的路线 就再寻找一次
	if (temp <= 0){
		aa.Setmap();//新增地图
		//aa.Drawmap();
		aa.Getpath(now_map);
		aa.PrintPath();
		temp = aa.m_Path.size() - 1;
	}
	//如果TEMP == 2 那么应该结束寻路了
	if ((aa.m_Path.size() - 1) < 2 || (aa.m_Path.size() == 0))
	{
		reset();//将这次寻路的数据都清除 
		aa.Wayfind = false;
		aa.realfind = false;
		aa.t_speed = 50;
		temp = 0;
		return;
	}
	//之前没注意 如果移动延时的时间没加进去 就程序就会不同步
	bool  move_ok = true;
	move_ok = move_enemy(aa, aa.m_Path[temp].nP);
	if (move_ok){
		//移动完删除最后面的位置
		aa.m_Path.erase(aa.m_Path.begin() + temp);
		int bb = rand() % 100;//限制一定30%的几率才能发出子弹
		if (bb < 30){
			if (aa.m_x == mytanka[0].m_x || aa.m_y == mytanka[0].m_y ||
				aa.m_x == mytanka[0].m_x + 1 || aa.m_y == mytanka[0].m_y + 1 ||
				aa.m_x == mytanka[0].m_x - 1 || aa.m_y == mytanka[0].m_y - 1
				)
			{
				aa.Firstball(aa.t_type, aa.b_tank, aa.t_position, aa.m_x, aa.m_y, aa.t_ball);
			}
		}
	}


}

 