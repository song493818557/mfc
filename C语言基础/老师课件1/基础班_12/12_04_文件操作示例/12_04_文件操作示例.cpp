// 12_04_文件操作示例.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

//向一个文件写入一句话，并读出来
void testWriteReadStr()
{
	fstream fobjOutFile, fobjInFile;
	fobjOutFile.open("d:\\file1.bat", ios::out);
	if (!fobjOutFile) { wcout << L"file1.dat can't open.\n"; abort(); }

	//输出到文件
	char szStr[] = "I love C++ programing.\n";
	for (int i = 0; i < (int)strlen(szStr); i++)
		fobjOutFile.put(szStr[i]);
	fobjOutFile.close();

	//从文件输入
	fobjInFile.open("d:\\file1.bat", ios::in);
	if (!fobjInFile) { wcout << L"file1.dat can’t open.\n"; abort(); }
	char cChar;
	while (fobjInFile.get(cChar))
		wcout.put(cChar);

	wcout << endl;
	fobjInFile.close();

}

//将一个文本文件的内容拷贝到另一个文件中
void testCopyStr()
{
	fstream fobjOutFile, fobjInFile;

	fobjInFile.open("d:\\file1.dat", ios::in);
	if (!fobjInFile) { wcout << "file1.dat can't open."; abort(); }
	fobjOutFile.open("d:\\file2.dat", ios::out);
	if (!fobjOutFile) { wcout << "file2.dat can’t open."; abort(); }

	char cChar;
	while (fobjInFile.get(cChar))
		fobjOutFile.put(cChar);
	fobjInFile.close();
	fobjOutFile.close();

}

//对二进制文件，要在open() 函数中加上ios::binary方式。
//并使用write() 和read() 函数从二进制文件中写和读信息
struct _PERSON {
	char cNme[80];
	double dHig;
	unsigned short usAge;
};
_PERSON g_stu[4] = { "Ma",1.78,35,
"Li",1.68,24,
"Hu",1.90,40,
"Lu",1.89,50 };
void testBinary()
{
	fstream fobjOutFile;
	fobjOutFile.open("d:\\file1.dat", ios::in | ios::out | ios::binary);
	if (!fobjOutFile) { wcout << "file1.dat can't open.\n"; abort(); }

	//输出到文件
	for (int i = 0; i < 4; i++)
		fobjOutFile.write((char*)&g_stu[i], sizeof(g_stu[i]));


	//从文件输入
	fobjOutFile.seekp(0, ios::beg);   //将读写指针指到文件头
	long index = fobjOutFile.tellp(); //获取当前位置的偏移量

	_PERSON stu[4] = { 0 };
	for (int i = 0; i < 4; i++) {
		fobjOutFile.read((char*)&stu[i], sizeof(stu[i]));
		wcout << stu[i].cNme << '\t' << stu[i].dHig << '\t' << stu[i].usAge << endl;
	}
	fobjOutFile.close();
}
int main()
{
	//testWriteReadStr();
	//testCopyStr();
	testBinary();
	return 0;
}


