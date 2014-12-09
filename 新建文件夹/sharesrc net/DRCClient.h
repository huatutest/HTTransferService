#pragma once

#pragma comment(lib, "ws2_32.lib")
#include <string>
#include <map>
#include "Mutex.h"
#include "pugixml.h"
using namespace pugi;
using namespace std;

/*

*/

enum DRC_PRODUCTS
{
	drc_dgclient = 0,
	drc_dgupdate,
};

enum DRC_CALLBACK_EVENT_CMD
{
	drc_repeated = 1,
};

enum DRC_CLIENT_ERROR
{
	drc_ok			= 0,
	drc_already_set = -10000,
	drc_unsupport_product,
	drc_setting_uncompleteness,
};

typedef void (*DRC_CALLBACK_GET_INDEX)(TCHAR* _index, int _len_index);
typedef void (*DRC_CALLBACK_TRIGGLE_EVENT)(int _cmd);

struct				DRC_CALLBACK_INFO{
	DRC_CALLBACK_GET_INDEX		cb_index;
	DRC_CALLBACK_TRIGGLE_EVENT  cb_event;
	TCHAR						index[1024];
};


typedef map<int, DRC_CALLBACK_INFO> MAPPRODUCTINFO;


class CDRCClient
{
public:
	CDRCClient(void);
	~CDRCClient(void);

	/*
	�ص�����Ҫ��ɻ�ȡ��ƷIndex�Ĳ���
	*/
	int set_cb_get_index(int _product, DRC_CALLBACK_GET_INDEX _cb);

	/*
	���ص�������ʱ�����ݻص�cmd�¼����н�����
	�ص����ݴ�����Ҫ�������У����������ظ��ص���
	*/
	int set_cb_triggle_event(int _product, DRC_CALLBACK_TRIGGLE_EVENT _cb);

	/*
		��ͬһ����Ʒid������ͬʱ�ɹ�����set_cb_get_index(),set_cb_triggle_event(),
		�ú������ܵ��óɹ�
	*/
	int					init(string _ip, int _port);
	int					uninit();

	void				thread_run();

private:

	void				init_net();
	SOCKET			connect_service();	
	/*
	��������Ƿ�ͨѶ����,��������쳣����Ҫ��������.
	*/
	bool				check_data_pipe();
	bool				check_pipe_alive();

	bool				check_mutex(int _product, wstring _mutex);
	bool				check_product(int _product);
	bool				check_set_completeness();

	void				set_event_cb(int _product, DRC_CALLBACK_TRIGGLE_EVENT _cb);
	void				set_index_cb(int _product, DRC_CALLBACK_GET_INDEX _cb);

	/*
	��һ�����������������ʱ,��Ҫ����ע��״̬
	*/
	void				reset_products_register_state();

	bool				dealwith_products();

	bool				protocol_register_product(TCHAR* _index, int _product, bool& _repeated);
	
	bool				send_xml(TCHAR* _index, int _product, TCHAR* _cmd);

	bool				recv_xml(wstring& _xml);

	MutexLock					m_lock;
	MAPPRODUCTINFO		m_map_product;

	string							m_ip;
	int								m_port;
	HANDLE						m_safe_exit;
	bool							m_exit;

	SOCKET						m_sk;

};
