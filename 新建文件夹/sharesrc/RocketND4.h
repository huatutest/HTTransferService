// RocketND4.h: interface for the CRocketND4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ROCKETND4_H__791905FA_2C43_4ECC_9B0B_4F0467D2553E__INCLUDED_)
#define AFX_ROCKETND4_H__791905FA_2C43_4ECC_9B0B_4F0467D2553E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "Rockey4_ND_32.h"

class CRocketND4  
{
public:
	CRocketND4();
	virtual ~CRocketND4();
	
	WORD m_dwPass1;	  //һ������1
	WORD m_dwPass2;   //һ������2
	WORD m_dwPass3;	  //��������1
	WORD m_dwPass4;	  //��������2

	int	 m_nErrorCode;
	WORD CheckDog();		//���΢���Ƿ����
	BOOL GetCurDogCount();  //�õ���ǰ�ķ��Ͽ����΢������

	BOOL ClearAllDogData();
	DWORD GetDogID();

	void ClsSetLastError(int error);

	BOOL SetModuleMode(WORD wModuleCode,WORD wModuleContent);
	BOOL IsModuleValid(WORD wModuleCode);

	BOOL WriteDogData(LPBYTE bt,int size);
	BOOL ReadDogData(LPBYTE bt,int size);
	WORD BuffToDWORD(const char* buffer);
};

#endif // !defined(AFX_ROCKETND4_H__791905FA_2C43_4ECC_9B0B_4F0467D2553E__INCLUDED_)
