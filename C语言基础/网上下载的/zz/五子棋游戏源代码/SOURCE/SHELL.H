
#ifndef _SHELL_H_
#define _SHELL_H_
#include "luffar.h"

void InitGraphics();
void Cls();

void DrawBackground();
char ReadKey();
void Rectangle(int,int,int,int,int,BOOL shadow=FALSE,int deep=0);

void WaitDlg(int nMode=0, int nDelay=0);
int ShowWinDlg(CPlayer* winner);

void IntToChar(int, char*);
void Message(char*);
#endif