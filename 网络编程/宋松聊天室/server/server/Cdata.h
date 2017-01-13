#pragma once 
#pragma once
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib")
#define MAPBG B_H_WHITE|F_H_RED //全局地图背景颜色定义
#define DRAWBG   B_H_WHITE|F_H_RED // 画图的相关	
#define MAPPATH   "c:\\a\\c\\"  //地图保存的路径
#define MAPNAME   ".txt"
#define MESSAGEBUF 1024
#define NAMELENGTH 50
#include <vector>
#include <string>
using std::vector;
using std::string;
enum MESSAGETYPE
{
	common = 1, //1 聊天消息属于普通消息
	reg,		//2 注册姓名的消息，主要用于客户端给服务器发送
	login,		//3 登录
	Anonymous,	//4 匿名聊天
	vchat,		//5 1V1 私聊vchat
	control,	//6 控制命令，服务器给客户端发
	file,		//7 发送文件的命令
	picture,	//8 发送图片的命令 
	search,		//9 搜索
	addfriend,	//10 添加好友  
	alluser     //11 查看所有在线用户
};

typedef struct _MESSAGE
{
	MESSAGETYPE type;		// 消息类型
	DWORD		len;		// 消息长度
	CHAR		buf[MESSAGEBUF]; // 存放要发送的消息，最大长度1024个字节
		
}MESSAGE;

struct  _RESULT  //保存查询的结果 
{
	vector<string>			vec_CloName; //列数据
	vector<vector<string>>  vec_Data;//
};

#define regok     "注册成功"
#define regnook   "注册失败"
#define loginok	  "登录成功"
#define loginnook "登录失败"
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
#define WALL_D    "∷" ///0x6  // ∷   路障
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