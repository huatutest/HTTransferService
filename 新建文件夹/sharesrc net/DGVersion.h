
#define VERSION_OUTSIDESETTINGEX	0x10
enum
{
	VERSION_STANDARD_HUATU			= 0x1,		//��;��׼�汾   ok
	VERSION_STANDARD_DAHENG			= 0x2,		//����׼�汾
	VERSION_XINMEIXING				= 0x4,		//�����ǰ汾     ok
	VERSION_SHUANGYOU				= 0x8,		//˫�Ѱ汾
	VERSION_STANDARD_CONFIG			= 0x10,		//�������ó���İ汾
	VERSION_STANDARD_USBSTOR		= 0x20,		//�Ƿ��U�̽���ȫ��ɨ��
	VERSION_STANDARD_DOMAIN			= 0x40,		//������ģʽ     ok
	VERSION_STANDARD_SCANOVER		= 0x80,		//ɨ����̽����� 
	VERSION_STANDARD_NETERRORTIME	= 0x100,	//�������ʱ��
	VERSION_UPDATE_BIGANT			= 0x200,	//bigant���ɰ�
	VERSION_DGCRYPT_NETLOAD			= 0x400,	//�ӽ��ܲ����Ҫ�ֹ������¼  ok
	VERSION_DGCRYPT_PASSWORD		= 0x800,	//�ӽ��ܲ����Ҫ�������   ok
	VERSION_DGCRYPT_NODECRYPT		= 0x1000,	//���ṩ�Ҽ����ܹ���
	VERSION_DGCLIENT_OPENCLOSE		= 0x2000,	//����ģʽ��¼ʹ�ÿ��ؿͻ���(����)
	VERSION_DGCLIENT_ALWAYSOPENCLOSE = 0x4000,  //�ͻ���ʼ��Ϊ���ؿͻ���ģʽ(һ��)
	VERSION_MAIL_MEASURE			= 0x8000,	//�Ҽ��˵������ʼ�������
	VERSION_RUNDLL_ACCESS			= 0x10000,	//�رտͻ���ʱ�Լ����ļ��ܾ�����
	VERSION_DGCLIENT_USBSTOR_FORBID = 0x20000,	//�ƶ��洢����
	VERSION_DGCLIENT_ALWAYSSHOWTRAY = 0x40000,  //�ͻ���������ʾ���̵����ܿ���
	VERSION_DGCLIENT_NOSHORTCUR		= 0x80000,	//��������ͳ��򴴽���ݷ�ʽ
	VERSION_DGADMIN_CHECKPASS		= 0x100000,	//��������ǿ��
	VERSION_DGADMIN_MIGUO			= 0x200000, //���ܰ汾
	VERSION_RUNDLL_SHANGQI			= 0x400000,	//�Ϻ������ر�汾
	VERSION_DGCRYPT_CHECKDOG		= 0x800000, 
	VERSION_RUNDLL_WORKLOG			= 0x1000000, 
	VERSION_LOGON_NOCASE			= 0x2000000, //��¼ʱ�����ִ�Сд
	VERSION_NEW_UPDATE				= 0x4000000, //ʹ���µĸ���ģ��
	VERSION_OA_DECRYPT				= 0x8000000, //OA�ĵ�����Ȩ�޷���
	VERSION_RUNDLL_TRAYNODISPLAY	= 0x10000000, //���ؿͻ��˲���ʾ����
	VERSION_ALL_MAIL				= 0x20000000, //���ؿͻ��˲���ʾ����	= 0x10000000, //���ؿͻ��˲���ʾ����
	VERSION_SPECIAL_OFFLINE			= 0x40000000, //���߼���ʧЧ
	VERSION_DGCLIENT_DEFAULTOPEN	= 0x80000000,	//�ͻ����п��ؿͻ���Ȩ��ʱĬ�Ͽ���״̬
};


enum
{
	VERSION_DGCLIENT_CONTROLCONNECT	= 0x1,	//����connect
	VERSION_CAN_USEDMALLOW			= 0x2,	//�Ҽ��ɽ���DocMentor�ļ�ת��
	VERSION_CHANGE_CONFIGMODE		= 0x4,  //�ͻ����л�����ģʽ
	VERSION_CHECK_DOGSERVER			= 0x8,  //�ͻ��˼��鹷����
	VERSION_SEMIROUTSIDE            = 0x10, //ɭ���ƶ��ⷢ
	VERSION_DOCPLUS					= 0x20, //doc+�汾
	VERSION_HIDEDGPATH				= 0x40, //�ͻ������ذ�װĿ¼
	VERSION_HOF					    = 0x200, //doc+�汾
    VERSION_LANDING_ENCRYPTION      = 0x400, //�Ƿ�������ؼ��� 
	VERSION_STARTUSENEWENCRYPTMODE	= 0x1000	//�Ƿ������¼��ܷ�ʽ
};

//��;������׼�汾
//#define DG_CURRENT_VERSION  VERSION_STANDARD_DAHENG | VERSION_DGCRYPT_PASSWORD

//#define DG_CURRENT_VERSION  VERSION_STANDARD_DAHENG | VERSION_DGCRYPT_PASSWORD

//Э�в�
//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_STANDARD_NETERRORTIME
//����
//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_UPDATE_BIGANT | VERSION_XINMEIXING
//�����
//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_UPDATE_BIGANT

//������ģ
//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_UPDATE_BIGANT | VERSION_DGCLIENT_NOSHORTCUR

//���ٴ���
//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_UPDATE_BIGANT
//����

//#define DG_CURRENT_VERSION  VERSION_STANDARD_HUATU | VERSION_DGCRYPT_PASSWORD | VERSION_DGCRYPT_NETLOAD | VERSION_UPDATE_BIGANT

extern DWORD gCurrentConfig;
extern DWORD gCurrentConfigEx;



#define DG_RIGHT_MODULE //��Ȩģ��

/*inline int GetCurrentVersion()
{
	//���л�;���б���,���Ի�;Ϊ׼
	int version  = DG_CURRENT_VERSION;

	if ((version & VERSION_STANDARD_HUATU) 
		&& (version & VERSION_STANDARD_DAHENG))
	{
		return version - VERSION_STANDARD_DAHENG;
	}
	return DG_CURRENT_VERSION;
}*/

inline int GetDGServerCurrentVersion()
{
	if (gCurrentConfig == 0)
	{
		char buffer[1024] = {0};
		GetSystemDirectoryA(buffer,1023);
		char strConfigFile[1024] = {0};
		sprintf(strConfigFile,"%s\\%s",buffer,"config.ini");
		FILE* fp = fopen(strConfigFile,"r");
		if (fp)
		{
			fscanf(fp,"%x",&gCurrentConfig);
			fclose(fp);
		}	
	}
	
	if (gCurrentConfig == 0)
	{
		gCurrentConfig = VERSION_STANDARD_DAHENG | VERSION_DGCRYPT_PASSWORD;
	}
	return gCurrentConfig;
}

#include "atlbase.h"
#include "ShFolder.h"
#include "shlobj.h"

typedef BOOL (WINAPI *LPFN_ISWOW64PROCESS) (HANDLE, PBOOL);

inline BOOL DGVIsWow64()
{
	LPFN_ISWOW64PROCESS fnIsWow64Process = (LPFN_ISWOW64PROCESS)GetProcAddress(
		GetModuleHandle(L"kernel32"),
		"IsWow64Process"
		);
	BOOL           bIsWow64 = FALSE;

	if (NULL != fnIsWow64Process)
	{
		if (!fnIsWow64Process(GetCurrentProcess(),&bIsWow64))
		{
			// Error handle
			return FALSE;
		}
	}
	return bIsWow64;
}


inline int GetClientCurrentVersion()
{

	USES_CONVERSION;
	if (gCurrentConfig == 0)
	{
		TCHAR buffer[1024] = {0};
		TCHAR strConfigFile[1024] = {0};
		CRegKey key;
		if (key.Open(HKEY_LOCAL_MACHINE,TEXT("software\\{F4C09C2D-E206-75B7-2DBF-15DBC6957210}\\Client"),KEY_READ|KEY_WOW64_32KEY) != ERROR_SUCCESS)
		{
			if (key.Open(HKEY_LOCAL_MACHINE,TEXT("software\\DocGuarder\\Client"),KEY_READ|KEY_WOW64_32KEY) != ERROR_SUCCESS)
			{
			}
		}
		DWORD length = 1024;
		key.QueryValue(buffer,_T("DGPath"),&length);
		_stprintf(strConfigFile,_T("%s\\%s"),buffer,_T("config.ini"));
				
		
		if(_tcslen(buffer) == 0)
		{
			SHGetSpecialFolderPath(NULL,buffer,CSIDL_PROGRAM_FILES,0);
			_stprintf(strConfigFile,_T("%s\\DG\\%s"),buffer,_T("config.ini"));
		}
		
		FILE* fp = _tfopen(strConfigFile,_T("r"));
		if (fp)
		{
			fscanf(fp,"%x",&gCurrentConfig);
			fclose(fp);
		}	
	}
	if (gCurrentConfig == 0)
	{
		gCurrentConfig = VERSION_STANDARD_DAHENG | VERSION_DGCRYPT_PASSWORD;
	}
	
	return gCurrentConfig;
}

inline int GetClientCurrentVersionEx()
{
	USES_CONVERSION;
	if (gCurrentConfigEx == 0)
	{
		TCHAR buffer[1024] = {0};
		TCHAR strConfigFile[1024] = {0};
		CRegKey key;
		if (key.Open(HKEY_LOCAL_MACHINE,TEXT("software\\{F4C09C2D-E206-75B7-2DBF-15DBC6957210}\\Client"),KEY_READ|KEY_WOW64_32KEY) != ERROR_SUCCESS)
		{
			if (key.Open(HKEY_LOCAL_MACHINE,TEXT("software\\DocGuarder\\Client"),KEY_READ|KEY_WOW64_32KEY) != ERROR_SUCCESS)
			{
			}
		}
		DWORD length = 1024;
		key.QueryValue(buffer,_T("DGPath"),&length);
		_stprintf(strConfigFile,_T("%s\\%s"),buffer,_T("config.ini"));
        if(_tcslen(buffer) == 0)
        {
            SHGetSpecialFolderPath(NULL,buffer,CSIDL_PROGRAM_FILES,0);
            _stprintf(strConfigFile,_T("%s\\DG\\%s"),buffer,_T("config.ini"));
        }
		gCurrentConfigEx = GetPrivateProfileInt(_T("ConfigEx"), _T("Config"), 0, strConfigFile);
	}
	return gCurrentConfigEx;
}



//��;(���)��׼�汾
/*
	��������
	�Ҽ��ӽ��ܲ˵�
	U�̲��벻�Զ�����
��ͬ:
    �����Ŀ�ݷ�ʽ
	��¼ͼƬ
	���ڶԻ���
*/

//˫�Ѱ汾
/*
	�ͻ����޼�������
	���Ҽ��˵�
	U�̲����Զ�����
	�ͻ��˲���Ҫ��¼��
	���ɿͻ��˰�װ����ֱ�ӽ���û���������
*/

//�����ǰ汾
/*
	���ӽ��ܹ���Ա(���˹���Ա���Խ��н��ܲ���)
*/

//������ģʽ
/*
	����˾������û����빦��
	�ͻ���ֱ���ڱ�����֤��¼�û�,����Ҫ���ӿ���
	LogonUser
*/
//