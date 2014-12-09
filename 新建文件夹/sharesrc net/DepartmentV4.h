// DepartmentV4.h: interface for the CDepartmentV4 class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DEPARTMENTV4_H__95C370EA_E939_4753_872B_D3D52DE9396A__INCLUDED_)
#define AFX_DEPARTMENTV4_H__95C370EA_E939_4753_872B_D3D52DE9396A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>
#include "UserInfoV4.h"
#include "VirtualMemFile.h"

class CDepartmentV4  
{
public:
	CDepartmentV4();
	virtual ~CDepartmentV4();

	int	 m_nDepartID;				//����ID
	LPTSTR m_strDepartName;			//��������

	BOOL m_bRoot;					//�Ƿ��Ǹ��ڵ�

	std::deque<CDepartmentV4*>	m_arrDepartment;   //�Ӳ���
	std::deque<CUserInfoV4*>	m_arrUser;		   //�����û�

public:
	CDepartmentV4*	FindSubDepartmentByID(int nDepartID);
	CDepartmentV4*	AddOneSubDepartment(int nDepartID, LPTSTR strDepartName);

	CUserInfoV4* FindSubUserByLoginName(LPTSTR strLoginName);
	CUserInfoV4* AddOneSubUser(LPTSTR strLoginName,LPTSTR m_strUserName);
	//CDepartmentV4*	FindSubDepartmentFromALL(int nDepartID);

	void WriteSubDepartmentToBuffer(CVirtualMemFile& mem, int nSubDepartSize);
	void ReadSubDepartmentFromBuffer(CVirtualMemFile& mem, int nSubDepartSize);
};

typedef std::map<int,CDepartmentV4*> MAP_DEPARTMENT;


#endif // !defined(AFX_DEPARTMENTV4_H__95C370EA_E939_4753_872B_D3D52DE9396A__INCLUDED_)
