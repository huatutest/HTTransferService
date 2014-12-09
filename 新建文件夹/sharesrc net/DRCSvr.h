#pragma once

#include <vector>
#include <map>
#include <string>
#include "Mutex.h"
using namespace std;

/*


*/


typedef map<wstring, int>	MAPBYINDEX;
typedef map<int, wstring>	MAPBYSOCKET;

enum DRC_PRODUCTS
{
	drc_dgclient = 0,
	drc_dgupdate,
};


class CDRCBusinessUnit;
class CDRCSvr
{
public:
	CDRCSvr(void);
	~CDRCSvr(void);
	

	/*
	��ʼ������ģ��
	_listen����������˿�
	_clt_nuits ��ҵ����ģ��,��ֵԽ�����ٶ�Խ��
	*/
	bool		init_service(int _listen = 8040, int _clt_nuits = 20);
	bool		uninit_service();

	/*
	��ⲻͬ�ͻ����Ƿ��ظ���½
	_product:��Ʒid
	_index: ��Ʒ����

	ret: 
	true �ͻ����Ѿ���½
	false �ͻ���δ��½
	*/
	bool		check_repeat_client(int _product, wstring _index);

	/*
	���ͬһ�ͻ����Ƿ����ظ�login
	_product:��Ʒid
	_sk: ��Ʒ����

	ret: 
	true �ͻ����Ѿ���½
	false �ͻ���δ��½
	*/
	bool		check_repeat_login(int _product, SOCKET _sk);


	bool		add_client(int _product, wstring _index, int _sk);
	bool		remove_client(int _sk);


private:
	void										init_net();
	SOCKET									create_listen(SOCKET _sk);


	vector<CDRCBusinessUnit*>		m_vct_units;

	MutexLock								m_lock_dgclient;		
	MAPBYSOCKET						m_sk_dgclient;
	MAPBYINDEX							m_ind_dgclient;

	MutexLock								m_lock_dgupdate;		
	MAPBYSOCKET						m_sk_dgupdate;
	MAPBYINDEX							m_ind_dgupdate;
};
