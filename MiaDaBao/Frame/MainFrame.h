#pragma once
#include "UIlib.h"
using namespace  DuiLib;
#include <string>
using namespace std;

class CMainFrame : public WindowImplBase
{
public:
	CMainFrame();
	~CMainFrame();

public:// UI≥ı ºªØ
	CDuiString GetSkinFolder();
	CDuiString GetSkinFile();
	LPCTSTR GetWindowClassName() const;
	CControlUI* CreateControl(LPCTSTR pstrClass);
	void InitWindow();
	void OnFinalMessage(HWND hWnd);
	LRESULT ResponseDefaultKeyEvent(WPARAM wParam);

	virtual void Notify(TNotifyUI& msg);
	
private:
	CTabLayoutUI* m_pTreeList;
	CEditUI*      m_pEdtObsBatPath;
	HICON         m_hIcon;

};

