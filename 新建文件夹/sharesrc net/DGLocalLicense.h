#pragma once
#include "ErrorRecorder.h"
/*
* ժ����Ҫ��
������������з�װ
�������ȼ��� ʱ����<--������<-����
*/

typedef BOOL (_cdecl *DGLL_Init)(CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLL_UnInit)(CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLL_CheckLicense)(BOOL& bDefaultLogin,CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLL_OnFlashClock)(LPTSTR lpLicPath, CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLL_GetOfflineInfo)(int& nMode, int& nLeftTime, CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLL_OnOffline)(LPTSTR lpLicPath,CErrorRecorder& cr);
typedef BOOL (_cdecl *DGLL_OnBackNet)(CErrorRecorder &cr);
typedef BOOL (_cdecl *DGLL_OnStoppageTime)(int nTime, CErrorRecorder& cr);


class CDGLocalLicense
{
public:
	CDGLocalLicense(void);
	~CDGLocalLicense(void);
	/*
	��������:
	����ģ���ʼ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ��ʼ���ɹ�
	false 
	*/
	BOOL Init(CErrorRecorder &cr);

	/*
	��������:
	����ģ�鷴��ʼ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ����ʼ���ɹ�
	false 
	*/
	BOOL UnInit(CErrorRecorder &cr);

	/*
	��������:
	�������ģ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ���Խ�������״̬
	false �Ҳ���������Ϣ
	*/
	BOOL CheckLicense(BOOL& bDefaultLogin,CErrorRecorder &cr);

	/*
	��������:
	ˢ��ʱ����
	����:
	cr		:���󼯶���
	����ֵ:
	true ˢ��ʱ�����ɹ�
	false 
	*/
	BOOL OnFlashClock(LPTSTR lpLicPath, CErrorRecorder &cr);

	/*
	��������:
	��ȡ�����ķ�ʽ��ʣ��ʱ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ��ȡ������Ϣ�ɹ�
	false 
	*/
	BOOL GetOfflineInfo(int& nMode, int& nLeftTime, CErrorRecorder& cr);

	/*
	��������:
	��������
	����:
	cr		:���󼯶���
	����ֵ:
	true ��������ɹ�
	false 
	*/
	BOOL OnOffline(LPTSTR lpLicPath,CErrorRecorder& cr);

	/*
	��������:
	�ص�����
	����:
	cr		:���󼯶���
	����ֵ:
	true �ص�����ɹ�
	false 
	*/
	BOOL OnBackNet(CErrorRecorder& cr);

	/*
	��������:
	��������ʱ��
	����:
	cr		:���󼯶���
	����ֵ:
	true ��������ʱ��ɹ�
	false 
	*/
	BOOL OnStoppageTime(int nTime, CErrorRecorder& cr);

private:
	void InitFunction(HMODULE hInst);

	HMODULE				m_hInst;
	DGLL_Init			m_pInit;
	DGLL_UnInit			m_pUnInit;
	DGLL_CheckLicense	m_pCheckLicense;
	DGLL_OnFlashClock	m_pOnFlashClock;
	DGLL_GetOfflineInfo m_pGetOfflineInfo;
	DGLL_OnOffline		m_pOnOffline;
	DGLL_OnBackNet		m_pOnBackNet;
	DGLL_OnStoppageTime	m_pOnStoppageTime;
};
