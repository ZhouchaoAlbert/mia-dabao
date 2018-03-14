#include "LoginFrame.h"
#include<atlstr.h>
#include "Singleton.h"

#include "Singleton.h"
#include <time.h>
#include <WindowsX.h>
#include "UtilString.h"
#include "UtilPath.h"
#include <ShlObj.h>

using namespace ATL;

CloginFrame::CloginFrame()
{
}


CloginFrame::~CloginFrame()
{
}


CDuiString CloginFrame::GetSkinFolder()
{
	return _T("Resource");
}

CDuiString CloginFrame::GetSkinFile()
{
	return _T("xml\\LoginFrame.xml");
}

LPCTSTR CloginFrame::GetWindowClassName(void) const
{
	return _T("CloginFrame");
}

void CloginFrame::InitWindow()
{
	m_hIcon = LoadIcon(CPaintManagerUI::GetInstance(), MAKEINTRESOURCE(102));
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	m_edtAccount = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edt_account")));
	m_edtPwd = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edt_pwd")));
	m_btnLogin = static_cast<CButtonUI*>(m_PaintManager.FindControl(_T("btn_login")));
}

void CloginFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK)
	{
		CDuiString szName = msg.pSender->GetName();
		if (szName == _T("btn_close"))
		{
			Close(IDCANCEL);
		}
		else if (szName == _T("btn_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (szName == _T("btn_login"))
		{	
			CString strAccount = m_edtAccount->GetText();
			CString strPwd = m_edtPwd->GetText();
			
		
			if (0 != strAccount.CollateNoCase(_T("zc")) || 0 != strPwd.CollateNoCase(_T("11")))
			{
				MessageBox(NULL, _T("账号密码输入错误请重新输入"), _T("提示"), MB_OK);
				return;
			}
			Close(IDOK);
		}
	}

}
