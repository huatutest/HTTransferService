// ClientSettingInfo.h: interface for the CClientSettingInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTSETTINGINFO_H__F6BF4E07_34CB_4D06_9A5B_08D19587C5FF__INCLUDED_)
#define AFX_CLIENTSETTINGINFO_H__F6BF4E07_34CB_4D06_9A5B_08D19587C5FF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>

typedef std::deque<LPTSTR> DOMAINLIST;

class CClientSettingInfo
{
public:
	CClientSettingInfo();
	virtual ~CClientSettingInfo();

	//����Ϣ
	int m_dwDomainCount;		//��ʷ�ϵ�¼����������

	TCHAR      m_strLastDomain[DG_MAX_TEMP];	//���һ�ε�¼������
	DOMAINLIST m_listDomain;	//��ʷ�ϵ�¼���������б�
	

	void AddOneDomainList(LPCTSTR strDomainName);

	BOOL ReadFromIniFile();
	BOOL WriteToIniFile();
};

#endif // !defined(AFX_CLIENTSETTINGINFO_H__F6BF4E07_34CB_4D06_9A5B_08D19587C5FF__INCLUDED_)
