// ClientDog.h: interface for the CClientDog class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_CLIENTDOG_H__A3A68711_68F7_475A_B48F_36E42F7E4BE5__INCLUDED_)
#define AFX_CLIENTDOG_H__A3A68711_68F7_475A_B48F_36E42F7E4BE5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
//#include "stdafx.h"
#include "RocketND4.h"

class CClientDog : public CRocketND4  
{
public:
	CClientDog(WORD pass1 = 0,WORD pass2 = 0,WORD pass3 = 0,WORD pass4 = 0);
	CClientDog(const char* pass1,const char* pass2,const char* pass3,const char* pass4);

	virtual ~CClientDog();

	BYTE	m_btFlag[10];

	DWORD m_dwDogID;
	WORD  m_wModule[16];
	DWORD m_dwModuleCount[16];
	BYTE  m_btKey[128];

	DWORD m_dwDogVersion;

	WORD WriteDogData();
	WORD ReadDogData();
	WORD WriteDogBuffer(LPBYTE bt, int size);
	WORD ReadDogBuffer(LPBYTE bt,int size);
	BOOL ClearAllDogData();
};

class CClientDogEx : public CRocketND4
{
public:
	CClientDogEx(WORD pass1 = 0,WORD pass2 = 0,WORD pass3 = 0,WORD pass4 = 0);
	CClientDogEx(const char* pass1,const char* pass2,const char* pass3,const char* pass4);
	
	virtual ~CClientDogEx();

	BYTE m_btFlag[10];
	DWORD m_dwDogID;
	BYTE  m_btKey[128];
	DWORD m_dwDogVersion;
	BYTE m_guid[40];
	INT m_nReserve;

	WORD m_dwProduct[MAXCOUNT];//��Ʒ������dwModule [0] = 1��ʾ����DocGuarder��
	int m_nCount[MAXCOUNT];//�ڵ�������nCount [0] = 100��ʾ��ƷDocGuarder�ڵ���100��-1��ʾ�����ƣ�
	SYSTEMTIME m_tTimeOver[MAXCOUNT];//��Ʒ����ʱ�䣨��tTimeOver[0]��ʾDocGuarder�ĵ���ʱ�䣬ȫ0��ʾ�����ƣ�
	DWORD m_dwTactics[MAXCOUNT];//��Ʒ���ڲ��� 0���޲��ԡ�0x1������һ��0x2�����Զ�......
	DWORD m_dwModuleFlag[MAXCOUNT];	//ģ���ʶ���磺����0x1�ⷢ0x2��Ȩ����0x4��
	FLOAT m_nProductViersion[MAXCOUNT];//֧�ֵĲ�Ʒ�汾

	WORD WriteDogData();
	WORD ReadDogData();
};

#endif // !defined(AFX_CLIENTDOG_H__A3A68711_68F7_475A_B48F_36E42F7E4BE5__INCLUDED_)
