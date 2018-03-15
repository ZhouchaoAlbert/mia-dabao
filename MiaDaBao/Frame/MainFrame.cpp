#include "MainFrame.h"
#include "Singleton.h"
#include "BrowApi.h"
#include"..\TerminalOut.h"
CMainFrame::CMainFrame()
{
}


CMainFrame::~CMainFrame()
{

}


CDuiString CMainFrame::GetSkinFolder()
{
	return _T("Resource");
}

CDuiString CMainFrame::GetSkinFile()
{
	return _T("xml\\MainFrame.xml");
}

LPCTSTR CMainFrame::GetWindowClassName(void) const
{
	return _T("MainFrameClass");
}

CControlUI* CMainFrame::CreateControl(LPCTSTR pstrClass)
{
	return NULL;
}

void CMainFrame::InitWindow()
{
	m_hIcon = LoadIcon(CPaintManagerUI::GetInstance(), MAKEINTRESOURCE(101));
	SetIcon(m_hIcon, TRUE);
	SetIcon(m_hIcon, FALSE);
	m_pTreeList = static_cast<CTabLayoutUI*>(m_PaintManager.FindControl(_T("tab_tree_list")));
	m_pEdtObsBatPath = static_cast<CEditUI*>(m_PaintManager.FindControl(_T("edt_obs_bat_path")));
	m_pEdtObsBatPath->SetText(_T("E:\\GitHub\\mia-dabao\\test.bat"));
}

void CMainFrame::OnFinalMessage(HWND hWnd)
{

}

LRESULT CMainFrame::ResponseDefaultKeyEvent(WPARAM wParam)
{
	if (wParam == VK_RETURN)
	{
		return TRUE;
	}
	else if (wParam == VK_F10)
	{
		return TRUE;
	}


	return FALSE;
}

void CMainFrame::Notify(TNotifyUI& msg)
{
	if (msg.sType == DUI_MSGTYPE_CLICK){
		CDuiString szName = msg.pSender->GetName();
		if (szName == _T("btn_min"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MINIMIZE, 0);
		}
		else if (szName == _T("btn_close"))
		{
			ShowWindow(false);
			Close();
		}
		else if (szName == _T("btn_sure"))
		{
			CRichEditUI*  pRichEdit = static_cast<CRichEditUI*>(m_PaintManager.FindControl(_T("rich_info")));
			if (NULL == pRichEdit)
			{
				return;
			}
			CString strText  = m_pEdtObsBatPath->GetText();
			CTerminalOut out;
			out.Init((LPTSTR)strText.GetString(), pRichEdit);
			out.PipeCmdLine();
		}
		else if (szName == _T("btn_max"))
		{
			SendMessage(WM_SYSCOMMAND, SC_MAXIMIZE, 0);
		}
		else if (szName == _T("opt-mia-obs"))
		{
			m_pTreeList->SelectItem(0);
		}
		else if (szName == _T("opt-mia-menten"))
		{
			m_pTreeList->SelectItem(1);
		}
	}
}
