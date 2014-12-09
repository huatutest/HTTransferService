// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently,
// but are changed infrequently

#pragma once

#ifndef STRICT
#define STRICT
#endif
#include "targetver.h"

#define _ATL_APARTMENT_THREADED
#define _ATL_NO_AUTOMATIC_NAMESPACE

#define _ATL_CSTRING_EXPLICIT_CONSTRUCTORS	// some CString constructors will be explicit

#include "resource.h"
#include <atlbase.h>
#include <atlcom.h>
#include <atlctl.h>

#include "AString.h"
#define BUFF_SIZE 4096
#define XML_SIZE 102400

using namespace ATL;

#define  MAXCOUNT 8

#define HTP_H3			 0
#define HTP_H5			 1
#define HTP_H7			 2
#define HTP_T3			 3

#define HTV_H3_Standard	 1
#define HTV_H3_Group	 2

#define HTM_LevelMgr	 0x1
#define HTM_DGFlow		 0x2
#define HTM_Authorize	 0x4
#define HTM_Outside		 0x8

#define  ERR_NODOG 300 //��������
#define  ERR_OLDOPENNEWDOG 301//�ϵĽӿڴ��µĹ�
#define  ERR_NOTVTDOG 302//�������ǵĹ� 
#define  ERR_WRITENODATE 303//д���ʱ��û������
#define  ERR_OLDWRITENEWDOG 304//�ϵĽӿ�д��4.6���͵�����
#define  ERR_UNKNOWDOG 305//δ֪��������
#define  ERR_INVALIDKEY 306//��Ч��key
#define  ERR_INVALIDXML 307//��Ч��XML
#define	 ERR_INVALIDDOGID 308//��Ч��DOG ID
#define  ERR_INVALIDDOGVERSION 309//��Ч��Dog Version
#define  ERR_NEWWRITEOLD 310//���µĽӿ�ȥд�Ϲ�
#define  ERR_WRITENEWDOGWITHOLDDOGVERSION 311//д�¹���ʱ��ȴʹ���˾ɵ�DogVersion
#define  ERR_NEWOPENOLDDOG 312//�µĽӿڴ��ϵĹ�
#define  ERR_OPENLICFAILED 313//����Ȩ�ļ�ʧ��
#define  ERR_CREATELICFAILED 314//������Ȩ�ļ�ʧ��
#define  ERR_INVALIDLICINFO 315//��Ч������Ȩ����
#define  ERR_INVALIDPARM 400//��Ч�Ĳ���

struct stDogInfo2
{
	BYTE btFlag[10];//����ʶ��Ĭ��Ϊvamtoo��
	DWORD dwDogVersion;//���汾��Ĭ��Ϊ1��
	DWORD dwDogID;//����
	BYTE  btKey[128];//��Կ
	WORD  dwProduct[MAXCOUNT];//��Ʒ������dwModule [0] = 1��ʾ����DocGuarder��
	INT nCount[MAXCOUNT];//�ڵ�������nCount [0] = 100��ʾ��ƷDocGuarder�ڵ���100��-1��ʾ�����ƣ�
	SYSTEMTIME	tTimeOver[MAXCOUNT];//��Ʒ����ʱ�䣨��tTimeOver[0]��ʾDocGuarder�ĵ���ʱ�䣬ȫ0��ʾ�����ƣ�
	DWORD dwTactics[MAXCOUNT];//��Ʒ���ڲ��� 0���޲��ԡ�0x1������һ��0x2�����Զ�......
	DWORD dwModuleFlag[MAXCOUNT];//ģ���ʶ���磺����0x1�ⷢ0x2��Ȩ����0x4��
	FLOAT nProductViersion[MAXCOUNT];//֧�ֵĲ�Ʒ�汾
	BYTE btGuid[38];//GUID�ַ���
	INT	nReserve;//�����ֶ�
};