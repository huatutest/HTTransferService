// LogBase.h: interface for the CLogBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGBASE_H__29D500AF_9D6F_4ECC_BAAF_B47145481504__INCLUDED_)
#define AFX_LOGBASE_H__29D500AF_9D6F_4ECC_BAAF_B47145481504__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <deque>

#include "VirtualMemFile.h"

enum
{
	LOG_FILE = 1,			//�ļ���־
	LOG_PRINT,				//��ӡ��־
	LOG_MAIL,				//�ʼ���־
	LOG_OUTSIDE,			//�ⷢ��־
	LOG_USB,				//USB������
	LOG_MANAGE,				//������־
	LOG_LOG,				//��־����
	LOG_LAND,				//����ǳ���־
	LOG_FILEACCREDIT,		//�ļ���Ȩ��־
	LOG_WORK,				//������¼
	FILE_ACCREDIT,			//�ļ���Ȩ��Ϣ
	//��������
	FILE_UPLOAD,			//�ļ��ϴ�
	
};

extern LPTSTR STRDUP(LPCTSTR strData);

class CLogBase  
{
public:
	CLogBase();
	virtual ~CLogBase();

	virtual void RecordToMemory(CVirtualMemFile& mem) = 0;
	virtual void MemoryToRecord(CVirtualMemFile& mem) = 0;

	//�����ݰ�������¼
	BOOL GetDataFromBuffer(LPBYTE btData,DWORD dwSize);

	//����¼д�����ݰ�
	BOOL SetDataToBuffer(LPBYTE* btData,DWORD& dwSize);

	//�õ��������Ϣ
	void GetLocalInfo();

	//����¼д�����ݿ�
	virtual LPTSTR GetInsertSQL(LPTSTR strSQL) = 0;

	virtual void InitTestData() = 0;

public:
	int		m_nLogType;	
	LPTSTR	m_strIndex;		//��־���
	LPTSTR	m_strComputer;	//�����
	LPTSTR	m_strUser;		//��Ա
	LPTSTR	m_strIP;		//IP
	LPTSTR  m_strTime;		//ʱ��
	LPTSTR  m_strGUID;			//��������
	int		m_nDeleted;
	BOOL	m_bUnicodeToAnsi;	//��unicode��ת��ΪAnsi��
};

typedef std::deque<CLogBase*> DEQUE_LOG;
extern void GetHostAddressEx(const char* strComputerName,char* lpszIP);
#endif // !defined(AFX_LOGBASE_H__29D500AF_9D6F_4ECC_BAAF_B47145481504__INCLUDED_)
