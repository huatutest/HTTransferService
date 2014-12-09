// AdoParameter.h: interface for the CAdoParameter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ADOPARAMETER_H__926454CA_4418_47D5_B966_9BB66A4C4264__INCLUDED_)
#define AFX_ADOPARAMETER_H__926454CA_4418_47D5_B966_9BB66A4C4264__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CAString;
class CADateTime;

class CAdoParameter
{
public:
	CAdoParameter();
	virtual ~CAdoParameter();
	CAdoParameter(enum AdbcDataType Type, long lSize, enum AdbcParaDirection Direction, CAString strName);

	ADODB::_ParameterPtr GetParameter();
	ADODB::_ParameterPtr& operator =(ADODB::_ParameterPtr& pParameter);

public:	
	ADODB::_ParameterPtr	m_ptrParameter;

public:
	//========================================
	// ���������
	//========================================
	CAString GetName();
	BOOL SetName(CAString strName);

	//========================================
	// ����ľ���
	//========================================
	BOOL SetPrecision(char nPrecision);

	//========================================
	// �����С��λ��
	//========================================
	BOOL SetNumericScale(int nScale);

	//========================================
	// �Ƿ�� Parameter ��������������߶����ԡ�
	// �Լ��Ƿ����ǳ���Ļش�ֵ�� 
	//========================================
	enum AdbcParaDirection GetDirection();
	BOOL SetDirection(enum AdbcParaDirection Direction);

	//========================================
	// Parameter ��ֵ�Ĵ�С����λ��Byte���� 
	//========================================
	int GetSize();
	BOOL SetSize(int size);

	//========================================
	// Parameter ��������̬�� 
	//========================================
	enum AdbcDataType GetType();
	BOOL SetType(enum AdbcDataType Type);

	//========================================
	// ���ָ����Parameter��ֵ 
	//========================================
	BOOL GetValue(CADateTime &value);
	BOOL GetValue(CAString &value);
	BOOL GetValue(double &value);
	BOOL GetValue(long &value);
	BOOL GetValue(int &value);
	BOOL GetValue(short &value);
	BOOL GetValue(BYTE &value);
	BOOL GetValue(bool &value);

	//========================================
	// ����ָ��Parameter��ֵ 
	//========================================
	BOOL SetValue(const float &value);
	BOOL SetValue(const short &value);
	BOOL SetValue(const BYTE &value);
	BOOL SetValue(const CADateTime &value);
	BOOL SetValue(const CAString &value);
	BOOL SetValue(const double &value);
	BOOL SetValue(const long &value);
	BOOL SetValue(const int &value);
	BOOL SetValue(const bool &value);
	BOOL SetValue(const _variant_t &value);
};

#endif // !defined(AFX_ADOPARAMETER_H__926454CA_4418_47D5_B966_9BB66A4C4264__INCLUDED_)
