#include "stdafx.h"
#include "Ceditmap.h"
#include <Windows.h>


/*
功能：右侧描述菜单输出
*/
void Ceditmap::Directions(){
//	system("color");
	m_mapid = 3; 
	for (int i = 0; i < 40; i++){
		for (int j = 40; j < 56; j++)
		{
			if (j == 40 || j == 55 || i == 0 || i == 39){

				WriteChar(i, j, WALL1_D, WALL1_DC);
			}
			else
			{
				WriteChar(i, j, "  ", 0);
			}

		}

	} 
	int k = 0;
		for (int j = 1 ; j < 31; j++)
		{
			if (j%2== 0 && k < 13){
				//WriteChar(j + 1, 41, gga[0], B_H_WHITE | F_GREEN);
				WriteChar(j, 42, gga[k], B_H_WHITE | F_GREEN);
				k++;
			}
			else
			{
				if (j == 1 )
				{
					WriteChar(j, 42, "                       ", B_H_WHITE | F_GREEN);
				}
				else
				{
					WriteChar(j, 42, gga[0], B_H_WHITE | F_GREEN);
				}
				
			}

		}

	// 
	//char gg[] = "■■■■■■■■■■■";
	//char gg1[] = "■  当前选择:土墙   ■";
	//char gg2[] = "■     2、空白      ■";//0x32 41 4  49
	//char gg3[] = "■     3、土墙      ■";//0x33 41 6
	//char gg4[] = "■     4、铁墙      ■";//0x34 41 8
	//char gg5[] = "■     5、河流      ■";//0x35 41 10 
	//char gg6[] = "■     6、障碍      ■";//0x36 41 12 		
	//char gg7[] = "■     7、草地      ■";//0x37 41 14 	
	//char gg9[] = "■■■■■■■■■■■";
	//char gg10[] = "■    左键画地图    ■";
	//char gg11[] = "■    右键清除      ■";
	//char gg12[] = "■    保存（S）     ■";//0X73 0X53  41 27
	//char gg13[] = "■    读取（L）     ■";//0X4C 0X6C  41 29
	//char gg14[] = "■    默认（D）     ■";//0X64 0X44  41 31
	//char gg15[] = "■    退出 (Q)      ■";//0X71 0X51  41 33
	//char gg8[] = "■                  ■";
	////地图元素选择区
	////WriteChar(0, 40, gg, B_H_WHITE | F_GREEN);
	//WriteChar(1, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(2, 40, gg1, B_H_WHITE | F_GREEN);
	//WriteChar(3, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(4, 40, gg2, B_H_WHITE | F_GREEN);
	//WriteChar(5, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(6, 40, gg3, B_H_WHITE | F_H_RED);
	//WriteChar(7, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(8, 40, gg4, B_H_WHITE | F_GREEN);
	//WriteChar(9, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(10, 40, gg5, B_H_WHITE | F_GREEN);
	//WriteChar(11, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(12, 40, gg6, B_H_WHITE | F_GREEN);
	//WriteChar(13, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(14, 40, gg7, B_H_WHITE | F_GREEN);
	//WriteChar(15, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(16, 40, gg, B_H_WHITE | F_GREEN);
	////键盘鼠标说明区
	//WriteChar(17, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(18, 40, gg10, B_H_WHITE | F_GREEN);
	//WriteChar(19, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(20, 40, gg11, B_H_WHITE | F_GREEN);
	//WriteChar(21, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(22, 40, gg, B_H_WHITE | F_GREEN);
	////存档说明区
	//WriteChar(23, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(24, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(25, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(26, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(27, 40, gg12, B_H_WHITE | F_GREEN);
	//WriteChar(28, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(29, 40, gg13, B_H_WHITE | F_GREEN);
	//WriteChar(30, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(31, 40, gg14, B_H_WHITE | F_GREEN);
	//WriteChar(32, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(33, 40, gg15, B_H_WHITE | F_GREEN);
	//WriteChar(34, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(35, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(36, 40, gg8, B_H_WHITE | F_GREEN);
	//WriteChar(37, 40, gg, B_H_WHITE | F_GREEN);
}
/*
功能：输出当前鼠标坐标
*/
void Ceditmap::outputPos(int nX, int nY)//输出测试
{
	char szBuf[100];
	sprintf_s(szBuf, sizeof(szBuf), "x=%2d,y=%2d", nX / 2, nY);
	SetConsoleTitleA(szBuf);
	WriteChar(0, 0, szBuf, 0x50);
}
/*
功能：处理键盘事件
*/
void Ceditmap::keyevent(KEY_EVENT_RECORD ker)
{
	if (ker.bKeyDown){
		WORD   temp;
		temp = ker.wVirtualScanCode;
		temp = ker.wVirtualKeyCode;
		switch (ker.uChar.AsciiChar)
		{
		case 0x32:m_key_Previous = m_mapid; m_mapid = 2; break;
		case 0x33:m_key_Previous = m_mapid; m_mapid = 3; break;
		case 0x34:m_key_Previous = m_mapid; m_mapid = 4; break;
		case 0x35:m_key_Previous = m_mapid; m_mapid = 5; break;
		case 0x36:m_key_Previous = m_mapid; m_mapid = 6; break;
		case 0x37:m_key_Previous = m_mapid; m_mapid = 7; break;
		case 0x73:case  0x53:m_key_Previous = m_mapid; m_mapid = 8; break;
		case 0x4C:case  0x6C:m_key_Previous = m_mapid; m_mapid = 9; break;
		case 0x64:case  0x44:m_key_Previous = m_mapid; m_mapid = 10; break;
		case 0x71:case  0x51:  case '\x1b':  m_mapid=99; break;//退出 
			
		}
		small_menu(1, m_mapid);
		WriteChar(0, 0, "键盘按下", 0x50);

	}
	else
	{
		//WriteChar(0, 0, "键盘弹起", 0x50);
	}

}
/*
功能：处理鼠标事件
*/
void Ceditmap::mouseEvent(MOUSE_EVENT_RECORD mer)//接收鼠标的函数
{
	int y = mer.dwMousePosition.Y;
	int x = mer.dwMousePosition.X/2;	
		switch (mer.dwEventFlags)
		{
			case 0:
			{
				ison = 1;
				if (mer.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED){
					if (x >0 && x< 39 && y> 0 & y<39)//
					{
						switch (m_mapid)
						{
						case 2: WriteChar(y, x, "  ", 0 | 0); now_map[y][x] = 1; break;
						case 3: WriteChar(y, x, "", B_H_WHITE | 0, 3); now_map[y][x] = 3; break;
						case 4: WriteChar(y, x, "", B_H_WHITE | 0, 4); now_map[y][x] = 4; break;
						case 5: WriteChar(y, x, "", B_H_WHITE | 0, 5); now_map[y][x] = 5; break;
						case 6: WriteChar(y, x, "", B_H_WHITE | 0, 6); now_map[y][x] = 6; break;
						case 7: WriteChar(y, x, "", B_H_WHITE | 0, 7); now_map[y][x] = 7; break;
							 
						}
					}
					else if (x <50 && x>40 ){
						switch (y)
						{
						case 4:  m_key_Previous = m_mapid; m_mapid = 2; break;
						case 6:  m_key_Previous = m_mapid; m_mapid = 3; break;
						case 8:  m_key_Previous = m_mapid; m_mapid = 4; break;
						case 10: m_key_Previous = m_mapid; m_mapid = 5; break;
						case 12: m_key_Previous = m_mapid; m_mapid = 6; break;
						case 14: m_key_Previous = m_mapid;  m_mapid = 7;  break;
						case 20: m_key_Previous = m_mapid;  m_mapid = 8; Savemap(); break;//保存地图
						case 22: m_key_Previous = m_mapid;  m_mapid = 9;   Readmap(0); break;//读取存档地图
						case 24: m_key_Previous = m_mapid;  m_mapid = 10; in_map = 1;   Readmap(0);  break;//读取默认地图
						case 26: m_key_Previous = m_mapid;  m_mapid = 11;  break;
						}
						small_menu(1, m_mapid);
					}	

				}
				else if (mer.dwButtonState==RIGHTMOST_BUTTON_PRESSED){
					ison = 2;
					if (x >0 && x< 39 && y> 0 & y<39)//
					{
						WriteChar(y, x, "  ", 0 | 0);
						now_map[y][x] = 1;
					}
				}
				else
				{
					ison = 0;
				}
			}break;
			case MOUSE_MOVED : {
				if (ison == 1){
					if (x >0 && x< 39 && y> 0 & y<39)//
					{
						switch (m_mapid)
						{
						case 2: WriteChar(y, x, "  ", 0 | 0); now_map[y][x] = 1; break;
						case 3: WriteChar(y, x, "", B_H_WHITE | 0, 3); now_map[y][x] = 3; break;
						case 4: WriteChar(y, x, "", B_H_WHITE | 0, 4); now_map[y][x] = 4; break;
						case 5: WriteChar(y, x, "", B_H_WHITE | 0, 5); now_map[y][x] = 5; break;
						case 6: WriteChar(y, x, "", B_H_WHITE | 0, 6); now_map[y][x] = 6; break;
						case 7: WriteChar(y, x, "", B_H_WHITE | 0, 7); now_map[y][x] = 7; break;
						}
					}
					ison = 1;
				}
				else if (ison == 2)
				{ 
					if (x >0 && x < 39 && y> 0 & y < 39)//
					{
						WriteChar(y, x, "  ", 0 | 0); now_map[y][x] = 1;
						ison = 2;
					}
				}
				//outputPos(mer.dwMousePosition.X, mer.dwMousePosition.Y);
				break;
			}
			
		}
	
}
/*
功能：循环监听鼠标键盘事件
*/
int Ceditmap::get_Message()//获取事件函数
{
	HANDLE hStdin = GetStdHandle(STD_INPUT_HANDLE);
	INPUT_RECORD stcRecord = { 0 };
	DWORD dwRead;
	SetConsoleMode(hStdin,ENABLE_WINDOW_INPUT|ENABLE_MOUSE_INPUT);
	while (m_mapid < 99){
		//等待事件
		ReadConsoleInput(hStdin,&stcRecord,1,&dwRead);
		//处理事件
		if (stcRecord.EventType ==KEY_EVENT){
			keyevent(stcRecord.Event.KeyEvent);
		}
		else if (stcRecord.EventType == MOUSE_EVENT)
		{
			mouseEvent(stcRecord.Event.MouseEvent);

		}
	}
	return 0;
}
/*
功能：右侧菜单读取+加变色提示
int number 变色提示
int map_id 选项ID
*/
void Ceditmap::small_menu(int number,int map_id){
	WORD wArr;	
	if (m_bool == 3)
	{ 
		m_bool = 1;
		return;		
	}
	if (number == 1 ){
	 wArr = B_H_WHITE | F_H_RED;
	 m_bool = 2;
	}
	else{
		 wArr = B_H_WHITE | F_GREEN;
		 m_bool = 3;
	}
	int xa = 42;
	switch (map_id)
	{
		
	case 2:  WriteChar(4, xa, "■     2、空白      ■", wArr); WriteChar(2, xa-0, "■  上个选择:空白   ■", B_H_WHITE | F_GREEN); break;
	case 3:  WriteChar(6, xa, "■     3、土墙      ■", wArr); WriteChar(2, xa-0, "■  上个选择:土墙   ■", B_H_WHITE | F_GREEN); break;
	case 4:  WriteChar(8, xa, "■     4、铁墙      ■", wArr); WriteChar(2, xa-0, "■  上个选择:铁墙   ■", B_H_WHITE | F_GREEN); break;
	case 5:  WriteChar(10, xa, "■     5、河流      ■", wArr); WriteChar(2, xa-0, "■  上个选择:河流   ■", B_H_WHITE | F_GREEN); break;
	case 6: WriteChar(12, xa, "■     6、障碍      ■", wArr); WriteChar(2, xa-0, "■  上个选择:障碍   ■", B_H_WHITE | F_GREEN); break;
	case 7: WriteChar(14, xa, "■     7、草地      ■", wArr); WriteChar(2, xa-0, "■  上个选择:草地   ■", B_H_WHITE | F_GREEN); break;
	case 8: WriteChar(20, xa, "■    保存（S）     ■", wArr); WriteChar(2, xa-0, "■  上个选择:保存   ■", B_H_WHITE | F_GREEN); break;
	case 9: WriteChar(22, xa, "■    读取（L）     ■", wArr); WriteChar(2, xa-0, "■  上个选择:读取   ■", B_H_WHITE | F_GREEN); break;
	case 10: WriteChar(24, xa, "■    默认（D）     ■", wArr); WriteChar(2, xa-0, "■  上个选择:默认   ■", B_H_WHITE | F_GREEN); break;
	case 11: WriteChar(26, xa, "■    退出 (Q)      ■", wArr); WriteChar(2, xa-0, "■  上个选择:退出   ■", B_H_WHITE | F_GREEN); break;
	}
	small_menu(2, m_key_Previous);
}
//地图保存
void Ceditmap::Savemap(){

	FILE * pFile = NULL;
	switch (in_map)
	{
	case 0:fopen_s(&pFile, "c:\\a\\0.txt", "rb+"); break;//默认地图
	case 1:fopen_s(&pFile, "c:\\a\\1.txt", "rb+"); break;//存档地图
	case 2:fopen_s(&pFile, "c:\\a\\2.txt", "rb+"); break;//关卡一
	case 3:fopen_s(&pFile, "c:\\a\\3.txt", "rb+"); break;//关卡二
	case 4:fopen_s(&pFile, "c:\\a\\4.txt", "rb+"); break;//关卡三
	}
	fwrite(
		now_map, //写的起始地址 buf2
		4, //一块的大小
		20 * 20 * sizeof(int),              //写入多少块
		pFile);
	fclose(pFile);
}
/*
功能：地图读取
int numb 0-5
*/
void Ceditmap::Readmap(int numb = 0){
	FILE * pFile = NULL;
	ClearMap();
	switch (in_map)
	{
	case 0:fopen_s(&pFile, "c:\\a\\0.txt", "rb+"); break;//默认地图
	case 1:fopen_s(&pFile, "c:\\a\\1.txt", "rb+"); break;//存档地图
	case 2:fopen_s(&pFile, "c:\\a\\2.txt", "rb+"); break;//关卡一
	case 3:fopen_s(&pFile, "c:\\a\\3.txt", "rb+"); break;//关卡二
	case 4:fopen_s(&pFile, "c:\\a\\4.txt", "rb+"); break;//关卡三
	}
	//fopen_s(&pFile, path, "rb+");
	fread(
		now_map, //写的起始地址 buf2
		4, //一块的大小
		20 * 20 * sizeof(int),              //写入多少块
		pFile);
	fclose(pFile);
	DrawMap();
}