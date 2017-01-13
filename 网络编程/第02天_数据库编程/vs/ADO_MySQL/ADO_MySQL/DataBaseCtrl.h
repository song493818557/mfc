#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

#import "C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll"\
        no_namespace rename ("EOF","adoEOF")
	
struct  _RESULT  //保存查询的结果 
{
	vector<string>			vec_CloName; //列数据
	vector<vector<string>>  vec_Data;//
};

class CDataBaseCtrl
{
public:
	CDataBaseCtrl();
	~CDataBaseCtrl();
	
	//1.连接数据库
	bool LinkDataBase(string server,
					  string DbName,
					  string UserName,
					  string PassWord);
	//2.发送SQL语句
	bool ExeSqlByConnect(_RESULT &re, string sql);
	bool ExeSqlByCommand(_RESULT &re, string sql);
	bool ExeSqlByRecordSet(_RESULT &re, string sql);

	//3.处理返回的记录集
	bool ParseRecordSet(_RESULT &re,_RecordsetPtr pReCordset);
	
	_ConnectionPtr m_pConn;
};

