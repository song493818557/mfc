#pragma once

#define NUM 100
// #define 查看所有 1
// #define 新增     2
// #define 删除     3
// #define 修改     4
// #define 查询     5

enum OPTION
{
	查看所有 = 1,
	新增,
	删除,
	修改,
	查询,
	保存文本,
	保存二进制,
};

typedef struct _PASSWORD
{
	char website[100];
	char userName[100];
	char passWord[100];
	char note[100];
}PASSWORD, *PPASSWORD;

extern int g_size;