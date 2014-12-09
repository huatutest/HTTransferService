// AdoErrors.h: interface for the CAdoErrors class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOERRORS_H__859DE811_90A6_45B1_A169_EB3ABC00CACB__INCLUDED_)
#define AFX_ADOERRORS_H__859DE811_90A6_45B1_A169_EB3ABC00CACB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CAString;

class CAdoError;

class CAdoErrors  
{
public:
	CAdoErrors();
	virtual ~CAdoErrors();

protected:
	ADODB::ErrorsPtr	m_ptrErrors;

public:
	//=============================================
	// ��������ȡ�� Errors ��������и��e Error ����ă���
	//=============================================
	CAdoError*	GetItem( const _variant_t & Index );
	//=============================================
	// �Ƴ� Errors �����е����� Error ���
	//=============================================
	BOOL		Clear();

	void		SetErrors(ADODB::ErrorsPtr ptrErrors);
};

#endif // !defined(AFX_ADOERRORS_H__859DE811_90A6_45B1_A169_EB3ABC00CACB__INCLUDED_)
