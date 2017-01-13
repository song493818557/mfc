// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <string>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
	string test = "dd dd d----e e e ee----k kk k";
	vector<string> strvec;
	string strtemp;

	string::size_type pos1, pos2;
	pos2 = test.find("----");
	pos1 = 0;
	while (string::npos != pos2)
	{
		strvec.push_back(test.substr(pos1, pos2 - pos1));

		pos1 = pos2 + 4;
		pos2 = test.find("----", pos1);
	}
	strvec.push_back(test.substr(pos1));

	vector<string>::iterator iter1 = strvec.begin(), iter2 = strvec.end();
	while (iter1 != iter2)
	{
		cout << *iter1 << endl;
		++iter1;
	}

	return 0;
}
