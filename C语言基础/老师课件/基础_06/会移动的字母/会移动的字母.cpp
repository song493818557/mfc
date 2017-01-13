// 会移动的字母.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <conio.h>
void WriteString(int x, int y, char* pString)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s",pString);
}
enum MyEnum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
};

typedef struct _POSITION
{
	int x;
	int y;
}POSITION;

int _tmain(int argc, _TCHAR* argv[])
{

	int nDir = 0;
	int nSize = 0;
	char cOper = 0;
	POSITION Snake[200] = { 0 };

	Snake[0].x = 10;
	Snake[0].y = 20;
	Snake[1].x = 11;
	Snake[1].y = 20;
	Snake[2].x = 12;
	Snake[2].y = 20;
	nSize = 3;

	while (true)
	{
		Sleep(100);
		if (_kbhit())
		{
			cOper = _getch();
			switch (cOper)
			{
			case 'w':
				nDir = UP;
			
				break;
			case 's':
				nDir = DOWN;
			
				break;
			case 'a':
				nDir = LEFT;
				
				break;
			case 'd':
			
				nDir = RIGHT;
				break;
			default:
				break;
			}
		}
		WriteString(Snake[nSize - 1].x, Snake[nSize - 1].y, " ");
		for (int i = nSize-2; i >=0; i--)
		{
			Snake[i+1] = Snake[i];
		}
		
		switch (nDir)
		{
		case UP:
			Snake[0].y--;
			break;
		case DOWN:
			Snake[0].y++;
			break;
		case LEFT:
			Snake[0].x--;
			break;
		case RIGHT:
			Snake[0].x++;
			break;
		default:
			break;
		}
		for (int i = 0; i < nSize; i++)
		{
			WriteString(Snake[i].x, Snake[i].y, "A");
		}
	}

	return 0;
}

