// DeleteFile.h: interface for the CDeleteFile class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DELETEFILE_H__FE12FA3E_FB2E_44DC_AA1A_3A097F828493__INCLUDED_)
#define AFX_DELETEFILE_H__FE12FA3E_FB2E_44DC_AA1A_3A097F828493__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "UpdateBaseClass.h"

enum
{
	DELETE_DIRECT = 1,		//ֱ��ɾ��
	DELETE_MOVE = 2,		//�ƶ���������ɾ��
	DELETE_UNREGSERVER = 4, //��ע�����
	DELETE_UNREG = 8,		//��ע��
};

class CDeleteFile : public CUpdateBaseClass
{
public:
	CDeleteFile();
	virtual ~CDeleteFile();

	void MakeDestFilePath();

	int m_nDeleteMode;				//ɾ��ģʽ

	LPTSTR m_lpszDestFileName;		//���·��
	int    m_nPathType;				//·������
};

#endif // !defined(AFX_DELETEFILE_H__FE12FA3E_FB2E_44DC_AA1A_3A097F828493__INCLUDED_)
