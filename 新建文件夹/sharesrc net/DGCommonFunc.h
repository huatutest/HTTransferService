#include <deque>
using namespace std;

#define LEVEL_ARR_SIZE 6000
typedef deque<int> INT_DEQUE;

#define U8 BYTE
#define U32 unsigned long
#define BUFF_SIZE 512

typedef struct rc4_key
{      
   unsigned char state[256];       
   unsigned char x;        
   unsigned char y;
} rc4_key;

#define swap_byte(x,y) t = *(x); *(x) = *(y); *(y) = t

struct Offline_Info	// DocGuarder2.0�ṹ
{
	DWORD DogID;
	BYTE Key[128];
	DWORD dwCurPriv;
	DWORD dwOverTime;
};
 
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

enum
{
	POLICY_OWN = 0,
	POLICY_BELOW,
	POLICY_ALL,
	POLICY_USER,
};

enum
{
	BAND_MAC = 0x01,
	BAND_HARDDISK = 0x02,
	BAND_PASSWORD = 0x04,
	BAND_INTERNET = 0x08,
};

class DGCommonFunc
{
public:
//	���������������ڽ��ַ���ת��Ϊ�涨�ַ����ϵ��ַ���
	static char LMoveBit(int base, int MoveNum);
	static void ToBase64( const unsigned char *in, int inlen, char *out );
	static void FromBase64( const unsigned char *base64code, int base64length, char *out );
////////////////////////////////////////////////////////////////////////////////////////////
//  ����Ϊrc4�㷨�ĺ���

	static void prepare_key(unsigned char *key_data_ptr, int key_data_len, rc4_key *key);
	static void rc4(unsigned char *buffer_ptr, int buffer_len, rc4_key *key);
	static BOOL Encrypt_RC4(LPBYTE lpszBuffer,DWORD dwSize,char* lpszPassword);
//  ��stringת��ΪIP, 127.0.0.1 -> 127 0 0 1
#ifndef NO_MFC_VERSION
	static BOOL String2IP(CAString strIP,BYTE& ip1,BYTE& ip2,BYTE& ip3,BYTE& ip4);
#endif
//  ��ȡע��������
//	static BOOL ReadRegData(LPTSTR strUser,LPTSTR strPass,LPTSTR strServerIP,DWORD& dwServerPort,LPTSTR strUpdateIP,DWORD& dwUpdatePort);
	static BOOL ReadRegData(LPTSTR strUser,LPTSTR strPass);
	static BOOL ReadRegDataEx(LPWSTR strUser,LPWSTR strPass);
	static BOOL ReadRegServerData(LPTSTR strServerIP,DWORD& dwServerPort);
	
	static BOOL ReadRegLogServerData(LPTSTR strLogServerIP,DWORD& dwLogServerPort);

	static BOOL ReadRegServerData2(LPTSTR strServerIP2,DWORD& dwServerPort2);

	static BOOL ReadRegUpdateData(LPTSTR strUpdateIP,DWORD& dwUpdatePort);
	static BOOL ReadRegUpdateData(DWORD& dwServerPort,DWORD& dwUpdatePort);
	static BOOL WriteRegServerData(DWORD dwServerPort);
	static BOOL WriteRegUpdateData(DWORD dwUpdatePort);
//  �ӷ�������֤�û�,���õ���ǰ�û���Ȩ��
//	Offline_Info2* GetLoginData(const char* strUser,const char* strPass,CString strServer,DWORD dwPort,int& nErrorType);
	static BOOL IsInExceptList(int* arrPolicy,int count,DWORD dwCryptLevel);
	static BOOL IsUserCanAccess(int* arrPolicy,int count,DWORD dwCryptLevel,DWORD dwFileLevel);
	static BOOL IsUserCanAccess2(int* arrPolicy,int count,DWORD dwCryptLevel,DWORD dwFileLevel,int nPrivType);
//  �õ�Ӳ����Ϣ
#ifndef NO_MFC_VERSION
	static CAString GetMacByNetBIOS();
	static BOOL GetMacByCmd( CAString &strMac );
	static CAString GetHardDiskSerial();
#endif
};
