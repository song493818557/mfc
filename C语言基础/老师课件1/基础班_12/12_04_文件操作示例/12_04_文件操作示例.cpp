// 12_04_�ļ�����ʾ��.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
using namespace std;

//��һ���ļ�д��һ�仰����������
void testWriteReadStr()
{
	fstream fobjOutFile, fobjInFile;
	fobjOutFile.open("d:\\file1.bat", ios::out);
	if (!fobjOutFile) { wcout << L"file1.dat can't open.\n"; abort(); }

	//������ļ�
	char szStr[] = "I love C++ programing.\n";
	for (int i = 0; i < (int)strlen(szStr); i++)
		fobjOutFile.put(szStr[i]);
	fobjOutFile.close();

	//���ļ�����
	fobjInFile.open("d:\\file1.bat", ios::in);
	if (!fobjInFile) { wcout << L"file1.dat can��t open.\n"; abort(); }
	char cChar;
	while (fobjInFile.get(cChar))
		wcout.put(cChar);

	wcout << endl;
	fobjInFile.close();

}

//��һ���ı��ļ������ݿ�������һ���ļ���
void testCopyStr()
{
	fstream fobjOutFile, fobjInFile;

	fobjInFile.open("d:\\file1.dat", ios::in);
	if (!fobjInFile) { wcout << "file1.dat can't open."; abort(); }
	fobjOutFile.open("d:\\file2.dat", ios::out);
	if (!fobjOutFile) { wcout << "file2.dat can��t open."; abort(); }

	char cChar;
	while (fobjInFile.get(cChar))
		fobjOutFile.put(cChar);
	fobjInFile.close();
	fobjOutFile.close();

}

//�Զ������ļ���Ҫ��open() �����м���ios::binary��ʽ��
//��ʹ��write() ��read() �����Ӷ������ļ���д�Ͷ���Ϣ
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

	//������ļ�
	for (int i = 0; i < 4; i++)
		fobjOutFile.write((char*)&g_stu[i], sizeof(g_stu[i]));


	//���ļ�����
	fobjOutFile.seekp(0, ios::beg);   //����дָ��ָ���ļ�ͷ
	long index = fobjOutFile.tellp(); //��ȡ��ǰλ�õ�ƫ����

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


