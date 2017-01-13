#pragma once 
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include "Cdata.h"
#include <iostream>
#include <fstream>
#include <Windows.h>
#include <conio.h>

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

