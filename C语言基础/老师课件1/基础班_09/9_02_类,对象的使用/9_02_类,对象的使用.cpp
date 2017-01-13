// 9_02_��,�����ʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

class CPoint
{
public:
	CPoint()
	{
		m_x = 10;
		m_y = 20;
	}
	void print() {
		printf("%d ,%d ", m_x, m_y);
	}

	int m_x;
	int getY() const { return m_y; }
	void setY(int val) {
		if (val<0)  //����һ�����
		{
			return;
		}
		m_y = val; }
protected:  //�������Ժ�˽������ֻ�м̳�ʱ�Ų�һ��
private:
	int m_y;
};
int main()
{
	//1.������ͨ����
	CPoint point;
	point.m_x = 50;   //��������ֱ�ӷ���
	point.setY(80);   //˽������ͨ���ӿڷ���
	point.print();

	//2. �������ָ�����
	CPoint * pObj = new CPoint;
	//....һϵ�еĲ���
	delete pObj;

	pObj = nullptr;
	pObj = &point;
	pObj->m_x = 50;

	//3. �����������
	CPoint & obj = point;
	obj.m_x = 50;   //��������ֱ�ӷ���
	obj.setY(80);   //˽������ͨ���ӿڷ���
	obj.print();

	//4. �����������
	CPoint objArr[10];
	objArr[0].m_x = 50;   //��������ֱ�ӷ���
	objArr[0].setY(80);   //˽������ͨ���ӿڷ���
	objArr[0].print();

    return 0;
}

