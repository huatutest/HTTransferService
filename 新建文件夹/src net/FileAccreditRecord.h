// FileAccreditRecord.h: interface for the CFileAccreditRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_FILEACCREDITRECORD_H__7908F3E4_9DA9_4C63_9841_76FD45247FA0__INCLUDED_)
#define AFX_FILEACCREDITRECORD_H__7908F3E4_9DA9_4C63_9841_76FD45247FA0__INCLUDED_
#include "LogBase.h"

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum
{
		PURVIEW_OPEN			= 0x1,		//�ɴ�
		PURVIEW_PRINT			= 0x2,		//�ɴ�ӡ
		PURVIEW_LEVEL			= 0x4,		//����ԭ���ĵȼ�Ȩ��
		PURVIEW_READONLY		= 0x8,		//�����
};

class CFileAccreditRecord : public CLogBase 
{
public:
	CFileAccreditRecord();
	virtual ~CFileAccreditRecord();
public:
	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);
	
	LPTSTR GetInsertSQL(LPTSTR strSQL);
	
	void InitTestData();
	
public:
	LPTSTR m_strFileName;	//�ļ���
	LPTSTR m_strCanopenuser;	//��Ȩ�û�
	LPTSTR m_strFileGuid;		//�ļ�GUID
	int m_nPurviewOper;	//��Ȩ�Ĳ���
	LPTSTR m_strOutTime;		//��Ȩ����ʱ��
};

#endif // !defined(AFX_FILEACCREDITRECORD_H__7908F3E4_9DA9_4C63_9841_76FD45247FA0__INCLUDED_)
