// LogOutSideRecord.h: interface for the CLogOutSideRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGOUTSIDERECORD_H__3A4532D5_DD64_4169_9D05_415DF24A4050__INCLUDED_)
#define AFX_LOGOUTSIDERECORD_H__3A4532D5_DD64_4169_9D05_415DF24A4050__INCLUDED_
#include "LogBase.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CLogOutSideRecord : public CLogBase 
{
public:
	CLogOutSideRecord();
	virtual ~CLogOutSideRecord();

public:
	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);
	
	LPTSTR GetInsertSQL(LPTSTR strSQL);
	
	void InitTestData();
	
public:
	LPTSTR m_strFileName;	//�ļ���
	int m_nOpenCount;		//�ɴ򿪴���
	int m_nOpenDay;			//�ɴ�����
	BOOL m_bCanPrint;		//�ɴ�ӡ

};

#endif // !defined(AFX_LOGOUTSIDERECORD_H__3A4532D5_DD64_4169_9D05_415DF24A4050__INCLUDED_)
