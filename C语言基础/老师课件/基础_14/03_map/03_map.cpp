// 03_map.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <map>
using std::map;
using std::pair;
int _tmain(int argc, _TCHAR* argv[])
{
	//  key  value
	map<int, char> obj; //�����ʱ��key�ǲ����ظ��ģ��൱��һ����ʶ

	obj.insert(pair<int ,char>(10, 'A'));//�������ݵĻ�����Ҫ���Բ���
	obj.insert(pair<int, char>(11, 'B'));
	obj.insert(pair<int, char>(12, 'B'));
	obj.insert(pair<int, char>(14, 'B'));

	printf("%c", obj[14]);  //��Ҫ���ĳһ��Key��value
	return 0;

}

