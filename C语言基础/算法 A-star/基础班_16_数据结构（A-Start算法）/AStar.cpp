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
* ��������:  ����A*Ѱ·��ͼ�ռ�
*
* �����б�:
*   int nWidth:         [in] Ѱ·�����
*   int nHigh:          [in] Ѱ·���߶�
*   PBYTE pSpace:       [in] A*Ѱ·��ͼ�ռ�
*
* ����ֵ:    void
*
*************************************/
void AStar::SetSpace(int nWidth, int nHigh, PBYTE pSpace)
{

    //1.����Ƿ������ʼ����
    if (m_pSpace)
    {
        delete[]m_pSpace;
        m_pSpace = nullptr;
    }
    //2.����Ƿ�������ȷ����				
    if (nWidth <= 0 || nHigh <= 0 || pSpace == nullptr)
    {
        return;
    }

    //3.����A*Ѱ·��ͼ�ռ�

    m_nMaxX = nWidth;
    m_nMaxY = nHigh;

    m_pSpace = new BYTE[nWidth*nHigh];
    memcpy_s(m_pSpace, nWidth*nHigh, pSpace, nWidth*nHigh);
}

/************************************
* Access:    public
* ��������:  ����A*Ѱ·����ʼ����Ŀ���
*
* �����б�:
*   COORD stcBegin:     [in] ��ʼ��
*   COORD stcEnd:       [in] Ŀ���
*
* ����ֵ:    void
*
*************************************/
void AStar::SetStartAndEnd(COORD stcBegin, COORD stcEnd)
{

    //1.����Ƿ������ʼ����

    //2.����Ƿ�������ȷ����				
    //  2.1 �������������ֵ
    //  2.1 �������Ƿ���Ч

    //3.ʵ�ֱ������Ĺ���

    m_stcStart.stcThis = stcBegin;
    m_stcEnd.stcThis = stcEnd;
}


/************************************
* Access:    public
* ��������:  ��ȡA*Ѱ·���
*
* �����б�:
*   vector<COORD> & vecPos:     [out]�������·�����꼯
*
* ����ֵ:    void
*
*************************************/
void AStar::GetPath(vector<COORD>& vecPos)
{

    //1.����Ƿ������ʼ����
    if (m_pSpace == nullptr)
    {
        return;
    }
    //2.����Ƿ�������ȷ����				
    //  2.1 �������������ֵ
    //  2.1 �������Ƿ���Ч

    //3.��ȡA*Ѱ·���
    //  3.1 ��ȡ���·��
    vector<PNODE> result;
    GetPathNode(result);

    //  3.2 �ѽڵ㼯,ת�������꼯��,���ҵ���˳��
    for (int i = result.size() - 1; i>=0;i--)
    {
        COORD coord = result[i]->stcThis;
        vecPos.push_back(coord);
    }

    //  3.2 ���Open���Close��,�Լ�Ѱ·���,׼���´�ʹ��
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
* ��������:  ��ȡA*Ѱ·���
*
* �����б�:
*   vector<PNODE> & vecPos:     [out]�������·���ڵ㼯
*
* ����ֵ:    bool
* true : �ɹ��ҵ�
* false: û���ҵ�
*************************************/
bool AStar::GetPathNode(vector<PNODE>& vecPos)
{
    /*
    //1. ����ʼ����ӵ�Open���У�Ѱ·�����е�һ����Open�б���������ݣ�
    //   1.1�����ʼ���������Ҫֵ

    //2. ��Open����ȡ��F��С�ĵ�,�Ѵ˵��Open����ɾ��,��ͬʱ��ӽ�Close��

    //3. �鿴�˵��Ƿ����յ�

    //4. ̽���õ�(����Χ�ĸ���,�ŵ�Open����)
    //   4.1 �����Χ�ĸ����������Ҫֵ
    //   4.2 �鿴��Χ�ĸ���,�Ƿ���Close����,�Ƿ����ϰ���,�ǵĻ�ֱ�ӷ���
    //   4.3 �鿴��Χ�ĸ���,�Ƿ���Open����,������ֱ�ӷ���,���ڵĻ�,��FС��ֵ������

    //5. �ظ�2,3,4��,ֱ��Open���еĵ����Ĺ�,����false;
    //               ����ֱ���ҵ��յ�,����true

    //6. ����ѭ�����(�Ƿ��ҵ�,���ز�ͬ��ֵ)
    */

    bool isFind = false;
    //1. ����ʼ����ӵ�Open���У�Ѱ·�����е�һ����Open�б���������ݣ�
    //   1.1�����ʼ���������Ҫֵ
    m_stcStart.H = abs(m_stcStart.stcThis.X - m_stcEnd.stcThis.X) +
                   abs(m_stcStart.stcThis.Y - m_stcEnd.stcThis.Y);
    m_stcStart.G = 0;
    m_stcStart.F = m_stcStart.H + m_stcStart.G;

    PNODE start = new NODE();
    *start = m_stcStart;
    m_vecOpen.push_back(start);

    while (!m_vecOpen.empty())
    {
        //2. ��Open����ȡ��F��С�ĵ�,�Ѵ˵��Open����ɾ��,��ͬʱ��ӽ�Close��
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

//=====================�˴��ǲ��Դ���====================
       // void writeChar(int row, int col, char* pszChar, WORD wArr);
       // #define B_H_RED    0x0040|0x0080        // ����
       // writeChar(pMin_F_Node->stcThis.Y, pMin_F_Node->stcThis.X, "C", B_H_RED);

        //3. �鿴�˵��Ƿ����յ�
        if (*pMin_F_Node == m_stcEnd)
        {
            isFind = true;
            m_stcEnd = *pMin_F_Node; //���յ����ø��ڵ�ָ��
            break;
        }

        //4. ̽���õ�(����Χ�ĸ���,�ŵ�Open����)
        NODE stcNewPoints[4] = {0};
        stcNewPoints[0].stcThis.X = pMin_F_Node->stcThis.X;     // ��
        stcNewPoints[0].stcThis.Y = pMin_F_Node->stcThis.Y - 1;
        stcNewPoints[1].stcThis.X = pMin_F_Node->stcThis.X;     // ��
        stcNewPoints[1].stcThis.Y = pMin_F_Node->stcThis.Y + 1;
        stcNewPoints[2].stcThis.X = pMin_F_Node->stcThis.X - 1; // ��
        stcNewPoints[2].stcThis.Y = pMin_F_Node->stcThis.Y;
        stcNewPoints[3].stcThis.X = pMin_F_Node->stcThis.X + 1; // ��
        stcNewPoints[3].stcThis.Y = pMin_F_Node->stcThis.Y;

        for (int i = 0; i < 4; i++)
        {
            //   4.1 �����Χ�ĸ����������Ҫֵ
            stcNewPoints[i].pFront = pMin_F_Node;
            stcNewPoints[i].H = abs(stcNewPoints[i].stcThis.X - m_stcEnd.stcThis.X) +
                                abs(stcNewPoints[i].stcThis.Y - m_stcEnd.stcThis.Y);
            stcNewPoints[i].G = pMin_F_Node->G + 1;
            stcNewPoints[i].F = stcNewPoints[i].H + stcNewPoints[i].G;

            //   4.2 �鿴��Χ�ĸ���,�Ƿ���Close����,�Ƿ����ϰ���,�ǵĻ�ֱ�ӷ���
            bool isNeedNode = true;
            //�Ƿ���close����
            //vector<PNODE>::iterator ishave = find(m_vecClose.begin(), m_vecClose.end(), pNewPoints);
            for (size_t j = 0; j < m_vecClose.size(); j++)
            {
                if (stcNewPoints[i] == *m_vecClose[j])
                {
                    isNeedNode = false;
                    break;
                }
            }
            //�Ƿ�Խ���������Ƿ����ϰ���
            int X = stcNewPoints[i].stcThis.X;
            int Y = stcNewPoints[i].stcThis.Y;

            //Խ��
            if (-1 == X ||
                -1 == Y ||
                m_nMaxX == X ||
                m_nMaxY == Y)
            {
                continue;
            }

            //�Ȱѵ�ͼת��������ָ��,����ͨ��[ ][ ]��ȡֵ,0��ͨ��,1����ͨ��.
            BYTE(*pbyMap)[40] = (BYTE(*)[40])m_pSpace;
            //��һ��д��(�����,������)
            //m_pSpace[m_nMaxX*y+x];
            //m_pSpace[m_nMaxX*(y) + (x)];

            switch (i)
            {
            case 0://������ɢ
                if ((pbyMap[Y - 1][X    ] != 0) ||
                    (pbyMap[Y - 1][X - 1] != 0) ||
                    (pbyMap[Y - 1][X + 1] != 0))
                {
                    continue; //ֱ�ӷ���
                }break;
            case 1://������ɢ
                if ((pbyMap[Y + 1][X    ] != 0) ||
                    (pbyMap[Y + 1][X - 1] != 0) ||
                    (pbyMap[Y + 1][X + 1] != 0))
                {
                    continue; //ֱ�ӷ���
                }break;
            case 2://������ɢ
                if ((pbyMap[Y    ][X - 1] != 0) ||
                    (pbyMap[Y - 1][X - 1] != 0) ||
                    (pbyMap[Y + 1][X - 1] != 0))
                {
                    continue; //ֱ�ӷ���
                }break;
            case 3://������ɢ
                if ((pbyMap[Y    ][X + 1] != 0) ||
                    (pbyMap[Y - 1][X + 1] != 0) ||
                    (pbyMap[Y + 1][X + 1] != 0))
                {
                    continue; //ֱ�ӷ���
                }break;;
            default:
                break;
            }
            
            //   4.3 �鿴��Χ�ĸ���,�Ƿ���Open����,������ֱ�ӷ���,���ڵĻ�,��FС��ֵ������
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

            //   4.4 ����Open����
            if (isNeedNode) {
                PNODE newNode = new NODE();
                *newNode = stcNewPoints[i];
                m_vecOpen.push_back(newNode);

                //=====================�˴��ǲ��Դ���====================
                //void writeChar(int row, int col, char* pszChar, WORD wArr);
                //#define B_H_GREEN  0x0020|0x0080        // ����
                //writeChar(newNode->stcThis.Y, newNode->stcThis.X, "O", B_H_GREEN);
            }
        }
        //5. �ظ�2,3,4��,ֱ��Open���еĵ����Ĺ�,����false;
        //               ����ֱ���ҵ��յ�,����true

    }

    if (isFind)
    {
        NODE node = m_stcEnd;
		// while (node.pFront) {
		// 	//NODE node = *node.pFront;
		// 	vecPos.push_back(node.pFront);
		// }

		for (int i = m_vecClose.size() - 1; i > 0; i--)     //��һ����,��㲻�÷Ž�ȥ(�Ž�ȥ��,����Ҫ��[1]��ȡֵ��ʼ�ж�)
		{
			if (node == *m_vecClose[i])
			{

				node = *node.pFront;
				vecPos.push_back(m_vecClose[i]);

				//=====================�˴��ǲ��Դ���====================
				//void writeChar(int row, int col, char* pszChar, WORD wArr);
				//#define B_H_YELLOW 0x0020|0x0040|0x0080 // ����
				//writeChar(m_vecClose[i]->stcThis.Y, m_vecClose[i]->stcThis.X, "��", B_H_YELLOW);
			}
		}
        return true;
    }
    else {
        //Open���еĵ����Ĺ�,����false
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
    G = stcNode.G;                // �ƶ����
    H = stcNode.H;                // ��Ŀ�ĵصľ���
    F = stcNode.F;                // G��H֮��
    stcThis = stcNode.stcThis;    // �ڵ�ĵ�ǰλ��
    pFront = stcNode.pFront;      // �ڵ����һ���ڵ�ָ��
      
}


// ������������Ҫ������ַ�������ɫ
void writeChar(int row, int col, char* pszChar, WORD wArr) {
    // ���ù������
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 1;
    cci.bVisible = FALSE;	// �Ƿ���ʾ���
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
    // ��������
    COORD loc;
    loc.X = col * 2; // x��ֵ��Wide��2��
    loc.Y = row;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
    // �����ı�����
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
    printf(pszChar); //��ӡʱ��Ҫע����Щ�����ַ���ռ�����ֽ�
}