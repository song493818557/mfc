#include "stdafx.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <fstream>
#include <vector>
using namespace std;
using std::cin;
using std::cout;
int _tmain6(int argc, _TCHAR* argv[])
{

	//int x;
	//cout << "enter choice:";
	//cin >> x;

	//for (string s ="aaa"; cin >> s;)
	// {
	//	// getline(cin,s);
	//	
	//	 cout << s << " ";
	// }
	//for (char a[10]; cin >> a;)
	//{
	//	 
	//	cout << a << "";
	//	cout << endl;

	//}
	//char a[40];
	//cin.getline(a, 40);//getline���ǽ���ĩ�Ļس����˵�  �ڱ���������û��ʲôӰ�� ���ж��� �����м������������͵�����ʱ ������GETLINEȻ��������ֽ����и������Ǽ����� �˽���һ�����Ҫ
	//cout << a << endl;
	//for (char ch; (ch = cin.get()) != '\n';)
	//{
	//	cout << ch;
	//	cout << endl;
	//}


	//�����һ��AAA.TXT�ļ� �������� ��֪��ÿ���м�������  Ҫ������ÿ�е������� ����ôʵ��?
	/* ����CIN>>���ܱ��ո�ͻس��Ĳ���  ���ֻ����GETLINE�ķ�ʽ���ж������ݵ�STRINGʵ����,����STRINGʵ���з������ɸ����������Ե��е����  һ���õķ���������STRING��
	���ж����ٷֽ����
	
	ifstream in("aaa.txt");
	
	for (string s; getline(in, s);)
	{
		int a, sum = 0;
		for (istringstream sin(s); sin >> a; sum += a);
		cout << sum << endl;
	}
*/

	//ifstream in("aaa.txt");
	//vector<int> s;
	//for (int a; in >> a;)
	//{
	//	s.push_back(a);
	//}
	//int pair = 0;
	//for (int i = 0; i < s.size() - 1;i++)
	//{
	//	for (int j = i + 1; j < s.size();++j)
	//	{
	//		if (s[i] == s[j])  pair++;
	//		cout << pair << "\n";
	//	}
	//}
	return 0;
	
}