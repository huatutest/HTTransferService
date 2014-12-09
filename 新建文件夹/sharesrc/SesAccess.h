// SesAccess.h: interface for the CSesAccess class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_SESACCESS_H__3C3C738A_7D4C_4034_9168_F92B760B14A1__INCLUDED_)
#define AFX_SESACCESS_H__3C3C738A_7D4C_4034_9168_F92B760B14A1__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "sense4.h"
#include "psense4.h"
#include "common.h"

struct Offline_Info2;
//���ڵ��ļ��ṹΪ

// ��Ŀ¼ "a001" �ļ�Ϊִ���ļ�
// \\0001\\d001  �ļ�Ϊ�����ļ�,�������ļ�

class CSesAccess  
{
public:
	CSesAccess(const BYTE* btUserPin,int UserPinLen,const BYTE* btDevPin,int DevUserPin);
	CSesAccess();
	virtual ~CSesAccess();

	LPBYTE ReadSesFile(const char* DirID,const char* FileID,WORD dwFileID,DWORD* dwSize);
	BOOL WriteSesDataFile(const char* FileID,const char* lpszFileName,DWORD dwFileType,DWORD* dwBytesWritten);
	BOOL WriteSesDataFile(const char* FileID,LPBYTE btBuffer,DWORD dwBufSize,DWORD dwFileType,DWORD* dwBytesWritten);

	CString GetDogID();
	BOOL RetsetDogContent();

	BOOL GetSenseCurTime(tm& curtime);

	BOOL IsDogExisting();

	BOOL IsKeyFileExisting();

	unsigned long m_dwResult;  //����sense���ķ���ֵ
	unsigned char lpUserPin[8];
	unsigned char lpDevPin[24];

	BOOL IsCanContinue(Offline_Info2& info);

	SENSE4_CONTEXT stS4Ctx;
};

#endif // !defined(AFX_SESACCESS_H__3C3C738A_7D4C_4034_9168_F92B760B14A1__INCLUDED_)
