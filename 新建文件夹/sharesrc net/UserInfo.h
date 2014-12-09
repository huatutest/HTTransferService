// UserInfo.h: interface for the CUserInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERINFO_H__4A4BDAB7_2517_4564_9467_963AA91BA2F4__INCLUDED_)
#define AFX_USERINFO_H__4A4BDAB7_2517_4564_9467_963AA91BA2F4__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include <map>
using namespace std;

#define USER_SA			1
#define USER_MANAGER	2
#define USER_NORMAL		3
#define USER_LOGMGER	4

enum
{
	DG_USER_FILE2 = 0,			//2.0 CUserInfo�汾
	DG_USER_FILE3 = 1,			//3.0 CUserInfo�汾
};

enum
{
	USR_FILE_VER2 = 1,			//2.0�汾��Usr�ļ��İ汾
	USR_FILE_VER3 = 2,			//3.0�汾��Usr�ļ��İ汾
};

//�ܼ���Ӧ�Ľ�ɫ�Ͳ��Զ�Ӧ��;

//�ļ�������ҪID,�ڷ��������ܹ�У�������û�

typedef deque<int> INT_DEQUE;

class CUserLevel		 //
{
public:
	CUserLevel();
	virtual ~CUserLevel();
	
	LPTSTR m_lpszLevelName;	//�ȼ�������
	DWORD m_dwCryptLevel;	//�ȼ�ֵ,����Ψһ��ֵ,ÿ��CUserLevel
	
	int m_nPolicyType;		//��������

	INT_DEQUE m_arrOpenPolicy;  //���Դ򿪵ĵȼ�
	INT_DEQUE m_arrDownPolicy;	//���Խ��ļ��ȼ����͵ķ�Χ
	INT_DEQUE m_arrPrintPolicy;	//������Щ�ȼ��ܹ���ӡ�õȼ����ļ�
	INT_DEQUE m_arrCryptPolicy; //������Щ�ȼ��ܹ����ܸõȼ����ļ�

	void Serialize(CArchive& ar);
};

typedef deque<CUserLevel*> LEVEL_DEQUE;

class CUserInfo  
{
public:
	CUserInfo();
	virtual ~CUserInfo();

public:
	int	m_nClsVersion;

public:
	LPTSTR  m_pszUserName;	//�û���
	LPTSTR  m_pszUserInfo;	//��¼��
	LPTSTR  m_pszUserDescribe;
	LPTSTR  m_pszPassword;
	int	  m_nUserType;
	int	  m_nOverTime;
	
	// 0x01--print 0x02--backup 0x04--copy 0x08--eptry File  0x10 snap srceen 0x20 ole
	long  m_nPopedom;	

	CUserLevel* m_pLevel;

	DWORD m_dwCryptLevel;	//0xffffffff  ��λ��ʾID��Level,��λ��ʾID�����,ÿ���û���Ψһ��ID;  ���65535��Level,65535���û�

	void ClearPolicyArray();

public:
	virtual void Serialize(CArchive& ar);
};

typedef deque<CUserInfo*> USERINFO_DEQUE;

class CDowithUserInfo
{
public:
	CDowithUserInfo();
	virtual ~CDowithUserInfo();

public:
	USERINFO_DEQUE		m_ptrUserInfo;
	
	//��¼����user��ӳ��
	map<CString,CUserInfo*>  m_mapUserInfo;

	LEVEL_DEQUE			m_ptrLevelInfo;

	int					m_nClsVersion;

	CUserInfo*			m_pCurUserInfo;
public:
	CUserLevel* FindLevelByNameAndValue(LPCTSTR strName,DWORD dwCryptLevel);
	LPTSTR GetUserLevel(LPTSTR strUser);

	void DeleteLevelFromList(CUserLevel* pUserLevel);

	void InitFirstusr();
	BOOL IsLawUser(CString strUser, CString strPassword);
	BOOL CheckPass(CString strUser, CString strPassword);
	//BOOL CheckPass2(CString strUser, CString strPassword);
	BOOL DeleteItem(CUserInfo	*pInfo);
	void SaveUsersInfoToFile(LPCTSTR lpszFileName);
	void LoadUserInfo(LPCTSTR lpszFile);
	void GetMaxUserID();
	void CheckSelf();
	virtual void Serialize(CArchive& ar);
};

#endif // !defined(AFX_USERINFO_H__4A4BDAB7_2517_4564_9467_963AA91BA2F4__INCLUDED_)
