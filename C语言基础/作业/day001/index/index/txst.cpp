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
	//cin.getline(a, 40);//getline总是将行末的回车符滤掉  在本次输入中没有什么影响 若有多行 切行中夹杂着其他类型的数据时 借助于GETLINE然后再猪儿分解行中各数据是简明的 了解这一点很重要
	//cout << a << endl;
	//for (char ch; (ch = cin.get()) != '\n';)
	//{
	//	cout << ch;
	//	cout << endl;
	//}


	//如果有一个AAA.TXT文件 有若干行 不知道每行有几个整数  要编程输出每行的整数和 该怎么实现?
	/* 由于CIN>>不能辨别空格和回车的差异  因此只能用GETLINE的方式朱行读入数据到STRING实体中,但在STRING实体中分离若干个整数还是显得有点吃力  一个好的方法就是用STRING流
	整行读入再分解读入
	
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