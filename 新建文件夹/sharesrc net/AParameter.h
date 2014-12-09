// AParameter.h: interface for the CAParameter class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_APARAMETER_H__69BBF5B0_02DE_4B3F_B5D6_31745AB6492C__INCLUDED_)
#define AFX_APARAMETER_H__69BBF5B0_02DE_4B3F_B5D6_31745AB6492C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
class CAString;

class CAdoParameter;
class CADateTime;

class CAParameter		
{
public:
	CAParameter();
	virtual ~CAParameter();
	CAParameter(enum AdbcDataType Type, long lSize, enum AdbcParaDirection Direction, CAString strName);

public:
	CAdoParameter *m_pAdoParameter;

	CAdoParameter* GetParameter();
	CAdoParameter* operator =(CAdoParameter *pAdoParameter);

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

#endif // !defined(AFX_APARAMETER_H__69BBF5B0_02DE_4B3F_B5D6_31745AB6492C__INCLUDED_)
