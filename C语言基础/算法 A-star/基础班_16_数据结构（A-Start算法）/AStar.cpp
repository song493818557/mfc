#include "stdafx.h"
#include "AStar.h"

AStar::AStar()
{
}

AStar::~AStar()
{
}

/************************************
* Access:    public
* 函数功能:  设置A*寻路地图空间
*
* 参数列表:
*   int nWidth:         [in] 寻路最大宽度
*   int nHigh:          [in] 寻路最大高度
*   PBYTE pSpace:       [in] A*寻路地图空间
*
* 返回值:    void
*
*************************************/
void AStar::SetSpace(int nWidth, int nHigh, PBYTE pSpace)
{

    //1.检查是否满足初始条件
    if (m_pSpace)
    {
        delete[]m_pSpace;
        m_pSpace = nullptr;
    }
    //2.检查是否传入了正确参数				
    if (nWidth <= 0 || nHigh <= 0 || pSpace == nullptr)
    {
        return;
    }

    //3.设置A*寻路地图空间

    m_nMaxX = nWidth;
    m_nMaxY = nHigh;

    m_pSpace = new BYTE[nWidth*nHigh];
    memcpy_s(m_pSpace, nWidth*nHigh, pSpace, nWidth*nHigh);
}

/************************************
* Access:    public
* 函数功能:  设置A*寻路的起始点与目标点
*
* 参数列表:
*   COORD stcBegin:     [in] 起始点
*   COORD stcEnd:       [in] 目标点
*
* 返回值:    void
*
*************************************/
void AStar::SetStartAndEnd(COORD stcBegin, COORD stcEnd)
{

    //1.检查是否满足初始条件

    //2.检查是否传入了正确参数				
    //  2.1 处理参数的特殊值
    //  2.1 检查参数是否有效

    //3.实现本函数的功能

    m_stcStart.stcThis = stcBegin;
    m_stcEnd.stcThis = stcEnd;
}


/************************************
* Access:    public
* 函数功能:  获取A*寻路结果
*
* 参数列表:
*   vector<COORD> & vecPos:     [out]传出最短路径坐标集
*
* 返回值:    void
*
*************************************/
void AStar::GetPath(vector<COORD>& vecPos)
{

    //1.检查是否满足初始条件
    if (m_pSpace == nullptr)
    {
        return;
    }
    //2.检查是否传入了正确参数				
    //  2.1 处理参数的特殊值
    //  2.1 检查参数是否有效

    //3.获取A*寻路结果
    //  3.1 获取最短路径
    vector<PNODE> result;
    GetPathNode(result);

    //  3.2 把节点集,转换成坐标集合,并且倒置顺序
    for (int i = result.size() - 1; i>=0;i--)
    {
        COORD coord = result[i]->stcThis;
        vecPos.push_back(coord);
    }

    //  3.2 清空Open表和Close表,以及寻路结果,准备下次使用
    for (size_t i = 0; i < m_vecOpen.size(); i++)
    {
        delete m_vecOpen[i];
    }
    for (size_t i = 0; i < m_vecClose.size(); i++) 
    {
        delete m_vecClose[i];
    }
    m_vecOpen.clear();
    m_vecClose.clear();
}

/************************************
* Access:    private
* 函数功能:  获取A*寻路结果
*
* 参数列表:
*   vector<PNODE> & vecPos:     [out]传出最短路径节点集
*
* 返回值:    bool
* true : 成功找到
* false: 没有找到
*************************************/
bool AStar::GetPathNode(vector<PNODE>& vecPos)
{
    /*
    //1. 将起始点添加到Open表中（寻路过程中第一次向Open列表中添加数据）
    //   1.1算出起始点的三个重要值

    //2. 从Open表中取出F最小的点,把此点从Open表中删除,并同时添加进Close表

    //3. 查看此点是否是终点

    //4. 探索该点(把周围四个点,放到Open表中)
    //   4.1 算出周围四个点的三个重要值
    //   4.2 查看周围四个点,是否在Close表中,是否是障碍物,是的话直接放弃
    //   4.3 查看周围四个点,是否在Open表中,不在则直接放入,若在的话,按F小的值来更新

    //5. 重复2,3,4步,直到Open表中的点消耗光,返回false;
    //               或者直到找到终点,返回true

    //6. 根据循环结果(是否找到,返回不同的值)
    */

    bool isFind = false;
    //1. 将起始点添加到Open表中（寻路过程中第一次向Open列表中添加数据）
    //   1.1算出起始点的三个重要值
    m_stcStart.H = abs(m_stcStart.stcThis.X - m_stcEnd.stcThis.X) +
                   abs(m_stcStart.stcThis.Y - m_stcEnd.stcThis.Y);
    m_stcStart.G = 0;
    m_stcStart.F = m_stcStart.H + m_stcStart.G;

    PNODE start = new NODE();
    *start = m_stcStart;
    m_vecOpen.push_back(start);

    while (!m_vecOpen.empty())
    {
        //2. 从Open表中取出F最小的点,把此点从Open表中删除,并同时添加进Close表
        PNODE pMin_F_Node = m_vecOpen[0];
        int nMin_F_Index = 0;
        for (size_t i = 0; i < m_vecOpen.size(); i++)
        {
            if (pMin_F_Node->F > m_vecOpen[i]->F)
            {
                pMin_F_Node = m_vecOpen[i];
                nMin_F_Index = i;
            }
        }
        m_vecClose.push_back(pMin_F_Node);
        m_vecOpen.erase(m_vecOpen.begin() + nMin_F_Index);

//=====================此处是测试代码====================
       // void writeChar(int row, int col, char* pszChar, WORD wArr);
       // #define B_H_RED    0x0040|0x0080        // 亮红
       // writeChar(pMin_F_Node->stcThis.Y, pMin_F_Node->stcThis.X, "C", B_H_RED);

        //3. 查看此点是否是终点
        if (*pMin_F_Node == m_stcEnd)
        {
            isFind = true;
            m_stcEnd = *pMin_F_Node; //给终点设置父节点指针
            break;
        }

        //4. 探索该点(把周围四个点,放到Open表中)
        NODE stcNewPoints[4] = {0};
        stcNewPoints[0].stcThis.X = pMin_F_Node->stcThis.X;     // 上
        stcNewPoints[0].stcThis.Y = pMin_F_Node->stcThis.Y - 1;
        stcNewPoints[1].stcThis.X = pMin_F_Node->stcThis.X;     // 下
        stcNewPoints[1].stcThis.Y = pMin_F_Node->stcThis.Y + 1;
        stcNewPoints[2].stcThis.X = pMin_F_Node->stcThis.X - 1; // 左
        stcNewPoints[2].stcThis.Y = pMin_F_Node->stcThis.Y;
        stcNewPoints[3].stcThis.X = pMin_F_Node->stcThis.X + 1; // 右
        stcNewPoints[3].stcThis.Y = pMin_F_Node->stcThis.Y;

        for (int i = 0; i < 4; i++)
        {
            //   4.1 算出周围四个点的三个重要值
            stcNewPoints[i].pFront = pMin_F_Node;
            stcNewPoints[i].H = abs(stcNewPoints[i].stcThis.X - m_stcEnd.stcThis.X) +
                                abs(stcNewPoints[i].stcThis.Y - m_stcEnd.stcThis.Y);
            stcNewPoints[i].G = pMin_F_Node->G + 1;
            stcNewPoints[i].F = stcNewPoints[i].H + stcNewPoints[i].G;

            //   4.2 查看周围四个点,是否在Close表中,是否是障碍物,是的话直接放弃
            bool isNeedNode = true;
            //是否在close表中
            //vector<PNODE>::iterator ishave = find(m_vecClose.begin(), m_vecClose.end(), pNewPoints);
            for (size_t j = 0; j < m_vecClose.size(); j++)
            {
                if (stcNewPoints[i] == *m_vecClose[j])
                {
                    isNeedNode = false;
                    break;
                }
            }
            //是否越绝或者是是否是障碍物
            int X = stcNewPoints[i].stcThis.X;
            int Y = stcNewPoints[i].stcThis.Y;

            //越界
            if (-1 == X ||
                -1 == Y ||
                m_nMaxX == X ||
                m_nMaxY == Y)
            {
                continue;
            }

            //先把地图转换成数组指针,可以通过[ ][ ]来取值,0可通行,1不可通行.
            BYTE(*pbyMap)[40] = (BYTE(*)[40])m_pSpace;
            //另一张写法(好理解,不优雅)
            //m_pSpace[m_nMaxX*y+x];
            //m_pSpace[m_nMaxX*(y) + (x)];

            switch (i)
            {
            case 0://向上扩散
                if ((pbyMap[Y - 1][X    ] != 0) ||
                    (pbyMap[Y - 1][X - 1] != 0) ||
                    (pbyMap[Y - 1][X + 1] != 0))
                {
                    continue; //直接放弃
                }break;
            case 1://向下扩散
                if ((pbyMap[Y + 1][X    ] != 0) ||
                    (pbyMap[Y + 1][X - 1] != 0) ||
                    (pbyMap[Y + 1][X + 1] != 0))
                {
                    continue; //直接放弃
                }break;
            case 2://向左扩散
                if ((pbyMap[Y    ][X - 1] != 0) ||
                    (pbyMap[Y - 1][X - 1] != 0) ||
                    (pbyMap[Y + 1][X - 1] != 0))
                {
                    continue; //直接放弃
                }break;
            case 3://向右扩散
                if ((pbyMap[Y    ][X + 1] != 0) ||
                    (pbyMap[Y - 1][X + 1] != 0) ||
                    (pbyMap[Y + 1][X + 1] != 0))
                {
                    continue; //直接放弃
                }break;;
            default:
                break;
            }
            
            //   4.3 查看周围四个点,是否在Open表中,不在则直接放入,若在的话,按F小的值来更新
            for (size_t j = 0; j < m_vecOpen.size(); j++)
            {
                if (stcNewPoints[i] == *m_vecOpen[j])
                {
                    if (stcNewPoints[i].F < m_vecOpen[j]->F)
                    {
                       
                        *m_vecOpen[j]=stcNewPoints[i];
                    }
                    isNeedNode = false;
                    break;
                }
            }

            //   4.4 插入Open表中
            if (isNeedNode) {
                PNODE newNode = new NODE();
                *newNode = stcNewPoints[i];
                m_vecOpen.push_back(newNode);

                //=====================此处是测试代码====================
                //void writeChar(int row, int col, char* pszChar, WORD wArr);
                //#define B_H_GREEN  0x0020|0x0080        // 亮绿
                //writeChar(newNode->stcThis.Y, newNode->stcThis.X, "O", B_H_GREEN);
            }
        }
        //5. 重复2,3,4步,直到Open表中的点消耗光,返回false;
        //               或者直到找到终点,返回true

    }

    if (isFind)
    {
        NODE node = m_stcEnd;
		// while (node.pFront) {
		// 	//NODE node = *node.pFront;
		// 	vecPos.push_back(node.pFront);
		// }

		for (int i = m_vecClose.size() - 1; i > 0; i--)     //第一个点,起点不用放进去(放进去后,外面要从[1]处取值开始判断)
		{
			if (node == *m_vecClose[i])
			{

				node = *node.pFront;
				vecPos.push_back(m_vecClose[i]);

				//=====================此处是测试代码====================
				//void writeChar(int row, int col, char* pszChar, WORD wArr);
				//#define B_H_YELLOW 0x0020|0x0040|0x0080 // 亮黄
				//writeChar(m_vecClose[i]->stcThis.Y, m_vecClose[i]->stcThis.X, "◎", B_H_YELLOW);
			}
		}
        return true;
    }
    else {
        //Open表中的点消耗光,返回false
        return false;
    }

    return false;
}




bool AStar::_NODE::operator==(_NODE stcNode)
{
    if (stcThis.X == stcNode.stcThis.X &&stcThis.Y == stcNode.stcThis.Y)
    {
        return true;
    }
    return false;
}

void AStar::_NODE::operator=(_NODE stcNode)
{
    G = stcNode.G;                // 移动损耗
    H = stcNode.H;                // 离目的地的距离
    F = stcNode.F;                // G与H之和
    stcThis = stcNode.stcThis;    // 节点的当前位置
    pFront = stcNode.pFront;      // 节点的上一个节点指针
      
}


// 行数，列数，要输出的字符串，颜色
void writeChar(int row, int col, char* pszChar, WORD wArr) {
    // 设置光标属性
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;	// 是否显示光标
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    // 设置坐标
    COORD loc;
    loc.X = col * 2; // x的值是Wide的2倍
    loc.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
    // 设置文本属性
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
    printf(pszChar); //打印时需要注意有些特殊字符是占两个字节
}