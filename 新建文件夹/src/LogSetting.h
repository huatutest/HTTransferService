// LogSetting.h: interface for the CLogSetting class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGSETTING_H__0484A866_CC28_44BA_99B6_76F9950A2C33__INCLUDED_)
#define AFX_LOGSETTING_H__0484A866_CC28_44BA_99B6_76F9950A2C33__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "VirtualMemFile.h"
#include <deque>
class CLogSetting  
{
public:
	CLogSetting();
	virtual ~CLogSetting();

	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);

	LPTSTR GetInsertSQL(LPTSTR strSQL);

	int  m_nLogType;
	int	 m_nMaxLogCount;		//����¼
	int  m_nOverOperType;		//��������¼�Ĳ�������
	int	 m_nPerPageCount;		//ÿҳ�ļ�¼��
};

typedef std::deque<CLogSetting*>  DEQUE_SETTING;

#endif // !defined(AFX_LOGSETTING_H__0484A866_CC28_44BA_99B6_76F9950A2C33__INCLUDED_)
