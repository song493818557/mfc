#include "stdafx.h"
#include "draw.h"
#include <windows.h>

void WriteChar(short row, short col, char * str)
{
	COORD pos = { 2 * col,row };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
	printf("%s", str);
}
