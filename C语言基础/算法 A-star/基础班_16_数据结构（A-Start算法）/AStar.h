#pragma once
#include <windows.h>
#include <vector>
using std::vector;


class AStar
{
    //������Ҫ��ֵ
    typedef struct _NODE
    {
        int G;             // �ƶ����
        int H;             // ��Ŀ�ĵصľ���
        int F;             // G��H֮��
        COORD  stcThis;    // �ڵ�ĵ�ǰλ��
        _NODE* pFront;     // �ڵ����һ���ڵ�ָ��
        bool operator==(_NODE stcNode);
        void operator=(_NODE stcNode);
    }NODE, *PNODE;

public:
    AStar();
    ~AStar();

    //������Ҫ�ı�
    vector<PNODE> m_vecOpen;     //Open�� //��̽���ĵ�
    vector<PNODE> m_vecClose;    //Close��//��̽���ĵ�
    
    //��Ҫ�õ���������Ϣ
    NODE         m_stcStart; // Ѱ·��ʼ��
    NODE         m_stcEnd;   // Ѱ·Ŀ���
    int          m_nMaxX;    // Ѱ·�����
    int          m_nMaxY;    // Ѱ·���߶�

    PBYTE        m_pSpace;   // A*Ѱ·��ͼ�ռ�


    void SetSpace(             /**����A*Ѱ·��ͼ�ռ�**************/
        int nWidth,             //[in] Ѱ·�����
        int nHigh,              //[in] Ѱ·���߶�
        PBYTE pSpace            //[in] A*Ѱ·��ͼ�ռ�
        );

    void SetStartAndEnd(       /**����A*Ѱ·����ʼ����Ŀ���*******/
        COORD stcBegin,         //[in] ��ʼ��
        COORD stcEnd            //[in] Ŀ���
        );

    void GetPath(              /**��ȡA*Ѱ·���*******************/
        vector<COORD> & vecPos  //[out]�������·�����꼯
        );

private:
    bool GetPathNode(          /**��ȡA*Ѱ·���*******************/
        vector<PNODE> & vecPos  //[out]�������·���ڵ㼯
        );

};

