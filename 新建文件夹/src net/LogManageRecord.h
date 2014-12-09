// LogManageRecord.h: interface for the CLogManageRecord class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGMANAGERECORD_H__4CD5A68B_7D2A_40AB_911C_29F6D81EC93A__INCLUDED_)
#define AFX_LOGMANAGERECORD_H__4CD5A68B_7D2A_40AB_911C_29F6D81EC93A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LogBase.h"

enum
{
	MANAGE_ADDUSER = 1,			//�����û�
	MANAGE_DELETEUSER,			//ɾ���û�
	MANAGE_MODIFYRIGHT,			//�޸�Ȩ��
};

class CLogManageRecord : public CLogBase  
{
public:
	CLogManageRecord();
	virtual ~CLogManageRecord();

public:
	void RecordToMemory(CVirtualMemFile& mem);
	void MemoryToRecord(CVirtualMemFile& mem);

	//����¼д�����ݿ�
	void InitTestData();
	LPTSTR GetInsertSQL(LPTSTR strSQL);

public:
	int		m_nRecordType;		//�����û���ɾ���û����޸�Ȩ��
	LPTSTR	m_strDescript;		//�޸ĵ�����
	LPTSTR  m_strUserObject;	//���޸ĵ��û���
};

#endif // !defined(AFX_LOGMANAGERECORD_H__4CD5A68B_7D2A_40AB_911C_29F6D81EC93A__INCLUDED_)
