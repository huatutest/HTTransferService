// AConnect.h: interface for the CAConnect class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ACONNECT_H__AF55B31A_46D3_4EFE_B81B_E1B36B26414B__INCLUDED_)
#define AFX_ACONNECT_H__AF55B31A_46D3_4EFE_B81B_E1B36B26414B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CAString;

class CAExtDataMgr;
class CAdoConnect;
class CARecordset;
class CAErrors;
class CAError;

#include "AdbcCommDef.h"

//////////////////////////////////////////////////////////////////////////////
// ʹ��˵����Jiessie 2003/11/17
//	1. ��ʹ�ñ���ǰ��Ҫ��ʼ��COM�����Ե��� CoInitialize(NULL)
//	   ����ʼ��, �����CoUninitialize()�ͷ�
//	2. ��ʹ�ü�¼������ǰ�ȵ���CAConnect::Open()����ͬ�����ݿ����ͣ���MS SQL
//	   ������OpenSQLserver���������ݿ⣬�����Ϻ�ɸ����CARecordSet����ʹ�á�
//	3. ʹ�ü�¼��CARecordsetִ��SQL���֮ǰ��Ҫʹ�ù������������SetAdoConnection()
//	   ���������Ӷ���
//	4. ��֤ msado15.dll��msadox.dll��Oledb32.dll ȫ·����ȷ, 
//     ����ΪstaAfx.h�ļ��ж����·��������Ϊ��Ӧ����ȷ·����
//////////////////////////////////////////////////////////////////////////////
//using namespace std;

class CAConnect  
{
public:
	CAConnect();
	virtual ~CAConnect();

protected:
	CAdoConnect			*m_pAdoConnect;
//	CAExtDataMgr		*m_pExtDataMgr;
	

public:
	short				m_nDBType;				// ����Դ������
	DWORD				m_dwFlag;	
	DWORD				m_dwExceptionProcess;
	UINT				m_nExceptionMsg;
//	HWND				m_hExceptionWnd;		// �����쳣��Ϣ��Wnd
	CAString			m_strErrorInfo;
	
public:
	void			ModifyExceptionFlag( DWORD dAdd , DWORD dRemove );
	BOOL			ReConnect();
	BOOL			GetConnectionString(CAString &strConnectString);
	BOOL			GetFreeConnectString(CAString &strConnectString );
	BOOL			GetUserData( LPCTSTR lpszVarName , CAString &strValue );
	BOOL			SetUserData( LPCTSTR lpszVarName, LPCTSTR lpszValue );
	BOOL			RemoveUserData( LPCTSTR lpszVarName );
	void			Release();
	void			InitConnect();
	void			SetConnectFlag( DWORD dwFlag );
	void			Exceptioin( UINT nCause, HRESULT hr = 0, CAString strErrorInfo = _T(""));
	CAdoConnect*	GetConnection();
	void			SetConnection(CAdoConnect *pAdoConnect);

	CAdoConnect*	operator =(CAdoConnect *pAdoConnect);
	void operator =(CAConnect &AConnect);

	//==============================================
	// ����һ���µ�Connection���
	//==============================================
	BOOL		Open( CAString lpszConnectionString, enum AdbcConnectOption nOption = adbcConnectUnspecified );
	BOOL		Open( CAString lpszConnectionString, CAString lpszUser, CAString lpszPassword, int nOption );
	BOOL		Connect( CAString strConnectString = _T(""), const bool& bRetry = false,
						 CAString strInitialCatalog = _T(""));
	BOOL		OpenSQLServer( CAString lpszServerName, CAString lpszDataBaseName, 
							   CAString lpszUser, CAString lpszPassword, 
						       enum AdbcConnectOption lOptions = adbcConnectUnspecified);
	BOOL		OpenOracleServer( LPCTSTR lpszServerName, LPCTSTR lpszDataBaseName, 
							      LPCTSTR lpszUser, LPCTSTR lpszPassword, 
								  enum AdbcConnectOption lOptions = adbcConnectUnspecified);
	BOOL		OpenAccess( LPCTSTR lpszMDBPath, 
						   LPCTSTR lpszPassword = NULL, 
							enum AdbcConnectOption lOptions = adbcConnectUnspecified);
	BOOL		OpenUDLFile( CAString strFileName, enum AdbcConnectOption lOptions = adbcConnectUnspecified);
	//==============================================
	// �ر�һ�� Connection ���
	//==============================================
	BOOL		Close();

	//==============================================
	// ��ʼһ���µĽ���
	//==============================================
	long			BeginTrans();
	//==============================================
	// �洢���׹����������ĸı䣬�K�ҽY�����ס�
	// Ҳ���������ʱ��ʼһ���µĽ��ס� 
	//==============================================
	BOOL			CommitTrans();
	//==============================================
	// ȡ�����׹����������ĸı䣬
	// Ҳ�����ڴ�ʱ��ʼ����һ���µĽ���
	//==============================================
	BOOL			RollbackTrans();

	//==============================================
	// ����һ����ѯ��SQLָ������
	//==============================================
	BOOL			Execute(LPCTSTR lpszCommandText);
	BOOL			Execute(LPCTSTR lpszCommandText, int &nRecordsAffected, enum AdbcCommandType Options = adbcCmdText );
	BOOL			Cancel();

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
	// ����ģʽ
	//==============================================
	enum AdbcConnectMode GetMode();
	BOOL			SetMode(enum AdbcConnectMode mode);

	//==============================================
	// �ش�ֵ���� Connection �ǿ�����رա�
	// ��һ�������� Connection ���ԣ��ش�ֵ�� adStateOpen��
	// ��� Connection �ǹرյ�״̬����ش� adStateClosed��
	//==============================================
	int				GetState();	
	BOOL			IsOpen();

	//==============================================
	// ���ӵ����Ͽ⡢��ش�һ������ѶϢ����Ҫ�ĵȴ�ʱ�䡣 
	//==============================================
	void			SetConnectionTimeout(long lTimeout = 15);
	long			GetConnectionTimeout();

	//==============================================
	// �����ŷ����˵� script�����Լ�ҕ����䛵�AdbcSchema��
	// ���磺���ϱ���λ���ȡ� 
	//==============================================
	CARecordset*	OpenSchema(enum AdbcSchema QueryType);

	BOOL SetCursorLocation(enum AdbcCursorLocation CursorLocation/* = adbcUseClient*/);
	void SetCommandTimeout(long pl);
	//===============================================
	// ������
	//===============================================
	CAString		GetComError(const _com_error& e);
	CAString		GetProviderError();
	void			SetErrorInfo( CAString strError );
	CAString		GetLastErrorText();
	CAString		GetErrorInfo( bool bAddLastError = true );
	CAString		GetLastSQLState();
	CAErrors*		GetErrors();
	CAError*		GetError(long index);
};

#endif // !defined(AFX_ACONNECT_H__AF55B31A_46D3_4EFE_B81B_E1B36B26414B__INCLUDED_)
