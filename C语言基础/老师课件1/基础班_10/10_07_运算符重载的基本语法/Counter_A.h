#pragma once
//��Ա��������
class CCounter_A
{
public:
	CCounter_A(int num=0);
	~CCounter_A();

	//��Ŀ���������
	//++/--
	CCounter_A& operator++();//ǰ��++
	CCounter_A operator++(int); //����++,int����ֻ�Ǳ�ʾΪ���÷���,����ʹ��


	//˫Ŀ���������
	int operator+(CCounter_A &);


	int getNum() const { return m_nNum; }
	void setNum(int val) { m_nNum = val; }
private:
	int m_nNum;
};

//���ط���ʱ,����ֵ���������Զ����
//1. ǰ��++,���ؼ����Ժ�Ľ��
//2. ����++,���ؼ�֮ǰ�Ľ��
//3. +,���ı������,����һ����ӵ��м����