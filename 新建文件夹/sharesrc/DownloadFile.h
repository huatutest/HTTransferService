// DownloadFile.h: interface for the CDownloadFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DOWNLOADFILE_H__A5451D5F_6382_4AB4_8E79_116589CEE626__INCLUDED_)
#define AFX_DOWNLOADFILE_H__A5451D5F_6382_4AB4_8E79_116589CEE626__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UpdateBaseClass.h"

class CDownloadFile : public CUpdateBaseClass  
{
public:
	CDownloadFile();
	virtual ~CDownloadFile();

	void MakeDestFilePath();

	LPTSTR m_lpszSourceFile;		//Դ�ļ�·��
	LPTSTR m_lpszFileMD5;			//�ļ�MD5
	LPTSTR m_lpszDestSubPath;		//Ŀ��·��
	LPTSTR m_lpszDomain;			//����
	LPTSTR m_lpszLogin;				//��¼��
	LPTSTR m_lpszPass;				//����
	LPTSTR m_lpszCommand;			//�����в���
	int    m_nPathType;				//·������
	BOOL   m_bNeedRegister;			//�Ƿ���Ҫע��
	BOOL   m_bNeedRegServer;		//�Ƿ���Ҫע��
	BOOL   m_bNeedRun;				//�Ƿ���Ҫ����
};

#endif // !defined(AFX_DOWNLOADFILE_H__A5451D5F_6382_4AB4_8E79_116589CEE626__INCLUDED_)
