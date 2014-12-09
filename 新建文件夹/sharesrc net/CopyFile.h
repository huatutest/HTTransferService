// CopyFile.h: interface for the CCopyFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COPYFILE_H__A707363D_9696_4978_A45A_06568778DB55__INCLUDED_)
#define AFX_COPYFILE_H__A707363D_9696_4978_A45A_06568778DB55__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UpdateBaseClass.h"

class CCopyFile: public CUpdateBaseClass  
{
public:
	CCopyFile();
	virtual ~CCopyFile();

	int m_nCopyType;				//0:�����ļ� 2:�ƶ��ļ�
	int m_nExistFileType;			//0:��ͨ�ļ� 1:system32�ļ� 2:windows�ļ� 3:��ǰĿ¼�µ��ļ�
	CAString m_strExistFilePath;
	CAString m_strExistFileName;
		
	int m_nTargetFileType;			//0:��ͨ�ļ� 1:system32�ļ� 2:windows�ļ� 3:��ǰĿ¼�µ��ļ�
	CAString m_strTargetFilePath;
	CAString m_strTargetFileName;
};

#endif // !defined(AFX_COPYFILE_H__A707363D_9696_4978_A45A_06568778DB55__INCLUDED_)
