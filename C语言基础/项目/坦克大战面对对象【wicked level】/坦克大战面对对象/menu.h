#pragma once
#include "stdafx.h"  
#include "Data.h"
/***
函数功能 ：设置窗口信息
参数一：宽度X行
参数二：高度Y行
参数三：打印的字符
参数四：打印字符的属性
***/

bool SetWindowSize(CHAR* pszWindowTitle, int nX, int nY);
void WriteChar(int y, int x, char *pszChar, WORD wArr);