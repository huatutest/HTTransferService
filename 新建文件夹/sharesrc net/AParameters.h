// AParameters.h: interface for the CAParameters class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APARAMETERS_H__C9BFB293_97DE_4B85_B981_7F57976A2E1B__INCLUDED_)
#define AFX_APARAMETERS_H__C9BFB293_97DE_4B85_B981_7F57976A2E1B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;
class CAdoParameters;
class CAParameter;

class CAParameters  
{
public:
	CAParameters();
	virtual ~CAParameters();
	
	CAdoParameters	*m_pAdoParameters;

public:
	//==========================================
	// ����һ�� Parameter �������С� 
	//==========================================
	BOOL			Append(CAParameters &AParameters);
	//==========================================
	// �h�������е�һ�� Parameter ����� 
	//==========================================
	BOOL			Delete(int nIndex);
	//==========================================
	// ���� Parameters ��������������ĸı䡣 
	//==========================================
	BOOL			Refresh();
	//==========================================
	// �ش������е� Parameter ������
	//==========================================
	long			GetCount();
	//==========================================
	// ��������ȡ�ü����� parameter ����ă���
	//==========================================
	CAParameter*	GetItem(int nIndex);
};

#endif // !defined(AFX_APARAMETERS_H__C9BFB293_97DE_4B85_B981_7F57976A2E1B__INCLUDED_)
