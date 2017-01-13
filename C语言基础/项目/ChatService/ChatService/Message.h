#pragma once
#include <WinSock2.h>
#pragma comment(lib,"Ws2_32.lib") 
#include "Cmenu.h"

 
enum MESSAGETYPE
{
	common = 1, // 聊天消息属于普通消息
	reg,		// 注册姓名的消息，主要用于客户端给服务器发送
	login,		// 登录
	file,		// 发送文件的命令
	picture,	// 发送图片的命令
	control		// 控制命令，服务器给客户端发
};

typedef struct _MESSAGE 
{
	MESSAGETYPE type;		// 消息类型
	DWORD		len;		// 消息长度
	CHAR		buf[MESSAGEBUF];	// 存放要发送的消息，最大长度1024个字节
}MESSAGE;
