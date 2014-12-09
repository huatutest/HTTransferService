// AdoCommand.h: interface for the CAdoCommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCOMMAND_H__77B202F4_4F72_4B55_8E39_898AB263E293__INCLUDED_)
#define AFX_ADOCOMMAND_H__77B202F4_4F72_4B55_8E39_898AB263E293__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;

class CAdoConnect;
class AdoRecordset;

class CAdoParameter;
class CAdoParameters;

#include "AdbcCommdef.h"


class CAdoCommand  
{
public:
	CAdoCommand();
	virtual ~CAdoCommand();
	CAdoCommand(CAdoConnect &AdoConnect, CAString strCommandText = _T(""), enum AdbcCommandType AdbcCommandType = adbcCmdStoredProc);

protected:
	ADODB::_CommandPtr		m_ptrCommand;
	CAdoConnect		*m_pAdoConnect;

	void			Release();

public:	
	ADODB::_CommandPtr&	GetCommand();
	bool			SetConnection(CAdoConnect *pAdoConnect);

	//=================================================
	// ִ���� CommandText ��������ָ���� SQL ָ������
	//=================================================
	bool  Execute(CAString strCommandText = _T(""), 
				  enum AdbcCommandType Options = adbcCmdText);
	bool  Execute(VARIANT *RecordsAffected, 
				  VARIANT *Parameters, 
				  enum AdbcCommandType Options );

	//=================================================
	// ����洢����
	//=================================================
	bool	ClearParameter();
	bool	DeleteParameter(const long nIndex );
	bool	AddParameter(CAString strName, enum AdbcDataType Type, 
						 enum AdbcParaDirection Direction, long lSize, 
						 const _variant_t & Value = vtMissing);
	bool	GetParamValue(CAString strName, VARIANT &varValue);

	//=================================================
	// �� Parameters ��������н���һ���µ� Parameter ���
	//=================================================
	CAdoParameter*	CreateParameter( CAString strName, enum AdbcDataType Type, 
									 enum AdbcParaDirection Direction, long lSize, 
									 const _variant_t & Value = vtMissing);
	bool			Cancel();

	_variant_t		GetValue(long index);
	_variant_t		GetValue(LPCTSTR lpstrName);
	bool			GetValue(LPCTSTR lpstrName, VARIANT &vt);

	//=================================================
	// ���Ҳ����ָ��һ������
	//=================================================
    CAString			GetName();
    void			SetName(CAString strName);

	//=================================================
	// ��������ָ������������
	//=================================================
	void			SetCommandType (enum AdbcCommandType plCmdType);
    enum AdbcCommandType GetCommandType ();

	//=================================================
	// �������ݿ�
	//=================================================
	void			SetActiveConnection(CAdoConnect *pAdoConnect);
	CAdoConnect*	GetActiveConnection();

	bool			GetPrepared();
	void			SetPrepared(bool bPrepared);

	//=================================================
	// �Ƿ�Ҫ��ִ��ǰ����һ������
	//=================================================
	CAdoParameter*	GetParameter (long nIndex);
	CAdoParameter*	GetParameter(LPCTSTR lpstrName);
	bool			Append(CAdoParameter *pAdoParameter);

	CAdoParameters*	GetParameters();

	//=================================================
	// ִ��һ��ָ����ָ���һ������ѶϢǰ��
	// ����Ҫ�ĵȴ�ʱ�䣨��λ�����ӣ��� 
	//=================================================
	long			GetCommandTimeout();
	void			SetCommandTimeout(long lTime);

	//=================================================
	// ����ȷ��Ŀǰ�� Command ����ǿ�����رյ�״̬��
	// ���磺����ǿ�������ش�ֵ�� adStateOpen��
	// ��֮���� adStateClosed�� 
	//=================================================
	long			GetState();

	//=================================================
	// һ�δ�����Ҫִ��ָ�������
	//=================================================
	CAString		GetCommandText();
	void			SetCommandText(CAString strCommandText);
	
	CAdoParameter	operator [](int index);
	CAdoParameter	operator [](LPCTSTR lpszParamName);
};

#endif // !defined(AFX_ADOCOMMAND_H__77B202F4_4F72_4B55_8E39_898AB263E293__INCLUDED_)
