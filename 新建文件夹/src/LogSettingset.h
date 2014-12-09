// LogSettingset.h: interface for the CLogSettingset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_LOGSETTINGSET_H__F50AA83C_EC2F_4F9B_B18A_0D168DCEAC55__INCLUDED_)
#define AFX_LOGSETTINGSET_H__F50AA83C_EC2F_4F9B_B18A_0D168DCEAC55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LogSetting.h"
#include "VirtualMemFile.h"
#include "DatabaseConnect.h"

class CLogSettingset  
{
public:
	CLogSettingset();
	virtual ~CLogSettingset();

	DEQUE_SETTING	m_dequeLog;
	
	int			m_nTotalCount;			//�ܼ�¼��

	//�ͷ��ڴ�
	void ClearMemory();
	
	//�����ݰ�������¼
	BOOL GetDataFromBuffer(LPBYTE btData,DWORD dwSize);
	
	//����¼д�����ݰ�
	BOOL SetDataToBuffer(LPBYTE* btData,DWORD& dwSize);
	
#ifdef DATABASE_SUPPORT
	//������д�����ݿ�
	void WriteToDatabase();
	
	//�����ݶ�ȡ����
	void ReadFromDatabase(LPCTSTR strTotalSQL,LPCTSTR strSQL);
#endif
	
};

#endif // !defined(AFX_LOGSETTINGSET_H__F50AA83C_EC2F_4F9B_B18A_0D168DCEAC55__INCLUDED_)
