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
			_bstr_t(""),			//udl�����˺��ò���
			_bstr_t(""),			//udl���������ò���
			adConnectUnspecified);  //ͬ����ʽ��������
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
			sql.c_str(),				//sql���
			m_pConn.GetInterfacePtr(),  //connect����
			adOpenStatic,				//���ݼ������ͣ��α�����ͣ�
			adLockOptimistic,			//������ʽ
			adCmdText					//��ô������һ������
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
		//1. ȡ����
		Fields * pFields = pReCordset->GetFields();
		long lCount = pFields->GetCount();
		for (long i = 0; i < lCount; i++)
		{
			FieldPtr pField = pFields->GetItem(i);
			string colName = pField->GetName();
			re.vec_CloName.push_back(colName);
		}

		//2. ȡ����
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
