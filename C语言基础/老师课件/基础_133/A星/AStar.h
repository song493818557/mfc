#pragma once
#include <Windows.h>
#define MAP_X 40
#define MAP_Y 40
#include <vector>
using std::vector;
enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};
typedef struct _POSITION
{
	int nX;  //坐标X
	int nY;
}POSITION, *LPPOSITION;

typedef struct _NODE
{
	POSITION stcPos; //坐标
	int nH;          //距离目标估算距离
	int nG;          //移动的损耗
	int nF;          //G+H，用于选择最优点
	POSITION stcFatherPos;//父节点的坐标
}NODE, *PNODE;

class CAStar
{
public:
	CAStar();
	~CAStar();
public:

	void SetInfo(POSITION stcBegin, POSITION stcEnd)
	{
		m_stcBegin = stcBegin;
		m_stcEnd = stcEnd;
	}
	void SetInfo(int nBegin_x, int nBegin_y, int End_x, int End_y)
	{
		m_stcBegin.nX = nBegin_x;
		m_stcBegin.nY = nBegin_y;
		m_stcEnd.nX = End_x;
		m_stcEnd.nY = End_y;
		m_Map[m_stcBegin.nY][m_stcBegin.nX] = 2;
		m_Map[m_stcEnd.nY][m_stcEnd.nX] = 3;
	}
	void SetMap(int Map[][40] = NULL)//int (*p)[40]
	{
		if (Map == NULL)
		{
			for (int x = 0; x < MAP_X; x++)
				for (int y = 0; y < MAP_Y; y++)
				{
					if (x == 0 || x == 39 || y == 0 || y == 39)
					{
						m_Map[y][x] = 1;
					}
				}
			for (size_t y = 5; y < 35; y++)
			{
				m_Map[y][10] = 1;
			}
		}
		else
		{
			//传入地图的方式，由大家自己实现了
		}
	}
	void PrintMap()
	{
		for (int x = 0; x < MAP_X; x++)
			for (int y = 0; y < MAP_Y; y++)
			{
				if (m_Map[y][x] == 1)
				{
					WriteChar(x, y, "■");
				}
				else if (m_Map[y][x] == 2)
				{
					WriteChar(x, y, "☆");
				}
				else if (m_Map[y][x] == 3)
				{
					WriteChar(x, y, "★");
				}
			}
	}

	void GetPath()
	{
		NODE Firstnode = { m_stcBegin ,CalcH(m_stcBegin,m_stcEnd)};
		Firstnode.nF = Firstnode.nH;
		m_vecOpen.push_back(Firstnode);
		//1 将起点加入到Open表中
		//2 开始循环寻路
		while (m_vecOpen.size() > 0)
		{ 
			int loc = 0;
			int Minf = m_vecOpen[0].nF;		      
			//3 从Open表中找出F最小的点
			for (int i = 0; i < m_vecOpen.size(); i++)
			{
				if (Minf >m_vecOpen[i].nF){
					Minf = m_vecOpen[i].nF;
					loc = i;//保存当前FOR循环的位置
				}

			}
			NODE nArray[4] = {
				m_vecOpen[loc],
				m_vecOpen[loc],
				m_vecOpen[loc],
				m_vecOpen[loc]
			};
			//4 将最小的点，向四周扩散出4个点
			nArray[0].stcPos.nX = m_vecOpen[loc].stcPos.nX - 1;
			nArray[1].stcPos.nX = m_vecOpen[loc].stcPos.nX + 1;
			nArray[2].stcPos.nY = m_vecOpen[loc].stcPos.nY + 1;
			nArray[3].stcPos.nY = m_vecOpen[loc].stcPos.nY - 1;
			//保存的是当前OPEN表中这个坐标 非 它扩散的四个点
			m_vecClose.push_back(m_vecOpen[loc]);
			
			//5 这四个点中，以下情况属于无效点
			for (int i = 0; i < 4; i++)
			{
			//  5.1假如是边界
				bool nSucess = true;
				if (nArray[i].stcPos.nY == 0 ||
					nArray[i].stcPos.nY == 39 ||
					nArray[i].stcPos.nX == 39 ||
					nArray[i].stcPos.nX == 0 
					){
					nSucess = false;
				}
			//  5.2假如是障碍物
				if (m_Map[nArray[i].stcPos.nY][nArray[i].stcPos.nX] == 3){
					nSucess = false;
				}
			//  5.3假如已经探测过，在Close表中
				for (int j = 0; j <m_vecClose.size(); j++)
				{
					if (nArray[i].stcPos.nX == m_vecClose[j].stcPos.nX &&
						nArray[i].stcPos.nY == m_vecClose[j].stcPos.nY
						)
					{
						nSucess = false;
						break;
					}
				}
			//  5.4假如已经在OPEN表中 待探测中
				for (int j = 0; j <m_vecOpen.size(); j++)
				{
					if (nArray[i].stcPos.nX == m_vecOpen[j].stcPos.nX &&
						nArray[i].stcPos.nY == m_vecOpen[j].stcPos.nY
						)
					{
						nSucess = false;
						break;
					}
				}
			//  5.5找到终点
				if (m_Map[nArray[i].stcPos.nY][nArray[i].stcPos.nX] == 3){
					POSITION Father = m_vecOpen[loc].stcFatherPos;//将当前大循环的父节点保存起来
					m_Path.push_back(Father);//保存到成功的路径中		
					 //遍历在CLOSE表中的那个FATHER 节点	
					while (true)
					{ 
					for (int j = 0; j < m_vecClose.size()-1 ; j++)
					{
						if (Father.nY == m_vecClose[j].stcPos.nY &&
							Father.nX == m_vecClose[j].stcPos.nX){
							m_Path.push_back(m_vecClose[j].stcPos); // 找到后保存起来
							//覆盖父节点 继续下一个
							Father = m_vecClose[j].stcFatherPos;
							break; 
						}
					}
						//如果已经是起点了 就跳出循环
						if (Father.nY == m_stcBegin.nY &&
							Father.nX == m_stcBegin.nX){
							return;
						}
					}					
				}
					//6 将不属于无效点的加入Open表中	
				if (nSucess == true)//如果没有之前的那些错误状态 
				{ 
					nArray[i].stcFatherPos = m_vecOpen[loc].stcPos;
					nArray[i].nH = CalcH(nArray[i].stcPos,m_stcEnd);//获取当前 H path   离目的地的距离
					nArray[i].nG = m_vecOpen[loc].nG + 1;//获取当前的G path 移动的损耗nG
					nArray[i].nF = nArray[i].nG + nArray[i].nH;
					// x y之前就已经赋值了 所以不需要改变 直接将该数组保存到COLSE表里面
					m_vecOpen.push_back(nArray[i]);
				}
				
			}
			//7 将选出的最小点从Open剔除，[加入Close表]（不懂）
			//7 将选出的点进行删除 因为已经检测完了
			m_vecOpen.erase(m_vecOpen.begin()+loc);
		}
			
}
	void PrintPath()
	{
		for (int i = 0; i < m_Path.size(); i++)
		{
			WriteChar(m_Path[i].nX, m_Path[i].nY, "◇");
		}
	}
private:
	void WriteChar(int x, int y, char* szString)
	{
		COORD pos = { x * 2, y };
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		printf(szString);
	}
	int CalcH(POSITION pos_1, POSITION pos_2)
	{
		return abs(pos_1.nX - pos_2.nX) + abs(pos_1.nY - pos_2.nY);
	}
private:

	vector<NODE> m_vecOpen;    //用于存储待探测的点
	vector<NODE> m_vecClose;   //用于存储已探测的点
	int m_Map[MAP_Y][MAP_X];//地图
	POSITION m_stcBegin;
	POSITION m_stcEnd;
	vector<POSITION> m_Path;
};

