#include "stdafx.h"
#include "Cui.h"
using std::wcout;
using std::ios;
using std::ifstream;
using std::string;
static int  now_map[40][40] = { 0 };

Cui::Cui()
{
}


Cui::~Cui()
{
}
void  read_map(){
	string path[] = { MAPPATH, MAPNAME };
	ifstream map;
	char ch[4] = {};
	_itoa_s(2, ch, 10);//10是进制数
	path[0].append(ch + path[1]);
	map.open(path->c_str(), ios::in | ios::binary);
	if (!map) { wcout << L"无法打开" << path->c_str() << ",\n"; }
	for (int i = 0; i < 40; i++) {
		map.read((char*)now_map[i], 40 * 4);//强转才行 
	}
	map.close();
}

void  draw_map()
{
	for (int i = 0; i < 40; i++) {
		for (int j = 0; j < 40; j++) {
			if (now_map[i][j] == 1)
			{
				WriteChar(i, j, "  ", MAPBG);
			}
			else
			{
				WriteChar(i, j, "※", MAPBG);
			}
			//now_map[i][j] == 1?WriteChar(i, j, "  ", MAPBG):WriteChar(i, j, WALL_D, MAPBG);

		}
	}
}
bool  SetWindowSize(CHAR* pszWindowTitle, int nX, int nY)
{
	//设置控制台标题
	SetConsoleTitleA(pszWindowTitle);
	HANDLE  hStdln, hStdOut;
	hStdln = GetStdHandle(STD_INPUT_HANDLE);
	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	//获取最大控制台的大小
	COORD pos = GetLargestConsoleWindowSize(hStdOut);
	COORD buffersize = { pos.X + 1, pos.Y + 1 };
	//设置控制台缓冲区大小
	if (!SetConsoleScreenBufferSize(hStdOut, buffersize)){
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());
	}
	SMALL_RECT srctWindow = { 0, 0, nX, nY };
	if (!SetConsoleWindowInfo(hStdOut, true, &srctWindow)){
		//设置控制台大小
		printf("size err %d\n", GetLastError());
		return false;
	}
	COORD Buffer = { nX + 1, nY + 1 };
	//设置控制台缓冲区大小
	if (!SetConsoleScreenBufferSize(hStdOut, Buffer)){
		//设置控制台窗口缓冲区失败
		printf("buffer err{%d %d}%d\n", buffersize.X, buffersize.Y, GetLastError());

	}
	return true;
}
void  WriteChar(int y, int x, char *pszChar, WORD wArr){
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = 1;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	COORD loc;
	loc.X = x * 2;
	loc.Y = y;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wArr);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), loc);
	printf(pszChar);

}