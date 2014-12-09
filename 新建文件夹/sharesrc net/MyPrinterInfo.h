#pragma once
#include <tchar.h>

//#define __PrinterInfo_Ini_Path				L".\\PrinterInfo.ini"
#define __PrinterInfo_Ini_AppName			L"PrinterInfo"

typedef struct _MyPrinter_Info
{

	TCHAR szPrinterName[128];

	TCHAR szDriverName[128];

}MyPrinter_Info;

class CMyPrinterInfo
{
public:
	CMyPrinterInfo(void);

	~CMyPrinterInfo(void);

	/*
	nSize :��ÿ��������С

	return:
	���ش�ӡ��������Ϣָ��
	*/

	MyPrinter_Info* GetInfo(int& nSize);


	/*

	PrinterDriverName:��ӡ����������
	bWriteToIni:�Ƿ�Ҫ��û���ϴ��Ĵ�ӡ����������ֱ��׷�ӵ�INI�ļ���
	return:
	<0 :�쳣
	0  :�Ѿ��ϴ�
	1, :δ�ϴ�
	*/
	int isNeedSendToDB(TCHAR* PrinterDriverName, bool bWriteToIni = true);

private:

	/*
	nArraySize ����0,����ʱnArraySize���ñ��޸�Ϊ����Ҫ����MyPrinter_Info�������
	pPrinterInfoArray ���ش�ӡ����Ϣ���飬ÿ������Ԫ��Ϊÿ̨��ӡ����Ϣ
	*/

	int GetMyPrinterInfo( int& nArraySize, MyPrinter_Info* pPrinterInfoArray);

	MyPrinter_Info* m_pInfo;

	
};
