// DllExeInfo.h: interface for the CDllExeInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DLLEXEINFO_H__DDF3B3D0_0CDB_4DC0_B03A_F090924290A6__INCLUDED_)
#define AFX_DLLEXEINFO_H__DDF3B3D0_0CDB_4DC0_B03A_F090924290A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <deque>
using namespace std;

#include "TreeNode.h"

struct DllExeInfo
{
	char* lpszModuleName; //ģ����
	BOOL bChecked;        //�Ƿ��ģ���ѱ����
};

typedef deque<DllExeInfo*> MODULE_DEQUE;

class CDllExeInfo : public CTreeNode
{
public:
	BOOL DelDllExeInfo(char* lpszModuleName);
	CDllExeInfo();
	virtual ~CDllExeInfo();

	MODULE_DEQUE m_ConfigDeque;
	int m_nCheckNum;		//��鵽ƥ��ĸ���

	BOOL m_bInitCheck;
	
	void InitCheckNum();

	BOOL IsModuleValid(const char* lpszModuleName);

	void CheckDllExeInfo(const char* lpszModuleName); //���ָ��ģ���Ƿ���������

	BOOL AddDllExeInfo(const char* lpszModuleName);
	void DeleteDllExeInfo(const char* lpszModuleName);

	DllExeInfo* FindDllExeInfo(const char* lpszModuleName);

	BOOL IsAllModuleCheckSuccess();

#ifndef NO_MFC_VERSION
	virtual void Serialize(CArchive& ar);
	virtual void Serialize_Unicode(CArchive& ar);
#else
	virtual void Serialize(HANDLE hFile,BOOL bRead);
	virtual void Serialize_Unicode(HANDLE hFile,BOOL bRead);
#endif
	
	
	BOOL CheckModule(const char* lpszModuleName);
};

#endif // !defined(AFX_DLLEXEINFO_H__DDF3B3D0_0CDB_4DC0_B03A_F090924290A6__INCLUDED_)
