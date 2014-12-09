// LogMailRecord.h: interface for the CLogMailRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGMAILRECORD_H__33BCADBD_9D30_494C_8C46_ED0AAC20E282__INCLUDED_)
#define AFX_LOGMAILRECORD_H__33BCADBD_9D30_494C_8C46_ED0AAC20E282__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LogBase.h"

class CLogMailRecord : public CLogBase
{
public:
	CLogMailRecord();
	virtual ~CLogMailRecord();

public:
	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);
	
	LPTSTR GetInsertSQL(LPTSTR strSQL);

	void InitTestData();
	
public:
	LPTSTR m_strSender;		//������
	LPTSTR m_strAddressee;	//������
	LPTSTR m_strCarboncopy;	//������
	LPTSTR m_strAttchments;	//�����б�
};

#endif // !defined(AFX_LOGMAILRECORD_H__33BCADBD_9D30_494C_8C46_ED0AAC20E282__INCLUDED_)
