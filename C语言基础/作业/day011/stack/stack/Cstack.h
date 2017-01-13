#pragma once
#include <iostream>
using namespace std;
class Cstack
{
public:
	//			��ǰָ��λ��	���캯������ǰ������5���ռ�
	Cstack() :m_nTos(9), m_nLength(10){
		  m_pstack = new int[10];//
	};
	//����
	void push(int numb){
		/************************************************************************/
		/*  1 ���ж�  m_nTos  �Ƿ���� m_nLength     �ǵĻ�����Ҫȥ����         
			2  ��ʼ���� �����ݷ���ջ��  	 									*/
		/************************************************************************/
		if (m_nTos == -1){
			cout << "����ջ��,�������" << endl;
			return;
		}
		m_pstack[m_nTos--] = numb;
	}
	//ɾ��
	void pop(int numb){
		//�����ջ��
		if (numb == m_pstack[m_nTos+1])
		{ 
			//++m_nTos;
			m_pstack[++m_nTos] = 0;
			
		}
		else
		{   //��������ʱ�ѿռ�(��Ϊ���ǵ���Ҫ����ģ�� Ӧ�ò�������ͨ����)  ��ջ 
			int * temp = new int[m_nLength];
			int temp_number = 0;
			int i = (m_nTos + 1);
			//��ջ
			for (; i < m_nLength-1; i++)
			{ 
				if (m_pstack[i] == numb)
				{
					m_pstack[i] = 0;
					break;
				}
				temp[temp_number] = m_pstack[i];
				m_pstack[i] = 0;
				temp_number++;
			}
			//��ջ
			for (; temp_number != 0; i--)
			{

				m_pstack[i] = temp[--temp_number];
			}
		}
	}
	//�����������ͷ��ڴ�ռ�
	~Cstack(){
		delete[] m_pstack;
	};
private:
	int* m_pstack;
	int m_nTos, m_nLength;//��ǰָ���λ��  ջ�����
};

