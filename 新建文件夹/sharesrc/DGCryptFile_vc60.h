#include "afx.h"
#include "afxwin.h"

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

extern "C" int add(int x,int y);
extern "C" int IsCryptedFile(LPCTSTR lpszFileName,DWORD dogID,const char* lpszKey,int nKeyLength,BOOL bFullCheck,DWORD* dwCryptLevel = NULL,DWORD* dwMajorVersion = NULL,DWORD* dwMinorVersion = NULL,DWORD* dwCheck = NULL);
extern "C" int EnCryptFile(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int EnCryptFile2(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,DWORD dwCryptLevel);
extern "C" int DeCryptFile(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int DeCryptFile2(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int EnCryptFile3(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,DWORD dwCryptLevel);
extern "C" int EnCryptFile4(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,DWORD dwCryptLevel);
extern "C" int ModifyFileLimitTime(LPCTSTR lpszFileName,CryptFileTime timeInfo,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int ClearFileLimitTime(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int GetFileLimitTime(LPCTSTR lpszFileName,CryptFileTime& timeInfo,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int ModifyFileKey(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,DWORD newDogID,LPCSTR newKey,int nNewKeyLength);
extern "C" int ModifyFileGUID(LPCTSTR lpszFileName,GUID guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int GetFileGUID(LPCTSTR lpszFileName,GUID& guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int ModifyFileOutsideGUID(LPCTSTR lpszFileName,GUID guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" int GetFileOutsideGUID(LPCTSTR lpszFileName,GUID& guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern "C" BOOL ReadCryptFile(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,LPBYTE bt,DWORD dwSize);
extern "C" BOOL dcfile(LPCTSTR fpath, CString strpass);
extern "C" BOOL ecfile(LPCTSTR fpath, CString strpass);
