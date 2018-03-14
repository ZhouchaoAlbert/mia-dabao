#ifndef __BROWAPI_H__
#define __BROWAPI_H__
#include "BaseDefine.h"
#include "BrowDefine.h"
#include <vector>
using namespace ATL;
using namespace std;
#include "UIlib.h"
using namespace DuiLib;
#define USER_MSG    USER_MSG + 1000
namespace Aux
{
	namespace BrowApi
	{
		BROWER_API void PreInit();
		BROWER_API void PostInit(HWND hECWnd);
		BROWER_API void PreUnInt();
	
		BROWER_API HWND GetECHwnd();

		BROWER_API void OpenPage(ST_BROWSER sBrowParam, BOOL bVisible = TRUE);

		//��ʾ���ص�PV ����ShowPage
		BROWER_API void RefreshPage(LPCTSTR szKey);
		BROWER_API void LoadPage(LPCTSTR szKey, LPCTSTR szURL);
		BROWER_API void ClosePage(LPCTSTR szKey);
		BROWER_API void ClosePage(UINT32 uBwsID); //�رս�������������
		BROWER_API void ExecuteJS(LPCTSTR szKey, LPCTSTR szType, LPCTSTR szJsonData);
		
		BROWER_API void ShowQuitTip(UINT32 uBwsID, bool bShow);    //��ʾ����
		BROWER_API BOOL GetIDList(vector<CString>& vecKey);      //��ȡ���д򿪵�BrowID
		BROWER_API void SetBeforeUnload(LPCTSTR szKey, UINT32 uCmd,LPCTSTR szJsData); //�ر���ʾ

		BROWER_API void PVLoadResult(UINT32 uBwsID, UINT16 uLoadResult);
		//ǶPV�ӿ�
		BROWER_API void OpenEmbedPage(CVerticalLayoutUI* pVer, LPCTSTR szKey, LPCTSTR szURL, BOOL bRefreshPage = TRUE);
		BROWER_API void OpenEmbedPage(CHorizontalLayoutUI* pHor, LPCTSTR szKey, LPCTSTR szURL, BOOL bRefreshPage = TRUE, UINT32 uWidth = 385, UINT32 uHeight = 590);
		BROWER_API void SetEmbedVisible(LPCTSTR szKey);
		BROWER_API BOOL GetEmbedVisible(LPCTSTR szKey);
		BROWER_API CString GetEmbedURL(LPCTSTR szKey);
		//��һ�����ص�PVҳ���� ������ ��ͨ����ʱ��ȥˢ�� �ٹر� 
		BROWER_API BOOL OpenPageHide(LPCTSTR szURL);
		BROWER_API BOOL IsExistKey(LPCTSTR szKey);
		BROWER_API BOOL ReplaceKey(UINT32 uBwsID, LPCTSTR szNewKey);
		
		BROWER_API BOOL OnPVJSCall(LPCTSTR szKey, UINT32 cmd, LPCTSTR szJson);
		BROWER_API BOOL OnPVGetSizeStatus(LPCTSTR szKey, BOOL& bZoomed);
		
		BROWER_API CString GetKeyByBwsID(UINT32 uBwsID);
		BROWER_API HWND GetHwnd(UINT32 uBwsID);
		//���Դ�PV
		BROWER_API void ReOpenPV(UINT32 uBwsID);
		//ע��Ҫ�㲥ˢ�µ�PV
		BROWER_API void RegBroadCastPV(UINT16 uType, LPCTSTR szValue);
		
		//�յ�IM֪ͨ�첽�㲥PV
		BROWER_API void AsynBroadCastPV(LPCTSTR szJsonData);

		//�޸�PV����������� Ŀ��ͱ�������
		BROWER_API void ModifyPvAttribute(UINT32 uBwsID,LPCTSTR szPvTitle);

		//֪ͨ�ͻ��˹رտͻ��˵�Loading���� 
		BROWER_API void NotifyCloseLoading(UINT32 uBwsID);

		//����PV����
		BROWER_API void SetPvFocus(LPCTSTR szKey);

		BROWER_API void SetPVCookie();

		BROWER_API void UpDatePvUrl(LPCTSTR szKey,LPCTSTR szParam, LPCTSTR szValue, BOOL bVisible);
		BROWER_API void DoExit();
	}
}

#endif