#pragma once
#include <atlstr.h>
#include <vector>
#include"UIlib.h"
using namespace std;
using namespace ATL;
using namespace DuiLib;
#include"TimerApi.h"

class CTerminalOut
{
public:
	CTerminalOut();
	~CTerminalOut();

	void Init(LPTSTR szPath, CRichEditUI* pRichEditUI)
	{
		m_strPath = szPath;
		m_pRichEditUI = pRichEditUI;
	}

	void PipeCmdLine();
	void OnThreadProc();
	void OnTimer(void *pParam1, void *pParam2, void *pParam3);
private:
	CString      m_strPath;
	CRichEditUI* m_pRichEditUI;

	CTimerSink	 m_tmRun;  //¶¨Ê±Æ÷
	std::vector<CString> m_vecOutInfo;

};

