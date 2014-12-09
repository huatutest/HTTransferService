// ComputerInfo.h: interface for the CComputerInfo class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_COMPUTERINFO_H__B390ADF6_8B25_4C98_B3DD_1E35A0EDED69__INCLUDED_)
#define AFX_COMPUTERINFO_H__B390ADF6_8B25_4C98_B3DD_1E35A0EDED69__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

enum
{
	BACKUP_CRYPTED_FILE = 0x1, //�����ݼ����ļ�
	BACKUP_ALL_FILE	= 0x2,	   //���������ļ�
	BACKUP_RIGHT_NOW = 0x4,	   //��ʱ����
	BACKUP_PLAN = 0x8,		   //ʹ�üƻ�����
		
};

enum
{
	EVERY_DAY = 0x1,			//ÿ�챸��
	EVERY_WEEK = 0x2,			//ÿ�ܱ���
	EVERY_MONTH = 0x3,			//ÿ�±���
};

class CBackupPlanInfo
{
public:
	CBackupPlanInfo();
	virtual ~CBackupPlanInfo();

	int m_nPlanType;		//�ƻ����������
	
	SYSTEMTIME m_StartTime;	//�ƻ���ʼ��ʱ��	
	
	
	SYSTEMTIME m_StartMonth; //�ƻ���ʼ��ÿ������
};

class CComputerBackupInfo  
{
public:
	CComputerBackupInfo();
	virtual ~CComputerBackupInfo();
	
public:

	LPSTR m_lpszComputerName;	//�������
	LPSTR m_lpszComputerIP;		//�����IP
	LPSTR m_lpszLoginName;		//�������¼�ʺ�

	int	m_nBackupOption;		//����ѡ��
	LPSTR m_lpszFilter;			//���˲���
	LPSTR m_lpszServerIP;		//�ļ����ݷ�������IP��ַ
	
	CBackupPlanInfo* m_pPlanInfo;	//�ƻ���Ϣ

};


#endif // !defined(AFX_COMPUTERINFO_H__B390ADF6_8B25_4C98_B3DD_1E35A0EDED69__INCLUDED_)
