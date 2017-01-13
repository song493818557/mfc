#pragma once
#include <iostream>
using namespace std;
class Cstack
{
public:
	//			当前指针位置	构造函数给当前类申请5个空间
	Cstack() :m_nTos(9), m_nLength(10){
		  m_pstack = new int[10];//
	};
	//增加
	void push(int numb){
		/************************************************************************/
		/*  1 先判断  m_nTos  是否等于 m_nLength     是的话就需要去扩容         
			2  开始插入 将数据放入栈底  	 									*/
		/************************************************************************/
		if (m_nTos == -1){
			cout << "已是栈顶,数据溢出" << endl;
			return;
		}
		m_pstack[m_nTos--] = numb;
	}
	//删除
	void pop(int numb){
		//如果在栈顶
		if (numb == m_pstack[m_nTos+1])
		{ 
			//++m_nTos;
			m_pstack[++m_nTos] = 0;
			
		}
		else
		{   //创建个临时堆空间(因为考虑到需要做成模板 应该不能用普通数组)  出栈 
			int * temp = new int[m_nLength];
			int temp_number = 0;
			int i = (m_nTos + 1);
			//出栈
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
			//入栈
			for (; temp_number != 0; i--)
			{

				m_pstack[i] = temp[--temp_number];
			}
		}
	}
	//析构函数给释放内存空间
	~Cstack(){
		delete[] m_pstack;
	};
private:
	int* m_pstack;
	int m_nTos, m_nLength;//当前指向的位置  栈的深度
};

