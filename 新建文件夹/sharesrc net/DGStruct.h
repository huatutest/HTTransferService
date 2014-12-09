#pragma once

#define LEN_MAX 8000
#ifndef LEN_NAME
#define LEN_NAME	128
#endif


#ifndef LEN_TIME
#define LEN_TIME	32
#endif
#include <vector>
using namespace std;

//ipc name
#ifndef		IPC_Name_LocalUpdateService					
#define		IPC_Name_LocalUpdateService					"HTLocalUpdateService"
#endif

#ifndef IPC_Name_HTLUpdateService					
#define	IPC_Name_HTLUpdateService						"HTLUpdateService"
#endif

#ifndef IPC_Name_DGLocalLog
#define IPC_Name_DGLocalLog								"DGLocalLogService"
#endif

#ifndef IPC_Name_DGLicense
#define IPC_Name_DGLicense								"DGLocalLicenseModule"
#endif

#ifndef HT_PROINFO
#define HT_PROINFO

#define HTP_H3			 0
#define HTP_H5			 1
#define HTP_H7			 2

#define HTV_H3_Standard	 1
#define HTV_H3_Group	 2

#define HTM_LevelMgr	 0x1
#define HTM_DGFlow		 0x2
#define HTM_Authorize	 0x4
#define HTM_Outside		 0x8

#endif
enum DG_ERROR_RECORDER
{
	//DGCrypt�ļ���������
	DGCrypt_SocketConnectError		=1001,//socket��������ʱ����
	DGCrypt_UserModalError,				  //�û�������ʾʧ��
	DGCrypt_RecvDataFilure,				//�ڳ�ʼ�û���Ϣ��ʱ��������ʧ��
	DGCrypt_DecryptAppError,			//���ļ����ɽ��в���
	DGCrypt_OffLineCannotDecrypt,		//����״̬�²��ɽ����ļ�
	DGCrypt_OperModeError,				//ѡ��Ĳ���ģʽ����ȷ
	DGCrypt_SendDeryptFileFailure,		//���ͽ����ļ�ʧ��
	DGCrypt_DonotFindFile,				//û�з����ļ�
	DGCrypt_DonotFileFirectory,			//û�з����ļ�·��
	DGCrypt_EncryptZIPFailure,			//����ѹ���ļ�ʧ��

	DGCrypt_DncryptZIPFailure,			//����ѹ���ļ�ʧ��
	DGCrypt_CopyFileError,				//�����ļ���������
	DGCrypt_HavenotSelectOper,			//û��ѡ�����
	DGCrypt_CreateCompressProcessToTempFailed,//������ѹѹ���ļ�����ʱ�ļ��н���ʧ��
	DGCrypt_EncryptedFileError,			//�ļ��Ѿ�������
	DGCrypt_DncryptedFileError,			//�ļ����Ǽ����ļ�
	DGCrypt_NoPermissionToDecryptFile,	//û��Ȩ�޽����ļ�
	DGCrypt_TestLogServerSocketFailure,	//������־����socket����ʧ��
	DGCrypt_TestLogServerRcvDataFailure,//������־�����������ʧ��
	DGCrypt_LogServerFailure,			//���Գ���־����ʧ��

	DGCrypt_AuthorServerNoConnect,		//��Ȩ����û������
	DGCrypt_AuthorServerSocketConnectFailure,//��Ȩ����û������
	DGCrypt_AuthorServerGetDataFailure,	//��Ȩ������������ʧ��
	DGCrypt_AuthorServerGetValueFailure,//��Ȩ�����ȡֵʧ��
	DGCrypt_GetAuthorPermisioneFailure,	//��ȡ��ȨȨ��ʧ��
	DGCrypt_AuthorFileOffLine,			//�������ܽ�����Ȩ�ļ�
	DGCrypt_AuthorFileNoDecryptPermision,//����Ȩ�ļ�û�н���Ȩ��
	DGCrypt_GetLoginNameFailreFromRrg,	//��ע����л�ȡlogin��ʧ��
	DGCrypt_GetSystemInfoFailure,		//��ȡ�����ڴ�ֵʧ��
	DGCrypt_OpenFileMappingFailure,		//�򿪹����ڴ�ʧ��

	DGCrypt_InitUserInfoFailure,		//��ʼ���û���Ϣʧ��
	DGCrypt_OpenFileFailure,			//���ļ�ʧ��
	DGCrypt_GetUserModelFailure,		//��ȡ�û�ģʽʧ��,
	DGCrypt_GetLeveTypelFailure,		//��ȡ�ļ��ȼ�����ʧ��
	DGCrypt_GetFileLevelFailure,		//��ȡ�ļ��ȼ���Ϣʧ��
	DGCrypt_GetFileAuthorGuidFailure,	//��ȡ�ļ���ȨGUIDʧ��
	DGCrypt_ChangeLevelHavenotFile,		//û�з��ֿ��Ե����ȼ����ļ�
	DGCrypt_ChangeLevelFileNoEncrypt,	//�����ȼ����ļ����Ǽ����ļ�
	DGCrypt_GetOffLineInfoFailure,		//��ȡ���������ʧ��,
	DGCrypt_HaveNotPermissionChangeLevel,//û�е����ȼ���Ȩ��

	DGCrypt_HaveNotThisFile,			//����������ļ�
	DGCrypt_HavaNotConnectClient,		//û�����ӿͻ���
	DGCrypt_GetSystemInfoFailed,		//��ȡ�����ڴ����Ϣʧ��
	DGCrypt_CreateConnectSocketFailed,	//��������Socketʧ��
	DGCrypt_RecvLong2StringDataFailed,	//����Long2���������ʧ��
	DGCrypt_GetUserInfoError,			//��ȡ�û���Ȩ����Ϣ����
	DGCrypt_CreateDeviceError,			//���豸ʧ��
	DGCrypt_GetSpeFolderPathFailed,		//��ȡ�����ļ�·��ʧ��
	DGCrypt_LoadOfflineConfigInfoFailed,//��������������Ϣʧ��
	DGCrypt_GetClientStateFailed,		//��ȡ�û�������Ϣʧ��

	DGCrypt_OpenRegFailed,				//��ע����ȡ������Ϣʧ��
	DGCrypt_InitWinSockFailed,			//��ʼ����������ʧ��
	DGCrypt_SocketStoreVersionError,	//WindowSocker�汾����
	DGCrypt_DogExistHaveNotMappingValue,//�����ڵ���û�л�ȡ�������ڴ��ֵ
	DGCrypt_CanccelEnterDecrypt,		//����ȡ�����������ļ�����
	DGCrypt_GetUserNameFailed,			//��ȡ�û���ʧ��
	DGCrypt_OpenRegGetUserInfoFailed,	//��ע����ȡ�û���Ϣʧ��
	DGCrypt_ReadRegLogServiceFailed,	//��ȡע�������־����ʧ��
	DGCrypt_LogServiceError,			//��־�������
	DGCrypt_ThereAreNotSelectAnyFile,	//û��ѡȡ�κ��ļ����в���

	DGCrypt_HaveNotGetUSerModal,		//�]��ȡ����֯�ṹ
	DGCrypt_SocketCreateFailed,			//Socket����ʧ��
	DGCrypt_InitNetServiceFailed,		//��ʼ���������ʧ��
	DGCrypt_CleanNetSocketFailed,		//ע��Windows Socketʧ��
	DGCrypt_LoadDGLocalSupportDllFailed,//����DGlocalSupportDllʧ��
	DGCrypt_NoFileTypeCanOperate,		//û�пɲ������ļ�����
	DGCrypt_EncryptFileFailed,			//��֧�ֶԴ��ļ����в���
	DGCrypt_DecryptFileFailed,			//�����ļ�ʧ��
	DGCrypt_FileHadEncrypted,			//�ļ��Ѿ�������
	DGCrypt_NoConnctAuthortionService,	//û��������Ȩ����

	DGCrypt_OfflineCanNotUploadFile,	//��������²��ϴ��ļ�
	DGCrypt_UploadEncryptFileFailed,	//����ʱ�ϴ�����ʧ��
	DGCrypt_UploadPermisiontFileFailed,	//����״̬�²��ϴ���Ȩ�ļ�����
	DGCrypt_OfflineCanNotUploadPermissionFile,//��������²��ϴ���Ȩ�ļ�����
	DGCrypt_NoPrivDecryptFile,			//û��Ȩ�޽����ļ�
	DGCrypt_ConnectServiceFailedPassowrdOrUserNameError,//���ӷ���ʧ�ܣ�Ip��˿ڴ���
	DGCrypt_CheckDogInfo_ERROR,			//��ȡ�û���Ȩ��ʧ��
	DGCrypt_FileHaveNotEncrypted,		//�ļ����Ǽ����ļ�
	DGCrypt_NoAllowOperateToFile,		//�ļ���֧�ָò���



	//DGClientSet����
	DGClientSet_GetDGServerIniInfoFailure = 2001,	//��ȡDGServer.ini�������Ϣ�ļ�ʧ��
	DGClientSet_GetSpeFolderPathFailure,//��ȡ�����ļ���·��ʧ��
	DGClientSet_LoginNameIsEmpty,		//�����û���Ϊ��
	DGClientSet_LoginPasswordEmpty,		//��������Ϊ��
	DGClientSet_TestLogServerFailure,	//��־����ʧ��
	DGClientSet_ConncetDatabaseFailure,	//�������ݿ�ʧ��
	DGClientSet_LoginPasswordError,		//�����������
	DGClientSet_GetHostIPFailed,		//��ȡ������IPʧ��
	DGClientSet_FindControldedProcess,	//�����ܿس����˳�������
	DGClientSet_HavenotGetPort,			//û����ע����﷢�ֶ˿ں�

	DGClientSet_LoginNameError,			//�����˺Ŵ���
	DGClientSet_PasswordDonotEmpty,		//���벻��Ϊ��
	DGClientSet_LoginPasswordNoneMatch,	//���벻ƥ��
	DGClientSet_DoMainPasswordError,	//���������
	DGClientSet_ModifyPasswordFailed,	//�޸�����ʧ��
	DGClientSet_PasswordError,			//���������
	DGClientSet_PasswordShort,			//����̫�̣��������ַ������֡��»������
	DGClientSet_PasswordSimple,			//������ڼ�
	DGClientSet_NoAllowModifyPassword,	//�������޸�����
	DGClientSet_ConnectDatabaseFailed,	//�������ݿ�ʧ�ܣ����IP��port�Ƿ���ȷ

	DGClientSet_PasswordOrLoginNameError,//��������ǵ����˺Ŵ���
	DGClientSet_TestUpdateServerFailed,	//���Ը��·���ʧ��
	DGClientSet_TestValidateServerFailed,//���Է���ʧ��
	DGClientSet_TestDogServiceFailed,	//���Թ�����ʧ��
	DGClientSet_TestLogServiceFailed,	//�����־����ʧ��
	DGClientSet_TestPerssionServiceFailed,//�����Ȩ����ʧ��
	DGClientSet_TestHofServiceFailed,	//����ⷢ����ʧ��

	//DGClient ����
	DGClient_ProcessNoWOW64 = 3001,			//������������WOW64������
	DGClient_GetSpecFolderPathFailed,	//��ȡ�����ļ�·��ʧ��
	DGClient_GetHostIpFailed,			//��ȡ����IP��ַʧ��
	DGClient_OpenFileFailed,			//���ļ�ʧ��
	DGClient_ProcessAlreadExist,		//�����Ѿ�����
	DGClient_SocketStartupFailed,		//���������ʼ��ʧ��
	DGClient_GetProcessIDTokenFailed,	//��ȡ��������ʧ��
	DGClient_CheckIntegrityLevelExist,	//��������ȼ����̴���
	DGClient_OpenOfflineConfigFileFailed,//�����������ļ�ʧ��
	DGClient_SendCommandToClientUFailed,//���������clienUʧ��

	DGClient_CreateDGWebSetFailed,		//����DGWeb�����ļ�ʧ��
	DGClient_CannotFindDiskNumber,		//�Ҳ������̸���
	DGClient_ControlDeviceIOFailed,		//�����豸IOʧ��
	DGClient_GetDeviceInfoError,		//��ȡ������Ϣ����
	DGClient_CreateClientListenSocketFailed,//����Client����Socketʧ��
	DGClient_GetDGFlowSetFailed,		//��ȡ���������ļ�ʧ��
	DGClient_GetDGFlowSetIniFailed,		//��ȡDGFlow ini�����ļ�ʧ��
	DGClient_GetDGFlowURLFailed,		//��ȡ�ⷢ����ַʧ��
	DGClient_ClientNotRuning,			//�ͻ���û������
	DGClient_ShowDGBubbleDlgMsgException,//��ʾ��ʾ�Ի����쳣

	DGClient_OpenClientConnectRegFailed,//�����ӷ�����ע���ʧ��
	DGClient_OpenProcessTokenFailed,	//�򿪳�������ʧ��
	DGClient_RegisterDeviceNotificationFailed,//ע���豸ʧ��
	DGClient_UserNoPriv,				//�û�û��Ȩ��
	DGClient_DoRegisterDeviceFailed,	//ע���豸ʧ��
	DGClient_GetProcessHandleFailed,	//��ȡ���̾��ʧ��
	DGClient_GetNextProcessHandleFailed,//��ȡ��һ�����̾��ʧ��
	DGClient_OpenFileMappingFailed,		//�򿪹����ڴ�ʧ��
	DGClient_ViewFileToMapFailed,		//�ļ�Ӱ��ʧ��
	DGClient_OpenMutexFailed,			//û�л�����

	DGClient_HaveNotdwCurPriv,			//û��Ȩ��
	DGClient_CreateFileFailed,			//���ļ�ʧ��
	DGClient_GetDeviceGuidFailed,		//�û�ȡGUID��ص��豸��Ϣ�����ʧ��
	DGClient_CreateFileError,			//��ȡ�ļ�����
	DGClient_HaveNotAddOfflineTime,		//û����������ʱ��
	DGClient_GetFileSizeError,			//��ȡ�ļ��Ĵ�С����
	DGClient_MutexHadAlreadExisted,		//�������Ѿ�����
	DGClient_OpenMappingFailed,			//�򿪹����ڴ�ʧ��
	DGClient_ClientStopRunning,			//�ͻ���֪ͨ����
	DGClient_NoPrivControlUSB,			//û��Ȩ�޿���USB�ӿ�

	DGClient_ServiceHaveNotCall,		//����û����Ӧ
	DGClient_UnUSBSTOR,					//USBû�б�����
	DGClient_OpenDiskFailed,			//�򿪴���ʧ��
	DGClient_FlowConnectFailed,			//��������ʧ��
	DGClient_NoDispalyTrayIcon,			//����ʾ����ͼ��


	DGLSupport_RecvCmdError,			//��DGLOCALSupport�н���cmd����
	DGLSupport_RecvDataError,			//��DGLOCALSupport�н������ݴ������
	DGLSupport_CreateConnectSocketError,//��DGLOCALSupport�����ӷ�����ʧ��
	DGLSupport_CheckLogSvrFailed		,//�����־����ʧ��
	DGLSupport_CheckDogSvrFailed		,//��⹷����ʧ��
	DGLSupport_CheckUpdateSvrFailed		,//�����·���ʧ��
	DGLSupport_CheckFilePermissionSvrFailed,//���Ȩ�޷���ʧ��
	DGLSupport_RecvFileError			,//�����ļ�ʧ�� 
	DGLSupport_InsufficientSpace		,//RecvNewestInitData�ӿ���������������Ϣ�Ŀռ䲻����

	DGLLicense_AlreadyExitInstance,//ʵ���Ѿ�����
	DGLLicense_InstanceNotFound,//ʵ��������
	DGLLicense_OfflineInfoNotFound,//������������������ļ�
	DGLLicense_AlreadyInit,//ʵ���Ѿ�����
	DGLLicense_SrvsInfoNotFound,//û���ҵ���������Ϣ

	DGLocalLog_AlreadyInit,//��־�����Ѿ���ʼ��
	DGLocalLog_DllNotFound,//��־dll�������ʧ��
	DGLocalLog_IpcSendLogFailed,//IPC������־ʧ��
	DGLocalLog_InterfaceNotFound,//�ӿ�û���ҵ�
	DGLocalLog_AlreadyExitInstance,//��־����ʵ���Ѿ�����
	DGLocalLog_InstanceNotCreate,//ʵ��û�д���
	DGLocalLog_DGSendPrintLogFailed,//���ʹ�ӡ��־ʧ��
	DGLocalLog_DGSendPrintLogSnpFailed,//���Ϳ���ʧ��
	DGLocalLog_DGSendFileOperateLogFailed,//�����ļ���־ʧ��

	T3Mode_RecvCmdError,			//��T3BusinessMode�н���cmd����
	T3Mode_RecvDataError,			//��T3BusinessMode�н������ݴ���
	T3Mode_CreateConnectSocketError,//��T3BusinessMode�����ӷ�����ʧ��
	T3Mode_CheckT3SvrFailed,		//����ⷢ����ʧ��
	T3Mode_CannotOpenFile,			//�޷����ⷢ�ļ�
	T3Mode_ErrorPassword,			//���벻��ȷ
	T3Mode_ErrorInstallDV,			//����������DV��װ������DV��װʧ��
	T3Mode_ErrorUserName,			//û�и��û�
	T3Mode_ErrorReadRegister,		//��ע����ȡ����ʧ��
	T3Mode_ErrorGetFileGuid,		//��ȡ�ļ�GUIDʧ��
	T3Mode_ErrorLoadDLL,			//����T3BusinessMode.dllʧ��

	HTLUpdate_ReadRegisterError,		//��ע����ȡ��ظ��µ�����ʧ��
	HTLUpdate_CreateConnectSocketError,	//���ӷ�����ʧ��
	HTLUpdate_RecvCmdError,				//����cmd����
	HTLUpdate_RecvDataError,			//�������ݴ���
	HTLUpdate_RecvFileError,			//�ӷ����������ļ�ʧ��
	HTLUpdate_RecvThreadError,			//�ӷ����������ļ��ĺ��������쳣
	HTLUpdate_GetFileMD5Error,			//��ȡ�ļ�MD5��ʧ��
	HTLUpdate_GetFileVersionIDError,	//��ȡ�ļ��汾��ʧ��
	HTLUpdate_InstallServiceError,		//ע��������


	HTUpdate_GetXmlFailed,				//��ȡxmlʧ��
	HTUpdate_ConnectDBFailed,			//����DBʧ��
	HTUpdate_SelectDBFailed,			//��ѯʧ��
	HTUpdate_RecvFailed,				//��������ʧ��
	HTUpdate_CreateIPCFailed,			//����IPCʧ��

};


enum DG_IPC_LOG_TYPE
{
	DG_LOG_PRINT = 1,//��ӡ��־
	DG_LOG_FILEOPERATE, //�ļ�������־
	DG_LOG_AUTHORIZESLEVEL,//��Ȩ�ܼ���־
	DG_LOG_AUTHORIZEPERIMISSION,//��ȨȨ����־
	DG_LOG_DSMFILE,//��Ȩ�ļ���־
};
enum DG_IPC_CMD
{
	IPC_CMD_NewUserConfigInfo		= 1,
	IPC_CMD_GetDGLanding,
	IPC_CMD_UpdateAprroveInfo,
	IPC_CMD_ChangeCFGNormal,
	IPC_CMD_ChangeCFGClose,
	IPC_CMD_ReflashReg,
	IPC_CMD_UploadWaterMarkModule,
};
enum DG_OFFLINETYPE
{
	DGOffline_Normal = -1,
	DGOffline_Fault	 = 0,
	DGOffline_SoftOffline =1,
	DGOffline_ClockLock = 2,
};

enum DG_ONOFFLINETYPE
{
	DGOnOffline	 = 0,
	DGOnBackNet =1,
	DGOnFlashClockLock = 2,
};
enum DG_PURVIEW
{
	CLIENT_OPENCLOSE_STATE = 0x80,
};
struct DG_LogAlarmRule
{
	int	  nId;
	TCHAR tcName[LEN_NAME];
	TCHAR tcReceive[LEN_MAX];
	int	  nState;
	int   nType;
	TCHAR tcCreateTime[LEN_TIME];
};

#ifndef LEVEL_ARR_SIZE
#define LEVEL_ARR_SIZE 6000
#endif
#ifndef DOCGUARDER42
struct Offline_Info2 // DocGuarder3.0�ṹ
{
	BYTE  Key[128];
	DWORD DogID;
	DWORD dwCurPriv;
	DWORD dwOverTime;
	DWORD dwCryptLevel;
	int	  nPolicyType;
	int	  nPolicyCount;
	int	  arrPolicy[LEVEL_ARR_SIZE];		//֧��1000���ȼ����������
	int   bandmask;				//����Ϣ
	char strNetSerial[32];		
	char strHardSerial[32];
	char strPassword[32];
	char strIP[16];				 //֧�ֹ��������սڵ�
	BOOL  bUseTimeControl;		 //�Ƿ�ʹ��ʱ�ӹ���  TRUE: ��������������������, FALSE: �� dwOverTime ��������
	tm    tmBase;			     //���ڵĻ�׼ʱ��
	int dwStartTimeSecond;     //�뿪ʼʹ�õ�ʱ��,(��Ϊ��λ)
	int dwEndTimeSecond;		 //�����ʹ�õ�ʱ��,(��Ϊ��λ)
};

struct Offline_Info3 // ���������ṹ
{
	TCHAR		strLoginName[512];			//������¼��
	TCHAR		strComputerName[512];		//�����������
	TCHAR		strClientID[40];			//�����ͻ���ID
	TCHAR		strNetErorID[40];			//������ȨID������ʱʹ��
	int			nTime;						//����ʱ��
	BOOL		bIsAddTime;					//�Ƿ�����ʱ��
	SYSTEMTIME	stOverDate;					//�����ļ���ʹ��ʱЧ
};

struct SystemApi32Use		//��Ӧ�ó�����봫�ݵ�����
{
	BYTE  Key[128];			//������Կ
	DWORD DogID;			//����
	DWORD dwCurPriv;		//��ǰ���û�Ȩ��
	DWORD dwCryptLevel;		//�û��ĵȼ�
	int	  nPolicyType;		//���Ե�����  (��ʱ��Ч)
	int	  nPolicyCount;		//���Ե�ʵ�ʸ���
	int	  arrPolicy[LEVEL_ARR_SIZE];  //֧��1000���ȼ��Ĵ򿪲���
};

#else
struct Offline_Info2 // DocGuarder3.0�ṹ
{
	BYTE  Key[128];
	DWORD DogID;
	LONGLONG dwCurPriv;
	DWORD dwOverTime;
	DWORD dwCryptLevel;
	int	  nPolicyType;
	int	  nPolicyCount;
	int	  arrPolicy[LEVEL_ARR_SIZE];		//֧��1000���ȼ����������
	int   bandmask;				//����Ϣ
	char strNetSerial[32];		
	char strHardSerial[32];
	char strPassword[32];
	char strIP[16];				 //֧�ֹ��������սڵ�
	BOOL  bUseTimeControl;		 //�Ƿ�ʹ��ʱ�ӹ���  TRUE: ��������������������, FALSE: �� dwOverTime ��������
	tm    tmBase;			     //���ڵĻ�׼ʱ��
	int dwStartTimeSecond;     //�뿪ʼʹ�õ�ʱ��,(��Ϊ��λ)
	int dwEndTimeSecond;		 //�����ʹ�õ�ʱ��,(��Ϊ��λ)
};

struct Offline_Info3 // ���������ṹ
{
	TCHAR		strLoginName[BUFF_SIZE];			//������¼��
	TCHAR		strComputerName[BUFF_SIZE];		//�����������
	TCHAR		strClientID[40];			//�����ͻ���ID
	TCHAR		strNetErorID[40];			//������ȨID������ʱʹ��
	int			nTime;						//����ʱ��
	BOOL		bIsAddTime;					//�Ƿ�����ʱ��
	SYSTEMTIME	stOverDate;					//�����ļ���ʹ��ʱЧ
};

struct SystemApi32Use		//��Ӧ�ó�����봫�ݵ�����
{
	BYTE  Key[128];			//������Կ
	DWORD DogID;			//����
	LONGLONG dwCurPriv;		//��ǰ���û�Ȩ��
	DWORD dwCryptLevel;		//�û��ĵȼ�
	int	  nPolicyType;		//���Ե�����  (��ʱ��Ч)
	int	  nPolicyCount;		//���Ե�ʵ�ʸ���
	int	  arrPolicy[LEVEL_ARR_SIZE];  //֧��1000���ȼ��Ĵ򿪲���
};
#endif


struct DG_LogAlarmRuleDetail
{
	int   nRid;
	int   nOperate;
	TCHAR tcExpression[LEN_MAX];
	int   nType;
	TCHAR tcField[LEN_NAME];
	TCHAR tcReceive[LEN_MAX];
};

struct	DG_NeedApproveInfo
{
	int nColID;
	TCHAR cColName[255];
};

enum DG_IPC_TYPE
{
	IPC_TYPE_LOG =1,
};
struct st_Log_Print_Record  
{
	int nIpcType;
	int	  nPrintID;
	WCHAR wcPrintIP[32];
	WCHAR wcPrintComputer[40];
	WCHAR wcPrintTime[40];
	WCHAR wcPrintUser[50];
	WCHAR wcPrintDocName[MAX_PATH];
	WCHAR wcPrintSnapshot[MAX_PATH];
	BOOL  bPrintDeleted;
	WCHAR wcManageGuid[38];
	WCHAR wcLogGuid[38];
};

struct DG_Log_Print_Record  
{
	int	  nPrintID;
	WCHAR wcPrintIP[32];
	WCHAR wcPrintComputer[40];
	WCHAR wcPrintTime[40];
	WCHAR wcPrintUser[50];
	WCHAR wcPrintDocName[MAX_PATH];
	WCHAR wcPrintSnapshot[MAX_PATH];
	BOOL  bPrintDeleted;
	WCHAR wcManageGuid[38];
	WCHAR wcLogGuid[38];
};

struct DG_Log_FileOperation_Record  
{
	int	  nLogFileID;
	WCHAR wcLogFileIP[32];					//IP
	WCHAR wcLogFileComputer[40];			//�������
	WCHAR wcLogFileTime[40];                //����ʱ��
	WCHAR wcLogFileUser[50];                //�û���
	WCHAR wcLogFileName[MAX_PATH];			//�ļ�·��
	int	  nFileSlevel;						//�ļ��ȼ�
	int   nFileOper;						//��������
	int   nInternalError;					//�ڲ�����
	int   nSystemError;					    //ϵͳ����
	BOOL  bDeleted;							//�Ƿ�ɾ��
	WCHAR wcManageGuid[40];					//����GUID
	WCHAR wcFileServerPath[MAX_PATH];		//�ϴ��������ϵ�·��
	WCHAR wcLogGuid[40];					//��־GUID
	WCHAR wcFileGuid[40];					//�ļ�GUID
	WCHAR wcFileOperateGuid[40];					//����ID
};

struct ST_Log_Uninstall_Record
{
	int nModule;
	TCHAR szIP[32];
	TCHAR szComputerName[128];
	TCHAR szUninstallTime[128];
	TCHAR szUser[128];
	TCHAR szModule[128];
};


struct DBS_SLevelInfo
{
	int nType;// 1:�û�	2:����
	int nPermission; //Ȩ��
	TCHAR szNameId[256];//logname
	TCHAR szName[256];//�û���/������
	TCHAR szSlevelName[256];//�ܼ���
	TCHAR szSleveId[256];//�ܼ�Id
};

struct DBS_FilePermission
{
	int nType;// 1:�û�	2:����
	int nPermission; //Ȩ��
	TCHAR szEmpId[256];//�û�loginid/������
	TCHAR szName[256];//�û���/������
	TCHAR szSlevelName[256];//�ܼ���
	TCHAR szFileId[256];//�ܼ�Id
	TCHAR szExpireDate[256];//����Ȩ����Ч��
};

struct DBS_FileInfo
{
	TCHAR szGuid[64];
	TCHAR szSuffix[64];
	TCHAR szFilePath[MAX_PATH];
	TCHAR szCreateName[255];

};
struct DBS_AuthorizeInfo
{
	TCHAR szNewId[40];
	TCHAR szOrgId[40];
	TCHAR szUser[256];
};

struct st_Tn_Monitor
{
	WCHAR	wcIP[LEN_NAME];
	WCHAR	wcComputer[LEN_NAME];
	WCHAR	wcLoginName[LEN_NAME];
	WCHAR	wcRecentTime[LEN_TIME];
	WCHAR	wcVer[LEN_NAME];
	WCHAR	wcServerName[LEN_NAME];
	WCHAR	wcClientID[LEN_NAME];
	int		nState;
};

struct DBS_FileLogInfo
{
	TCHAR szGuid[64];
	TCHAR szSuffix[64];
	TCHAR szFilePath[MAX_PATH];
	TCHAR szSvrFilePath[MAX_PATH];
	TCHAR szCreateName[255];

};

struct DBS_LOG_FilePermission
{
	int nType;// 1:�û�	2:����
	int nPermission; //Ȩ��
	TCHAR szEmpId[256];//�û�loginid/������
	TCHAR szName[256];//�û���/������
	TCHAR szSlevelName[256];//�ܼ���
	TCHAR szFileId[256];//�ܼ�Id
	TCHAR szExpireDate[256];//����Ȩ����Ч��
	TCHAR szLogGuid[40];
};

struct DBS_LOG_SLevelInfo
{
	int nType;// 1:�û�	2:����
	int nPermission; //Ȩ��
	TCHAR szNameId[256];//logname
	TCHAR szName[256];//�û���/������
	TCHAR szSlevelName[256];//�ܼ���
	TCHAR szSleveId[256];//�ܼ�Id
	TCHAR szLogGuid[40];
};


typedef std::vector<st_Tn_Monitor> vecStTnMonitor;

/*
�ⷢ��صĽṹ
*/
struct T3_DBS_LoginInfo
{
	TCHAR szLoginName[128];
	TCHAR szLoginPasswd[128];
};

struct T3_DBS_RTLoginInfo
{
	int nRet;//0 У��ͨ�� 1 �޴��˺� 2�������
	int nSetupCount;
};

struct T3_DBS_SetupInfo
{
	TCHAR szName[128];
};

struct T3_DBS_RTSetupInfo
{
	int nRet;// 0 �ɹ� 1ʧ��
};


struct T3_DBS_CheckFileInfo
{
	int nFileId;
	TCHAR szPasswd[128];
	TCHAR szName[128];

};

struct T3_DBS_RTCheckFileInfo
{
	bool bNeedCheckPass;
	int nRet;//��ѯ��� 0���� 1 �ļ�Ȩ�޹��� 2�޷��鵽Ȩ����Ϣ 3.�򿪴����þ� 4 ������� 5�˺Ų�����
	int nPermission;

};

struct Outside_CheckDog
{
	DWORD dwLable;
	TCHAR strCompanyMD5[40];	//��˾
	BYTE  Key[128];				//������Կ
	DWORD DogID;				//����
	TCHAR hardSerial[128];		//Ӳ���󶨺�
};


struct Outside_CheckDog2
{
	int nMode;
	DWORD dwDogID;
};

enum OutsideFile_Type
{
	DG_Outsidefile_Type_Normal = -1,		//����
	DG_Outsidefile_Type_Encrypt = 0,		//����
	DG_Outsidefile_Type_4_5 = 1,			//4.5�ⷢ�ļ�
	DG_Outsidefile_Type_4_6 = 2,			//4.6�ⷢ�ļ�
	DG_Outsidefile_Type_Compression,		//ѹ���ļ�
};



struct DG_SPIPCS
{
	int nType;
	int nComIndex;
	int nbaudrate;
	char cPhoneNumber[256];
	TCHAR szData[256];
};

/*
���·�����ؽṹ
*/

enum HTLU_IPC_LOG_TYPE
{
	IPC_HTLU_ServiceInfo = 1,	//������IP�Ͷ˿���Ϣ
	IPC_HTLU_BasicPCInfo,			//���˼���������Ϣ
	IPC_HTLU_ServiceTestContinue,
	IPC_HTLU_ServiceTestGetUserName,
};

struct HTLU_ServiceInfo
{
	TCHAR szServIP[1024];
	DWORD dwPort;
};

struct HTLU_BasicPCInfo
{
	TCHAR strDName[1024];
	TCHAR strUser[1024];
	TCHAR strGuid[1024];
	TCHAR strGID[1024];
	TCHAR strDes[4096];
};