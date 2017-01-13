#include "stdafx.h"
#include "ADOClass.h"
CADOClass::CADOClass(){


}
CADOClass::~CADOClass(){
	if (m_pConnection)
	{
		try
		{
			//�ر����ݿ�
			HRESULT hr = m_pConnection->Close();
			m_pRecordSet->Close();
			::CoUninitialize();
		}
		catch (_com_error &e)
		{
			MessageBox(0,e.Description(),0,0);
		}
	}
}
//************************************
// ����:    �������ݿ� 
// ����ֵ:   BOOL 
// Parameter: LOGININFO LoginInfo  ���ݿ��¼��Ϣ
// Parameter: CString & strErrorInfo  ����ִ�д�����Ϣ
//************************************
bool CADOClass::LoginDataBase(LOGININFO LoginInfo, CString &strErrorInfo){
	try
	{
		//1.�������ݿ�,�����Connection �����Ƿ�Ϊ��,���������������ݿ�
		if (m_pConnection &&(m_pConnection->State == adStateOpen))
		{
			m_pConnection->Close();
		}
		//2.����Connection����
		HRESULT hr = m_pConnection.CreateInstance(__uuidof(Connection));
		//����_T("ADODB.Connection")
		//3.���������ַ��� ������BSTR�ͻ���_bstr_t����
		CString strFormatBuff;
		strFormatBuff.Format(L"Provider=SQLOLEDB;Server=%s;\	  							  Database=%s;Uid=%s;Pwd=%s", LoginInfo.strDataBaseIP, LoginInfo.strDataBaseName, LoginInfo.strUserName, LoginInfo.strPassWord);
		//���ݿ�IP ���� ��¼��  ��¼����
		//4.�򿪲��������ݿ�
		m_pConnection->Open(_bstr_t(strFormatBuff),//����������Ϣ
			_bstr_t(L""),	//����ʱҪʹ�õ��û�����
			_bstr_t(L""),	//����ʱҪʹ�õ��û�����
			adConnectUnspecified);//ȷ��Ӧ�ڽ�������֮��(ͬ��)����Ӧ�ڽ�������֮ǰ(�첽)���ر�����
	}
	catch (_com_error& e)
	{
		strErrorInfo = (LPCSTR)e.Description();//�õ�����
		return false;
	}
	return true;
}
//************************************
// Method:    ConnExeSql 
// ����ֵ:   bool 
// Parameter: CString strSql			//ִ��SQL���
// Parameter: CString & strErrorInfo	//����ִ�д�����Ϣ
//************************************
bool CADOClass::ConnExeSql(CString strSql, CString &strErrorInfo){
	if (nullptr == m_pConnection)
	{
		return false;
	}
	try
	{
		HRESULT hr = m_pConnection->Execute(_bstr_t(strSql), NULL, adCmdText);
	}
	catch (_com_error & e)
	{
		strErrorInfo = (LPCSTR)e.Description();
		return false;
	} 
	return true;
}
//************************************
// Method:    SelectTableInfo  ���ؼ�¼��
// ����ֵ:   bool 
// Parameter: vector<USEINFO> & vecUseInfo	���ر���Ϣ
// Parameter: CString strSql				ִ��SQL�����
// Parameter: CString & strErrorInfo		����ִ�д�����Ϣ
//************************************
bool CADOClass::SelectTableInfo(vector<USEINFO>&vecUseInfo, CString strSql, CString &strErrorInfo){
	if (nullptr == m_pConnection)
	{
		return false;
	}
	if (nullptr == m_pRecordSet)
	{
		//1.����RECORDSET����
		HRESULT hr = m_pRecordSet.CreateInstance(L"ADODB.Recordset");
		if (!hr)
		{
			return false;
		}
	}
	try
	{
		vecUseInfo.clear();//���vector����
		//2.�򿪼�¼��
		HRESULT hr = m_pRecordSet->Open(
			_bstr_t(strSql),	//SQLִ�����
			m_pConnection.GetInterfacePtr(),//Connection����������
			adOpenStatic,		//ָʾ Recordset ���������õ��α�����
			adLockOptimistic,	//ָ���ڱ༭�����м�¼�ϵ���������
			adCmdText);			//ָ��������������ķ���
		if (FAILED(hr))
		{
			m_pRecordSet.Release();//����_RecordsetPtr����
			return false;
		}
		//3.��ȡ��ǰ�α�λ��,�Ƿ������λ��
		VARIANT_BOOL bRet = m_pRecordSet->GetadoEOF();
		while (!bRet)
		{
			USEINFO UseInfo = {};
			UseInfo.strAge = m_pRecordSet->GetCollect("����");
			UseInfo.strUseSex = m_pRecordSet->GetCollect("�Ա�");
			UseInfo.strBirth = m_pRecordSet->GetCollect("��������");
			UseInfo.strE_mail = m_pRecordSet->GetCollect("EMIAL");
			UseInfo.strUseName = m_pRecordSet->GetCollect("�û���");
			UseInfo.strPassWord = m_pRecordSet->GetCollect("����");
			UseInfo.strNationality = m_pRecordSet->GetCollect("����");
			vecUseInfo.push_back(UseInfo);
			//3.1 ָ����һ����¼
			m_pRecordSet->MoveNext();
			//3.2 ��ȡ�α�λ��
			bRet = m_pRecordSet->GetadoEOF();
		}
	}
	catch (_com_error & e)
	{
		strErrorInfo = (LPCSTR)e.Description();
		return FALSE;
	} 
	return true;
}