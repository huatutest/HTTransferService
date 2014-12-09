// ClientNodeInfo.h: interface for the CClientNodeInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTNODEINFO_H__54E82AD1_8CFA_453F_A3C9_2A91397378B9__INCLUDED_)
#define AFX_CLIENTNODEINFO_H__54E82AD1_8CFA_453F_A3C9_2A91397378B9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#define OVERTIME 100*60   //��ʱʱ��,10����

#include <deque>
using namespace std;

typedef deque<int> INT_DEQUE;

class CClientNodeInfo  
{
public:
	CClientNodeInfo();
	virtual ~CClientNodeInfo();

	LPTSTR m_strMac;				//������ַ
	LPTSTR m_strComputer;		//�������
	LPTSTR m_strIP;

	BOOL m_bClient;				//�Ƿ�Ϊ�ͻ��˵�¼

	LPTSTR m_strUser;			//�û���
	LPTSTR m_strPass;			//����
	
	LPTSTR  m_pszVersion;


	BOOL m_bOverTime;			
	
	DWORD m_dwPriv;				//�ͻ���Ȩ��
	DWORD m_dwOverTime;
	DWORD m_dwCryptLevel;
	int	  m_nPolicyType;
	INT_DEQUE m_arrPolicy;		

	DWORD GetClientPriv(HINSTANCE hBase,LPCTSTR strCurUser,BOOL bSystemDir = TRUE); //��鵱ǰ�����û���Ȩ��
	DWORD GetClientPriv2(HINSTANCE hBase,LPCTSTR strCurUser,BOOL bSystemDir = TRUE);
	
	SYSTEMTIME m_PrevTime;			//�ϴ�����ʱ��ʱ��
	DWORD	   m_dwPrevTickCount;	//ϵͳ������ļ��

	BOOL IsOverTime(DWORD dwCurTick); //�ж��Ƿ�ʱ
};

typedef deque<CClientNodeInfo*> CLIENT_DEQUE;

#endif // !defined(AFX_CLIENTNODEINFO_H__54E82AD1_8CFA_453F_A3C9_2A91397378B9__INCLUDED_)
