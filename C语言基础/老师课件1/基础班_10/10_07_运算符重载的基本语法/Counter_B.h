#pragma once
//��Ա��������
class CCounter_B
{
public:
	CCounter_B(int num = 0);
	~CCounter_B();

	//��Ŀ���������
	//++/--
	friend CCounter_B& operator++(CCounter_B&);//ǰ��++
	friend CCounter_B operator++(CCounter_B&,int); //����++,int����ֻ�Ǳ�ʾΪ���÷���,����ʹ��


	//˫Ŀ���������
	friend int operator+(CCounter_B & op1,CCounter_B & op2);


	int getNum() const { return m_nNum; }
	void setNum(int val) { m_nNum = val; }
private:
	int m_nNum;
};

