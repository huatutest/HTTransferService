// LogRecordset.h: interface for the CLogRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGRECORDSET_H__E7746296_027A_4713_9B92_69CF6A60E89E__INCLUDED_)
#define AFX_LOGRECORDSET_H__E7746296_027A_4713_9B92_69CF6A60E89E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LogFileRecord.h"
#include "LogManageRecord.h"
#include "LogLogRecord.h"
#include "LogPrintRecord.h"
#include "LogMailRecord.h"
#include "LogFileaccreditRecord.h"
#include "LogOutSideRecord.h"
#include "FileAccreditRecord.h"
#include "LogWorkRecord.h"
#include "DatabaseConnect.h"

enum
{
	LOG_DELETE = 0,
	LOG_BACKUP,
};

class CLogRecordset  
{
public:
	CLogRecordset();
	virtual ~CLogRecordset();

	int			m_nRecordType;			//��¼������
	DEQUE_LOG	m_dequeLog;

	DWORD		m_dwNextPos;
	//�ͷ��ڴ�
	void ClearMemory();

	//�����ݰ�������¼
	BOOL GetDataFromBuffer(LPBYTE btData,DWORD dwSize,BOOL bUnicodeToAnsi = FALSE);

	//����¼д�����ݰ�
	BOOL SetDataToBuffer(LPBYTE* btData,DWORD& dwSize,BOOL bUnicodeToAnsi = FALSE);

#ifdef DATABASE_SUPPORT
	//������д�����ݿ�
	void WriteToDatabase(int nLogType);

	//�����ݶ�ȡ����
	virtual void ReadFromDatabase(LPCTSTR strTotalSQL, LPCTSTR strSQL) = 0;
#endif

	virtual void BuildTestData() = 0;

//  �������ݽ�����־��������ʹ��

	int			m_nPages;				//��ҳ��
	int			m_nRecordPerPage;		//ÿҳ��¼��
	int			m_nCurrentPage;			//��ǰҳ
	int			m_nTotalCount;			//�ܼ�¼��

/*#ifdef DATABASE_SUPPORT
public:
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
#endif*/
};

#endif // !defined(AFX_LOGRECORDSET_H__E7746296_027A_4713_9B92_69CF6A60E89E__INCLUDED_)
