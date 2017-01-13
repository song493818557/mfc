#pragma once
#include <vector>
#include <string>
using std::vector;
using std::string;

#import "C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll"\
        no_namespace rename ("EOF","adoEOF")
	
struct  _RESULT  //�����ѯ�Ľ�� 
{
	vector<string>			vec_CloName; //������
	vector<vector<string>>  vec_Data;//
};

class CDataBaseCtrl
{
public:
	CDataBaseCtrl();
	~CDataBaseCtrl();
	
	//1.�������ݿ�
	bool LinkDataBase(string server,
					  string DbName,
					  string UserName,
					  string PassWord);
	//2.����SQL���
	bool ExeSqlByConnect(_RESULT &re, string sql);
	bool ExeSqlByCommand(_RESULT &re, string sql);
	bool ExeSqlByRecordSet(_RESULT &re, string sql);

	//3.�����صļ�¼��
	bool ParseRecordSet(_RESULT &re,_RecordsetPtr pReCordset);
	
	_ConnectionPtr m_pConn;
};

