#pragma once
#include "Cmenu.h" 
using std::vector;
using std::string;

#import "C:\\Program Files (x86)\\Common Files\\System\\ado\\msado15.dll" \
no_namespace rename ("EOF","adoEOF")
//�Ҳ���ֱ������ ����.TLI TLS�ļ� �Ϳ�����



class Cmysql
{
public:
	Cmysql();
	~Cmysql();

	//1.�������ݿ�
	bool LinkDataBase(string server,
		string DbName,
		string UserName,
		string PassWord);
	bool LinkDataBase1();
	//2.����SQL���
	// ����-1��ʾ��ѯʧ�ܣ�0��ʾ�ɹ�ִ�е�û���ݷ��أ�������ʾ�ɹ�
	int ExeSqlByConnect(_RESULT &re, string sql);
	int ExeSqlByCommand(_RESULT &re, string sql);
	int ExeSqlByRecordSet(_RESULT &re, string sql);

	//3.�����صļ�¼��
	// ����-1��ʾ��ѯʧ�ܣ�0��ʾ�ɹ�ִ�е�û���ݷ��أ�������ʾ�ɹ�
	int ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset);

	_ConnectionPtr m_pConn;
	bool m_bSucess;
};