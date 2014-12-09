// PackageFileInfo.h: interface for the CPackageFileInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_PACKAGEFILEINFO_H__730DBF3C_16D9_48B5_ABFC_5D072B42DDC3__INCLUDED_)
#define AFX_PACKAGEFILEINFO_H__730DBF3C_16D9_48B5_ABFC_5D072B42DDC3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <deque>

enum  FileControlMode
{
	FILE_BY_NONE = 0,
	FILE_BY_COUNT,
	FILE_BY_TIME,
};

enum FileEditMode
{
	FILE_READONLY_MODE = 0,
	FILE_EDIT_MODE,
};

class CPackageFileInfo  
{
public:
	CPackageFileInfo();
	virtual ~CPackageFileInfo();

	void Init(LPCTSTR strFileName,LPCTSTR strPathName,LPCTSTR strFileGUID);
	void ResetContent();

	void SetFileName(LPCTSTR strFileName);
	void SetPathName(LPCTSTR strPathName);
	void SetFileGUID(LPCTSTR strFileGUID);

	void WriteData(CMemFile& file);
	void ReadData(CMemFile& file);

	BOOL IsFileValid(SYSTEMTIME tFirstUser,SYSTEMTIME tCurrent);

	void GetLicFromSystem();		//��ϵͳ�ļ�����ע���õ����µ���Ȩ

public:
	LPTSTR m_lpszFileName;			//�ļ���
	LPTSTR m_lpszPathName;			//ȫ·����
	LPTSTR m_lpszFileGUID;			//�ļ�ID

	int		_ctrlType;				//��������
	int		m_nCounts;				//���ݿ������͵Ĳ�ͬ�������Ǵ���
	int		m_nDays;				//����
	int		_editMode;				//�༭ģʽ
	BOOL	m_bCanPrint;			//�Ƿ���Դ�ӡ
};

typedef std::deque<CPackageFileInfo*> PACKAGE_FILE_INFO;

#endif // !defined(AFX_PACKAGEFILEINFO_H__730DBF3C_16D9_48B5_ABFC_5D072B42DDC3__INCLUDED_)
