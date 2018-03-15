#pragma once
#include <atlstr.h>
#include <vector>
#include"UIlib.h"
using namespace std;
using namespace ATL;
using namespace DuiLib;
#include"TimerApi.h"
#include "UtilMsg.h"
class CTerminalOut : public Util::Msg::CMsgBase
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
	static UINT32 WINAPI  ThreadProc(void* pVoid);
	void Run();
	void OnTimer(void *pParam1, void *pParam2, void *pParam3);
	void OnMessage(UINT32 uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandle);

private:
	CString      m_strPath;
	CRichEditUI* m_pRichEditUI;

	CTimerSink	 m_tmRun;  //¶¨Ê±Æ÷
	std::vector<CString> m_vecOutInfo;

};

