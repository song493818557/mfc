#pragma once
#include "AASART.h"

class Cbuff : public Cmap {
	/*
	BUFF系统	显示  逻辑判断
	无敌
	加速
	护盾(抵挡一棵子弹) 圈
	*/
public:
	Cbuff(){ 	}
	bool buff_state = false;//buff的状态
	vector<int> buff_type; //将当前坦克获取到的BUFF可以依次保存到数组 达到BUFF的效果可以叠加 同一BUFF的时间是覆盖的 
	vector<clock_t> buff_Start;//当前坦克的BUFF计时开始容器 
	vector<int> buff_time; //当前坦克的BUFF停留时间容器  
	static void clearbuff();
	static void creat_buff();
	static void push_buff();
private:
	static clock_t m_Fstart;//在当前地图存活时间计时开始
	static int m_stay;//在当前地图存活的总时间
	static int m_pfood;
	static int max_food;
	static vector<POSTION> m_food;//buff的数组 包括坐标 和方向 
	static void draw_buff(int type);

};
