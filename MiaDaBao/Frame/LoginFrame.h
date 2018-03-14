#pragma once

#include "UIlib.h"
#include <atlstr.h>
using namespace ATL;

using namespace DuiLib;

class  CloginFrame : public WindowImplBase              
{ 
public:
	CloginFrame();
	~CloginFrame();

	virtual CDuiString GetSkinFolder();   //得到皮肤文件夹
	virtual CDuiString GetSkinFile();     //得到皮肤文件
	virtual LPCTSTR GetWindowClassName(void) const;  //得到窗口名
	virtual void InitWindow();            //初始化窗口
	virtual void Notify(TNotifyUI& msg);  //处理控件消息

private:
	CEditUI * m_edtAccount;
	CEditUI * m_edtPwd;
	CButtonUI * m_btnLogin;

	HICON     m_hIcon;
	
};

