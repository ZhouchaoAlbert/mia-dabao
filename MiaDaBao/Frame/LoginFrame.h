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

	virtual CDuiString GetSkinFolder();   //�õ�Ƥ���ļ���
	virtual CDuiString GetSkinFile();     //�õ�Ƥ���ļ�
	virtual LPCTSTR GetWindowClassName(void) const;  //�õ�������
	virtual void InitWindow();            //��ʼ������
	virtual void Notify(TNotifyUI& msg);  //����ؼ���Ϣ

private:
	CEditUI * m_edtAccount;
	CEditUI * m_edtPwd;
	CButtonUI * m_btnLogin;

	HICON     m_hIcon;
	
};

