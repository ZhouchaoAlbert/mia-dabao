#ifndef __EC_DEFINE_H__
#define __EC_DEFINE_H__
#define WM_BOX_MSG_INFO						WM_USER+1000
#define WM_BOX_OPEN_EMAIL_URL				WM_USER+1001    //�ʼ�����  
#define  WM_BOX_OPEN_SHARE_CUSTOMERS		WM_USER+1002    //����ͻ�
#define UM_OPEN_PROFILE_NORMAL_PV			WM_USER+1003
#define UM_SEARCH_MORE						WM_USER+1004	//��������
#define UM_SEARCH_COLLECTED					WM_USER+1005	//��������
#define PV_LOADTIMEOUT                      WM_USER+1006    //PV���س�ʱ

#define  UM_OPEN_ALIOSS_FAILED_WND   WM_USER+1007  //���� ��ȡ����Key ʧ�ܵĴ�����ʾ
#define UM_OPEN_MOBILESIGNATURE_WND			WM_USER+1008	//�����ö���ǩ�����ִ���
#define	UM_OPEN_SINGLEEDIT_WND				WM_USER+1009	//�򿪵����༭�򴰿�	
#define UM_SINGLEEDIT_MSG					WM_USER+1010	//�����༭�򴰿ڷ��͵���Ϣ��

#define TIME_CHECK_MSG_COUNT		6000
#define ID_HOTKEY_SHOWWINDOW		7000
#define ID_HOTKEY_CATCHSCREEN		7001
#define ID_HOTKEY_GETMESSAGE		7002
#define ID_HOTKEY_OPENPANEL			7003

#define ID_TOOLTIP_TOP_TIME         65533
#define ID_TOOLTIP_BOTTOM_TIME      65534
#define ID_GIF_ACTIVE_TIME			65535

#define ID_GRPSET_TOOLTIP_MSG			10		//�Ƿ���ʾ��Ϣ����
#define ID_DISCSET_TOOLTIP_MSG			11		//�Ƿ���ʾ��Ϣ����

#define KICK_OUT    _T("KickOut")               //�ʺ��������ط���¼����������
#define PWD_CHANGE  _T("PwdChange")             //�޸����룬ע��EC��ʾ���µ�¼
#define ACC_CHANGE  _T("AccountChange")         //�����ʺŷ��������ע��EC��ʾ���µ�¼
#define LOGOUT_ACNT	_T("LogoutAccount")			//�ʺ�ע��
#define SWICTH_COMP	_T("SwicthComp")			//�л���ҵ

#define ICON_WANGNING _T("material//warning.png")      //size.x = 69 size.y = 61
#define ICON_WANGNING_X  50
#define ICON_WANGNING_Y  40

#define TITLEICON_WANGING _T("")//material//logo.png

#define ICON_SUCCESS  _T("material//success2.png")   //size.x = 69 size.y = 61
#define ICON_SUCCESS_X  60
#define ICON_SUCCESS_Y  40

#define ICON_KINDLYREMIND	 _T("material//kindlyremind.png")   //size.x = 69 size.y = 61
#define ICON_KINDLYREMIND_X  60
#define ICON_KINDLYREMIND_Y  40

#define PVLINK_URL	_T("https://my.workec.com")
#endif // !__EC_DEFINE_H__