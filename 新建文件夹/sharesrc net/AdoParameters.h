// AdoParameters.h: interface for the CAdoParameters class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOPARAMETERS_H__EE922DF4_E9C9_42B8_8436_898607A11FAA__INCLUDED_)
#define AFX_ADOPARAMETERS_H__EE922DF4_E9C9_42B8_8436_898607A11FAA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CAString;

class CAdoParameter;


class CAdoParameters
{
public:
	CAdoParameters();
	virtual ~CAdoParameters();

	ADODB::ParametersPtr	m_ptrParameters;

public:
	//==========================================
	// ����һ�� Parameter �������С� 
	//==========================================
	BOOL			Append(CAdoParameters *pAdoParameters);
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
	CAdoParameter*	GetItem(int nIndex);

	ADODB::ParametersPtr&	operator =(ADODB::ParametersPtr& pParameters);
};

#endif // !defined(AFX_ADOPARAMETERS_H__EE922DF4_E9C9_42B8_8436_898607A11FAA__INCLUDED_)
