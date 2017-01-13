#include "stdafx.h"
#include "DataBaseCtrl.h"


CDataBaseCtrl::CDataBaseCtrl()
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


CDataBaseCtrl::~CDataBaseCtrl()
{
}



bool CDataBaseCtrl::LinkDataBase(string udlName)
{
	try
	{
		string strOpen = "FILE Name=" + udlName;
		m_pConn->Open(_bstr_t(strOpen.c_str()),
			_bstr_t(""),			//udl连接账号用不到
			_bstr_t(""),			//udl连接密码用不到
			adConnectUnspecified);  //同步方式建立连接
	}
	catch (_com_error &e)
	{
		MessageBox(0, e.ErrorMessage(), 0, 0);
		m_bSucceed = false;
		return false;
	}
	m_bSucceed = true;
	return true;
}

INT CDataBaseCtrl::ExeSqlByRecordSet(RESULT &re, string sql)
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
	return true;
}

INT CDataBaseCtrl::ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset)
{
	INT nRet = 0;
	try
	{
		//1. 取列名
		Fields * pFields = pReCordset->GetFields();
		long lCount = pFields->GetCount();
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
			for (long i = 0; i < lCount; i++)
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
		//MessageBox(0, e.ErrorMessage(), 0, 0);
		wprintf_s(L"%s",e.ErrorMessage());
		return 0;
	}
}
