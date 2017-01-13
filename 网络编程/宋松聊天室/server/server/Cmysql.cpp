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
		������� -> ������ ->ODBC����Դ��32/64��
		����udl�ļ�
		*/

		//����һ��

		//Provider: ���ݿ�����̱�ʾ
		//Data Source:���õ�����Դ
		//Initial Catalog����ʼ���ӵ����ݿ���
		//User ID���û���
		//Password������

		char strLink[MAX_PATH] = { 0 };
		sprintf_s(strLink, MAX_PATH, "Provider=MSDASQL.1;Persist Security Info=True;Data Source=%s;Initial Catalog=%s;User ID=%s;Password=%s",
			server.c_str(),
			DbName.c_str(),
			UserName.c_str(),
			PassWord.c_str()
			);

		m_pConn->Open(_bstr_t(strLink),
			_bstr_t(""),			//�˺�
			_bstr_t(""),			//����
			adConnectUnspecified);  //ͬ����ʽ��������
		/*

		//��������
		m_pConn->Open(_bstr_t("FILE Name=dblink.udl"),
		_bstr_t(""),			//�˺�
		_bstr_t(""),			//����
		adConnectUnspecified);  //ͬ����ʽ��������
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
		������� -> ������ ->ODBC����Դ��32/64��
		����udl�ļ�
		*/
		//�������� 
		m_pConn->Open(_bstr_t("FILE Name=dblink.udl"),
			_bstr_t(""),			//�˺�
			_bstr_t(""),			//����
			adConnectUnspecified);  //ͬ����ʽ��������
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
			_bstr_t(sql.c_str()),  //sql���
			&RecordsAffected,	   //��������Ӱ��
			adCmdText);            //��ν�����һ���������ı���ʽ��

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
		//���ò���
		/*
		char var[100];
		_ParameterPtr param = pComm->CreateParameter(
		"paramName",		//����������
		adVarChar,			//��������������
		adParamInput,		//����������
		sizeof(var),        //�����Ĵ�С
		var                 //������ֵ
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
}

int Cmysql::ParseRecordSet(_RESULT &re, _RecordsetPtr pReCordset)
{
	int nRet = 0;
	try
	{
		//1. ȡ����
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

		//2. ȡ����
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
		//return -1; û�����ݲ������ѯʧ��?
	}
}
