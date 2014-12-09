#pragma once

#include "MessageDlgDef.h"

/*
dll��װ��,�������dll.
*/

typedef int  (_cdecl *DlgInstance)(MSG_DLG_INFO info);
typedef int  (_cdecl *DlgAddMessageType)(int nMsgType, CString& str);
typedef void (_cdecl *DlgRemoveInfoByIndex)(int nIndex);
typedef void (_cdecl *DlgRemoveAllInfo)();
typedef void (_cdecl *DlgRemoveBubbleDlgByIndex)(int nIndex);
typedef void (_cdecl *DlgInitAprroveInfo)(TCHAR* szUser, TCHAR* szIniPath);

class CPackMessageDlg
{
public:
	CPackMessageDlg(void);

	~CPackMessageDlg(void);

	/*
	��DLL�����Ϣ����,DLLֻ�ܽ����Ѿ���ӹ�����Ϣ����
	nType: ��Ϣ����
	str:   ��Ӧ��ʾ�ַ���
	*/
	int AddMessageType(int nType, CString str);

	/*
	ͨ����ֵMSG_DLG_INFO,��dll��������
	*/
	int AddMessage(MSG_DLG_INFO info);

	/*
	��������ɾ����Ϣ
	*/
	void RemoveInfoByIndex(int nIndex);

	/*
	��������ɾ��bubble dlg��Ϣ
	*/
	void RemoveBubbleDlgByIndex(int nIndex);

	/*
	ɾ��������Ϣ
	*/
	void RemoveAllInfo();

	/*
	����������ʼ����Ϣ
	*/
	void InitApproveInfo(TCHAR* szUser, TCHAR* szIniPath);


private:

	void InitFunction(HMODULE hInst);

	HMODULE						m_hInst;

	DlgInstance					m_pDlgInstance;
	DlgAddMessageType			m_pDlgAddMessageType;
	DlgRemoveInfoByIndex		m_pDlgRemoveInfoByIndex;
	DlgRemoveAllInfo			m_pDlgRemoveAllInfo;
	DlgRemoveBubbleDlgByIndex	m_pRemoveBubbleDlgByIndex;
	DlgInitAprroveInfo			m_pInitAprroveInfo;
};
