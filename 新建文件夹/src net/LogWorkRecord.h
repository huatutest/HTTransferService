// LogWorkRecord.h: interface for the CLogWorkRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGWORKRECORD_H__E062F157_D5BC_4326_9C0A_DB79F6FF476D__INCLUDED_)
#define AFX_LOGWORKRECORD_H__E062F157_D5BC_4326_9C0A_DB79F6FF476D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "LogBase.h"

class CLogWorkRecord : public CLogBase  
{
public:
	CLogWorkRecord();
	virtual ~CLogWorkRecord();
public:
	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);
	
	LPTSTR GetInsertSQL(LPTSTR strSQL);

	void InitTestData();

public:
	int		m_nPerTime;		//ʱ����
	int		m_nTotalTime;		//���չ�����ʱ��
	FLOAT	m_fEff;			//����Ч��
};

#endif // !defined(AFX_LOGWORKRECORD_H__E062F157_D5BC_4326_9C0A_DB79F6FF476D__INCLUDED_)
