#pragma once
#include "Cmenu.h" 
using std::vector;
using std::string;

#import "C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll" \
no_namespace rename ("EOF","adoEOF")
//找不到直接生产 会有.TLI TLS文件 就可以了



class Cmysql
{
public:
	Cmysql();
	~Cmysql();

	//1.连接数据库
	bool LinkDataBase(string server,
		string DbName,
		string UserName,
		string PassWord);
	bool LinkDataBase1();
	//2.发送SQL语句
	// 返回-1表示查询失败，0表示成功执行但没数据返回，其他表示成功
	int ExeSqlByConnect(_RESULT &re, string sql);
	int ExeSqlByCommand(_RESULT &re, string sql);
	int ExeSqlByRecordSet(_RESULT &re, string sql);

	//3.处理返回的记录集
	// 返回-1表示查询失败，0表示成功执行但没数据返回，其他表示成功
	int ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset);

	_ConnectionPtr m_pConn;
	bool m_bSucess;
};