#ifndef __BROWDEFINE_H__
#define __BROWDEFINE_H__
#include <atlstr.h>
using namespace ATL;

namespace Aux
{
	namespace BrowApi
	{
		struct ST_BROWSER
		{
			ST_BROWSER()
			{
				hParentHwnd = NULL;
				nLeft = 0;
				nTop = 40;
				nHeight = 570;
				nWidth = 725;
				uTitleIcon = 201;
				bMin = TRUE;
				bMax = FALSE;
				bClose = TRUE;
				bSetBtn = FALSE;
				bTitle = TRUE;
				bReflashWhenExist = TRUE;
				bCheckInputWhenClose = FALSE;
				bResizeAble = FALSE;
				bTitleBar = FALSE;
				strIconPath = _T("material/logo.png");
				nTipsType = 0;
				uCmd = 0;
				bJumpURL = FALSE;
			}
			HWND	hParentHwnd;   //������
			CString strTitleName;  //��������
			CString strURL;        //��URL
			INT32   nLeft;		   //left��top��PV���ڴӸ����ڵ��Ǹ�λ�ÿ�ʼ��ʾ
			INT32   nTop;
			INT32   nHeight;        //�򿪴��ڵ��ܹ��߶�
			INT32   nWidth;			//�򿪴��ڵ��ܹ����
			UINT32  uTitleIcon;		//ͼƬ��ԴID
			BOOL    bMin;			//�Ƿ���С��
			BOOL    bMax;			//�Ƿ����
			BOOL    bClose;			//�ر�
			BOOL    bSetBtn;		//���ð�ť
			BOOL    bTitle;			//�����Ƿ���ʾ
			BOOL    bReflashWhenExist;    //������ˢ��
			BOOL    bCheckInputWhenClose; //�رմ��ڼ���Ƿ��������
			BOOL    bResizeAble;	//0��Native�ģ�1��web���Ƶģ������1��minButton��maxButtonʧЧ�����������Ĭ����0
			BOOL    bTitleBar;		//0����������������ڴ�С��1������������������ڴ�С��Ĭ��0
			BOOL    bNeedLogin;     //�Ƿ���Ҫ��¼̬
			CString strIconPath;	//��Դͼ��·��
			CString strTempURL;		//��ʱURL ��ʱ=ֻ�е绰�����õ�

			INT32   nTipsType;      //������ʾ���� 1���½��ͻ�
			CString strJSData;      //JS�ص�
			UINT32  uCmd;           //�ص�����Э��
			CString strKey;          //PV����Ψһ�ԣ�ͨ��path��param����url�����MD5��
			CString strKeyParam;     //PV����Ψһ�ԣ�ͨ��path��param����url��ɣ����û��MD5
			UINT32  uBwsID;         //�����Ψһֵ
			BOOL    bJumpURL;       //�Ƿ��ڵ�ǰҳ����תURL
			CString GetIconPath()
			{
				if (211 == uTitleIcon) //��������
				{
					strIconPath = _T("material\\sales_assistant_nom.png");
				}
				return strIconPath;
			}
		};
	}
}


#endif
