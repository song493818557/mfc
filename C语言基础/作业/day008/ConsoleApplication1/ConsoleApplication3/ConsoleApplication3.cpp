// ConsoleApplication3.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
class student{
public:
	student() :m(2){ printf("student"); }
	~student() { printf("student"); }
	int m;
private:
	
};
class graduatestudent :public student{
public:
	graduatestudent() :a(3){ printf("graduatestudent"); }
	~graduatestudent()   { printf("~graduatestudent"); }
	int a;
private:
	
};

int _tmain(int argc, _TCHAR* argv[])
{
	graduatestudent gs;
	student s = gs;// s������ GS�����е�student���� ������������ʵ��student����ʵ��
	student & t = gs; // T��ȻҲ������student���� ���� t������ ����ͼ�д���GS�����еĲ��ɷ����student����  ֻ�ܲ���GS��STUDENT����
	student * p = &gs;//p��studentָ�� ָ��graduatestudent�����GS���׵�ַ ��ǡ��Ҳ������student���󲿷ֵ��׵�ַ  ֻ�ܲ���GS��STUDENT����
	/*gs = s;  ���ø������S���������GS��ֵ ��Ϊ�����е����ݲ����  ����������ȫ������Ϣ ���Ծܾ�ִ��
	graduatestudent * pgs = &s; �ø������ĵ�ַ&s���������ָ��PGS��ֵ Ҳ�ǷǷ��� ��Ȼ��ַ��������ƶ�����ؽ� 
	  ��� ���ǽ������Ǹ��ൽ�����ת�� ר�ſ������������Ǹ��������һ���������ǰ�� 
	*/ 
	t.m = 3;
	int x, y;
	x = y = 3;
	scanf_s("%d",&x);
	return 0;
}

