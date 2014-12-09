// UserInfoV4.h: interface for the CUserInfoV4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_USERINFOV4_H__744A2520_3901_4583_A04E_AAA6788BD729__INCLUDED_)
#define AFX_USERINFOV4_H__744A2520_3901_4583_A04E_AAA6788BD729__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "LevelInfoV4.h"
#include <map>

enum
{
	RIGHT_OPEN = 1,
	RIGHT_ADJUST,
	RIGHT_DECRYPT,
	RIGHT_PRINT,
	RIGHT_READ,
	RIGHT_OUTSIDE,
	RIGHT_APPROVALDECRYPT,
	RIGHT_APPROVALOUTSIDE,
};

class CUserInfoV4  
{
public:
	CUserInfoV4();
	virtual ~CUserInfoV4();

	LPTSTR m_strLoginName;		//��¼��
	LPTSTR m_strUserName;		//�û���
	LPTSTR m_strPassword;		//�û�����

	BOOL m_bIsBinding;			//�Ƿ�����������
public:
	void SetUserRight(DWORD lRight);
	DWORD GetUserRight();
	void SetOverTime(int dwOverTime);
	int  GetOverTime();
	void SetCurrentLevel(int level);
	int	 GetCurrentLevel();

	void SetOneLevelInfo(int nType,int nLevelID);

	BOOL CanOpen(int nLevelID);
	BOOL CanAdjust(int nLevelID);
	BOOL CanDecrypt(int nLevelID);
	BOOL CanPrint(int nLevelID);
	BOOL CanRead(int nLevelID);
	BOOL CanOutSide(int nOutSideID);
	BOOL CanApprovalDecrypt(int nLevelID);
	BOOL CanApprovalOutSide(int nLevelID);

	int GetOpenFileSize();
	int GetAdjustFileSize();
	int GetDecryptFileSize();
	int GetPrintFileSize();
	int GetReadFileSize();
	int GetOutSideFileSize();
	int GetApprovalDecryptSize();
	int GetApprovalOutSideSize();
	int GetUserDepartCount();

	int GetOpenFile(int nOpen);
	int GetAdjustFile(int nAdjust);
	int GetDecryptFile(int nDecrypt);
	int GetPrintFile(int nPrint);
	int GetReadFile(int nPrint);
	int GetOutSideFile(int nOutSide);
	int GetApprovalDecrypt(int nApprovalDecrypt);
	int GetApprovalOutSide(int nApprovalOutSide);

	int GetDepartID(int nDepart);

	BOOL ExistDeparement(int nDepartID);
	void AddOntDepart(int nDepartID, LPTSTR strDepartName);
	BOOL IsUserDepart(int nDepartID);
private:

#ifdef DOCGUARDER42
	LONGLONG  m_dwRightGroup;	//�û�Ȩ��
#else
	DWORD	m_dwRightGroup;
#endif
	
	int		m_dwOverTime;		//��������ʱ��(Сʱ)

	int		m_nLevelID;			//�ȼ�
	
	std::map<int,int>			m_arrOpenFile;		//�򿪵ȼ�
	std::map<int,int>			m_arrPrintFile;		//��ӡ�ȼ�
	std::map<int,int>			m_arrAdjustFile;	//�����ȼ�
	std::map<int,int>			m_arrDecryptFile;	//���ܵȼ�
	std::map<int,int>			m_arrReadFile;		//����ȼ�
	std::map<int,int>			m_arrOutSideFile;		//�ⷢ�ȼ�
	std::map<int,int>			m_arrApprovalDecrypt;	//��������
	std::map<int,int>			m_arrApprovalOutSide;	//�����ⷢ

	std::map<int,CAString>		m_arrDepartmentID;	//�û������Ĳ���ID	
};

typedef std::map<CAString,CUserInfoV4*> MAP_USER;


#endif // !defined(AFX_USERINFOV4_H__744A2520_3901_4583_A04E_AAA6788BD729__INCLUDED_)
