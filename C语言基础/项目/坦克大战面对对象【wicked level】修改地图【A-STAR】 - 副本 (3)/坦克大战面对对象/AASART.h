#pragma once
#include "map.h"
//A star
class Castar :public  Cmap{
public:
	//设置地图  起点 终点
	void Setmap();
	void Drawmap();
	void Getpath(int now_map[40][40]);
	void PrintPath();
	void reset();
	POSTION sTart;
	POSTION eNd;
	vector<POSTION> m_Path; //最终结果
private:
	vector<STRSTAR> m_Openlist; //待探测
	vector<STRSTAR> m_Closelist;//已经探测
	int m_map[40][40];
	//计算当前位置到终点的绝对值 x
	int CalcH(POSTION pos_1, POSTION pos_2);
	void WriteChara(int x, int y, char* szString);
};

