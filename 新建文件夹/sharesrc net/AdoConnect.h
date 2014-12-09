// AdoConnect.h: interface for the CAdoConnect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOCONNECT_H__107036CD_353B_45E1_A7DA_6C8686459181__INCLUDED_)
#define AFX_ADOCONNECT_H__107036CD_353B_45E1_A7DA_6C8686459181__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdbcCommDef.h"

class CAdoRecordset;
class CAdoErrors;
class CAdoError;
class CAString;

class CAError;
class CAErrors;

class CAdoConnect  
{
public:
	CAdoConnect();
	virtual ~CAdoConnect();

protected:
	void			Release();
	inline void		TESTHR(HRESULT x) {if FAILED(x) _com_issue_error(x);};

	ADODB::_ConnectionPtr	m_ptrConnection;
public:
	CAString		m_strConnectString;
	int				m_lConnectionState;
	CAString		m_strDataSource;
	int				m_nQueryTimeOut;

public:
	bool GetConnectionString( CAString &strConnectString );
	bool GetFreeConnectString( CAString &strConnectString );

	ADODB::_ConnectionPtr& GetConnection();
	void			SetConnection(ADODB::_ConnectionPtr ptrConnection);

	ADODB::_ConnectionPtr operator =(ADODB::_ConnectionPtr &ptrConnection);
	void operator =(CAdoConnect &AdoConnect);
	//==============================================
	// ������
	//==============================================
	CAString			GetComError(const _com_error& e);
	CAString			GetProviderError();
	CAString			GetLastErrorText();
	CAString			GetLastSQLState();
	CAdoErrors*			GetErrors();
	CAdoError*			GetError(long index);

	//==============================================
	// ������Ϣ
	//==============================================
	CAString			GetProviderName();
	//==============================================
	// �ش� ADO �İ汾���롣
	//==============================================
	CAString			GetVersion();
	//==============================================
	// Ԥ�����Ͽ⡣
	//==============================================
	CAString			GetDefaultDatabase();

	//==============================================
	// �ش�ֵ���� Connection �ǿ�����رա�
	// ��һ�������� Connection ���ԣ��ش�ֵ�� adStateOpen��
	// ��� Connection �ǹرյ�״̬����ش� adStateClosed��
	//==============================================
	int				GetState();	
	bool			IsOpen();

	//==============================================
	// ����ģʽ
	//==============================================
	enum AdbcConnectMode GetMode();
	bool			SetMode(enum AdbcConnectMode mode);

	//==============================================
	// ���ӵ����Ͽ⡢��ش�һ������ѶϢ����Ҫ�ĵȴ�ʱ�䡣 
	//==============================================
	void			SetConnectionTimeout(long lTimeout = 15);
	long			GetConnectionTimeout();

	//==============================================
	// �����ŷ����˵� script�����Լ�ҕ����䛵�AdbcSchema��
	// ���磺���ϱ���λ���ȡ� 
	//==============================================
	CAdoRecordset*	OpenSchema(enum AdbcSchema QueryType);

	//==============================================
	// ����һ���µ�Connection���
	//==============================================
	bool		Open( CAString strConnectionString, 
					  enum AdbcConnectOption nOption = adbcConnectUnspecified );
	bool		Open( CAString strConnectionString, 
					  CAString strUser, 
					  CAString strPassword, 
					  int nOption );
	bool		Connect(LPCTSTR lpszConnectString = NULL, 
						const bool& bRetry = false,
						LPCTSTR lpszInitialCatalog = NULL);
	//==============================================
	// �ر�һ�� Connection ���
	//==============================================	
	bool		Close();

	//==============================================
	// ��ʼһ���µĽ���
	//==============================================
	long		BeginTrans();
	//==============================================
	// �洢���׹����������ĸı䣬�K�ҽY�����ס�
	// Ҳ���������ʱ��ʼһ���µĽ��ס� 
	//==============================================
	bool		CommitTrans();
	//==============================================
	// ȡ�����׹����������ĸı䣬
	// Ҳ�����ڴ�ʱ��ʼ����һ���µĽ���
	//==============================================
	bool		RollbackTrans();

	bool SetCursorLocation(enum AdbcCursorLocation CrLocation);
	void SetCommandTimeout(long pl);
	//==============================================
	// ����һ����ѯ��SQLָ������
	//==============================================
	bool		Execute(CAString CommandText, int &nRecordsAffected, enum AdbcCommandType Options = adbcCmdText );
	bool		Cancel();
};

#endif // !defined(AFX_ADOCONNECT_H__107036CD_353B_45E1_A7DA_6C8686459181__INCLUDED_)
