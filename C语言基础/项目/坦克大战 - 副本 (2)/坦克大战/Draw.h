#include "Data.h"

#include <process.h>
#include <windows.h>

void DrawTank();
void ClerarTank();
void DrawrobotTank();
void ClearrobotTank();
/***
画地图
***/
void DrawMap();

//打印屏幕
void box(int array[40][40], int x, int y);
//绘制菜单
void game_menu(char amenu[11][70]);
/***
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/
void WriteChar(int y, int x, char *pszChar, WORD wArr);
/***
函数功能 ：设置窗口信息
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/
bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
