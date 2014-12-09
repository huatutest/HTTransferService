#pragma once
#include "ErrorRecorder.h"
#include "DGStruct.h"

// struct Outside_CheckDog
// {
// 	DWORD dwLable;
// 	TCHAR strCompanyMD5[40];
// 	BYTE  Key[128];				//������Կ
// 	DWORD DogID;				//����
// };

//T3 Business Mode
typedef BOOL (_cdecl *T3BM_MainTestT3Service)(CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_TestT3Service)(CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetXmlInfoFromServ)(int nSize, LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_ApplyAuthorization)(int nSize, LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetUserListfoFromServ)(LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_LoginDVSystem)(LPSTR lpSvrIp, DWORD dwSvrPort,T3_DBS_LoginInfo t3LoginInfo,T3_DBS_RTLoginInfo& t3RtnLoginInfo,  CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_CheckSetupInfo)(LPSTR lpSvrIp, DWORD dwSvrPort,T3_DBS_SetupInfo t3SetupInfo,T3_DBS_RTSetupInfo& t3RtnSetupInfo, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_CheckFilePermission)(T3_DBS_CheckFileInfo t3FilePermission, T3_DBS_RTCheckFileInfo& t3RtnFilePermission, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_CheckFilePassword)(T3_DBS_CheckFileInfo t3CheckInfo, T3_DBS_RTCheckFileInfo& t3RtnData, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_OpenT3File)(T3_DBS_CheckFileInfo t3FilePermission,T3_DBS_RTCheckFileInfo& t3RtnData, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetT3FileInfo)(LPCTSTR lpstrPath, int& nPermission, BOOL& bSetWatermark, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetT3FileRemainDate)(LPCTSTR lpstrPath, LONGLONG& lRemainTime, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_ReadFileInfoFromIni)(LPCTSTR lpstrPath, int& nPermission, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetDogData)(DWORD& dwDogID, char* Key, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetFileInfoFromServ)(T3_DBS_CheckFileInfo t3FileInfo, LPTSTR lpXmlPath, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetWatermarkState)(LPCTSTR lpstrPath, CErrorRecorder& cr);
typedef BOOL (_cdecl *T3BM_GetAccreditInfo)(Outside_CheckDog& DogInfo);

class CT3Business
{
public:
	CT3Business(void);
	~CT3Business(void);

		/*
	�������ܣ�
	��ʼ��Winsock����
	*/
	BOOL InitNetwork(void);

	/*
	�������ܣ�
	ע��Winsock����
	*/
	BOOL UnInitNetwork(void);
	

	BOOL MainTestT3Service(CErrorRecorder& cr);
	/*
	��������:
	�����ⷢ����
	true ������������
	false ������������
	*/
	BOOL TestT3Service(CErrorRecorder& cr);

	/*
	�������ܣ�
	�ӷ��������չ�˾���˺���Ϣ
	*/

	BOOL GetUserListfoFromServ(LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);

		/*
	�������ܣ�
	�ϴ����ܹ�����Ϣ��������
	*/

	BOOL ApplyAuthorization(int nSize, LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);


	/*
	�������ܣ�
	�ϴ��ļ���Ϣ�����ӷ�������ȡ�ļ�ID
	*/
	BOOL GetXmlInfoFromServ(int nSize, LPTSTR lpData,LPTSTR lpXmlPath,CErrorRecorder& cr);


	/*
	�������ܣ�
	��½��������ͨ������ֵt3RtnLoginInfo�ж��Ƿ���ȷ��½��DVʣ�లװ����
	*/
	BOOL LoginDVSystem(LPSTR lpSvrIp, DWORD dwSvrPort,T3_DBS_LoginInfo t3LoginInfo,T3_DBS_RTLoginInfo& t3RtnLoginInfo,  CErrorRecorder& cr);

	/*
	�������ܣ�
	DV��װ��ɺ������������ָ��������޸�ʣ��İ�װ����������0�ɹ���1ʧ��
	*/
	BOOL CheckSetupInfo(LPSTR lpSvrIp, DWORD dwSvrPort,T3_DBS_SetupInfo t3SetupInfo,T3_DBS_RTSetupInfo& t3RtnSetupInfo,CErrorRecorder& cr);

	/*
	��������:
	���ļ�ʱ��ȡ�ļ�Ȩ����Ϣ���Ƿ���Ҫ������֤���Ƿ���Դ򿪣��Լ��ļ���ӡ���޸�Ȩ��
	*/
	BOOL CheckFilePermission(T3_DBS_CheckFileInfo t3FilePermission, T3_DBS_RTCheckFileInfo& t3RtnFilePermission,CErrorRecorder& cr);
	
	/*
	��������:
	���ߴ��ļ�ʱ������У������
	*/
	BOOL CheckFilePassword(T3_DBS_CheckFileInfo t3CheckInfo, T3_DBS_RTCheckFileInfo& t3RtnData, CErrorRecorder& cr);

	/*
	��������:
	���ļ�ʱ��ȡ�ļ�Ȩ����Ϣ���Ƿ���Ҫ������֤���Ƿ���Դ򿪣��Լ��ļ���ӡ���޸�Ȩ�ޣ������Ҫ���룬
	������������Ի��򣬷������뵽������У��
	����ֵ:
	t3RtnFilePermission.bNeedCheckPass 0����Ҫ������֤
	t3RtnFilePermission.nRet  0���� 1 �ļ�Ȩ�޹��� 2�޷��鵽Ȩ����Ϣ 3.�򿪴����þ� 4 ������� 5�˺Ų�����
	*/
	BOOL OpenT3File(T3_DBS_CheckFileInfo t3FilePermission,T3_DBS_RTCheckFileInfo& t3RtnData, CErrorRecorder& cr);

	/*
	�������ܣ�
	���ļ�ʱ������Ǳ�����֤����ini�ļ���ȡȨ���ж��ܷ�򿪣����ڴ򿪺��޸�ini�ļ��е�ֵ
	*/
	BOOL ReadFileInfoFromIni(LPCTSTR lpstrPath,int& nPermission, CErrorRecorder& cr);

	/*
	�������ܣ�
	��ȡ�ļ�Ȩ�ޣ�enum{Read = 0x10,Write =0x20��print = 0x40,};
	*/
	BOOL GetT3FileInfo(LPCTSTR lpstrPath, int& nPermission, BOOL& bSetWatermark, CErrorRecorder& cr);

	BOOL GetT3FileInfo(LPCTSTR lpstrPath, LONGLONG& lRemainTime, CErrorRecorder& cr);

	/*
	�������ܣ�
	ͨ��ע�����ȡ���ź���Կ
	*/
	BOOL GetDogData(DWORD& dwDogID, char* Key, CErrorRecorder& cr);

	/*
	�������ܣ�
	���ӷ���������ȡ�ⷢ�ļ��ľ�����Ϣ
	*/
	BOOL GetFileInfoFromServ(T3_DBS_CheckFileInfo t3FileInfo, LPTSTR lpXmlPath, CErrorRecorder& cr);


	BOOL GetWatermarkState(LPCTSTR lpstrPath, CErrorRecorder& cr);

	BOOL GetAccreditInfo(Outside_CheckDog& DogInfo);

private:
	void InitFunction(HMODULE hInst);

	HMODULE						m_hInst;
	T3BM_MainTestT3Service		m_pMainTestT3Service;
	T3BM_TestT3Service			m_pTestT3Service;
	T3BM_GetXmlInfoFromServ		m_pGetXmlInfoFromServ;
	T3BM_ApplyAuthorization		m_pApplyAuthorization;
	T3BM_GetUserListfoFromServ	m_pGetUserListfoFromServ;
	T3BM_LoginDVSystem			m_pLoginDVSystem;
	T3BM_CheckSetupInfo			m_pCheckSetupInfo;
	T3BM_CheckFilePermission	m_pCheckFilePermission;
	T3BM_CheckFilePassword		m_pCheckFilePassword;
	T3BM_OpenT3File				m_pOpenT3File;	
	T3BM_ReadFileInfoFromIni	m_pReadFileInfoFromIni;
	T3BM_GetT3FileInfo			m_pGetT3FileInfo;
	T3BM_GetT3FileRemainDate	m_pGetT3FileRemainDate;
	T3BM_GetDogData				m_pGetDogData;
	T3BM_GetAccreditInfo		m_pGetAccreditInfo;
	T3BM_GetFileInfoFromServ	m_pGetFileInfoFromServ;
	T3BM_GetWatermarkState		m_pGetWatermarkState;
	
};
