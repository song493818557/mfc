#include "stdafx.h"
#include "ADOClass.h"
CADOClass::CADOClass(){


}
CADOClass::~CADOClass(){
	if (m_pConnection)
	{
		try
		{
			//关闭数据库
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
// 功能:    连接数据库 
// 返回值:   BOOL 
// Parameter: LOGININFO LoginInfo  数据库登录信息
// Parameter: CString & strErrorInfo  返回执行错误信息
//************************************
bool CADOClass::LoginDataBase(LOGININFO LoginInfo, CString &strErrorInfo){
	try
	{
		//1.链接数据库,并检查Connection 对象是否为空,是则重新链接数据库
		if (m_pConnection &&(m_pConnection->State == adStateOpen))
		{
			m_pConnection->Close();
		}
		//2.创建Connection对象
		HRESULT hr = m_pConnection.CreateInstance(__uuidof(Connection));
		//或者_T("ADODB.Connection")
		//3.设置连接字符串 必须是BSTR型或者_bstr_t类型
		CString strFormatBuff;
		strFormatBuff.Format(L"Provider=SQLOLEDB;Server=%s;\	  							  Database=%s;Uid=%s;Pwd=%s", LoginInfo.strDataBaseIP, LoginInfo.strDataBaseName, LoginInfo.strUserName, LoginInfo.strPassWord);
		//数据库IP 名称 登录名  登录密码
		//4.打开并链接数据库
		m_pConnection->Open(_bstr_t(strFormatBuff),//包含连接信息
			_bstr_t(L""),	//链接时要使用的用户名称
			_bstr_t(L""),	//链接时要使用的用户密码
			adConnectUnspecified);//确定应在建立连接之后(同步)还是应在建立链接之前(异步)返回本方法
	}
	catch (_com_error& e)
	{
		strErrorInfo = (LPCSTR)e.Description();//得到错误集
		return false;
	}
	return true;
}
//************************************
// Method:    ConnExeSql 
// 返回值:   bool 
// Parameter: CString strSql			//执行SQL语句
// Parameter: CString & strErrorInfo	//返回执行错误信息
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
// Method:    SelectTableInfo  返回记录集
// 返回值:   bool 
// Parameter: vector<USEINFO> & vecUseInfo	返回表信息
// Parameter: CString strSql				执行SQL的语句
// Parameter: CString & strErrorInfo		返回执行错误信息
//************************************
bool CADOClass::SelectTableInfo(vector<USEINFO>&vecUseInfo, CString strSql, CString &strErrorInfo){
	if (nullptr == m_pConnection)
	{
		return false;
	}
	if (nullptr == m_pRecordSet)
	{
		//1.创建RECORDSET对象
		HRESULT hr = m_pRecordSet.CreateInstance(L"ADODB.Recordset");
		if (!hr)
		{
			return false;
		}
	}
	try
	{
		vecUseInfo.clear();//清空vector向量
		//2.打开记录集
		HRESULT hr = m_pRecordSet->Open(
			_bstr_t(strSql),	//SQL执行语句
			m_pConnection.GetInterfacePtr(),//Connection变量对象名
			adOpenStatic,		//指示 Recordset 对象中所用的游标类型
			adLockOptimistic,	//指定在编辑过程中记录上的锁定类型
			adCmdText);			//指定解释命令参数的方法
		if (FAILED(hr))
		{
			m_pRecordSet.Release();//销毁_RecordsetPtr对象
			return false;
		}
		//3.获取当前游标位置,是否在最后位置
		VARIANT_BOOL bRet = m_pRecordSet->GetadoEOF();
		while (!bRet)
		{
			USEINFO UseInfo = {};
			UseInfo.strAge = m_pRecordSet->GetCollect("年龄");
			UseInfo.strUseSex = m_pRecordSet->GetCollect("性别");
			UseInfo.strBirth = m_pRecordSet->GetCollect("出生日期");
			UseInfo.strE_mail = m_pRecordSet->GetCollect("EMIAL");
			UseInfo.strUseName = m_pRecordSet->GetCollect("用户名");
			UseInfo.strPassWord = m_pRecordSet->GetCollect("密码");
			UseInfo.strNationality = m_pRecordSet->GetCollect("民族");
			vecUseInfo.push_back(UseInfo);
			//3.1 指向下一条记录
			m_pRecordSet->MoveNext();
			//3.2 获取游标位置
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