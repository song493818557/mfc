#include "stdafx.h"
#include "MySocket.h"

vector<CMySocket*> CMySocket::pvecClientSock = {};
CDataBaseCtrl* CMySocket::pDataBase = new CDataBaseCtrl;
CMySocket::CMySocket()
{
}


CMySocket::CMySocket(SOCKET sock, sockaddr_in addr)
{
	m_sock = sock;
	m_addr = addr;
	ZeroMemory(m_name, NAMELENGTH);
}

CMySocket::~CMySocket()
{
}


bool CMySocket::RecvSocket()
{	
	CreateThread(
		NULL, NULL, RecvThread, (LPVOID)this, NULL, NULL);
	return true;
}

DWORD WINAPI CMySocket::RecvThread(_In_ LPVOID lpParameter)
{
	CMySocket *pThis = (CMySocket*)lpParameter;
	INT retValue;
	MESSAGE message = {};
	while (true)
	{
		ZeroMemory(&message, sizeof(MESSAGE));
		retValue = recv(pThis->m_sock, (CHAR*)&message, sizeof(message), 0);
		
		if (retValue == SOCKET_ERROR || retValue == 0)
		{
			// ���˵���û��¼�͵��ߵĿͻ���
			if (pThis->m_name)
			{
				// ɾ�����sock
				pThis->DeleteSock();
				// ֪ͨ�����ͻ�������������
				pThis->Leave();
			}
			// �ر��׽���
			closesocket(pThis->m_sock);
			// ɾ���ö�����Ϊ��new������-->new��λ��Service���Accept����
			delete pThis;
			return 0;

		}
		else
		{
			pThis->MyDispatchMessage(message);
		}
		
	}
	return 0;
}



void CMySocket::DeleteSock()
{
	for (DWORD i = 0; i < pvecClientSock.size();i++)
	{
		if (pvecClientSock[i] == this)
		{
			pvecClientSock.erase(pvecClientSock.begin() + i);
			break;
		}
		
	}
}


void CMySocket::Leave()
{
	MESSAGE message;
	message.type = common;
	sprintf_s(message.info.buf, MESSAGEBUF,"%s������",m_name);
	message.len = strlen(message.info.buf);
	// ����֪ͨ���пͻ��ˣ��Լ��Ѿ����б���ɾ����
	SendSockMessage(message);
	// �ڷ����������һ��
	printf("%s", message.info.buf);
}

void CMySocket::SendSockMessage(MESSAGE &message, SOCKET sock)
{
	// ȫ����
	if (sock == INVALID_SOCKET)
	{
		for (CMySocket* &mysock : pvecClientSock)
		{
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	// ��sock֮��ķ�
	else
	{
		for (CMySocket* &mysock : pvecClientSock)
		{
			if (mysock->m_sock == sock)
			{
				continue;
			}
			send(mysock->m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
		}
	}
	
}

// �ַ���Ϣ
INT CMySocket::MyDispatchMessage(MESSAGE &message)
{
	// �ж���Ϣ����,�ֱ���
	MESSAGETYPE type = message.type;
	INT nRet = 0;
	switch (type)
	{
	case common:
		SendSockMessage(message,this->m_sock);
		printf("%s\n", message.info.buf);
		break;
	case reg:
		nRet = OnMessageReg(message);
		break;
	case Anonymous:// ��������
		OnMessageAnonymous();
		break;
	case login:
		OnMessageLogin(message);
		break;

	}
	return nRet;
}

void CMySocket::OnMessageAnonymous(CHAR* name)
{
	MESSAGE message;
	// �����������ǳ�
	if (name == nullptr)
	{
		// �������ߵķ�����ǳ�
		sprintf_s(m_name, NAMELENGTH, "�ǳ�%d", m_addr.sin_port);
		// ���߸ÿͻ����Լ����ǳ�
		message.type = common;
		strcpy_s(message.info.buf, MESSAGEBUF, m_name);
		message.len = strlen(m_name);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		sprintf_s(m_name, NAMELENGTH, "%s", name);
	}
	// ֪ͨ������������������
	message.type = common;// ��ͨ��Ϣ
	sprintf_s(message.info.buf, sizeof(message.info.buf), "%s����������", m_name);
	message.len = strlen(message.info.buf);
	SendSockMessage(message);
	// ����ͻ����б�
	pvecClientSock.push_back(this);
}

// -1��ʾʧ��
INT CMySocket::OnMessageReg(MESSAGE &message)
{
	// Ҫע�����������
	RESULT dataResult;
	CHAR name[NAMELENGTH] = {};
	CHAR password[MESSAGEBUF - NAMELENGTH] = {};
	DWORD dwNameLen = message.info.reginfo.nameLen;
	DWORD dwPassLen = message.len - 4 - dwNameLen;
	strncpy_s(name, message.info.reginfo.name, dwNameLen);
	strncpy_s(password, message.info.reginfo.name+ dwNameLen, dwPassLen);
	char sql[1024] = {};
	sprintf_s(sql, 1024, "SELECT * FROM user_data WHERE user_name = '%s'", name);
	INT nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	// nRet - 1˵�����ִ��ʧ�ܣ�0˵��û�в�ѯ�����ݣ����������ݷ���
	if (nRet == 0)
	{// �ǳƲ����ڣ�������������
		sprintf_s(sql, 1024,
			"INSERT INTO user_data(user_name,user_password) VALUES('%s','%s')",
			name, password);
		nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	}
	if (nRet == -1)
	{
		// sql���ִ��ʧ��
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "���ݿ������쳣��");
		message.type = reg;
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		// �ɹ��������ݿ⣬֪ͨ�ͻ��˺������ͻ���
		OnMessageAnonymous(name);
		// ���ͻ��˻�Ӧ���ɹ�ע�����Ϣ
		message.type = reg;
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	return nRet;
}

INT CMySocket::OnMessageLogin(MESSAGE &message)
{
	// Ҫ��¼����������
	RESULT dataResult;
	CHAR name[NAMELENGTH] = {};
	CHAR password[MESSAGEBUF - NAMELENGTH] = {};
	DWORD dwNameLen = message.info.reginfo.nameLen;
	DWORD dwPassLen = message.len - 4 - dwNameLen;
	strncpy_s(name, message.info.reginfo.name, dwNameLen);
	strncpy_s(password, message.info.reginfo.name + dwNameLen, dwPassLen);
	char sql[1024] = {};
	sprintf_s(sql, 1024, "SELECT * FROM user_data WHERE user_name = '%s' AND user_password = '%s' ", name,password);
	INT nRet = pDataBase->ExeSqlByRecordSet(dataResult, string(sql));
	if (nRet >0 )
	{
		// �ɹ���¼
		OnMessageAnonymous(name);
		// ���ͻ��˻�Ӧ���ɹ�����Ϣ
		message.type = login;
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "succeed!");
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	else
	{
		// ʧ��
		sprintf_s(message.info.buf, MESSAGEBUF, "%s", "�˻�/�������");
		message.type = login;
		message.len = strlen(message.info.buf);
		send(m_sock, (CHAR*)&message, sizeof(MESSAGE), 0);
	}
	return 0;
}

