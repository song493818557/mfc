#include "stdafx.h"
#include "AASART.h"
 
void Castar::Getpath(int now_map[40][40]){
	//1、将起点加入到open表中  结构体初始化  将起始坐标和坐标离终点的位置赋值
	STRSTAR First = { sTart, CalcH(sTart, eNd) };
	First.nF = First.nG + First.nH;
	m_Openlist.push_back(First);//将OPEN表装入设置好的第一个起始点坐标 
	//2、开始循环寻路  计算起点和终点的距离
	while (m_Openlist.size() != 0) //循环到没有可到达的方法为止
	{
		//3、从OPEN表中找出F最小的点
		int opensieze = m_Openlist.size();//获取当前的容器里面有多少个元素
		int MinF = m_Openlist[0].nF;//获取第一次存入的最小的 F  path
		int MinPos = 0;//X Y坐标等于0
		for (int i = 0; i < opensieze; i++)
		{
			if (MinF> m_Openlist[i].nF){//如果当前保存的MinF 大于当前遍历数组F PATH  就覆盖
				MinF = m_Openlist[i].nF;//可以达到找到最佳的那个坐标点
				MinPos = i;	 //保存当前元素的坐标？不确定				
			}
		}
		//4、将最小的点向四周扩散出四个点
		//4.1 将当前覆盖的MinPos的值创建四个数组 遍历
		STRSTAR minArray[4] = {
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos]
		};		//将创建的4个点进行区分赋值 分辨代表往上下左右  
	
		minArray[AUP].stcpos.nY = m_Openlist[MinPos].stcpos.nY - 1;
		minArray[AUP].stcpos.nP = 1;
		minArray[ADOWN].stcpos.nY = m_Openlist[MinPos].stcpos.nY + 1;
		minArray[ADOWN].stcpos.nP = 2;
		minArray[ALEFT].stcpos.nX = m_Openlist[MinPos].stcpos.nX - 1;
		minArray[ALEFT].stcpos.nP = 3;
		minArray[ARIGHT].stcpos.nX = m_Openlist[MinPos].stcpos.nX + 1;
		minArray[ARIGHT].stcpos.nP = 4;
		//将赋值好的数据保存到CLOSE表  因为即将要进行检测
		m_Closelist.push_back(m_Openlist[MinPos]);
		//4.2 开始遍历
		for (int i = 0; i < 4; i++)
		{
			bool checkstate = true;
			if (minArray[i].stcpos.nX == 0 ||
				minArray[i].stcpos.nX == 39 ||
				minArray[i].stcpos.nY == 0 ||
				minArray[i].stcpos.nY == 39
				)
			{
				checkstate = false;
			}

			 if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 1)
			{ 
				checkstate = false;
			}  

			//5.3  假如已经在COLSE表中
			for (int j = 0; j < (m_Closelist.size()); j++)
			{
				if (m_Closelist[j].stcpos.nY == minArray[i].stcpos.nY &&
					m_Closelist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}
			//5.4  已经在OPEN表中 待探测中
			for (int j = 0; j < m_Openlist.size(); j++)
			{
				if (m_Openlist[j].stcpos.nY == minArray[i].stcpos.nY &&
					m_Openlist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}
			//WriteChar(minArray[i].stcpos.nY, minArray[i].stcpos.nX, "◇", 0 | F_H_WHITE);
			//5.5 找到终点
			//minArray[i].stcpos.nY == eNd.nY  && minArray[i].stcpos.nX == eNd.nX
			if (abs(minArray[i].stcpos.nY - eNd.nY) < 2 && abs(minArray[i].stcpos.nX - eNd.nX) < 2){

				POSTION Father = m_Openlist[MinPos].Fatherpos;//保存当前的父节点
				m_Path.push_back(Father);//将当前的父节点坐标保存到成功的表里面去
				while (true)
				{
					for (int i = (m_Closelist.size()) - 1; i >= 0; i--)
					{
						if (Father.nX == m_Closelist[i].stcpos.nX &&
							Father.nY == m_Closelist[i].stcpos.nY)
						{
							m_Path.push_back(Father);//找到了对应的坐标 保存到成功的表里面去
							Father = m_Closelist[i].Fatherpos;
							break;
						}

					}
					if (Father.nX == sTart.nX && Father.nY == sTart.nY){
						return;
					}
				}
			}
			if (checkstate == true){
				//6 将不属于无效点的加入OPEN表中
				minArray[i].Fatherpos = m_Openlist[MinPos].stcpos;
				minArray[i].nG = m_Openlist[MinPos].nG + 1;
				minArray[i].nH = CalcH(minArray[i].stcpos, eNd);
				minArray[i].nF = minArray[i].nH + minArray[i].nG;
				m_Openlist.push_back(minArray[i]);
			}
		}
		//7 将选出的最小点从OPEN表中剔除 并且加入CLOSE 表
		m_Openlist.erase(m_Openlist.begin() + MinPos);

	}

}
void Castar::PrintPath()
{
	
	for (int i = 0; i < (m_Closelist.size()); i++)
	{
		//WriteChar(m_Closelist[i].stcpos.nY, m_Closelist[i].stcpos.nX, "卍", 0 | F_H_RED);
	}
	for (int i = 0; i < m_Path.size(); i++)
	{
		WriteChar(m_Path[i].nY, m_Path[i].nX, "◇", MAPBG);
	}
}

//获取H的值 即距离目的地的距离
int Castar::CalcH(POSTION pos_1, POSTION pos_2)
{
	return abs(pos_1.nX - pos_2.nX) + abs(pos_1.nY - pos_2.nY);
}
void Castar::WriteChara(int x, int y, char* szString)
{
	COORD pos = { x * 2, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf(szString);
}
void Castar::Setmap(){
	for (int y = 0; y < 40; y++)
	{
		for (int x = 0; x < 40; x++){
			if (x == 0 || y == 39 || x == 39 || y == 0){
				m_map[y][x] = 1;
			}
			else if (now_map[y][x] == 1){

				m_map[y][x] = 0;
			}
			else if (now_map[y][x] > 1 && now_map[y][x] < 7){
				m_map[y][x] = 1;
				m_map[y][x-1] = 1;
				m_map[y][x+1] = 1;
				m_map[y+1][x] = 1;
				m_map[y-1][x] = 1;
			} 
		} 
	}	  
}
void Castar::Drawmap(){
	for (int y = 0; y < 39; y++)
	{
		for (int x = 0; x < 39; x++){
			if (m_map[y][x] == 1){
				WriteChar(y, x, WALL1_D, WALL1_DC);
			} 
			else{
				WriteChar(y, x, "　",MAPBG);
			}
		} 
	} 
}

void Castar::reset(){
	m_Openlist.clear();
	m_Closelist.clear();
	sTart.nX = 0;
	sTart.nY = 0; 
	eNd.nX = 0;
	eNd.nY = 0; 
	m_Path.clear();
}