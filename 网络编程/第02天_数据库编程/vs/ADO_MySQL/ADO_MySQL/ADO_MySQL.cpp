// ADO_MySQL.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "DataBaseCtrl.h"


int main()
{
	CDataBaseCtrl db;//����DB����
	db.LinkDataBase(
		"MYSQL", 
		"game_info",
		"root",
		"888888"); //�������ݿ�

	_RESULT result;
	db.ExeSqlByConnect(result,"select * from gmplay_info");
	//db.ExeSqlByCommand(result, "select * from ��ұ�");
	//db.ExeSqlByRecordSet(result, "select * from ��ұ�");

    return 0;
}

