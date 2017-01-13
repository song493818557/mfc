#import "C:\\Program Files\\Common Files\\System\\ado\\msado15.dll"\
no_namespace rename("EOF", "adoEOF")
//#include "stdafx.h"
#include <vector>
using std::vector;
#include <afxstr.h>
//�ýṹ���Ӧ�����ݿ��б�ı���
typedef struct _USEINFO{
	CString strUseName;		//�û���
	CString strPassWord;	 //����
	CString strUseSex;		//�Ա�
	CString strAge;			//����
	CString strBirth;		//��������
	CString strNationality;	//����
	CString strE_mail;		//E-Mail 
}USEINFO,*PUSEINFO;
//��¼���ݿ���Ҫ�õ�����Ϣ
typedef struct _LOGININFO
{
	CString strDataBaseIP;		//���ݿ�IP��ַ
	CString strDataBaseName;	//���ݿ�����
	CString strUserName;		//��¼��
	CString strPassWord;		//��¼����
}LOGININFO, *PLOGININFO;
class CADOClass{
public:
	CADOClass() ;
	~CADOClass();
public:
	//�������ݿ�
	bool LoginDataBase(LOGININFO LoginInfo,CString &strErrorInfo);
	//ִ��sql���(�����ؼ�¼��)
	bool ConnExeSql(CString strSql, CString &strErrorInfo);
	//ִ��SQL��䲢���ؼ�¼��
	bool SelectTableInfo(vector<USEINFO>&vecUseInfo, CString strSql, CString &strErrorInfo);//����˸����� 

private:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordSet;
};