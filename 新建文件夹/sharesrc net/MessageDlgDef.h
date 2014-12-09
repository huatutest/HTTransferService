#pragma once

#define safe_delete(p)  if (p != NULL) {	delete  p; 	p = NULL;}

//��ʾ�Ի�������
enum Dlg_Type{

	dlg_bubble = 0,//����
	dlg_linker,//����
	dlg_ok,//ȷ��
	dlg_okcancel,//ȷ��ȡ��
	dlg_yesnolater,
};

//����ICON����
enum MDD_ICON_TYPE
{
	icon_type_warning,
	icon_type_error,
	icon_type_linker,
	icon_type_infomation,
	icon_type_question,
};

//������Ϣʱ�Ĳ�������
typedef	struct __Dlg_Operate_Type
{

	int onOk ;//�����ȷ��
	int onCancel;//�����ȡ��
	int onLater;//�Ժ���

}Mdd_Operate_Type;

typedef struct __Dlg_InitInfo
{
	__Dlg_InitInfo()
	{

		bModal = false;
		nElapse = 4000;
		hWnd = 0;
		nIconType=icon_type_warning;
		nIndex = 0;
		nMsgCount = 0;
		nApproveId = -1;
		OperateType.onOk =0;
		OperateType.onCancel =1;
		memset(strInfo,0,sizeof(strInfo));
		memset(strUrl,0,sizeof(strUrl));

	}
	bool bModal;//�Ƿ�ģ̬
	int nMsgCount;//�Զ�����Ϣ����
	int nDlgType;//�Ի�������
	int nIconType;
	int nMessageType;//��Ϣ����
	int nElapse;//����Ի���Ϊdlg_bubble,��Ҫ����ò���2000.
	int nIndex;//�ṹ������,���踳ֵ,dll�ڲ�����ʱʹ��.
	int nApproveId;
	HWND hWnd;// ������
	Mdd_Operate_Type	OperateType;
	TCHAR strInfo[1024];//�ĵ��ַ���
	TCHAR strUrl[1024];//�����ӵ�ַ

}MSG_DLG_INFO;