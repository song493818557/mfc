#pragma once
#include <windows.h>

#define MESSAGEBUF 1024
enum MESSAGETYPE
{
	common = 1, // 聊天消息属于普通消息
	reg,		// 注册姓名的消息，主要用于客户端给服务器发送
	login,		// 登录
	file,		// 发送文件的命令
	picture,	// 发送图片的命令
	control,	// 控制命令，服务器给客户端发
	Anonymous
};

typedef struct _MESSAGE 
{
	MESSAGETYPE type;	// 消息类型
	DWORD		len;	// 消息长度
	union 
	{
		CHAR	buf[MESSAGEBUF];// 平时发送消息用这个
		struct
		{
			DWORD nameLen;		// 姓名长度，因为客户端发过来name和password是一起的。。。
			CHAR name[50];		// 注册登录用这个
			CHAR password[50];
		}reginfo;
	}info;
}MESSAGE;
