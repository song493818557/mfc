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
	// �������ݿ�
	bool LinkDataBase(string udlName);
	// ����-1��ʾ��ѯʧ�ܣ�0��ʾ�ɹ�ִ�е�û���ݷ��أ�������ʾ�ɹ�
	INT ExeSqlByRecordSet(RESULT &re, string sql);
	INT ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset);
	_ConnectionPtr m_pConn;
	bool m_bSucceed;

};

