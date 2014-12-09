/*
*�̳߳�ģ��
*thread_pool_run():��ҵ�߳�
*add_task_run()�����������̳߳���
*print_state_run()������ʱʹ�ã�ʵʱ��ʾ�̳߳����ж����߳�����
*read_config_run()����ȡ������Ϣ���Ƿ��������̼߳���־���ģ��
*/

#pragma once
#include "windows.h"
#include "TaskUnit.h"
#include "Logger.h"
#include "Mutex.h"
#include <deque>

using namespace std;

enum Service_Type
{
	DogService4 = 0,
	DogFlow,
	HTUpdateService,
	DGFileApprovalServer,
	DGFileUploadService,
	MobileServer,
};

class CThreadPool
{
public:
	CThreadPool(int nServiceType);
	~CThreadPool(void);

	void								init_thread_pool(int nThreadSum ,int nThrTimeOut = 2);			
	void								add_task_to_deq(CTaskUnit* TaskUnit);
	//�̺߳���
	void								thread_pool_run();
	BOOL								add_task_run();
	void								print_state_run();
	void								read_config_run();

private:
	void								get_cfg_path();
	void								get_log_path();
	void								read_cfg();

	BOOL								m_bThreadPoolRun;
	BOOL								m_bAddTaskRun;
	BOOL								m_bEndPrint;
	BOOL								m_bReadCfg;
	BOOL								m_bLogger;
	BOOL								m_bDebug;
	BOOL								m_bInit;

	int									m_nThreadSum;
	int									m_nThreadTimeOut;
	int									m_TimeCount;
	int									m_ServiceType;
	LONG								m_nThreadRunCount;


	CAString								m_strIniPath;
	CAString								m_strLogPath;

	HANDLE								m_hWaitingWork;//֪ͨ�߳�������
	HANDLE								m_hGotgWork;//�ظ����߳�,�߳��Ѿ����
	HANDLE								m_hAddTask;

	MutexLock							m_LockDeq;

	deque<CTaskUnit*>					m_DequeTask;
};
