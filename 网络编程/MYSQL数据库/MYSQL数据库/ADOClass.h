#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"\
no_namespace rename("EOF", "adoEOF")
//#include "stdafx.h"
#include <vector>
using std::vector;
#include <afxstr.h>
//该结构体对应着数据库中表的表列
typedef struct _USEINFO{
	CString strUseName;		//用户名
	CString strPassWord;	 //密码
	CString strUseSex;		//性别
	CString strAge;			//年龄
	CString strBirth;		//出生日期
	CString strNationality;	//民族
	CString strE_mail;		//E-Mail 
}USEINFO,*PUSEINFO;
//登录数据库需要用到的信息
typedef struct _LOGININFO
{
	CString strDataBaseIP;		//数据库IP地址
	CString strDataBaseName;	//数据库名称
	CString strUserName;		//登录名
	CString strPassWord;		//登录密码
}LOGININFO, *PLOGININFO;
class CADOClass{
public:
	CADOClass() ;
	~CADOClass();
public:
	//连接数据库
	bool LoginDataBase(LOGININFO LoginInfo,CString &strErrorInfo);
	//执行sql语句(不返回记录集)
	bool ConnExeSql(CString strSql, CString &strErrorInfo);
	//执行SQL语句并返回记录集
	bool SelectTableInfo(vector<USEINFO>&vecUseInfo, CString strSql, CString &strErrorInfo);//多加了个引用 

private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordSet;
};