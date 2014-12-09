// ClientInfo.h: interface for the CClientInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTINFO_H__6A71A44D_56CD_4BF2_8301_4FEF17281162__INCLUDED_)
#define AFX_CLIENTINFO_H__6A71A44D_56CD_4BF2_8301_4FEF17281162__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "ClientNodeInfo.h"
class CClientDogEx;
#ifndef  MAXCOUNT
#define  MAXCOUNT 8
#endif
struct LicenseInfo2
{
	UINT mask;					//�жϰ󶨵���Ϣ
	char strMacAddress[32];		//MAC��ַ
	char strHardID[32];			//Ӳ�̺�
	char strUserPass[1024];		//�û�����; Ӱ������ļ�
	UINT uLicenseID;			//License��ʶ ��ͬ��DogID
	UINT uVersion;				//�ͻ��˰汾  0x02012007D1 ��ʾ 2.1.2001�汾
	UINT uLicenseVersion;		//License�Ķ��Ĵ���,�߰汾���޸�license���߲ſ��Խ���License����
	UINT uCount;				//�ڵ���
	SYSTEMTIME timeOver;			//����ʱ��
};

struct LicenseInfo3
{
	UINT mask;					//�жϰ󶨵���Ϣ
	char strMacAddress[64];		//MAC��ַ
	char strHardID[64];			//Ӳ�̺�
	char strUserPass[1024];		//�û�����; Ӱ������ļ�
	UINT uLicenseID;			//License��ʶ ��ͬ��DogID
	UINT uVersion;				//�ͻ��˰汾  0x02012007D1 ��ʾ 2.1.2001�汾
	UINT uLicenseVersion;		//License�Ķ��Ĵ���,�߰汾���޸�license���߲ſ��Խ���License����
	UINT uCount;				//�ڵ���
	SYSTEMTIME timeOver;			//����ʱ��
	int	 nTime;
	int  nReserve;
};


typedef struct LicenseInfo4
{
	BYTE btFlag[10];//����Ȩ��ʶ��Ĭ��Ϊvamtoo��
	DWORD dwDogVersion;//����Ȩ�汾��Ĭ��Ϊ1��
	DWORD dwDogID;//����
	BYTE btKey[128];//��Կ
	DWORD dwBandMask;//�жϰ󶨵���Ϣ BAND_MAC = 0x01BAND_HARDDISK = 0x02
	CHAR cBandInfo[128];//����Ϣ
	WORD dwProduct[MAXCOUNT];//��Ʒ������dwModule [0] = 1��ʾ����DocGuarder��
	INT nCount[MAXCOUNT];//�ڵ�������nCount [0] = 100��ʾ��ƷDocGuarder�ڵ���100��-1��ʾ�����ƣ�
	SYSTEMTIME tTimeOver[MAXCOUNT];//��Ʒ����ʱ�䣨��tTimeOver[0]��ʾDocGuarder�ĵ���ʱ�䣬ȫ0��ʾ�����ƣ�
	DWORD dwTactics[MAXCOUNT];//��Ʒ���ڲ��� 0���޲��ԡ�0x1������һ��0x2�����Զ�......
	DWORD dwModuleFlag[MAXCOUNT];//ģ���ʶ���磺����0x1�ⷢ0x2��Ȩ����0x4��
	FLOAT nProductViersion[MAXCOUNT];//֧�ֵĲ�Ʒ�汾
	BYTE btGuid[40];//GUID�ַ���
	INT	nReserve;//�����ֶ�
}LicenseInfo4,*PLicenseInfo4;
class CClientInfo  
{
public:
	CClientInfo();
	virtual ~CClientInfo();

	DWORD	m_dwAuthorizedMoules;

	HINSTANCE m_hBaseDll;

	CLIENT_DEQUE m_arrNodeInfo;			//�������ӵĽڵ�

	CLIENT_DEQUE m_arrOverTimeNodeInfo; //��ʱ�ڵ�

	CClientNodeInfo* m_pCurrentNode;

//	CRocketDog m_dogAccess;				//΢����Ϣ


	DWORD m_dwDogID;
	DWORD m_dwDogCount;
	BYTE  m_btKey[128];
	int	  m_nMode;
	int	  m_nTime;
	int	  m_nStrategy;
	LONGLONG  m_lDeadline;
	BOOL  m_bNewDog;
	BOOL  m_bNewSoftLic;

	CClientNodeInfo* FindNodeByKeyInNormal(LPCTSTR strComputer,LPCTSTR strMac);

	CClientNodeInfo* FindNodeByIP(LPCTSTR strIP);

	CClientNodeInfo* FindNodeByKeyInOverTime(LPCTSTR strComputer,LPCTSTR strMac);

	int GetNodeTypeInfo(int& OverTimeNode);
	void DeleteOverTimeNode(CClientNodeInfo* pInfo);

	void DeleteNormalNode(CClientNodeInfo* pInfo);

	void DeleteNode(CClientNodeInfo* pInfo);

	BOOL AddNewClientNode(LPCTSTR strComputer,LPCTSTR strMac,LPCTSTR strCurUser,LPCTSTR szHost);
	
	BOOL CheckAllOverTimeNode();

	BOOL CheckPass(LPCTSTR strUser,LPCTSTR strPass,int* nUserType,DWORD* pdwPriv);
	BOOL CheckPass2(LPCTSTR strUser,LPCTSTR strPass,int* nUserType,DWORD* pdwPriv,DWORD* pdwCryptLevel,int* pnPolicyType,INT_DEQUE& PolicyDeque);
	
	int GetUserCount();
	int GetDogInfo();



	void ParseVersion(WORD* pPro, FLOAT* pVer);
};

#endif // !defined(AFX_CLIENTINFO_H__6A71A44D_56CD_4BF2_8301_4FEF17281162__INCLUDED_)
