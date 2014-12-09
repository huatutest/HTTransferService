#pragma once
#include "ErrorRecorder.h"
#include <string>
using namespace std;
#include "AString.h"
#pragma  comment(lib,"ws2_32.lib")

#ifndef LEN_NAME
#define LEN_NAME 128
#endif
struct DG_Approval
{
	int nType;
	int nTempID;
	TCHAR strTempName[LEN_NAME];
};

typedef std::deque<DG_Approval> deqDGApproval;
#include "DGStruct.h"

typedef BOOL (_cdecl *DGLP_CheckUserPassword)(LPTSTR strUser,LPTSTR strPass,LPSTR lpIp,DWORD dwPort,CErrorRecorder& cr); 
typedef BOOL (_cdecl *DGLP_TestServer)(LPSTR lpIp,UINT uPort,LPTSTR lpRetStr ,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_TestLogServer)(LPSTR lpIp,UINT uPort, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_TestValidateServer)(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_TestUpdateServer)(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_TestPermissionServer)(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_SendData)(LPSTR lpIP,UINT uPort,LPTSTR lpCmd,LPVOID lpData, int nLen, CErrorRecorder& cr);
typedef int (_cdecl *DGLP_ModifyUserPass)(LPCTSTR strUser,LPCTSTR strPass,LPSTR lpIp,DWORD dwPort,LPTSTR strNewPass, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_CheckDogDefault)(LPSTR lpIP,LPTSTR lpLoginName,LPTSTR lpClientId,DWORD dwPort, Offline_Info2& outInfo, CErrorRecorder& cr); 
typedef BOOL (_cdecl *DGLP_CheckDogInfo)(LPTSTR strUser,LPTSTR strPass,LPSTR strIP, LPTSTR lpClientId,DWORD dwPort, BOOL& bConnect, Offline_Info2& outInfo, CErrorRecorder& cr);
typedef int (_cdecl *DGLP_GetOfflineInfo)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR strLoginName, CErrorRecorder& cr);
typedef int (_cdecl *DGLP_GetOfflineInfo1)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR strLoginName, LPTSTR lpCLientId, CErrorRecorder& cr);
typedef int (_cdecl *DGLP_RequestOutofNetWork)(LPSTR lpSvrIp, DWORD dwSvrPort, LPTSTR lpClientID,CErrorRecorder& cr);
typedef int	(_cdecl *DGLP_RequestOutofNetWork1)(LPSTR lpSvrIp, DWORD dwSvrPort, LPTSTR lpClientID,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_GetSystemParameter)(LPSTR lpSvrIp, DWORD dwSvrPort,int &nFlushInfo, int &nCheckDog, int &nNetError ,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_GetDGWebSetFile)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpPath, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_SendArrayData)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,int nArraryCount,LPVOID lpArray, int nLen, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_CheckSoftOffline)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpUser, LPTSTR lpClientId,BOOL &bHaveSoftOffline, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_SetAlertsInfo)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpUser, BOOL bRemindOnce,LPTSTR lpMinute, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_UploadFileToServer)(LPSTR lpSvrIp, DWORD dwSvrPort,int nRecordType, LPTSTR lpPath, LPTSTR lpUserName, LPTSTR lpServerFilePath,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_CheckOfflineInfo)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpClientId,BOOL bAddDogCount,LPTSTR lpUserName, int& nType,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_SendArrayFiles)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,int nArraryCount,wstring* strFiles, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_RecvUserCfgFile)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUserName, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_RecvNewestInitData)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUsrName, DG_Approval* deqDGApprovalList, int& nLen,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_RecvDGLandingInitFile)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,CAString strCommand,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLP_CheckFirstLogin)(LPSTR lpSvrIp, DWORD dwSvrPort ,LPCTSTR lpUser, BOOL& bFirstLogin,CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLP_SubmitFirstLogin)(LPSTR lpSvrIp, DWORD dwSvrPort ,LPCTSTR lpUser, CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLP_RecvWarterMarkModule)(LPSTR lpSvrIp,DWORD dwSvrPort,CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLP_GetModules)(LPSTR lpSvrIp, DWORD dwSvrPort ,DWORD& dwModules, CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLP_SendDSMFiles)(LPSTR lpSvrIp, DWORD dwSvrPort ,LPTSTR pXmlPath, CErrorRecorder &cr);

typedef BOOL (_cdecl *DGLP_GetRoleCfgFile)(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUserName, CErrorRecorder& cr);

class CDGLSupportPackage
{
public:
	CDGLSupportPackage(void);
	~CDGLSupportPackage(void);

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

	/*
	��������:
	���������֤�û������Ƿ���ȷ
	����:
	strUser :�û���
	strPass :�û�����
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	����ֵ:
	true ������ȷ
	false �������
	*/
	BOOL CheckUserPassword(LPTSTR strUser,LPTSTR strPass,LPSTR lpIp,DWORD dwPort,CErrorRecorder& cr);

	/*
	��������:
	���Է���
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	lpRetStr: ��������֤�ַ���
	����ֵ:
	true ������������
	false ������������
	*/
	BOOL TestServer(LPSTR lpIp,UINT uPort, LPTSTR lpRetStr ,CErrorRecorder& cr);

	/*
	��������:
	������־����
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	����ֵ:
	true ������������
	false ������������
	*/
	BOOL TestLogServer(LPSTR lpIp,UINT uPort, CErrorRecorder& cr);
	/*
	��������:
	������֤�����Ƿ���������
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	����ֵ:
	true ������������
	false ������������
	*/
	BOOL TestValidateServer(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
	/*
	��������:
	���Ը��·����Ƿ���������
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	����ֵ:
	true ������������
	false ������������
	*/
	BOOL TestUpdateServer(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
	/*
	��������:
	����Ȩ�޷����Ƿ���������
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	cr		:���󼯶���
	����ֵ:
	true ������������
	false ������������
	*/
	BOOL TestPermissionServer(LPSTR lpIP,UINT uPort, CErrorRecorder& cr);
	/*
	��������:
	�����������.
	����:
	lpIp	:������Ip
	dwPort	:�������˿�
	lpCmd	:ͨѶָ��
	lpData	:����ָ��
	nLen	:���ݳ���
	cr		:���󼯶���
	*/
	BOOL SendData(LPSTR lpIP,UINT uPort,LPTSTR lpCmd,LPVOID lpData, int nLen, CErrorRecorder& cr);
	/*
	��������:
	�޸��û�������
	����:
	strUser :�û���
	strPass :�û�����
	lpIp	:������Ip
	dwPort	:�������˿�
	strNewPass :������
	cr		:���󼯶���
	*/
	int ModifyUserPass(LPCTSTR strUser,LPCTSTR strPass,LPSTR lpIp,DWORD dwPort,LPTSTR strNewPass, CErrorRecorder& cr);
		/*
	��������:
	��֤Ĭ�ϵ�¼����Ϣ
	����:
	lpLoginName :�û���
	lpIp	:������Ip
	dwPort	:�������˿�
	lpClientId :�ͻ���id��
	outInfo	:��ȡ�ṹ��Ϣ
	cr		:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL CheckDogDefault(LPSTR lpIP,LPTSTR lpLoginName,LPTSTR lpClientId,DWORD dwPort, Offline_Info2& outInfo, CErrorRecorder& cr);
	/*
	��������:
	��֤��½�û���½��Ϣ
	����:
	lpLoginName :�û���
	strPass		:�û�����
	lpIp	:������Ip
	dwPort	:�������˿�
	lpClientId :�ͻ���id��
	outInfo	:��ȡ�ṹ��Ϣ
	cr		:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL CheckDogInfo(LPTSTR strUser,LPTSTR strPass,LPSTR strIP, LPTSTR lpClientId,DWORD dwPort, BOOL& bConnect, Offline_Info2& outInfo, CErrorRecorder& cr);
	/*
	��������:
	��ȡ������Ϣ
	*/
	int GetOfflineInfo(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR strLoginName, CErrorRecorder& cr);
	int GetOfflineInfo1(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR strLoginName, LPTSTR lpCLientId, CErrorRecorder& cr);
	/*
	��������:
	Ӧ�����������Ƿ�ɹ�
	*/
	int RequestOutofNetWork(LPSTR lpSvrIp, DWORD dwSvrPort, LPTSTR lpClientID,CErrorRecorder& cr);
	int RequestOutofNetWork1(LPSTR lpSvrIp, DWORD dwSvrPort, LPTSTR lpClientID,CErrorRecorder& cr);
	/*
	��������:
	��ȡϵͳ����
	����:
	nFlushInfo		:ˢ�����ü��
	nCheckDog		:���ӹ�������
	nNetError		:��������
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL GetSystemParameter(LPSTR lpSvrIp, DWORD dwSvrPort,int &nFlushInfo, int &nCheckDog, int &nNetError ,CErrorRecorder& cr);
	/*
	��������:
	��ȡweb�����ļ�
	����:
	lpPath			:��������·��·��
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL GetDGWebSetFile(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpPath, CErrorRecorder& cr);
	/*
	��������:
	����һ������ṹ��������
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpCmd			:Э������
	nArraryCount	:�������
	lpArray			:����ͷ��ַ
	nLen			:����Ԫ�س���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL SendArrayData(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,int nArraryCount,LPVOID lpArray, int nLen, CErrorRecorder& cr);
	/*
	��������:
	����Ƿ�������
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpUser			:��¼��
	lpClientId		:�ͻ���ID��
	bHaveSoftOffline:�Ƿ��д�������
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL CheckSoftOffline(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpUser, LPTSTR lpClientId,BOOL &bHaveSoftOffline, CErrorRecorder& cr);
	/*
	��������:
	���õ�����Ϣ����
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpUser			:��¼��
	bRemindOnce		:������һ��
	lpMinute		:���Ѽ��(����)
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL SetAlertsInfo(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpUser, BOOL bRemindOnce,LPTSTR lpMinute, CErrorRecorder& cr);
	/*
	��������:
	�ϴ��ļ���������
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	nRecordType		:�ļ�����
	lpPath			:�ļ�·��
	lpUserName		:��¼��
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL UploadFileToServer(LPSTR lpSvrIp, DWORD dwSvrPort,int nRecordType, LPTSTR lpPath, LPTSTR lpUserName, LPTSTR lpServerFilePath,CErrorRecorder& cr);
	/*
	��������:
	ʹ���ļ�����ʱ,�������У����Ϣ
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpClientId		:�ͻ���ID
	bAddDogCount	:
	lpUserName		:��¼��
	nType			:У��������
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL CheckOfflineInfo(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpClientId,BOOL bAddDogCount,LPTSTR lpUserName, int& nType,CErrorRecorder& cr);
	/*
	��������:
	����������������ļ�
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpCmd			:Э������
	nArraryCount	:�������
	strFiles		:·������ͷ��ַ
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL SendArrayFiles(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,int nArraryCount,wstring* strFiles, CErrorRecorder& cr);
	
		/*
	��������:
	��ȡ�û�CFG�ļ���Ϣ���浽Normal.cfg
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	lpCmd			:Э������ "GetUserCfgFile2"
	strUserName		:�û���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL RecvUserCfgFile(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUserName, CErrorRecorder& cr);

	/*
	��������:
	��ȡ��ؼ���Ini��Ϣ
	����:
	lpSvrIp			:���·�����Ip
	dwSvrPort		:���·������˿�
	lpCmd			:Э������ "GetDGLandingIni"
	strCommand		:�ַ���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL RecvDGLandingInitFile(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd,CAString strCommand,CErrorRecorder& cr);

	/*
	��������:
	����ApprovalList.ini�����ļ�
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�+3
	lpCmd			:Э������ "GetUpdateApprovalList"
	strUserName		:�û���
	deqDGApprovalList����Ž�����Ϣ��ָ��
	nLen			:DG_Approval�������ݵĸ���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL RecvNewestInitData(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUsrName, DG_Approval* deqDGApprovalList, int& nLen,CErrorRecorder& cr);
	/*
	��������:
	�ж��û��Ƿ����״ε�½
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	strUserName		:�û���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL CheckFirstLogin(LPSTR lpSvrIp, DWORD dwSvrPort ,LPCTSTR lpUser, BOOL& bFirstLogin,CErrorRecorder &cr);

	/*
	��������:
	�ύ����,�û��Ѿ��״ε�½
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	strUserName		:�û���
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL SubmitFirstLogin(LPSTR lpSvrIp, DWORD dwSvrPort ,LPCTSTR lpUser, CErrorRecorder &cr);

		/*
	��������:
	�ύ����,�û��Ѿ��״ε�½
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL RecvWarterMarkModule(LPSTR lpSvrIp, DWORD dwSvrPort , CErrorRecorder &cr);

	
	/*
	��������:
	��ȡ����������װģ��
	����:
	lpSvrIp			:������Ip
	dwSvrPort		:�������˿�
	dwModules		:ģ��flag
	cr				:���󼯶���
	����ֵ:
	ture�ɹ�,false�д���.
	*/
	BOOL GetModules(LPSTR lpSvrIp, DWORD dwSvrPort ,DWORD& dwModules, CErrorRecorder &cr);

	BOOL SendDSMFiles(LPSTR lpSvrIp, DWORD dwSvrPort ,LPTSTR pXmlPath, CErrorRecorder &cr);

	BOOL GetRoleCfgFile(LPSTR lpSvrIp, DWORD dwSvrPort,LPTSTR lpCmd, CAString strUserName, CErrorRecorder &cr);

private:
	void InitFunction(HMODULE hInst);

	HMODULE								m_hInst;
	DGLP_CheckUserPassword			m_pCheckUserPassword;
	DGLP_TestServer						m_pTestServer;
	DGLP_TestLogServer					m_pTestLogServer;
	DGLP_TestValidateServer			m_pTestValidateServer;
	DGLP_TestUpdateServer			m_pTestUpdateServer;
	DGLP_TestPermissionServer		m_pTestPermissionServer;
	DGLP_SendData						m_pSendData;
	DGLP_ModifyUserPass				m_pModifyUserPass;
	DGLP_CheckDogDefault			m_pCheckDogDefault;
	DGLP_CheckDogInfo					m_pCheckDogInfo;
	DGLP_GetOfflineInfo				m_pGetOfflineInfo;
	DGLP_GetOfflineInfo1				m_pGetOfflineInfo1;
	DGLP_RequestOutofNetWork		m_pRequestOutofNetWork;
	DGLP_RequestOutofNetWork1	m_pRequestOutofNetWork1;
	DGLP_GetSystemParameter		m_pGetSystemParameter;
	DGLP_GetDGWebSetFile			m_pGetDGWebSetFile;
	DGLP_SendArrayData				m_pSendArrayData;
	DGLP_CheckSoftOffline				m_pCheckSoftOffline;
	DGLP_SetAlertsInfo					m_pSetAlertsInfo;
	DGLP_UploadFileToServer			m_pUploadFileToServer;
	DGLP_CheckOfflineInfo				m_pCheckOfflineInfo;
	DGLP_SendArrayFiles				m_pSendArrayFiles;
	DGLP_RecvUserCfgFile				m_pRecvUserCfgFile;
	DGLP_GetRoleCfgFile				m_pGetRoleCfgFile;
	DGLP_RecvDGLandingInitFile		m_pRecvDGLandingInitFile;
	DGLP_RecvNewestInitData		m_pRecvNewestInitData;
	DGLP_CheckFirstLogin				m_pCheckFirstLogin;
	DGLP_SubmitFirstLogin				m_pSubmitFirstLogin;
	DGLP_RecvWarterMarkModule   m_pRecvWarterMarkModule;
	DGLP_GetModules					m_pGetModules;
	DGLP_SendDSMFiles					m_pSendDSMFiles;
};
