#include "stdafx.h"
#include "Cstar.h"

void Cstar::Getpath(){
	//1���������뵽open����  �ṹ���ʼ��  ����ʼ������������յ��λ�ø�ֵ
	strstar First = { start, CalcH(start, end) };
	First.nF = First.nG + First.nH;
	m_Openlist.push_back(First);//��OPEN��װ�����úõĵ�һ����ʼ������ 
	//2����ʼѭ��Ѱ·  ���������յ�ľ���
	while (m_Openlist.size() != 0) //���� ����ٿ�
	{
		//3����OPEN�����ҳ�F��С�ĵ�
		int opensieze = m_Openlist.size();//��ȡ��ǰ�����������ж��ٸ�Ԫ��
		int MinF = m_Openlist[0].nF;//��ȡ��һ�δ������С�� F  path
		int MinPos = 0;//X Y�������0
		for (int i = 0; i < opensieze; i++)
		{
			if (MinF> m_Openlist[i].nF){//�����ǰ�����MinF ���ڵ�ǰ��������F PATH  �͸���
				MinF = m_Openlist[i].nF;//���Դﵽ�ҵ���ѵ��Ǹ������
				MinPos = i;	 //����ѭ�����±�				
			}
		}
		//4������С�ĵ���������ɢ���ĸ���
			//4.1 ����ǰ���ǵ�MinPos��ֵ�����ĸ����� ����
		strstar minArray[4] = {
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos],
			m_Openlist[MinPos]
		};		//��������4����������ָ�ֵ �ֱ��������������  
		minArray[UP].stcpos.nY = m_Openlist[MinPos].stcpos.nY - 1;
		minArray[DOWN].stcpos.nY = m_Openlist[MinPos].stcpos.nY + 1;
		minArray[LEFT].stcpos.nX = m_Openlist[MinPos].stcpos.nX - 1;
		minArray[RIGHT].stcpos.nX = m_Openlist[MinPos].stcpos.nX + 1;
		//����ֵ�õ����ݱ��浽CLOSE��  ��Ϊ����Ҫ���м��
		m_Closelist.push_back(m_Openlist[MinPos]);
		//4.2 ��ʼ����
		for (int i = 0; i < 4; i++)
		{
			bool checkstate = true;
			//5�����ĸ�����  һ�����������Ч��
			//5.1  �����Ǳ߽�
			if (minArray[i].stcpos.nY == 0 ||
				minArray[i].stcpos.nY == 39||
				minArray[i].stcpos.nX == 0 ||
				minArray[i].stcpos.nX == 39 
				){
				checkstate = false;
			}
			//5.2  �������ϰ��� ****************
			 if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 1 ){
				checkstate = false;
			}			
			//5.3  �����Ѿ���COLSE����
			for (int  j = 0; j < m_Closelist.size(); j++)
			{
				if (m_Closelist[j].stcpos.nY == minArray[i].stcpos.nY && 
					m_Closelist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}
			//5.4  �Ѿ���OPEN���� ��̽����
			for (int j = 0; j < m_Openlist.size(); j++)
			{
				if (m_Openlist[j].stcpos.nY == minArray[i].stcpos.nY && 
					m_Openlist[j].stcpos.nX == minArray[i].stcpos.nX){
					checkstate = false;
					break;
				}
			}

			//5.5 �ҵ��յ�
			if (m_map[minArray[i].stcpos.nY][minArray[i].stcpos.nX] == 3){

				position Father = m_Openlist[MinPos].Fatherpos;//���浱ǰ�ĸ��ڵ�
				m_Path.push_back(Father);//����ǰ�ĸ��ڵ����걣�浽�ɹ��ı�����ȥ
				while (true)
				{
					for (int i = m_Closelist.size() - 1; i >= 0; i--)
					{
						if (Father.nX == m_Closelist[i].stcpos.nX &&
							Father.nY == m_Closelist[i].stcpos.nY)
						{
							m_Path.push_back(Father);//�ҵ��˶�Ӧ������ ���浽�ɹ��ı�����ȥ
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
					//6 ����������Ч��ļ���OPEN����
					minArray[i].Fatherpos = m_Openlist[MinPos].stcpos;
					minArray[i].nG = m_Openlist[MinPos].nG + 1;
					minArray[i].nH = CalcH(minArray[i].stcpos, end);
					minArray[i].nF = minArray[i].nH + minArray[i].nG;
					m_Openlist.push_back(minArray[i]);
				}
			
		}
			//7 ��ѡ������С���OPEN�����޳� ���Ҽ���CLOSE ��
			m_Openlist.erase(m_Openlist.begin() + MinPos);
		
	}

	/**/
	//8 �����ҵ����յ�
	//9  ���Ǵ�CLOSE�����ҳ�·��

}
void Cstar::PrintPath()
{
	for (int i = 0; i < m_Path.size(); i++)
	{
		WriteChar(m_Path[i].nY, m_Path[i].nX, "��");
	}
}