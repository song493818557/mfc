#pragma once
#include "stdafx.h" 
#include <Windows.h>
#define MAPBG B_YELLOW //全局地图背景颜色定义
#define DRAWBG   B_H_WHITE|F_H_RED // 画图的相关	
#define MAPPATH   "c:\\a\\c\\"  //地图保存的路径
#define MAPNAME   ".txt"
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
#define H_H_H   0|0
/****************************************************/
/*	常用图形符号定义								*/
/****************************************************/
#define WALL_NO   0x0  // 未激活区域,不打印,无敌不可穿越
#define WALL_NULL 0x1  // 空道00000001
#define WALL_A1   0x3  // ▓   土墙 （可破坏） 00000022
#define WALL_A2   0x3  // 卍  土墙 （可破坏,破坏形态）
#define WALL_B    0x4  // 〓  铁墙 （可破坏）
#define WALL_C    0x5  // ≈   河流 （不可穿越，子弹可过）
#define WALL_D    0x6  // ∷   路障
#define WALL_E    0x7  // ≡ ^^  丛林 （隐身）
#define WALL_F    0x7  // ※  08  高速路（加速）不好处理 
#define WALL_G    0x9  // ☆   箱子 （随机加BUff）
/****************************************************/
/*	常用图形符号定义111111								*/
/****************************************************/
//#define WALL1_A   0x3  // ▓   土墙 （可破坏） 00000022
#define WALL1_A   "▓"  //   土墙 （可破坏,破坏形态）0x3
#define WALL1_AC   F_H_WHITE | B_BLUE  //    土墙背景颜色
#define WALL1_B    "■" // 〓  铁墙 （可破坏）0x4
#define WALL1_BC   F_H_WHITE | B_BLUE // 〓  铁墙背景颜色
#define WALL1_C    "≈"  // ≈   河流 （不可穿越，子弹可过）0x5
#define WALL1_CC    F_H_WHITE | B_BLUE // ≈   河流 背景颜色
#define WALL1_D   "〓"   // ■   路障     0x6
#define WALL1_DC   B_H_WHITE   // ■   路障 背景颜色
#define WALL1_E    "∑"  //  ∑ 丛林 （隐身）0x7
#define WALL1_EC    B_H_GREEN  //    丛林 背景颜色
#define WALL1_F    "※"  //  ※ 高速  0x8 暂时没用到
#define WALL1_FC    B_H_GREEN  //    高速 背景颜色
#define WALL1_G    "☆"  // ☆   箱子 （随机加BUff）
#define WALL1_GC    B_H_YELB_PURPLELOW  //    高速 背景颜色
//讲子弹和坦克移动后的结果返回地图元素里面去
#define TANK_G    B_H_RED|B_PURPLE//0x10 0x11 0x17 0x18// ■   我方坦克 敌方坦克 我方草地坦克 敌方草地坦克    子弹可销毁 不可穿越 
#define TANK_G1   B_H_BLUE|F_H_PURPLE// 0x11   // ■   子弹  子弹可销毁 不可穿越 


#define MISSILETYPE_1   0x01 // ☉  炮弹
#define MISSILETYPE_2   0x02 // ¤  榴弹
#define MISSILETYPE_3   0x03 // ◎  穿甲弹
#define MISSILETYPE_4   0x04 // ⊙ 贫轴弹
#define MISSILETYPE_5   0x05 // ⊕  坦克杀手子母弹
/****************************************************/
/*	地图上的BUFF属性定义							*/
/****************************************************/
#define BUFF_SPEED_GRAPHICS    "速"	//速度
#define BUFF_GOD_GRAPHICS  "强"	//无敌
#define BUFF_SHIELD_GRAPHICS  "盾"	//护盾 
#define BUFF_BG  B_H_RED | F_YELLOW
#define BUFF_SHIELD_LIEF  19
//定义统一的错误码
enum BUFF_NAME
{
	BUFF_STAY,
	BUFF_GOD,     //无敌
	BUFF_SPEED,   //速度
	BUFF_SHIELD  //护盾[可以减少1次攻击]
	//预留
};
  


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
extern int sysMap00[40][40]; 