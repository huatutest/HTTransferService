#ifndef _SP_COMM_H_
#define _SP_COMM_H_

#include <winsock2.h>

/*
ͨѶ�࣬by wenyy 2002-02-01
��װ��ͨ����Ķ�д������(�಻���̰߳�ȫ��)
v.01 ֧��Socket
v.02 ֧��NamedPipe
ͨ��������Ҫ��װ��ͨ�Ŷ�д����
�����๦�ܵ�˵����CIPCComm����
v.01 socket communication

2002-06-25
by wenyy
���ļ������ΪDLL ��ʽ��ͬʱ������ص�ȫ�ֺ�����������ʹ��������еľ�̬��Ա����
���UDP֧��
����������ࣺCTCPSocket��CUDPSocket���ֱ�֧��TCP��UDPЭ��
����UDP����������ƹ�ϵ�����ڷ���UDP��ʱ��Ҫ���������ߴ�
*/

//ʹ������Ĵ���������DLL
/*
#if defined(_DEBUG)
	#pragma comment(lib, "commIPC_D.lib")
#else
	#pragma comment(lib, "commIPC.lib")
#endif
*/

namespace commIPC

//�����������
//�ɹ�
#define SP_ERR_SUCCESS			0
//�������
#define SP_ERR_NETWORK			1
//û����ɶ���д,ֻ�����д������Ҫ��Ҫ������
#define SP_ERR_NOT_FINISH		2
//����ʱ��
#define SP_ERR_TIMEOUT			3
//������
#define SP_ERR_NODATA			4
//UDP�����ȳ���ϵͳ����
#define SP_UDP_TOOLONG			5
//UDP����ʱ����������̫С
#define SP_UDP_SMALLBUF			6
//δʵ�ָõ���
#define SP_ERR_NOT_IMPLEMENT	98
//һ�����
#define SP_ERR_GENERAL			99

{//�������ֿռ�

//pszLocalAddrΪ������ʹ�õ�IP��ַ,���ΪNULL,����ʹ������IP��ַ,ϵͳ�Զ�ѡ��
//pszLocalAddr��Ҫ�󶨵ı��ص�ַ�����ΪNULL�������е�ַ
//����INVALID_SOCKET����ʧ��
extern "C" SOCKET SPCreateListenSocket(LPCSTR pszLocalAddr,UINT uPort);
//�����ͻ���SOCKET
//pszLocalAddr��Ҫ�󶨵ı��ص�ַ�����ΪNULL�������е�ַ
//����INVALID_SOCKET����ʧ��
extern "C" SOCKET SPCreateConnectSocket(LPCSTR pszRemoteAddr,int iPort,LPCSTR pszLocalAddr=NULL);
//�������Ž�����ͻ��˵�����
//pszHost,iPort���ڵõ��Է������ĵ�ַ�Ͷ˿�
extern "C" SOCKET SPCreateAcceptSocket(SOCKET sockListen,char* pszHost=NULL,int *piPort=NULL);
//����UDP Socket�����ڽ��շ�����ָ���˿ڣ����ͷ����Բ�ָ��
//pszLocalAddr ������Socket�󶨵ĵ�ַ
extern "C" SOCKET SPCreateUDPSocket(int iLocalPort=0,LPCSTR pszLocalAddr=NULL);

class CIPCComm
{
public :
	CIPCComm(){};
	~CIPCComm(){};
public:
	//��������к��������ܷ��� SP_ERR_GENERAL:��ʾ����δ֪����

	//��:ֱ����ȫ�������ݣ����Ǵ�����
	//���أ�SP_ERR_SUCCESS��SP_ERR_NETWORK,SP_ERR_GENERAL
	//iWant:��Ҫ������ֽ���
	//iRead:����ʵ�ʶ�����ֽ���
	virtual int Recv(const int iWant,BYTE* pbBuf,int& iRead)=0;

	//д:ֱ����ȫд�����ݣ����Ǵ�����
	//���أ�SP_ERR_SUCCESS��SP_ERR_NETWORK,SP_ERR_GENERAL
	//iWant:��Ҫд�����ֽ���
	//iWrote:����ʵ��д�����ֽ���
	virtual int Send(const int iWant,const BYTE *pbBuf,int& iWrote)=0;

	//�����Ƿ������ݵ���
	//���أ�SP_ERR_SUCCESS(�����ݵ���)��SP_ERR_NETWORK��SP_ERR_NODATA,SP_ERR_GENERAL
	//iTimeOut: ��ʱʱ�䣬��
	virtual int TestRead(int iTimeOut)=0;

	//�����Ƿ������ӵ���
	//���أ�SP_ERR_SUCCESS(�����ݵ���)��SP_ERR_NETWORK��SP_ERR_NODATA�������ӵ��,SP_ERR_GENERAL
	//iTimeOut: ��ʱʱ�䣬��
	virtual int TestConnect(int iTimeOut)=0;

	//�ڹ涨ʱ���ڶ���Ҫ������������,�����ܶ�Ķ�������
	//����SP_ERR_SUCCESS��SP_ERR_NETWORK��SP_ERR_NOT_FINISH����ʱ��ֻ���벿�����ݣ���SP_ERR_NODATA��δ�����κ����ݣ�,SP_ERR_GENERAL
	virtual int RecvWithTimeOut(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead)=0;

	//������ݲ����룬�ڼ�⵽���ݺ�ֻ����һ�ζ�������
	//���أ�SP_ERR_SUCCESS������Ҫ�����ݣ���SP_ERR_NETWORK��SP_ERR_NOT_FINISH����⵽���ݣ���ֻ���벿�����ݣ���SP_ERR_NODATA����ʱ��δ�����κ����ݣ�,SP_ERR_GENERAL
	virtual int TestAndRecv(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead)=0;
};

class CIPCSocket: public CIPCComm
{
public:
	//fAutoDel �Ƿ���ɾ������ʱ�Զ��ر�Socket
	CIPCSocket(SOCKET sockComm,BOOL fAutoDel=FALSE);
	~CIPCSocket();
	SOCKET GetSocket(void){return m_sockComm;};
	SOCKET DetachSocket(void){SOCKET s=m_sockComm;m_sockComm=INVALID_SOCKET;return s;};
public:
	//����Socket helper function
	static SOCKET CreateListenSocket(LPCSTR pszLocalAddr,UINT uPort)
	{
		return SPCreateListenSocket(pszLocalAddr,uPort);
	}
	static SOCKET CreateConnectSocket(LPCSTR pszRemoteAddr,int iPort,LPCSTR pszLocalAddr)
	{
		return SPCreateConnectSocket( pszRemoteAddr, iPort, pszLocalAddr);
	}
	static SOCKET CreateUDPSocket(int iLocalPort=0,LPCSTR pszLocalAddr=NULL)
	{
		return SPCreateUDPSocket(iLocalPort,pszLocalAddr);
	}
	static SOCKET CreateAcceptSocket(SOCKET sockListen,char* pszHost=NULL,int *piPort=NULL)
	{
		return SPCreateAcceptSocket(sockListen,pszHost,piPort);
	}
	//
	virtual int Recv(const int iWant,BYTE* pbBuf,int& iRead);
	virtual int Send(const int iWant,const BYTE *pbBuf,int& iWrote);
	virtual int TestRead(int iTimeOut);
	virtual int TestConnect(int iTimeOut);
	static int TestRead(SOCKET sock,int iTimeOut)
	{
		CIPCSocket sTemp(sock,FALSE);
		return sTemp.TestRead(iTimeOut);
	};
	static int TestConnect(SOCKET sock,int iTimeOut)
	{
		CIPCSocket sTemp(sock,FALSE);
		return sTemp.TestConnect(iTimeOut);
	};
	virtual int RecvWithTimeOut(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead);
	virtual int TestAndRecv(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead);
protected:
	SOCKET m_sockComm;
	BOOL m_fAutoDel;
};
//UDPͨ����
class CUDPSocket: public CIPCSocket
{
public:
	CUDPSocket(SOCKET sockComm,BOOL fAutoDel=FALSE);
	//ȡ��ԭ�з��͡����պ�������
	virtual int Recv(const int iWant,BYTE* pbBuf,int& iRead)
	{return SOCKET_ERROR;};
	virtual int Send(const int iWant,const BYTE *pbBuf,int& iWrote)
	{return SOCKET_ERROR;};
	virtual int TestConnect(int iTimeOut)
	{return SOCKET_ERROR;};
	virtual int RecvWithTimeOut(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead)
	{return SOCKET_ERROR;};
	virtual int TestAndRecv(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead)
	{return SOCKET_ERROR;};
	//����ĺ���
	//�������ݣ����������ݳ��ȹ���ʱ���أ�SP_UDP_TOOLONG
	//pszHost,iPort�������öԷ������ĵ�ַ�Ͷ˿�
	virtual int SendTo(const int iWant,const BYTE* pbBuf,int& iWrote,LPCSTR pszHost,const int iPort);
	//�������ݣ�iWantΪ��������󳤶ȣ�����ڽ���ʱ�ó��ȹ�С���᷵�أ�SP_UDP_SMALLBUF
	//pszHost,iPort���ڵõ��Է������ĵ�ַ�Ͷ˿�
	virtual int RecvFrom(const int iWant,const BYTE* pbBuf,int& iRead,char* pszHost=NULL,int *piPort=NULL);

protected:
	UINT m_uMaxUDP;//UDP������󳤶�
};
//TCPͨ����,�ڻ�����û�о����޸�
class CTCPSocket: public CIPCSocket
{
public:
	CTCPSocket(SOCKET sockComm,BOOL fAutoDel=FALSE):CIPCSocket(sockComm,fAutoDel)
	{};

};

//pszPipeName \\.\pipe\pipe_name
//���� INVALID_HANDLE_VALUE ����ʧ��
//�����������˹ܵ�,���ȴ�����
//iTimeout Ϊ�ȴ����ӵĳ�ʱ�г����������
extern "C" HANDLE SPCreateServerPipe(LPCSTR pszPipeName,int iTimeout=10);
//�����ͻ��˹ܵ��������ӵ���������
//pszPipeName \\server\pipe\pipe_name
//iTimeout Ϊ��ʱʱ��
extern "C" HANDLE SPCreateClientPipe(LPCSTR pszPipeName,int iTimeout=10);

class CIPCNamedPipe: public CIPCComm
{
public:
	//fAutoDel �Ƿ���ɾ������ʱ�Զ��ر�Socket
	CIPCNamedPipe(HANDLE hPipe,BOOL fAutoDel=FALSE);
	~CIPCNamedPipe();
	HANDLE GetPipe(void){return m_hPipe;};
	HANDLE DetachPipe(void){HANDLE h=m_hPipe;m_hPipe=NULL;return h;};
public:
	static HANDLE CreateServerPipe(LPCSTR pszPipeName,int iTimeout=10)
	{
		return SPCreateServerPipe(pszPipeName,iTimeout);
	};
	static HANDLE CreateClientPipe(LPCSTR pszPipeName,int iTimeout=10)
	{
		return SPCreateClientPipe(pszPipeName,iTimeout);
	};

	virtual int Recv(const int iWant,BYTE* pbBuf,int& iRead);
	virtual int Send(const int iWant,const BYTE *pbBuf,int& iWrote);
	virtual int TestRead(int iTimeOut);
	virtual int TestConnect(int iTimeOut);
	static int TestRead(HANDLE hPipe,int iTimeOut)
	{
		CIPCNamedPipe sTemp(hPipe,FALSE);
		return sTemp.TestRead(iTimeOut);
	};
	static int TestConnect(HANDLE hPipe,int iTimeOut)
	{
		CIPCNamedPipe sTemp(hPipe,FALSE);
		return sTemp.TestConnect(iTimeOut);
	};
	virtual int RecvWithTimeOut(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead);
	virtual int TestAndRecv(int iTimeout,const int iWant,BYTE* pbBuf,int& iRead);
protected:
	HANDLE m_hPipe;
	BOOL m_fAutoDel;
};

}//������ֿռ�Ķ���
#endif

