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
}NODE,*PNODE;

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
	void SetInfo(int nBegin_x,  int nBegin_y,int End_x,int End_y)
	{
		m_stcBegin.nX = nBegin_x;
		m_stcBegin.nY = nBegin_y;
		m_stcEnd.nX = End_x;
		m_stcEnd.nY = End_y;
		m_Map[m_stcBegin.nY][m_stcBegin.nX] = 2;
		m_Map[m_stcEnd.nY][m_stcEnd.nX] = 3;
	}
	void SetMap(int Map[][40] =NULL)//int (*p)[40]
	{
		if (Map==NULL)
		{
			for (int x = 0; x < MAP_X;x++)
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
		//1 将起点加入到Open表中
		NODE FirstNode = { m_stcBegin, CalcH(m_stcBegin, m_stcEnd) };
		FirstNode.nF = FirstNode.nG + FirstNode.nH;
		m_vecOpen.push_back(FirstNode);

		//2 开始循环寻路
		while (m_vecOpen.size()!=0)
		{
			//3 从Open表中找出F最小的点
			int nOpenSize = m_vecOpen.size();
			int nMinF = m_vecOpen[0].nF;
			int nMinPos = 0;
			for (int i = 0; i < nOpenSize; i++)
			{
				if (nMinF>m_vecOpen[i].nF)
				{
					nMinF = m_vecOpen[i].nF;
					nMinPos = i;
				}
			}
			//4 将最小的点，向四周扩散出4个点
			NODE NodeArray[4] = { 
				m_vecOpen[nMinPos], 
				m_vecOpen[nMinPos], 
				m_vecOpen[nMinPos],
				m_vecOpen[nMinPos] 
			};
			NodeArray[UP].stcPos.nY = m_vecOpen[nMinPos].stcPos.nY-1;
			NodeArray[DOWN].stcPos.nY = m_vecOpen[nMinPos].stcPos.nY + 1;
			NodeArray[LEFT].stcPos.nX = m_vecOpen[nMinPos].stcPos.nX - 1;
			NodeArray[RIGHT].stcPos.nX = m_vecOpen[nMinPos].stcPos.nX + 1;
			m_vecClose.push_back(m_vecOpen[nMinPos]);
			for (size_t i = 0; i < 4; i++)
			{
				//5 这四个点中，以下情况属于无效点
				//  5.1假如是边界
				bool nSurvice = true;
				if (NodeArray[i].stcPos.nX == 0 || 
					NodeArray[i].stcPos.nX == 39||
					NodeArray[i].stcPos.nY == 0 ||
					NodeArray[i].stcPos.nY == 39 
					)
				{
					nSurvice = false;
				}
				//  5.2假如是障碍物
				if (m_Map[NodeArray[i].stcPos.nY][NodeArray[i].stcPos.nX]==1)
				{
					nSurvice = false;
				}
				//  5.3假如已经探测过，在Close表中
				for (int j = 0; j < m_vecClose.size(); j++)
				{
					if (m_vecClose[j].stcPos.nX == NodeArray[i].stcPos.nX&&
						m_vecClose[j].stcPos.nY == NodeArray[i].stcPos.nY)
					{
						nSurvice = false;
						break;
					}
				}
				//  5.4假如已经在OPEN表中 待探测中
				for (int j = 0; j < m_vecOpen.size(); j++)
				{
					if (m_vecOpen[j].stcPos.nX == NodeArray[i].stcPos.nX&&
						m_vecOpen[j].stcPos.nY == NodeArray[i].stcPos.nY)
					{
						nSurvice = false;
						break;
					}
				}

				//  找到终点
				if (m_Map[NodeArray[i].stcPos.nY][NodeArray[i].stcPos.nX] == 3)
				{
					POSITION Father = m_vecOpen[nMinPos].stcFatherPos;
					m_Path.push_back(Father);
					while (true)
					{
						for (int i = m_vecClose.size() - 1; i >= 0; i--)
						{
							if (Father.nX == m_vecClose[i].stcPos.nX&&
								Father.nY == m_vecClose[i].stcPos.nY)
							{
								m_Path.push_back(m_vecClose[i].stcPos);
								Father = m_vecClose[i].stcFatherPos;
								break;
							}
						}
						if (Father.nX==m_stcBegin.nX&&
							Father.nY == m_stcBegin.nY)
						{
							return;
						}
					}

				}
				if (nSurvice==true)

				{	//6 将不属于无效点的加入Open表中
					NodeArray[i].stcFatherPos = m_vecOpen[nMinPos].stcPos;
					NodeArray[i].nG = m_vecOpen[nMinPos].nG + 1;
					NodeArray[i].nH = CalcH(NodeArray[i].stcPos, m_stcEnd);
					NodeArray[i].nF = NodeArray[i].nG + NodeArray[i].nH;
					m_vecOpen.push_back(NodeArray[i]);
				}
				
			}
			//7 将选出的最小点从Open剔除，加入Close表
			m_vecOpen.erase(m_vecOpen.begin() + nMinPos);
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

