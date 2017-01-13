#pragma once
#include <string>
using std::string;
#include <vector>
using std::vector;

#import "C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll"\
        no_namespace rename ("EOF","adoEOF")


typedef struct  _RESULT
{
	vector<string>			vec_CloName;
	vector<vector<string>>  vec_Data;
}RESULT;


class CDataBaseCtrl
{
public:
	CDataBaseCtrl();
	~CDataBaseCtrl();
	// 连接数据库
	bool LinkDataBase(string udlName);
	// 返回-1表示查询失败，0表示成功执行但没数据返回，其他表示成功
	INT ExeSqlByRecordSet(RESULT &re, string sql);
	INT ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset);
	_ConnectionPtr m_pConn;
	bool m_bSucceed;

};

