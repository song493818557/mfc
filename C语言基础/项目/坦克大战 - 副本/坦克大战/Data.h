#pragma once
#include "stdafx.h"
/****************************************************/
/*	方法宏											*/
/****************************************************/
#define CHAR_TO_WCHAR(lpChar, lpW_Char)\
	MultiByteToWideChar(CP_ACP, NULL, lpChar, -1, lpW_Char, _countof(lpW_Char)); //char*转换为wchar_t*
#define KEY_DOWN(key) GetAsyncKeyState(key)&0x8000  ?1:0					     //键盘监控



/****************************************************/
/*	常用颜色定义									*/
/****************************************************/

// 字体颜色
#define F_BLUE     FOREGROUND_BLUE      // 深蓝
#define F_H_BLUE   0x0001|0x0008        // 亮蓝
#define F_GREEN    0x0002               // 深绿
#define F_H_GREEN  0x0002|0x0008        // 亮绿
#define F_RED      0x0004               // 深红
#define F_H_RED    0x0004|0x0008        // 亮红
#define F_YELLOW   0x0002|0x0004        // 深黄

#define F_H_YELLOW 0x0002|0x0004|0x0008 // 亮黄
#define F_PURPLE   0x0001|0x0004        // 深紫
#define F_H_PURPLE 0x0001|0x0004|0x0008 // 亮紫
#define F_CYAN     0x0002|0x0004        // 深青
#define F_H_CYAN   0x0002|0x0004|0x0008 // 亮青
#define F_WHITE    0x0004|0x0002|0x0001
#define F_H_WHITE  0x0004|0x0002|0x0001|0x0008

// 背景颜色
#define B_BLUE     BACKGROUND_BLUE      // 深蓝
#define B_H_BLUE   0x0010|0x0080        // 亮蓝
#define B_GREEN    0x0020               // 深绿
#define B_H_GREEN  0x0020|0x0080        // 亮绿
#define B_RED      0x0040               // 深红
#define B_H_RED    0x0040|0x0080        // 亮红
#define B_YELLOW   0x0020|0x0040        // 深黄
#define B_H_YELB_PURPLELOW 0x0020|0x0040|0x0080 // 亮黄
#define B_PURPLE   0x0010|0x0040        // 深紫
#define B_H_PURPLE 0x0010|0x0040|0x0080 // 亮紫
#define B_CYAN     0x0020|0x0040        // 深青
#define B_H_CYAN   0x0020|0x0040|0x0080 // 亮青
#define B_WHITE    0x0010|0x0020|0x0040
#define B_H_WHITE  0x0010|0x0020|0x0040|0x0080

/****************************************************/
/*	常用图形符号定义								*/
/****************************************************/
#define WALL_NO   0x0  // 未激活区域,不打印,无敌不可穿越
#define WALL_NULL 0x1  // 空道00000001
#define WALL_A1   0x2  // ▓   土墙 （可破坏） 00000022
#define WALL_A2   0x3  // 卍  土墙 （可破坏,破坏形态）
#define WALL_B    0x4  // 〓  铁墙 （可破坏）
#define WALL_C    0x5  // ≈   河流 （不可穿越，子弹可过）
#define WALL_D    0x6  // ∷   路障
#define WALL_E    0x7  // ≡   丛林 （隐身）
#define WALL_F    0x8  // ※  高速路（加速）
#define WALL_G    0x9  // ☆   箱子 （随机加BUff）

#define MISSILETYPE_1   0x01 // ☉  炮弹
#define MISSILETYPE_2   0x02 // ¤  榴弹
#define MISSILETYPE_3   0x03 // ◎  穿甲弹
#define MISSILETYPE_4   0x04 // ⊙ 贫轴弹
#define MISSILETYPE_5   0x05 // ⊕  坦克杀手子母弹

/****************************************************/
/*	常用属性定义								    */
/****************************************************/
#define UP    0x0	//向上	orientation 朝向
#define DOWN  0x1	//向下
#define LEFT  0x2	//向左
#define RIGHT 0x3	//向右

//scoreID(玩家id)
#define PALY_A    0x0  //  
#define PALY_B    0x1  // 
#define NPC       0x2  //  

/****************************************************/
/*	全局变量声明								    */
/****************************************************/
//extern int sysMap01[40][40];	//游戏内置的一张地图
extern int sysMap00[40][40];	//用户自定义边际地图时,提供的一个模板
//
//extern int sysMap01[40][40] = {
//	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_D, 1, 1, 1, WALL_D, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, WALL_A1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
//	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D
//
//};
//
int sysMap00[40][40] = {
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_B, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_B, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, WALL_A2, WALL_A2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_E, WALL_E, WALL_E, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_A1, WALL_A1, WALL_D, 1, 1, 1, WALL_D, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_F, WALL_F, WALL_F, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, WALL_A1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, WALL_A1, 1, WALL_A1, 1, 1, 1, 1, WALL_C, WALL_C, WALL_C, WALL_C, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, WALL_A1, WALL_A1, WALL_A1, 1, 1, WALL_A1, 1, 1, WALL_A1, 1, 1, 1, WALL_A1, WALL_A1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, WALL_D, WALL_D, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, 1, 1, WALL_D, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, WALL_D, \
	WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D, WALL_D

};
struct _tankball{
	bool isBullet;
	int b_type;//敌我子弹
	//int t_demo[4][3][3];//坦克模型九方格  四个模型
	int b_position;//定义子弹的方向
	int b_x;//玩家操作的坦克移动x坐标
	int b_y;//玩家操作的坦克移动y坐标
	char t_ball[2];//子弹☉
	//int t_move[100][100];//移动坐标

	//int t_npc_stank;//小坦克
	//int t_npc_jtank;//精英坦克
	//int t_npc_btank;//BOSS坦克

}; _tankball myball[256] = { 0 };

typedef struct _WALL
{
	int nType : 4;
	int nXue  : 4;

	int nBaoliu : 24;
}WALL;

int g_nMap[40][40] = { 0 };//全局数组初始化

char g_game_menu[11][70] = {
	"			※※※※※※※※※※※※※※※※※※※※※※※※※",
	"			※                                              ※",
	"			※                                              ※",
	"			※              坦克大战 Max ^_^                ※",
	"			※              ①  开始游戏	                ※",
	"			※              ②  游戏设置	                ※",
	"			※              ③  绘制地图	                ※",
	"			※              ④  游戏帮助	                ※",
	"			※                                              ※",
	"			※                                              ※",
	"			※※※※※※※※※※※※※※※※※※※※※※※※※" };
char start_menu[11][70] = {
	"			※※※※※※※※※※※※※※※※※※※※※※※※※",
	"			※                                              ※",
	"			※                                              ※",
	"			※              坦克大战 Max ^_^                ※",
	"			※              ①  Player  	                ※",
	"			※              ②  Player  	                ※",
	"			※                                              ※",
	"			※                                              ※",
	"			※                                              ※",
	"			※                                              ※",
	"			※※※※※※※※※※※※※※※※※※※※※※※※※" };