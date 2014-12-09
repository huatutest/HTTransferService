// AdoRecordset.h: interface for the CAdoRecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADORECORDSET_H__6CDA9FA4_5451_4E41_889D_EAC28CE3AC76__INCLUDED_)
#define AFX_ADORECORDSET_H__6CDA9FA4_5451_4E41_889D_EAC28CE3AC76__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;
class CADateTime;

class CAdoConnect;
class CADORecordBinding;

#include "AdbcCommDef.h"

class CAdoRecordset  
{
protected:
	ADODB::_RecordsetPtr	m_ptrRecordset;

	CAdoConnect				*m_pAdoConnect;
	
	CAString				m_strFind;
	IADORecordBinding		*m_pAdoRecordBinding;
	enum AdbcSearchDirection	m_SearchDirection;
	_variant_t				m_varBookmark;

protected:
	void	Release();
	inline	void TESTHR(HRESULT x) {if FAILED(x) _com_issue_error(x);};

public:
	CAdoRecordset();
	virtual ~CAdoRecordset();
	CAdoRecordset(CAdoConnect *pAdoConnect);

	//=======================================
	// �� Recordset �п���һ��ָ��
	//=======================================
	bool	Open( CAString strSource, 
				  CAdoConnect *pAdoConnect,
				  enum AdbcCursorType nCursorType = adbcOpenStatic,
				  enum AdbcLockType nLockType = adbcLockOptimistic,
				  enum AdbcCommandType Options = adbcCmdText );
	//=======================================
	// �ر�һ�� Recordset �Լ���ص����
	//=======================================
	bool Cancel();
	bool Close();
	//=======================================
	// ����һ���µ�����¼��
	//=======================================
	bool AddNew(const _variant_t &FieldList = vtMissing, const _variant_t &Values = vtMissing);
	bool AddNew(CADORecordBinding &pAdoRecordBinding);
	//======================================
	// �洢Ŀǰ����¼���������κθı�
	//======================================
	bool Update();
	//======================================
	// ���θ���
	//======================================
	bool UpdateBatch(enum AdbcAffect AffectRecords = adbcAffectAll);
	//======================================
	// ȡ�����¡�
	//======================================	
	bool CancelUpdate();
	//======================================
	// ȡ�����θ���
	//======================================
	bool CancelBatch(enum AdbcAffect AffectRecords = adbcAffectAll);
	//======================================
	// ��һ�����ڿ����� Recordset �Єh��һ������¼
	//======================================
	bool Delete(enum AdbcAffect AffectRecords = adbcAffectCurrent);
	
	//=======================================
	// Ŀǰ����¼�ı༭״̬
	//=======================================
	enum AdbcEditMode GetEditMode();

	//=======================================
	// �ж�Ŀǰ����¼��λ���Ƿ��ڵ�һ������¼֮ǰ
	//=======================================
	bool IsEOF();
	//=======================================
	// �ж�Ŀǰ����¼�Ƿ������һ������¼֮��
	//=======================================
	bool IsBOF();
	bool IsOpen();
	//=======================================
	// �ش�һ����ʾ Recordset ����ǿ��������ǹرյ�״̬��
	//=======================================
	long GetState();
	//=======================================
	// Ŀǰ����¼��״̬��ͨ�����ǿ��Ը����₀�ش�ֵ��
	// Ȼ������Ƿ�Ҫ���δ�����������������ʽ��
	//=======================================
	long GetStatus();

	//=======================================
	// һ����ѯ���Իش�������¼��Ŀ���������
	//=======================================
	long GetMaxRecordCount();
	bool SetMaxRecordCount(long count);
	
	//=======================================
	// ���λ��
	//=======================================
	enum AdbcCursorLocation GetCursorLocation();
	bool SetCursorLocation(enum AdbcCursorLocation CrLocation = adbcUseClient);
	
	//=======================================
	// �������
	//=======================================
	enum AdbcCursorType GetCursorType();
	bool SetCursorType(enum AdbcCursorType AdbcCursorType = adbcOpenStatic);
	
	//=======================================
	// ������������Ŀǰ����¼��λ��
	//=======================================
	_variant_t GetBookmark();
	bool SetBookmark(_variant_t varBookMark = _variant_t((long)adbcBookmarkFirst));
	
	//=======================================
	// Ŀǰ����¼ָ��ľ���λ��
	//=======================================
	long GetAbsolutePosition();
	bool SetAbsolutePosition(int nPosition);

	long GetAbsolutePage();
	bool SetAbsolutePage(int nPage);

	//=======================================
	// �趨�M��һҳ������¼����
	//=======================================
	long GetPageSize();
	bool SetPageSize(long nPageSize);
	//=======================================
	// �洢�ڱ����������ݴ���������¼��Ŀ
	//=======================================
	bool SetCacheSize(const long& lCacheSize);
	//=======================================
	// �ش� Recordset ���ڰ�������ҳ����������
	//=======================================	
	long GetPageCount();

	//=======================================
	// �ش� Recordset �е�����¼������
	//=======================================
	long GetRecordCount();
	//=======================================
	// �ش� Recordset �е��ֶ���
	//=======================================
	long GetFieldsCount();
	
	//=======================================
	// ���Ӷ��� 
	//=======================================
	CAdoConnect* GetConnection() {return m_pAdoConnect;}
	void SetAdoConnection(CAdoConnect *pAdoConnect);

	//=======================================
	// ��¼������
	//=======================================
	ADODB::_RecordsetPtr& GetRecordset();
	void	SetRecordset(ADODB::_RecordsetPtr ptrRecordset);

	//=======================================
	// �õ����Ĵ�����Ϣ
	//=======================================
	CAString GetLastError();

	//=======================================
	// �ֶ�����
	// �ֶμ����ֶζ���
	//=======================================
	ADODB::FieldsPtr GetFields();
	ADODB::FieldPtr  GetField(long lIndex);
	ADODB::FieldPtr  GetField(LPCTSTR lpszFieldName);
	
	//=======================================
	// ����ֶ���
	//=======================================
	CAString GetFieldName(long lIndex);
	
	//=======================================
	// ����ֶ���������
	//=======================================
	enum AdbcDataType GetFieldType(long lIndex);
	enum AdbcDataType GetFieldType(LPCTSTR lpszFieldName);

	//=======================================
	// ����ֶ�ʵ�ʳ���
	//=======================================
	long  GetFieldAttributes(long lIndex);
	long  GetFieldAttributes(LPCTSTR lpszFieldName);

	//=======================================
	// ��ö�����ֶγ���
	//=======================================
	long  GetFieldDefineSize(long lIndex);
	long  GetFieldDefineSize(LPCTSTR lpszFieldName);

	//=======================================
	// �ֶ�ʵ�ʳ���
	//=======================================
	long  GetFieldActualSize(long lIndex);
	long  GetFieldActualSize(LPCTSTR lpszFieldName);

	//=======================================
	// �ж��ֶ��Ƿ�ΪNULL
	//=======================================
	bool  IsFieldNull(long nIndex);
	bool  IsFieldNull(LPCTSTR lpFieldName);

	//=======================================
	// ���Ɉ���ԭ�еĲ�ѯ��������
	//=======================================
	bool Requery(enum AdbcConnectOption Options = adbcConnectUnspecified);
	bool AdbcResync(enum AdbcAffect AffectRecords = adbcAffectAll, 
				enum AdbcResync ResyncValues = adbcResyncAllValues);   
	//=======================================
	// �ӵײ�����Ͽ��и������ϡ�
	//=======================================
	bool RecordBinding(CADORecordBinding &pAdoRecordBinding);

	//=======================================
	// ���ƶ�Ŀǰ����¼��λ�õ���һ�ʡ����һ�ʡ�
	// ��һ�ʡ�ǰһ�ʵ�λ�á� 
	//=======================================
	bool MoveFirst();
	bool MovePrevious();
	bool MoveNext();
	bool MoveLast();
	//=======================================
	// �ƶ�Ŀǰ����¼��λ��
	//=======================================
	bool Move(long lRecords, _variant_t Start = _variant_t((long)adbcBookmarkFirst));
	
	//=======================================
	// ����ָ���ļ�¼
	//=======================================
	bool Find(LPCTSTR lpszFind, enum AdbcSearchDirection SrDirection = adbcSearchForward);
	bool FindNext();

	//=======================================
	// ����/����־����ļ�
	//=======================================
	bool Save(LPCTSTR strFileName = _T(""), 
			  enum AdbcPersistFormat PsFormat = adbcPersistXML);
	bool Load(LPCTSTR strFileName);
	
	//=======================================
	// �����ֶ�ֵ
	//=======================================
	bool SetValue(const _variant_t Index, const _variant_t pvar ); 
	bool SetValue(long nIndex, const _variant_t value);
	bool SetValue(long nIndex, const CAString value);
	bool SetValue(long nIndex, const double value);
	bool SetValue(long nIndex, const float  value);
	bool SetValue(long nIndex, const long   value);
	bool SetValue(long nIndex, const DWORD  value);
	bool SetValue(long nIndex, const int    value);
	bool SetValue(long nIndex, const short  value);
	bool SetValue(long nIndex, const BYTE   value);
	bool SetValue(long nIndex, const bool   value);
	bool SetValue(long nIndex, const CADateTime value);
	bool SetValue(long nIndex, const CURRENCY value);
	bool SetValue(long nIndex, const char cData);	

	bool SetValueByName(LPCTSTR strFieldName, const _variant_t value);
	bool SetValueByName(LPCTSTR strFieldName, const CAString value);
	bool SetValueByName(LPCTSTR strFieldName, const double value);
	bool SetValueByName(LPCTSTR strFieldName, const float  value);
	bool SetValueByName(LPCTSTR strFieldName, const long   value);
	bool SetValueByName(LPCTSTR strFieldName, const DWORD  value);
	bool SetValueByName(LPCTSTR strFieldName, const int    value);
	bool SetValueByName(LPCTSTR strFieldName, const short  value);
	bool SetValueByName(LPCTSTR strFieldName, const BYTE   value);
	bool SetValueByName(LPCTSTR strFieldName, const bool   value);
	bool SetValueByName(LPCTSTR strFieldName, const CADateTime value);
	bool SetValueByName(LPCTSTR strFieldName, const CURRENCY value);
	bool SetValueByName(LPCTSTR strFieldName, const char cData);	

	//==========================================
	// ����ֶ�ֵ
	//==========================================
	_variant_t GetValue (const _variant_t & Index);
	bool	GetValueByName(CAString strFieldName, VARIANT& vFieldVal);
	bool	GetValueByName(CAString strFieldName, CAString& strData);
	bool	GetValueByName(CAString strFieldName, double& dData);
	bool	GetValueByName(CAString strFieldName, float& fData);
	bool	GetValueByName(CAString strFieldName, long& lData);
	bool	GetValueByName(CAString strFieldName, int& nData);
	bool	GetValueByName(CAString strFieldName, BYTE& byData);
	bool	GetValueByName(CAString strFieldName, char& cData);
	bool	GetValueByName(CAString strFieldName, UINT& unData);
	bool	GetValueByName(CAString strFieldName, DWORD &dwData);
	bool	GetValueByName(CAString strFieldName, bool& bData);
	bool	GetValueByName(CAString strFieldName, CADateTime& tData);
	bool	GetValueByName(CAString strFieldName, CURRENCY& cData);
	bool	GetValueByName(CAString strFieldName, short &nData);	

	bool	GetValue(long nIndex, CAString& strData);
	bool	GetValue(long nIndex, double& dData);
	bool	GetValue(long nIndex, float& fData);
	bool	GetValue(long nIndex, long& lData);
	bool	GetValue(long nIndex, int& nData);
	bool	GetValue(long nIndex, BYTE& byData);
	bool	GetValue(long nIndex, char& cData);	
	bool	GetValue(long nIndex, DWORD &dwData);
	bool	GetValue(long nIndex, UINT& unData);
	bool	GetValue(long nIndex, bool& bData);
	bool	GetValue(long nIndex, CADateTime& tData);
	bool	GetValue(long nIndex, CURRENCY& cData);
	bool	GetValue(long nIndex, short &nData);

	//=======================================
	// BLOB ���ݴ�ȡ 
	//=======================================
	bool AppendChunk(ADODB::FieldPtr pField, LPVOID lpData, UINT nBytes);
	bool AppendChunk(long nIndex, LPVOID lpData, UINT nBytes);
	bool AppendChunk(LPCTSTR strFieldName, LPVOID lpData, UINT nBytes);
	
	bool AppendChunkFile(long nIndex, LPCTSTR lpszFileName);
	bool AppendChunkFile(LPCTSTR strFieldName, LPCTSTR lpszFileName);
	bool AppendChunkString(LPCTSTR strFieldName, LPCTSTR lpszString);
	bool AppendChunkString(long nIndex, LPCTSTR lpszString);

	bool GetChunk(ADODB::FieldPtr pField, LPVOID lpData);
	bool GetChunk(long nIndex, LPVOID lpData);
	bool GetChunk(LPCTSTR strFieldName, LPVOID lpData);
//	bool GetChunk(long nIndex, CBitmap &bitmap);
//	bool GetChunk(LPCTSTR strFieldName, CBitmap &bitmap);

	bool GetChunkFile(LPCTSTR strFieldName, LPCTSTR lpszFileName);
	bool GetChunkFile(long nIndex, LPCTSTR lpszFileName);
	bool GetChunkString(LPCTSTR strFieldName, CAString &strString);
	bool GetChunkString(long nIndex, CAString &strString);
	//========================================
	// ��ʾ�Ƿ�Ҫʹ�� Filter����������
	//========================================
	bool SetFilter(LPCTSTR lpszFilter);

	//========================================
	// ����
	//========================================
	bool SetSort(LPCTSTR lpszCriteria);

	//========================================
	// ȷ���Ƿ� Recordset ����֧ԮĳЩ�ض��Ĺ��ܡ�
	//========================================
	bool Supports(enum AdbcCursorOption CrOptions = adbcAddNew);

	//========================================
	// ����һ�� Recordset ����ĸ�����
	//========================================
	bool Clone(CAdoRecordset *pAdoRecordset);
	ADODB::_RecordsetPtr operator = (ADODB::_RecordsetPtr &ptrRecordset);
	void operator =(CAdoRecordset &AdoRecordset);
};

#endif // !defined(AFX_ADORECORDSET_H__6CDA9FA4_5451_4E41_889D_EAC28CE3AC76__INCLUDED_)
