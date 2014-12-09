// RightObject.h: interface for the CRightObject class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RIGHTOBJECT_H__C44AF987_5719_4701_BE6E_89936E077CB8__INCLUDED_)
#define AFX_RIGHTOBJECT_H__C44AF987_5719_4701_BE6E_89936E077CB8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include <map>

using namespace std;

enum
{
	RIGHT_NORMAL,		//����Ȩ��
	RIGHT_LOG,			//��־Ȩ��
	RIGHT_FILE,			//�ļ�Ȩ��
	RIGHT_RIGHT,		//��ȨȨ��
	RIGHT_SPEC,			//����Ȩ��
	RIGHT_MAIL,			//�ʼ�Ȩ��
};

class CRightObject  
{
public:
	CRightObject();
	virtual ~CRightObject();
	
	TCHAR m_strRightName[32];   //Ȩ������
	TCHAR m_strRightDes[256];	//����
	DWORD m_dwFeature;			//Ȩ������
	DWORD m_dwPara;				//Ȩ�޲���	3.0�汾�����˲���
	int	  m_nRightType;			//Ȩ������
};

typedef map<int,CRightObject*>  MAP_RIGHT;

#endif // !defined(AFX_RIGHTOBJECT_H__C44AF987_5719_4701_BE6E_89936E077CB8__INCLUDED_)
