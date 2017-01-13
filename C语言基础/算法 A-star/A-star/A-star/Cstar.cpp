#include "stdafx.h"
#include "Cstar.h"

void Cstar::Getpath(){
	//1、将起点加入到open表中  结构体初始化  将起始坐标和坐标离终点的位置赋值
	strstar First = { start, CalcH(start, end) };
	First.nF = First.nG + First.nH;
	m_Openlist.push_back(First);//将OPEN表装入设置好的第一个起始点坐标 
	//2、开始循环寻路  计算起点和终点的距离
	while (m_Openlist.size() != 0) //不懂 晚点再看
	{
		//3、从OPEN表中找出F最小的点
		int opensieze = m_Openlist.size();//获取当前的容器里面有多少个元素
		int MinF = m_Openlist[0].nF;//获取第一次存入的最小的 F  path
		int MinPos = 0;//X Y坐标等于0
		for (int i = 0; i < opensieze; i++)
		{
			if (MinF> m_Openlist[i].nF){//如果当前保存的MinF 大于当前遍历数组F PATH  就覆盖
				MinF = m_Openlist[i].nF;//可以达到找到最佳的那个坐标点
				MinPos = i;	 //保存循环的下标				
			}
		}
		//4、将最小的点向四周扩散出四个点
			//4.1 将当前覆盖的MinPos的值创建四个数组 遍历
		strstar minArray[4] = {
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos]
		};		//将创建的4个点进行区分赋值 分辨代表往上下左右  
		minArray[UP].stcpos.nY = m_Openlist[MinPos].stcpos.nY - 1;
		minArray[DOWN].stcpos.nY = m_Openlist[MinPos].stcpos.nY + 1;
		minArray[LEFT].stcpos.nX = m_Openlist[MinPos].stcpos.nX - 1;
		minArray[RIGHT].stcpos.nX = m_Openlist[MinPos].stcpos.nX + 1;
		//将赋值好的数据保存到CLOSE表  因为即将要进行检测
		m_Closelist.push_back(m_Openlist[MinPos]);
		//4.2 开始遍历
		for (int i = 0; i < 4; i++)
		{
			bool checkstate = true;
			//5、这四个点中  一下情况属于无效点
			//5.1  假如是边界
			if (minArray[i].stcpos.nY == 0 ||
				minArray[i].stcpos.nY == 39||
				minArray[i].stcpos.nX == 0 ||
				minArray[i].stcpos.nX == 39 
				){
				checkstate = false;
			}
			//5.2  假如是障碍物 ****************
			 if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 1 ){
				checkstate = false;
			}			
			//5.3  假如已经在COLSE表中
			for (int  j = 0; j < m_Closelist.size(); j++)
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

			//5.5 找到终点
			if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 3){

				position Father = m_Openlist[MinPos].Fatherpos;//保存当前的父节点
				m_Path.push_back(Father);//将当前的父节点坐标保存到成功的表里面去
				while (true)
				{
					for (int i = m_Closelist.size() - 1; i >= 0; i--)
					{
						if (Father.nX == m_Closelist[i].stcpos.nX &&
							Father.nY == m_Closelist[i].stcpos.nY)
						{
							m_Path.push_back(Father);//找到了对应的坐标 保存到成功的表里面去
							Father = m_Closelist[i].Fatherpos;
							break;
						}

					}
					if (Father.nX == start.nX && Father.nY == start.nY){
						return;
					}
				}
			}
				if (checkstate == true){
					//6 将不属于无效点的加入OPEN表中
					minArray[i].Fatherpos = m_Openlist[MinPos].stcpos;
					minArray[i].nG = m_Openlist[MinPos].nG + 1;
					minArray[i].nH = CalcH(minArray[i].stcpos, end);
					minArray[i].nF = minArray[i].nH + minArray[i].nG;
					m_Openlist.push_back(minArray[i]);
				}
			
		}
			//7 将选出的最小点从OPEN表中剔除 并且加入CLOSE 表
			m_Openlist.erase(m_Openlist.begin() + MinPos);
		
	}

	/**/
	//8 加入找到了终点
	//9  我们从CLOSE表中找出路径

}
void Cstar::PrintPath()
{
	for (int i = 0; i < m_Path.size(); i++)
	{
		WriteChar(m_Path[i].nY, m_Path[i].nX, "◇");
	}
}