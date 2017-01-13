#pragma once 
#include "Data.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>
#define _WINSOCK_DEPRECATED_NO_WARNINGS
void read_map();
void draw_map();
void WriteChar(int y, int x, char *pszChar, WORD wArr);
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
class Cui
{
public:
	Cui();
	~Cui();
};

