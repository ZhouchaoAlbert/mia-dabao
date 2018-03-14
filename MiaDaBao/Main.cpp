#include "UtilPath.h"
#include "UIlib.h"
#include "Singleton.h"
#include "Frame\MainFrame.h"
#include "Frame\LoginFrame.h"

using namespace DuiLib;


BOOL LoginFrame()
{
	CloginFrame*	pLoginFrame = &Singleton<CloginFrame>::Instance();
	pLoginFrame->Create(NULL, _T("Mia������"), WS_POPUPWINDOW, 0, 0, 0, 0, 0);
	pLoginFrame->CenterWindow();
	UINT32 uRet = pLoginFrame->ShowModal();
	if (uRet == IDOK)
	{
		Singleton<CloginFrame>::UnInstance();
		return TRUE;
	}
	return FALSE;
}


HWND ShowMainFrame()
{
	CMainFrame* pMainFrame = &Singleton<CMainFrame>::Instance();
	pMainFrame->Create(NULL, _T("Mia������"), WS_OVERLAPPEDWINDOW, WS_EX_TOOLWINDOW, 0, 0, 0, 0);
	pMainFrame->CenterWindow();
	pMainFrame->ShowWindow(true);
	return pMainFrame->GetHWND();
}


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/, LPSTR /*lpCmdLine*/, int nCmdShow)
{
	// COM
	HRESULT Hr = ::CoInitialize(NULL);
	if (FAILED(Hr)) return 0;
	//������Դ����
	CPaintManagerUI::SetInstance(hInstance);
	CString s = Util::Path::GetResFolder();
	CPaintManagerUI::SetResourcePath(s);

	//��������
	if (FALSE != LoginFrame())
	{
		HWND Hwnd = ShowMainFrame();
	}
	//��Ϣѭ��
	CPaintManagerUI::MessageLoop();


	::CoUninitialize();
	return 0;
}
