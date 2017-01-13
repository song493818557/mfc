// 10 输入输出示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

#include <iostream>
#include <iomanip>
#include <stdlib.h>
using std::wcout;       using std::endl;
using std::setiosflags; using std::ios;

int _tmain(int argc, _TCHAR* argv[]) {
	int number = 1001;
	wcout << L"Decimal:" << std::dec << number << endl \
	 	 << L"Hexadecimal:" << std::hex << number << endl \
		 << L"Octal:" << std::oct << number << endl \
		<< L"Hexadecimal:" << std::hex                \
		<< setiosflags(ios::uppercase) << number << endl;
	system("pause");
	return 0;
}
