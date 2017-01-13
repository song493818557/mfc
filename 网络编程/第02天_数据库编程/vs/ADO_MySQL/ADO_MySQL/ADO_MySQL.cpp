// ADO_MySQL.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "DataBaseCtrl.h"


int main()
{
	CDataBaseCtrl db;//创建DB对象
	db.LinkDataBase(
		"MYSQL", 
		"game_info",
		"root",
		"888888"); //连接数据库

	_RESULT result;
	db.ExeSqlByConnect(result,"select * from gmplay_info");
	//db.ExeSqlByCommand(result, "select * from 玩家表");
	//db.ExeSqlByRecordSet(result, "select * from 玩家表");

    return 0;
}

