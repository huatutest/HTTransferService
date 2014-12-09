#ifndef CRYPTBASE_H
#define CRYPTBASE_H

//���������ķ���ֵ
enum
{
	ERROR_FILE_CRYPTED = 1,	   //���ڱ�ʾ�ļ���һ���Ϸ��ļ����ļ�
	ERROR_ALREADY_CRYPTE = 2,  //�Ѿ��Ǽ����ļ����ļ����ܲ���
	ERROR_CANNOT_OPENFILE = 3, //���ܴ򿪸��ļ�
	ERROR_NO_MAPPING = 4,	   //�ļ�ӳ�������ܴ���
	ERROR_NO_MAPVIEW = 5,	   //�޷������ڴ�ӳ��
	ERROR_KEYLEN_OVERFLOW = 6, //��Կ���ȹ���
	ERROR_DECRYPT_NORMAL = 7,  //��ͼ����һ���������ļ�
	ERROR_NOPRIV_FILE = 8,
	ERROR_FILE_NORMAL = 9,
};

enum 
{
	OFFLINE_LOCALTIME,
	OFFLINE_FORBID,
};

enum
{
	OPER_FORBID,
	OPER_PROMPT,
};

struct CryptFileTime
{
	char	   btFlag[10];				//����ʱ��ı��
	SYSTEMTIME tOverTime;
	int		   nOffineLine;				//���ߴ���ʽ
	int		   nFileOper;				//�����ļ�����ʽ
};

class CDGFileTime
{
public:
	CDGFileTime() {}
	~CDGFileTime() {}

	void GetTimeInfo(HANDLE hFile)
	{
		GetFileTime(hFile,&m_tCreate,&m_tAccess,&m_tWrite);
	}
	void SetTimeInfo(HANDLE hFile)
	{
		SetFileTime(hFile,&m_tCreate,&m_tAccess,&m_tWrite);
		CloseHandle(hFile);
	}
private:
	FILETIME m_tCreate;
	FILETIME m_tWrite;
	FILETIME m_tAccess;
};

#define HEAD_LEN 1024
#define KEY_LEN 128
#define ENCODE_LEN 256
#define TABLE_LEN 256

#define CRYPT_LEVEL_POS 0x2a0  //672
#define CRYPT_TIME_POS	0x2a0+2*sizeof(DWORD)
#define CRYPT_GUID_POS  (CRYPT_TIME_POS+sizeof(CryptFileTime))
#define CRYPT_COMPUTER_POS  (CRYPT_GUID_POS+sizeof(GUID))
#define CRYPT_USER_POS CRYPT_COMPUTER_POS+32

#define RESERVE_LEN 344

//DocGuarder�ļ��İ汾,Ŀǰ��1.0 �� 3.0
#define MAJOR_VERSION	3
#define MINOR_VERSION	0

//1.0�ļ����ļ���ʶΪ "DOCGUARDER_FILE"
//3.0�ļ����ļ���ʶΪ "DG_FILE VER 3.0"

#define XOR_CODE1 0x5c
#define XOR_CODE2 0xc5

#define CHECK_CODE 0x89abcdef

//int nSystemErrorCode = 0;


//lpszFileName:�ļ���
//dogID:		Ӳ�����ĺ���
//lpszKey:		��Կ
//nKeyLength:	��Կ�ĳ��� ���ܴ���128λ

//���� 0 ��ʾ�ɹ�,��������ֵ�������Ĵ�����

//1.0�ļ��ļ��ܺ���
extern int EnCryptFile(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength);

//3.0�ļ��ļ��ܺ���
extern int EnCryptFile2(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength,DWORD dwCryptLevel);
extern int EnCryptFile3(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength,DWORD dwCryptLevel);

//lpszFileName:�ļ���
//dogID:		Ӳ�����ĺ���
//lpszKey:		��Կ
//nKeyLength:	��Կ�ĳ��� ���ܴ���128λ
//���� 0 ��ʾ�ɹ�,��������ֵ�������Ĵ�����
extern int DeCryptFile(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength);
extern int DeCryptFile2(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength);

//lpszFileName:�ļ���
//dogID:		Ӳ�����ĺ���
//lpszKey:		��Կ
//nKeyLength:	��Կ�ĳ��� ���ܴ���128λ
//bFullCheck:	TRUE:Ҫ�����жϸ��ļ��Ƿ��Ǹ�����dogID��key���ܵ��ļ�
//				FALSE:���ж��ļ���ʶ������Docguarder��ʽ���ļ�����

//���� ERROR_FILE_CRYPTED ��ʾ��һ�����������ļ����ļ�
//���� 0	��ʾ����һ��DOCGUARDER��ʽ���ļ�(������һ�������ļ�)
//����������ʾ�޷��ж��Ƿ�Ϊ�����ļ�,���������
extern int IsCryptedFile(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength,BOOL bFullCheck,DWORD* dwCryptLevel = NULL,DWORD* dwMajorVersion = NULL,DWORD* dwMinorVersion = NULL,DWORD* dwCheck = NULL);

extern int ModifyFileLimitTime(LPCTSTR lpszFileName,CryptFileTime timeInfo,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern int GetFileLimitTime(LPCTSTR lpszFileName,CryptFileTime& timeInfo,DWORD dogID,LPCSTR lpszKey,int nKeyLength);

extern int GetFileGUID(LPCTSTR lpszFileName,GUID& guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern int ModifyFileGUID(LPCTSTR lpszFileName,GUID guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern int ClearFileLimitTime(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
//extern int nSystemErrorCode;

extern int ModifyFileOutsideGUID(LPCTSTR lpszFileName,GUID guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern int GetFileOutsideGUID(LPCTSTR lpszFileName,GUID& guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);

//�����ؼ��ļ��ļ���
extern BOOL dcfile(LPCTSTR fpath, CString strpass);
extern BOOL ecfile(LPCTSTR fpath, CString strpass);
extern __int64 epass(CString strpass);
#endif