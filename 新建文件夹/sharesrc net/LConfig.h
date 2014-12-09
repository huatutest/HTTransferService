#pragma once
/*
* Copyright (C), 2009-2012, Huatusoft Tech. Co., Ltd.
* All rights reserved.
*
* �ļ����� LConfig.h
* �ļ���ʶ��
* ժ����Ҫ��
*

* ��ǰ�汾��1.0
* ԭ���ߡ���wmk
* ������ڣ�2012��10��23��
* �޶���¼������
*/

//#include "DGVersion.h"
#include "ErrorRecorder.h"
class CLConfig
{
public:
	CLConfig(void);
	~CLConfig(void);
	/*
	��������:
	�ж��Ƿ�Ϊ���û���¼
	����:
	cr		:���󼯶���
	����ֵ:
	true	���û���¼
	false	�����û���¼
	�꣺
	VERSION_RUNDLL_SHANGQI			= 0x400000,	//�����ʹ�õ�ǰ���û���¼
	*/
	BOOL IsDomainMode(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϿͻ����Ƿ��Զ���������
	������
	cr		:���󼯶���
	����ֵ��
	true	�ͻ����Զ���������
	false	�ͻ��˲��Զ���������
	�꣺
	VERSION_MAIL_MEASURE			= 0x8000,	//�ͻ����Զ���������
	*/
	BOOL IsAutoDownloadCfg(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϹرտͻ���ʱ�Ƿ�Լ����ļ��ܾ�����
	������
	cr		:���󼯶���
	����ֵ��
	true	�رտͻ���ʱ�Լ����ļ��ܾ�����
	false	�رտͻ���ʱ�Լ����ļ��������
	�꣺
	VERSION_RUNDLL_ACCESS			= 0x10000,	//�رտͻ���ʱ�Լ����ļ��ܾ�����
	*/
	BOOL IsDeniedAccessEncrypteFile(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϹرտͻ����Ƿ��л�����ģʽ
	������
	cr		:���󼯶���
	����ֵ��
	true	�ͻ����л�����ģʽ
	false	
	�꣺
	VERSION_CHANGE_CONFIGMODE		= 0x4,  //�ͻ����л�����ģʽ
	*/
	BOOL IsChangeCFGNormal(CErrorRecorder &cr);

	/*
	�������ܣ�
	��ȡ�ͻ����п��ؿͻ���Ȩ��ʱ��Ĭ��״̬
	������
	cr		:���󼯶���
	����ֵ��
	true	�ͻ����п��ؿͻ���Ȩ��ʱĬ�Ͽ���״̬
	false	�ͻ����п��ؿͻ���Ȩ��ʱĬ�Ϲر�״̬
	�꣺
	VERSION_DGCLIENT_DEFAULTOPEN	= 0x80000000,	//�ͻ����п��ؿͻ���Ȩ��ʱĬ�Ͽ���״̬
	*/
	BOOL IsDGClientDefaultOpen(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϿ��ؿͻ����Ƿ���ʾ����
	������
	cr		:���󼯶���
	����ֵ��
	true	���ؿͻ��˲���ʾ����
	false	���ؿͻ�����ʾ����
	�꣺
	VERSION_RUNDLL_TRAYNODISPLAY	= 0x10000000, //���ؿͻ��˲���ʾ����
	*/
	BOOL IsTrayNoDisplay(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϷ���ģʽ��¼�Ƿ�ʹ�ÿ��ؿͻ���
	������
	cr		:���󼯶���
	����ֵ��
	true	����ģʽ��¼ʹ�ÿ��ؿͻ���
	false	����ģʽ��¼��ʹ�ÿ��ؿͻ���
	�꣺
	VERSION_DGCLIENT_OPENCLOSE		= 0x2000,	//����ģʽ��¼ʹ�ÿ��ؿͻ���(����)
	*/
	BOOL IsNonDomainModeOpenClose(CErrorRecorder &cr);

	/*
	�������ܣ�
	�жϿͻ����Ƿ�������ʾ����
	������
	cr		:���󼯶���
	����ֵ��
	true	�ͻ���������ʾ���̵����ܿ���
	false	
	�꣺
	VERSION_DGCLIENT_ALWAYSSHOWTRAY = 0x40000,  //�ͻ���������ʾ���̵����ܿ���
	*/
	BOOL IsAlwaysShowTray(CErrorRecorder &cr);

	/*
	�������ܣ�
	�ж��ƶ��洢�Ƿ����
	������
	cr		:���󼯶���
	����ֵ��
	true	�ƶ��洢����
	false	
	�꣺
	VERSION_DGCLIENT_USBSTOR_FORBID = 0x20000,	//�ƶ��洢����
	*/
	BOOL IsUsbForbid(CErrorRecorder &cr);

	/*
	�������ܣ�
	�ж��Ƿ��U�̽���ȫ��ɨ��
	������
	cr		:���󼯶���
	����ֵ��
	true	��U�̽���ȫ��ɨ��
	false	���Զ�U�̽���ȫ��ɨ��
	�꣺
	VERSION_STANDARD_USBSTOR		= 0x20,		//�Ƿ��U�̽���ȫ��ɨ��
	*/
	BOOL IsFullScanUsb(CErrorRecorder &cr);



};

