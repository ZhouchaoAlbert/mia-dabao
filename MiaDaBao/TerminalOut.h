#pragma once
#include <atlstr.h>
#include <vector>
#include"UIlib.h"
using namespace std;
using namespace ATL;
using namespace DuiLib;

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
private:
	CString      m_strPath;
	CRichEditUI* m_pRichEditUI;

};

