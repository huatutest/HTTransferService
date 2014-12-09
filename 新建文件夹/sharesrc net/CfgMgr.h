
#pragma once
#include <string>
using namespace std;
#define	GLOBAL_CHECKPASSWD_ON_CLIENTRUN				L"global_checkpasswd_on_clientrun"
#define GLOBAL_CLOSEMACRO_ON_CLIENTRUN					L"global_closemacro_on_clientrun"
#define GLOBAL_CHECK_DGCLIENT_ID								L"global_check_dgclient_id"
#define GLOBAL_CHECK_UPDATE_ID									L"global_check_update_id"
#define	SECTION_CHECKDOG_ON_CLIENTRUN					L"section_checkdog_on_clientrun"
#define SECTION_HIDEICON												L"section_hideicon"
#define SECTION_HIDEPROPETY										L"section_hidepropety"
#define	SECTION_HIDETRAY												L"section_hidetray"


class CCfgMgr
{
public:
	CCfgMgr();
	~CCfgMgr(void);
	/*
	���ܣ�Ѱ��cfg.xml�ļ��У�index_name��valueΪAttributeName���ж�able��value�Ƿ�Ϊ1
	������AttributeName��index_name��value��bAble��able��value��bFlush���Ƿ����¼���cfg.xml
	���أ��ɹ�����TRUE;ʧ�ܷ���FALSE
	*/
	BOOL			ReadCfgData(TCHAR *szAttributeName, BOOL &bAble, BOOL bFlush = FALSE);

private:
	wstring		GetCfgPathFromReg();
	wstring		LoadCfgXml();
	void			DecryptCfgXmlByRC4();

	wstring		m_CfgXmlPath;
	wstring		m_CfgData;
};