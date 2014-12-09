// ARecordset.h: interface for the CARecordset class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ARECORDSET_H__E84E56C6_0F47_4892_A4AE_E860824CAD23__INCLUDED_)
#define AFX_ARECORDSET_H__E84E56C6_0F47_4892_A4AE_E860824CAD23__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "AdbcCommDef.h"
class CAString;
class CAdoRecordset;
class CAConnect;
class CADORecordBinding;

class CADateTime;
class CAField;


class CARecordset
{
public:
	CARecordset();
	virtual ~CARecordset();
	CARecordset(CAConnect *pAConnect);

public:
	CAdoRecordset	*m_pAdoRecordset;
	CAConnect		*m_pAConnect;

protected:
	void	Release();

public:
	//=======================================
	// �� Recordset �п���һ��ָ��
	//=======================================
	bool	Open( LPCTSTR lpszSource, CAConnect *pAConnect, 
				  enum AdbcCursorType nCursorType = adbcOpenStatic, 
				  enum AdbcLockType nLockType = adbcLockOptimistic, 
				  enum AdbcCommandType Options = adbcCmdText );
	//=======================================
	// �ر�һ�� Recordset �Լ���ص����
	//=======================================
	bool	Cancel();
	bool	Close();

	//=======================================
	// �������ݿ�
	//=======================================
	CAConnect*	GetConnection();
	void		SetAdoConnection(CAConnect *pAConnect);

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
	// �ش� Recordset �е�����¼������
	//=======================================
	long GetRecordCount();
	//=======================================
	// �ش� Recordset �е��ֶ���
	//=======================================
	long GetFieldsCount();

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
	// ����ֶ���
	//=======================================
	CAString GetFieldName(long lIndex);
	
	//=======================================
	// �����ֶ�ֵ
	//=======================================
	bool SetValue(const _variant_t & Index, const _variant_t  pvar ); 
	bool SetValue(long nIndex, const _variant_t value);
	bool SetValue(long nIndex, LPCTSTR lpszValue);
	bool SetValue(long nIndex, const double value);
	bool SetValue(long nIndex, const float  value);
	bool SetValue(long nIndex, const long   value);
	bool SetValue(long nIndex, const DWORD  value);
	bool SetValue(long nIndex, const int    value);
	bool SetValue(long nIndex, const short  value);
	bool SetValue(long nIndex, const BYTE   value);
	bool SetValue(long nIndex, const bool   value);
	bool SetValue(long nIndex, const CADateTime	value);
	bool SetValue(long nIndex, const CURRENCY value);
	bool SetValue(long nIndex, const char cData);	

	bool SetValueByName(LPCTSTR lpszFieldName, const _variant_t value);
	bool SetValueByName(LPCTSTR lpszFieldName, LPCTSTR lpszValue);
	bool SetValueByName(LPCTSTR lpszFieldName, const double value);
	bool SetValueByName(LPCTSTR lpszFieldName, const float  value);
	bool SetValueByName(LPCTSTR lpszFieldName, const long   value);
	bool SetValueByName(LPCTSTR lpszFieldName, const DWORD  value);
	bool SetValueByName(LPCTSTR lpszFieldName, const int    value);
	bool SetValueByName(LPCTSTR lpszFieldName, const short  value);
	bool SetValueByName(LPCTSTR lpszFieldName, const BYTE   value);
	bool SetValueByName(LPCTSTR lpszFieldName, const bool   value);
	bool SetValueByName(LPCTSTR lpszFieldName, const CADateTime value);
	bool SetValueByName(LPCTSTR lpszFieldName, const CURRENCY value);
	bool SetValueByName(LPCTSTR lpszFieldName, const char cData);	
	
	//==========================================
	// ����ֶ�ֵ
	//==========================================
	_variant_t GetValue (const _variant_t & Index);
	bool GetValueByName(LPCTSTR lpszFieldName, VARIANT& vFieldVal);
	
	CAString GetStrValueByName(LPCTSTR lpszFieldName, bool bTrimRight = false );
	CAString GetStrValue( long nIndex , bool bTrimRight = false );

	bool GetValueByName(LPCTSTR lpszFieldName, double& dData);
	bool GetValueByName(LPCTSTR lpszFieldName, float& fData);
	bool GetValueByName(LPCTSTR lpszFieldName, long& lData);
	bool GetValueByName(LPCTSTR lpszFieldName, int& nData);
	bool GetValueByName(LPCTSTR lpszFieldName, BYTE& byData);
	bool GetValueByName(LPCTSTR lpszFieldName, char& cData);
	bool GetValueByName(LPCTSTR lpszFieldName, UINT& nData);
	bool GetValueByName(LPCTSTR lpszFieldName, DWORD &dwData);
	bool GetValueByName(LPCTSTR lpszFieldName, bool& bData);
	bool GetValueByName(LPCTSTR lpszFieldName, CADateTime& tData);
	bool GetValueByName(LPCTSTR lpszFieldName, CURRENCY& cData);
	bool GetValueByName(LPCTSTR lpszFieldName, short &nData);
	bool GetValueByName(LPCTSTR lpszFieldName, CAString& strData, bool bTrimRight = false);

	bool GetValue(long nIndex, CAString& strData, bool bTrimRight = false);
	bool GetValue(long nIndex, double& dData);
	bool GetValue(long nIndex, float& fData);
	bool GetValue(long nIndex, long& lData);
	bool GetValue(long nIndex, int& nData);
	bool GetValue(long nIndex, BYTE& vFieldVal);
	bool GetValue(long nIndex, char& cData);
	bool GetValue(long nIndex, DWORD &dwData);
	bool GetValue(long nIndex, UINT& nData);
	bool GetValue(long nIndex, bool& bData);
	bool GetValue(long nIndex, CADateTime& tData);
	bool GetValue(long nIndex, CURRENCY& cData);
	bool GetValue(long nIndex, short &nData);

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
	// Ŀǰ����¼�ı༭״̬
	//=======================================
	enum AdbcEditMode GetEditMode();

	//=======================================
	// һ����ѯ���Իش�������¼��Ŀ���������
	//=======================================
	long GetMaxRecordCount();
	bool SetMaxRecordCount(long count);

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
	// ��ö�����ֶγ���
	//=======================================
	long GetFieldDefineSize(long lIndex);
	long GetFieldDefineSize(LPCTSTR lpszFieldName);
	
	//=======================================
	// Ŀǰ����¼���ڵġ�ҳ��������ֵ����
	// ��ָ��Ŀǰ����¼ָ��Ҫ������ҳ��
	//=======================================
	long GetAbsolutePage();
	bool SetAbsolutePage(int nPage);
	
	//=======================================
	// Ŀǰ����¼ָ��ľ���λ��
	//=======================================
	long GetAbsolutePosition();
	bool SetAbsolutePosition(int nPosition);

	//=======================================
	// ��¼������
	//=======================================
	CAdoRecordset*	GetRecordset();
	void			SetRecordset(CAdoRecordset *pAdoRecordset);

	//=======================================
	// �õ����Ĵ�����Ϣ
	//=======================================
	CAString GetLastError();
	//=======================================
	// ����ֶ�ʵ�ʳ���
	//=======================================
	long  GetFieldActualSize(long lIndex);
	long  GetFieldActualSize(LPCTSTR lpszFieldName);

	//=======================================
	// �ж��ֶ��Ƿ�ΪNULL
	//=======================================
	bool  IsFieldNull(long nIndex);
	bool  IsFieldNull(CAString strFieldName);

	//=======================================
	// �ֶ�����
	// �ֶμ����ֶζ���
	//=======================================
	ADODB::FieldsPtr GetFields();
	bool  GetField(long lIndex, CAField *pField , bool bCopyData = true );
	bool  GetField(LPCTSTR lpszFieldName, CAField *pField , bool bCopyData = true );
	
	//=======================================
	// �α�����
	//=======================================
	enum AdbcCursorType	GetCursorType();
	bool 			SetCursorType(enum AdbcCursorType AdbcCursorType = adbcOpenStatic);

	//=======================================
	// �α�λ��
	//=======================================
	enum AdbcCursorLocation	GetCursorLocation();
	bool				SetCursorLocation(enum AdbcCursorLocation CursorLocation = adbcUseClient);
		
	//=======================================
	// ������������Ŀǰ����¼��λ��
	//=======================================
	_variant_t	GetBookmark();
	bool		SetBookmark(_variant_t varBookMark = _variant_t((long)adbcBookmarkFirst));
	bool		SetBookmark(enum AdbcBookmark AdbcBookmark = adbcBookmarkFirst);
	
	//=======================================
	// ����ֶ���������
	//=======================================
	enum AdbcDataType GetFieldType(long lIndex);
	enum AdbcDataType GetFieldType(LPCTSTR lpszFieldName);

	//=======================================
	// ����ֶ�����
	//=======================================
	long  GetFieldAttributes(long lIndex);
	long  GetFieldAttributes(LPCTSTR lpszFieldName);

	//=======================================
	// ���Ɉ���ԭ�еĲ�ѯ��������
	//=======================================
	bool Requery(enum AdbcConnectOption Options = adbcConnectUnspecified);
	//=======================================
	// �ӵײ�����Ͽ��и������ϡ�
	//=======================================
	bool AdbcResync(enum AdbcAffect AffectRecords = adbcAffectAll, 
				enum AdbcResync ResyncValues = adbcResyncAllValues);   
	bool RecordBinding(CADORecordBinding &pAdoRecordBinding);

	//=======================================
	// �����ݱ��� 
	//=======================================
	bool AppendChunk(ADODB::FieldPtr pField, LPVOID lpData, UINT nBytes);
	bool AppendChunk(long nIndex, LPVOID lpData, UINT nBytes);
	bool AppendChunk(LPCTSTR lpszFieldName, LPVOID lpData, UINT nBytes);

	bool AppendChunkFile(long nIndex, LPCTSTR lpszFileName);
	bool AppendChunkFile(LPCTSTR lpszFieldName, LPCTSTR lpszFileName);
	bool AppendChunkString(LPCTSTR lpszFieldName, LPCTSTR lpszString);
	bool AppendChunkString(long nIndex, LPCTSTR lpszString);

	//=======================================
	// ��ó�����
	//=======================================
	bool GetChunk(ADODB::FieldPtr pField, LPVOID lpData);
	bool GetChunk(long nIndex, LPVOID lpData);
	bool GetChunk(LPCTSTR lpszFieldName, LPVOID lpData);
//	bool GetChunk(long nIndex, CBitmap &bitmap);
//	bool GetChunk(CAString strFieldName, CBitmap &bitmap);

	bool GetChunkFile(LPCTSTR lpszFieldName, LPCTSTR lpszFileName);
	bool GetChunkFile(long nIndex, LPCTSTR lpszFileName);
	bool GetChunkString(LPCTSTR lpszFieldName, CAString &strString);
	bool GetChunkString(long nIndex, CAString &strString);
	
	//=======================================
	// ����ָ����¼
	//=======================================
	bool Find(LPCTSTR lpszFind, enum AdbcSearchDirection SrDirection = adbcSearchForward);
	bool FindNext();

	//=======================================
	// �Ѽ�¼������\�����ļ�
	//=======================================
	bool Save(CAString strFileName = _T(""), 
			  enum AdbcPersistFormat PsFormat = adbcPersistXML);
	bool Load(CAString strFileName);


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
	bool Clone(CARecordset *pARecordset);
	CAdoRecordset* operator = (CAdoRecordset *pARecordset);
	void operator =(CARecordset &ARecordset);
};

#endif // !defined(AFX_ARECORDSET_H__E84E56C6_0F47_4892_A4AE_E860824CAD23__INCLUDED_)
