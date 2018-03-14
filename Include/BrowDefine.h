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
			HWND	hParentHwnd;   //父窗口
			CString strTitleName;  //标题名字
			CString strURL;        //打开URL
			INT32   nLeft;		   //left、top：PV窗口从父窗口的那个位置开始显示
			INT32   nTop;
			INT32   nHeight;        //打开窗口的总共高度
			INT32   nWidth;			//打开窗口的总共宽度
			UINT32  uTitleIcon;		//图片资源ID
			BOOL    bMin;			//是否最小化
			BOOL    bMax;			//是否最大化
			BOOL    bClose;			//关闭
			BOOL    bSetBtn;		//设置按钮
			BOOL    bTitle;			//标题是否显示
			BOOL    bReflashWhenExist;    //存在则刷新
			BOOL    bCheckInputWhenClose; //关闭窗口检查是否存在输入
			BOOL    bResizeAble;	//0：Native的，1：web控制的，如果是1，minButton和maxButton失效，如果不传，默认是0
			BOOL    bTitleBar;		//0：可以拖拉变更窗口大小，1：不可以拖拉变更窗口大小，默认0
			BOOL    bNeedLogin;     //是否需要登录态
			CString strIconPath;	//资源图标路径
			CString strTempURL;		//临时URL 暂时=只有电话哪里用到

			INT32   nTipsType;      //弹窗提示类型 1：新建客户
			CString strJSData;      //JS回调
			UINT32  uCmd;           //回调类型协议
			CString strKey;          //PV窗口唯一性（通过path、param或者url组成在MD5）
			CString strKeyParam;     //PV窗口唯一性（通过path、param或者url组成）这个没有MD5
			UINT32  uBwsID;         //浏览器唯一值
			BOOL    bJumpURL;       //是否在当前页面跳转URL
			CString GetIconPath()
			{
				if (211 == uTitleIcon) //销售助手
				{
					strIconPath = _T("material\\sales_assistant_nom.png");
				}
				return strIconPath;
			}
		};
	}
}


#endif
