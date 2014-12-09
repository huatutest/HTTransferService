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
	ERROR_DOGKEY = 9,			   //���Ž�Կ��ƥ��
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

extern int EnCryptFile3V4(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,DWORD dwCryptLevel);
extern int  DeCryptFile2V4(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
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
extern int nSystemErrorCode;

extern int ModifyFileOutsideGUID(LPCTSTR lpszFileName,GUID guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);
extern int GetFileOutsideGUID(LPCTSTR lpszFileName,GUID& guid,DWORD dogID,LPCSTR lpszKey,int nKeyLength);

extern BOOL ReadCryptFile(LPCTSTR lpszFileName,DWORD dogID,LPCSTR lpszKey,int nKeyLength,LPBYTE bt,DWORD dwSize);
//�����ؼ��ļ��ļ���
extern BOOL dcfile(LPCTSTR fpath, CString strpass);
extern BOOL ecfile(LPCTSTR fpath, CString strpass);
extern __int64 epass(CString strpass);
#endif