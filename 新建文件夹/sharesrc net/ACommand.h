// ACommand.h: interface for the CACommand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACOMMAND_H__29A7B0EF_E9B4_44A9_81F2_F5425FEB92BF__INCLUDED_)
#define AFX_ACOMMAND_H__29A7B0EF_E9B4_44A9_81F2_F5425FEB92BF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;
class CADateTime;
class CAVariantConv;

class CAdoCommand;
class CARecordset;
class CAdoParameter;
class CAdoParameters;
class CAParameters;
class CAParameter;
class CAConnect;


#include "AdbcCommDef.h"

//////////////////////////////////////////////////////
//
// ע�⣺ʹ��ǰ����SetActiveConnection����CAConnect
// 
//////////////////////////////////////////////////////

class CACommand  
{
public:	
	CAdoCommand		*m_pAdoCommand;
	CAConnect		*m_pAConnect;
public:
	CACommand();
	virtual ~CACommand();
	CACommand( CAConnect &AConnect, CAString strCommandText = _T(""), enum AdbcCommandType AdbcCommandType = adbcCmdStoredProc );

public:	
	//=================================================
	// ִ���� CommandText ��������ָ���� SQL ָ������
	//=================================================
	bool	Execute( CAString strCommandText = _T(""), enum AdbcCommandType Options = adbcCmdText );
	bool	Execute( VARIANT *RecordsAffected, VARIANT *Parameters, enum AdbcCommandType Options );
	//=================================================
	// ����洢����
	//=================================================
	bool	ClearParameter();
	bool	DeleteParameter(const _variant_t & Index );
	bool	RunStoredProc( CAString strStoredName );
	bool	AddParameter(CAString strName, enum AdbcDataType Type, 
						 enum AdbcParaDirection Direction, long lSize, 
						 const _variant_t & Value = vtMissing);
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const CAString &Value = _T("") );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const double &Value = 0.0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const float &Value = 0.0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const long &Value = 0L );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const int &Value = 0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const BYTE &Value = 0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const char &Value = '\0' );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const DWORD &Value = 0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const UINT &Value = 0 );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const bool &Value = false );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const CADateTime &Value );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const CURRENCY &Value );
	bool	AddParameter( CAString strName, enum AdbcDataType Type,
						 enum AdbcParaDirection Direction, long lSize, 
						 const short &Value = 0 );

	bool	GetParamValue(CAString strName, CAString &strValue);
	bool	GetParamValue(CAString strName, int &nValue);
	bool	GetParamValue(CAString strName, bool &bValue);
	bool	GetParamValue(CAString strName, VARIANT &varValue);

	//=================================================
	// �� Parameters ��������н���һ���µ� Parameter ���
	//=================================================
	CAParameter*	CreateParameter( CAString strName, enum AdbcDataType Type,
									 enum AdbcParaDirection Direction, long lSize, 
									 const _variant_t &Value = vtMissing );

	bool			Append( CAParameter *pAParameter );

	CAParameter*	GetParameter (long nIndex);
	CAParameter*	GetParameter(CAString strName);
	
	void			Release();
	CAdoCommand*	GetCommand();

	bool			Cancel();
	_variant_t		GetValue( long index );
	_variant_t		GetValue( CAString strName );

	//=================================================
	// ���Ҳ����ָ��һ������
	//=================================================
	CAString			GetName();
    void			SetName( CAString strName );

	//=================================================
	// ��������ָ������������
	//=================================================
	void			SetCommandType ( enum AdbcCommandType plCmdType );
    enum AdbcCommandType GetCommandType ();

	//=================================================
	// �������ݿ�
	//=================================================
	bool			SetConnection( CAConnect *pAConnect );
	void			SetActiveConnection( CAConnect *pAConnect );
	CAConnect*		GetActiveConnection();

	//=================================================
	// �Ƿ�Ҫ��ִ��ǰ����һ������
	//=================================================
	bool			GetPrepared();
	void			SetPrepared(bool bPrepared);

	CAParameters*	GetParameters ();
	
	//=================================================
	// ִ��һ��ָ����ָ���һ������ѶϢǰ��
	// ����Ҫ�ĵȴ�ʱ�䣨��λ�����ӣ��� 
	//=================================================
	long			GetCommandTimeout();
	void			SetCommandTimeout(long pl);

	//=================================================
	// һ�δ�����Ҫִ��ָ�������
	//=================================================
	CAString			GetCommandText();
	void			SetCommandText(CAString strCommandText);

	//=================================================
	// ����ȷ��Ŀǰ�� Command ����ǿ�����رյ�״̬��
	// ���磺����ǿ�������ش�ֵ�� adStateOpen��
	// ��֮���� adStateClosed�� 
	//=================================================
	long			GetState();

	CAParameter		operator [](int index);
	CAParameter		operator [](CAString strParamName);
};

#endif // !defined(AFX_ACOMMAND_H__29A7B0EF_E9B4_44A9_81F2_F5425FEB92BF__INCLUDED_)
