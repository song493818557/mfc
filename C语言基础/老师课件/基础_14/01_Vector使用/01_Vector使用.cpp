// 01_Vectorʹ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <vector> // 1 ����ͷ�ļ���ע��û��.h
#include <set>
using std::vector;// 2 ʹ�������ռ�
using std::set;
int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> obj;
	vector<int> obj2;
	obj.push_back(0);
	obj.push_back(1);
	obj.push_back(2);
	obj.push_back(3);
	obj.push_back(4);
	obj.push_back(5);

	//��һ�ֱ�����ʽ
	//for (int i = 0; i < obj.size(); i++)
	//{
	//	printf("%d ", obj[i]);
	//	//printf("%d ", obj.at(i));���������Ĺ�����һ����
	//}
	//�ڶ��ֱ�����ʽ
	vector<int>::iterator vecit = obj.begin();//������
	for (; vecit != obj.end(); vecit++)
	{
		printf("%d  ", *vecit);
	}
	vecit = obj.begin()+2;
	obj.insert(vecit, 10);//ע��insert��Ҫ���ݵ�����
	int a = 0;
	obj.pop_back( );             //ɾ�����һ������
	obj.erase(obj.begin() + 2);  //ɾ��ָ��λ�õ�Ԫ�أ�ע��Ҫ���ݵ�����
	obj.clear();                 //���

	obj2.push_back(100);
	obj2.push_back(200);
	obj2.push_back(300);
	obj2.push_back(400);
	obj2.push_back(500);
	obj.swap(obj2);
	obj[0] = 10;


	return 0;
}

