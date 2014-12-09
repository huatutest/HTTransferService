// AErrors.h: interface for the CAErrors class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_AERRORS_H__A82608E3_D659_434F_8343_63B0CB1BF43C__INCLUDED_)
#define AFX_AERRORS_H__A82608E3_D659_434F_8343_63B0CB1BF43C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;
class CAError;
class CAdoErrors;


///////////////////////////////////////
// ���󼯺�
//	
///////////////////////////////////////

class CAErrors  
{
public:
	CAErrors();
	virtual ~CAErrors();

protected:
	CAdoErrors	*m_pAdoErrors;

public:
	void		SetErrors(CAdoErrors *pAdoErrors);
	//=============================================
	// ��������ȡ�� Errors ��������и��e Error ����ă���
	//=============================================
	CAError*	GetItem( const _variant_t & Index );
	//=============================================
	// �Ƴ� Errors �����е����� Error ���
	//=============================================
	BOOL		Clear();
};

#endif // !defined(AFX_AERRORS_H__A82608E3_D659_434F_8343_63B0CB1BF43C__INCLUDED_)
