// SoftwareTypeInfo.h: interface for the CSoftwareTypeInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SOFTWARETYPEINFO_H__C59E3EBA_EE18_4D7C_BCF1_2FD194D279E2__INCLUDED_)
#define AFX_SOFTWARETYPEINFO_H__C59E3EBA_EE18_4D7C_BCF1_2FD194D279E2__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "SoftwareVersionInfo.h"


class CSoftwareTypeInfo : public CTreeNode  
{
public:
	LPTSTR		m_lpszSoftTypeName; //�������: ��Office,AutoCAD��
	BOOL		m_bSaveThisType;

public:
	BOOL DeleteItem(CSoftwareVersionInfo *pVersionInfo);
	CSoftwareTypeInfo();
	virtual ~CSoftwareTypeInfo();

	CSoftwareVersionInfo* FindSoftVersionByName(LPCTSTR lpszSoftVersion);

	SOFTVER_DEQUE m_arrSoftVersion;	 //����ĸ����汾

//	virtual void Serialize(CArchive& ar);
	CSoftwareVersionInfo* CheckModule(LPCTSTR lpszModuleName);
};

typedef deque<CSoftwareTypeInfo*> SOFTTYPE_DEQUE;

#endif // !defined(AFX_SOFTWARETYPEINFO_H__C59E3EBA_EE18_4D7C_BCF1_2FD194D279E2__INCLUDED_)
