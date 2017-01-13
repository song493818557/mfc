#include "stdafx.h"
#include "Cmysql.h"




Cmysql::Cmysql()
{
	try
	{
		CoInitialize(NULL);
		m_pConn.CreateInstance(__uuidof(Connection));
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
	}
}


Cmysql::~Cmysql()
{
	try
	{
		m_pConn->Close();
		CoUninitialize();
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
	}
}

bool Cmysql::LinkDataBase(string server,
	string DbName,
	string UserName,
	string PassWord)
{
	try
	{
		/*
		控制面板 -> 管理工具 ->ODBC数据源（32/64）
		创建udl文件
		*/

		//方法一：

		//Provider: 数据库服务商标示
		//Data Source:配置的数据源
		//Initial Catalog：初始连接的数据库名
		//User ID：用户名
		//Password：密码

		char strLink[MAX_PATH] = { 0 };
		sprintf_s(strLink, MAX_PATH, "Provider=MSDASQL.1;Persist Security Info=True;Data Source=%s;Initial Catalog=%s;User ID=%s;Password=%s",
			server.c_str(),
			DbName.c_str(),
			UserName.c_str(),
			PassWord.c_str()
			);

		m_pConn->Open(_bstr_t(strLink),
			_bstr_t(""),			//账号
			_bstr_t(""),			//密码
			adConnectUnspecified);  //同步方式建立连接
		/*

		//方法二：
		m_pConn->Open(_bstr_t("FILE Name=dblink.udl"),
		_bstr_t(""),			//账号
		_bstr_t(""),			//密码
		adConnectUnspecified);  //同步方式建立连接
		*/
		m_bSucess = true;
		return true;
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0); \
		m_bSucess = false;
		return false;
	}
}

bool Cmysql::LinkDataBase1()
{
	try
	{
		/*
		控制面板 -> 管理工具 ->ODBC数据源（32/64）
		创建udl文件
		*/
		//方法二： 
		m_pConn->Open(_bstr_t("FILE Name=dblink.udl"),
			_bstr_t(""),			//账号
			_bstr_t(""),			//密码
			adConnectUnspecified);  //同步方式建立连接
		m_bSucess = true;
		return true;
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		m_bSucess = false;
		return false;
	}
}
int Cmysql::ExeSqlByConnect(_RESULT &re, string sql)
{
	try
	{
		_variant_t RecordsAffected;
		_RecordsetPtr pReCord = m_pConn->Execute(
			_bstr_t(sql.c_str()),  //sql语句
			&RecordsAffected,	   //多少行受影响
			adCmdText);            //如何解析第一个参数（文本方式）

		return ParseRecordSet(re, pReCord);
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		return -1;
	}
}

int Cmysql::ExeSqlByCommand(_RESULT &re, string sql)
{
	try
	{
		_CommandPtr pComm;
		pComm.CreateInstance(__uuidof(Command));
		//设置参数
		/*
		char var[100];
		_ParameterPtr param = pComm->CreateParameter(
		"paramName",		//参数的名字
		adVarChar,			//参数的数据类型
		adParamInput,		//参数的作用
		sizeof(var),        //参数的大小
		var                 //参数的值
		);
		pComm->Parameters->Append(param);
		*/

		_variant_t RecordsAffected;
		pComm->CommandText = _bstr_t(sql.c_str());
		pComm->ActiveConnection = m_pConn;
		_RecordsetPtr pRecord = pComm->Execute(&RecordsAffected, NULL, adCmdText);

		return ParseRecordSet(re, pRecord);
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		return -1;
	}
}

int  Cmysql::ExeSqlByRecordSet(_RESULT &re, string sql)
{
	try
	{
		_RecordsetPtr pRecord;
		pRecord.CreateInstance(__uuidof(Recordset));

		pRecord->Open(
			sql.c_str(),				//sql语句
			m_pConn.GetInterfacePtr(),  //connect对象
			adOpenStatic,				//数据集的类型（游标的类型）
			adLockOptimistic,			//锁定方式
			adCmdText					//怎么解析第一个参数
			);

		return ParseRecordSet(re, pRecord);
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		return -1;
	}
}

int Cmysql::ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset)
{
	int nRet = 0;
	try
	{
		//1. 取列名
		Fields * pFields = pReCordset->GetFields();
		long lCount = pFields->GetCount();
		if (lCount == 0)
		{
			return false;
		}
		for (long i = 0; i < lCount; i++)
		{
			FieldPtr pField = pFields->GetItem(i);
			string colName = pField->GetName();
			re.vec_CloName.push_back(colName);
		}

		//2. 取数据
		while (!pReCordset->GetadoEOF())
		{
			nRet++;
			vector<string> item;
			for (long i = 0; i<lCount; i++)
			{
				//pReCordset->GetCollect("userName");
				_variant_t value = pReCordset->GetCollect(i);
				if (value.vt == VT_NULL)
				{
					item.push_back("");
				}

				else {
					string str = _bstr_t(value);
					item.push_back(str);
				}
			}
			re.vec_Data.push_back(item);
			pReCordset->MoveNext();
		}
		return nRet;
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		return 0;
		//return -1; 没有数据不代表查询失败?
	}
}
