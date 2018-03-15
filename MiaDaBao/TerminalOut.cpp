#include "TerminalOut.h"
#include<thread>


CTerminalOut::CTerminalOut()
{
	m_tmRun.Register(_T("Timer"), this, &CTerminalOut::OnTimer);
	
}


CTerminalOut::~CTerminalOut()
{
}







void CTerminalOut::PipeCmdLine()
{
	std::thread t(&CTerminalOut::OnThreadProc,this);
	t.join();
}


void CTerminalOut::OnThreadProc()
{
	do
	{
		SECURITY_ATTRIBUTES sa;
		ZeroMemory(&sa, sizeof(sa));
		sa.nLength = sizeof(SECURITY_ATTRIBUTES);
		sa.lpSecurityDescriptor = NULL;  //默认的安全描述符   
		sa.bInheritHandle = TRUE;        //这个必须要设定TRUE,参考资料：《windows核心编程》第三章   
		HANDLE hRead = NULL, hWrite = NULL;
		if (!CreatePipe(&hRead, &hWrite, &sa, 0))
		{
			ATLASSERT(FALSE);
			break;
		}

		STARTUPINFO siStartInfo;
		PROCESS_INFORMATION piProcInfo;
		ZeroMemory(&siStartInfo, sizeof(STARTUPINFO));
		siStartInfo.cb = sizeof(STARTUPINFO);
		siStartInfo.dwFlags |= STARTF_USESHOWWINDOW | STARTF_USESTDHANDLES;
		siStartInfo.hStdOutput = hWrite;
		siStartInfo.hStdError = hWrite;

		if (!CreateProcess(NULL, (LPTSTR)m_strPath.GetString(), NULL, NULL, TRUE, NULL, NULL, NULL, &siStartInfo, &piProcInfo))
		{
			ATLASSERT(FALSE);
			break;
		}
		CloseHandle(hWrite);

		//Read
		char		buf[MAX_PATH];

		while (1)
		{
			DWORD bytesRead = 0;
			if (!ReadFile(hRead, buf, sizeof(buf) - 1, &bytesRead, NULL) || !bytesRead)
			{
				break;
			}
			buf[bytesRead - 1] = 0;
			CStringA strTemp(buf);
			ATL::CA2W szTemp(strTemp, CP_UTF8);
			m_pRichEditUI->AppendText(szTemp);
/*			if (!m_tmRun.IsWork())
			{
				m_tmRun.Start(1000);
			}
			m_vecOutInfo.push_back(szTemp.m_psz);
*/
		}
		//Windows下 CMD 输出默认为GBK
		//Util::String::A_2_W(strTemp, strOutput);

		CloseHandle(piProcInfo.hProcess);
		CloseHandle(piProcInfo.hThread);
	} while (0);
}

void CTerminalOut::OnTimer(void *pParam1, void *pParam2, void *pParam3)
{
	std::vector<CString>::iterator iter= m_vecOutInfo.begin();
	if (iter != m_vecOutInfo.end())
	{
		m_pRichEditUI->AppendText(*iter);
		m_vecOutInfo.erase(iter);
	}
	else
	{
		m_tmRun.Stop();
	}
	
}