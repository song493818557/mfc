#pragma once
#include <windows.h>
#include <vector>
using std::vector;


class AStar
{
    //三个重要的值
    typedef struct _NODE
    {
        int G;             // 移动损耗
        int H;             // 离目的地的距离
        int F;             // G与H之和
        COORD  stcThis;    // 节点的当前位置
        _NODE* pFront;     // 节点的上一个节点指针
        bool operator==(_NODE stcNode);
        void operator=(_NODE stcNode);
    }NODE, *PNODE;

public:
    AStar();
    ~AStar();

    //两张重要的表
    vector<PNODE> m_vecOpen;     //Open表 //待探索的点
    vector<PNODE> m_vecClose;    //Close表//已探索的点
    
    //需要用到的其他信息
    NODE         m_stcStart; // 寻路起始点
    NODE         m_stcEnd;   // 寻路目标点
    int          m_nMaxX;    // 寻路最大宽度
    int          m_nMaxY;    // 寻路最大高度

    PBYTE        m_pSpace;   // A*寻路地图空间


    void SetSpace(             /**设置A*寻路地图空间**************/
        int nWidth,             //[in] 寻路最大宽度
        int nHigh,              //[in] 寻路最大高度
        PBYTE pSpace            //[in] A*寻路地图空间
        );

    void SetStartAndEnd(       /**设置A*寻路的起始点与目标点*******/
        COORD stcBegin,         //[in] 起始点
        COORD stcEnd            //[in] 目标点
        );

    void GetPath(              /**获取A*寻路结果*******************/
        vector<COORD> & vecPos  //[out]传出最短路径坐标集
        );

private:
    bool GetPathNode(          /**获取A*寻路结果*******************/
        vector<PNODE> & vecPos  //[out]传出最短路径节点集
        );

};

