#pragma once

/*
* ժ����Ҫ��
DGLocalLogRecorder.dll�ӿڷ�װ

�ͻ��˵�����־ģ��˵��:
��Ҫ�ȵ���InitClientUnit()
����˵�����־ģ��˵��:
��Ҫ�ȵ���InitSvrUnit()
ʹ�ý�������Ҫ����UninitSvrUnit();
*/
#include "ErrorRecorder.h"
#include "DGStruct.h"

typedef BOOL (_cdecl *DGLLog_InitClientUnit)(CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLLog_SendLog)(int nType, char* pData, int nLen, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLLog_InitSvrUnit)(CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLLog_UninitSvrUnit)();


class CDGLocalLogPackage
{
public:
	CDGLocalLogPackage(void);

	~CDGLocalLogPackage(void);

	/*
	��������:
	��־�ͻ���ģ���ʼ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ��ʼ���ɹ�
	false 
	*/
	BOOL InitClientUnit(CErrorRecorder& cr);

	
	/*
	��������:
	��־����˳�ʼ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ��ʼ���ɹ�
	false 
	*/
	BOOL InitSvrUnit(CErrorRecorder& cr);

	/*
	��������:
	���������־����
	����:
	nType		:�ο�DGStruct.h DG_IPC_LOG_TYPEö������
	pData		:��־����
	nLen		:���ݳ���
	����ֵ:
	true ��ʼ���ɹ�
	false 
	*/
	BOOL SendLog(int nType, char* pData, int nLen, CErrorRecorder& cr);



	/*
	��������:
	��־����˷���ʼ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ����ʼ���ɹ�
	false 
	*/
	BOOL UninitSvrUnit(CErrorRecorder &cr);


	
private:
	void InitFunction();

	HMODULE						m_hInst;

	DGLLog_InitClientUnit		m_pInitClientUnit;	
	DGLLog_SendLog				m_pSendLog;
	DGLLog_InitSvrUnit			m_pInitSvrUnit;
	DGLLog_UninitSvrUnit		m_pUninitSvrUnit;
};
